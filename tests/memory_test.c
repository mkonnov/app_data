#include "unity.h"
#include "app_data.h"

static void init_should_allocate(void) {
	TEST_ASSERT_EQUAL_INT(0, app_data_init(10));
}

static void deinit_should_free(void) {
	TEST_ASSERT_EQUAL_INT(0, app_data_deinit());
}

int main(void) {
	UNITY_BEGIN();
	RUN_TEST(init_should_allocate);
	RUN_TEST(deinit_should_free);
	return UNITY_END();
}
