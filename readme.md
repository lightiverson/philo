# Philo

In this project, you will learn the basics of threading a process.
You will see how to create threads and you will discover mutexes.

## Notes

Bouw image genaamd ubuntu-philo op basis van Dockerfile:
```bash
docker build -t ubuntu-philo .
```

Draai container op basis van image genaamd  ubuntu-philo met mounted eigen folder:
```bash
docker run --cap-add=SYS_PTRACE --security-opt seccomp=unconfined -it --rm --init -v "$PWD:/pwd"  ubuntu-philo sh -c "cd /pwd; bash"
```
--cap-add=SYS_PTRACE --security-opt seccomp=unconfined = nodig om lldb te kunnen runnen in container
-i = interactive so bash doesn’t immediately quit because there is no input\
-t = bash shows prompt\
--rm = delete container on exit to not waste space\
-v = mounts specific folder from host to Docker container\
--init = shiieet snap het nut niet, maar Noah gebruikt het\
-c = CPU shares (relative weight) ???\
sh = ?
