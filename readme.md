# Philo

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

Run code met readline in Ubuntu:
```bash
gcc code.c -L/usr/local/lib -I/usr/local/include -lreadline
```

1. Returned thread create functie een id? Nee, returned 0
2. Je kan een void pointer als arg mee geven -> en 'em daarna naar een andere type pointer omzetten -> hiermee zou je functies kunnen generaliseren die verschillende soorten typen pointers gebruiken, maar wel dezelfde logica
3. Wat is het verschil tussen pthreads.h en threads.h? Threads.h is nieuwe lib voor C11, maar online word aangeraden om oudere pthreads.h te gebruiken
