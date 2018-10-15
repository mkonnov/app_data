#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "app_data.h"

struct app_data_item {
	bool data_updated;
	void *data;
	void *data_prev;
	app_data_config_struct_t init;
};

static struct app_data_item *items = NULL;

int app_data_init(uint32_t count) {
	items = (struct app_data_item *) malloc (sizeof(struct app_data_item) * count);
	if (items == NULL)
		return -1;

	memset(items, 0, sizeof(struct app_data_item) * count);
	return 0;
}

int app_data_deinit(void) {
	if (items != NULL) {
		free(items);
	}
	return 0;
}

int app_data_add_item(const app_data_config_struct_t *item, uint32_t id) {
	/* item is already occupied by another data */
	if (items[id].data != NULL)
		return -2;

	items[id].data = malloc (item->size);
	items[id].data_prev = malloc (item->size);

	memcpy(&items[id].init, item, sizeof(app_data_config_struct_t));
	return 0;
}

//int app_data_get_size(size_t *sz, uint32_t id) {
int app_data_get_size(uint32_t id, size_t *sz) {

	if (items[id].data == NULL)
		return -1;
	*sz = items[id].init.size;
	return 0;
}


int app_data_set(uint32_t id, const void *data) {

	if (items[id].data == NULL)
		return -1;

	/*
	 * move the current data to a "previous" place
	 */
	memset(items[id].data_prev, 0, items[id].init.size);
	memcpy(items[id].data_prev, items[id].data, items[id].init.size);

	/*
	 * put the new data at "current" position
	 */
	memset(items[id].data, 0, items[id].init.size);
	memcpy(items[id].data, data, items[id].init.size);

	/*
	 * if the data is differs, then reise "updated" flag
	 */
	items[id].data_updated = false;
	if (memcmp(items[id].data, items[id].data_prev, items[id].init.size) != 0)
		items[id].data_updated = true;

	return 0;
}

int app_data_get(uint32_t id, void *data_out) {

	if (items[id].data == NULL)
		return -1;

	memcpy(data_out, items[id].data, items[id].init.size);
	return 0;
}

int app_data_get_data_ptr(uint32_t id, void **ptr) {

	*ptr = items[id].data;
	return 0;
}

int app_data_acquire(uint32_t id) {

	int ret;

	if (items[id].data == NULL)
		return -1;

	memset(items[id].data_prev, 0, items[id].init.size);
	memcpy(items[id].data_prev, items[id].data, items[id].init.size);
	items[id].data_updated = false;

	ret = items[id].init.acquire_cb(items[id].data);
	if (ret != 0)
		return ret;

	if (memcmp(items[id].data, items[id].data_prev, items[id].init.size) != 0)
		items[id].data_updated = true;

	return 0;
}

int app_data_post(uint32_t id, const void *arg) {

	int ret;
	if (items[id].init.post_cb == NULL)
		return -1;
	ret = items[id].init.post_cb(id, arg);
	if (ret != 0)
		return ret;
	return 0;
}

bool app_data_is_updated(uint32_t id) {
	return items[id].data_updated;
}

bool app_data_is_differs(uint32_t id) {
	if (memcmp(items[id].data, items[id].data_prev, items[id].init.size) != 0)
		return true;
	return false;
}

void app_data_equalize(uint32_t id) {
	memcpy(items[id].data_prev, items[id].data, items[id].init.size);
}

void app_data_set_updated(uint32_t id, bool updated) {
	items[id].data_updated = updated;
}
