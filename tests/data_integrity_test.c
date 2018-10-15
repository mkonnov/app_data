#include "unity.h"
#include "app_data.h"

#include <stdio.h>

enum {
	ITEM_0,
	ITEM_1,
	ITEM_2,
	ITEM_3,
	ITEM_4,
	ITEM_5,
	ITEM_6,
	ITEM_7,
	ITEM_8,
	ITEM_9,
	ITEM_MAX
};

const app_data_config_struct_t conf[] = {
	[ITEM_0] = {
		4,
		NULL,
		NULL
	}
};

static void data_should_match(void) {
	int int_set = 0xa5a5a5a5, int_get;
	TEST_ASSERT_EQUAL_INT(0, app_data_init(ITEM_MAX));	
	TEST_ASSERT_EQUAL_INT(0, app_data_add_item(&conf[ITEM_0], ITEM_0));
	TEST_ASSERT_EQUAL_INT(0, app_data_set(ITEM_0, &int_set));
	TEST_ASSERT_EQUAL_INT(0, app_data_get(ITEM_0, &int_get));
	TEST_ASSERT_EQUAL_INT(0, memcmp(&int_set, &int_get, sizeof(int_get)));
}

int main(void) {
	UNITY_BEGIN();
	RUN_TEST(data_should_match);
	return UNITY_END();
}
