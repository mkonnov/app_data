#include <stdint.h>

#include "os_port.h"

#include "FreeRTOS.h"
#include "semphr.h"

int os_port_mutex_init(struct os_mutex *mux) {
	mux->mux = xSemaphoreCreateMutex();
	if (mux->mux == NULL)
		return -1;
	return 0;
}

int os_port_mutex_deinit(struct os_mutex *mux) {
	vSemaphoreDelete(mux->mux);
	return 0;

}
int os_port_mutex_trylock(struct os_mutex *mux) {
	if (xSemaphoreTake(mux->mux, 0) != pdTRUE)
		return -1;
	return 0;

}
int os_port_mutex_lock(struct os_mutex *mux) {
	xSemaphoreTake(mux->mux, portMAX_DELAY);
	return 0;
}

int os_port_mutex_unlock(struct os_mutex *mux) {
	if (xSemaphoreGive(mux->mux) != pdTRUE)
		return -1;
	return 0;
}
