#include "philo.h"

void    set_bool(pthread_mutex_t *mutex, bool *dest, bool value)
{
    mutex_handle(mutex, LOCK);
    *dest = value;
    mutex_handle(mutex, UNLOCK);
}

bool    get_bool(pthread_mutex_t *mutex, bool *value)
{
    bool    temp;

    mutex_handle(mutex, LOCK);
    temp = *value;
    mutex_handle(mutex, UNLOCK);
    return(temp);
}

void    set_long(pthread_mutex_t *mutex, long *dest, long value)
{
    mutex_handle(mutex, LOCK);
    *dest = value;
    mutex_handle(mutex, UNLOCK);
}

long    get_long(pthread_mutex_t *mutex, long *value)
{
    long    temp;

    mutex_handle(mutex, LOCK);
    temp = *value;
    mutex_handle(mutex, UNLOCK);
    return(temp);
}

void    desyncronized(t_philo *philo)
{
    if (philo->table->n_philo % 2 == 0)
    {
        if (philo->id % 2 == 0)
            sleeping(3e4, philo->table);
    }
    else
    {
        if (philo->id % 2 == 0)
            thinking(philo);
    }
}
