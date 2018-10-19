#ifndef OS_PORT_INTERFACE_H
#define OS_PORT_INTERFACE_H

#include "os_port.h"

int os_port_mutex_init(struct os_mutex *mux);
int os_port_mutex_deinit(struct os_mutex *mux);
int os_port_mutex_trylock(struct os_mutex *mux);
int os_port_mutex_lock(struct os_mutex *mux);
int os_port_mutex_unlock(struct os_mutex *mux);

#endif /* OS_PORT_INTERFACE_H */
