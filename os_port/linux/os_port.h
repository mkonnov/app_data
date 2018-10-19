#ifndef OS_PORT_H
#define OS_PORT_H

#include <pthread.h>

struct os_mutex {
	pthread_mutex_t mux;
};

#endif /* OS_PORT_H */
