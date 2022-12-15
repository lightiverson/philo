#include "philo.h"
// Moet ik ook mutex gebruiken om stdout te locken?

size_t left(size_t i)
{
    return (i);
}

size_t right(size_t i, size_t num_of_philos)
{
    return ((i + 1) % num_of_philos);
}

int main (int argc, char *argv[5])
{
    size_t i = 0;

    think(i);
    eat(i);
    sleep(i);

    return (0);
}
