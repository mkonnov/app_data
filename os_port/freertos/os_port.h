#ifndef OS_PORT_H
#define OS_PORT_H

#include "FreeRTOS.h"
#include "semphr.h"

struct os_mutex {
	SemaphoreHandle_t mux;
};

#endif /* OS_PORT_H */
