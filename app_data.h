#ifndef APP_DATA_H
#define APP_DATA_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
	uint32_t size;				/*!< The space to be allocated for item. */
	int (*acquire_cb)(void *out_buf);	/*!< Callback that does smth for data acquisition. */
	int (*post_cb)(uint32_t id, const void *arg);	/*!< Callback to process the current data. */
} app_data_config_struct_t;

int app_data_init(uint32_t count);
int app_data_deinit(void);

int app_data_register_item(const app_data_config_struct_t *item, uint32_t id);

int app_data_get(uint32_t id, void *data_out);
int app_data_set(uint32_t id, const void *data);
int app_data_acquire(uint32_t id);
int app_data_post(uint32_t id, const void *arg);

int app_data_get_size(uint32_t id, size_t *sz);

int app_data_get_data_ptr(uint32_t id, void **ptr);

bool app_data_is_differs(uint32_t id);
void app_data_equalize(uint32_t id);

bool app_data_is_updated(uint32_t id);
void app_data_set_updated(uint32_t id, bool updated);

#endif /* APP_DATA_H */
