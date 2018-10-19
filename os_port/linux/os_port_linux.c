#include <stdint.h>
#include <pthread.h>

#include "os_port.h"

int os_port_mutex_init(struct os_mutex *mux) {
	if (pthread_mutex_init(&mux->mux, NULL) != 0) {
		return -1;
	}
	return 0;
}

int os_port_mutex_deinit(struct os_mutex *mux) {
	if (pthread_mutex_destroy(&mux->mux) != 0) {
		return -1;
	}
	return 0;
}


int os_port_mutex_trylock(struct os_mutex *mux) {
	if (pthread_mutex_trylock(&(mux->mux)) != 0) {
		return -1;
	}
	return 0;
}

int os_port_mutex_lock(struct os_mutex *mux) {
	if (pthread_mutex_lock(&(mux->mux)) != 0) {
		return -1;
	}
	return 0;
}

int os_port_mutex_unlock(struct os_mutex *mux) {
	if(pthread_mutex_unlock(&(mux->mux)) != 0) {
		return -1;
	}
	return 0;
}

