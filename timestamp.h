#ifndef TIMESTAMP_H
# define TIMESTAMP_H

/* Public libraries */
#include <sys/time.h>

unsigned long timeval_to_ms(struct timeval tv);
unsigned long get_current_timestamp_in_ms(void);

#endif