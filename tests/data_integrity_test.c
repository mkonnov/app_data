#include <string.h>

#include "unity.h"
#include "app_data.h"

#define ITEM_ID 0

const app_data_config_struct_t conf = {
	4, 	/* data size */
	NULL,	/* no acquire callback */
	NULL	/* no post callback */
};

static void data_should_match(void) {
	uint32_t int_set = 0xa5a5a5a5, int_get;
	TEST_ASSERT_EQUAL_INT(0, app_data_init(1)); 			/* allocate space for 1 item */
	TEST_ASSERT_EQUAL_INT(0, app_data_register_item(&conf, ITEM_ID));	
	TEST_ASSERT_EQUAL_INT(0, app_data_set(ITEM_ID, &int_set));
	TEST_ASSERT_EQUAL_INT(0, app_data_get(ITEM_ID, &int_get));
	TEST_ASSERT_EQUAL_INT(0, memcmp(&int_set, &int_get, sizeof(int_get)));
}

int main(void) {
	UNITY_BEGIN();
	RUN_TEST(data_should_match);
	return UNITY_END();
}
