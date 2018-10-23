#include "unity.h"
#include "os_port_interface.h"

static struct os_mutex m;

static void os_port_mutex_should_init(void) {
	TEST_ASSERT_EQUAL_INT(0, os_port_mutex_init(&m));
}

static void os_port_mutex_lock_unlock(void) {
	TEST_ASSERT_EQUAL_INT(0, os_port_mutex_lock(&m));
	TEST_ASSERT_EQUAL_INT(0, os_port_mutex_unlock(&m));
}

static void os_port_mutex_lock_trylock_should_fail(void) {
	TEST_ASSERT_EQUAL_INT(0, os_port_mutex_lock(&m));
	TEST_ASSERT_EQUAL_INT(-1, os_port_mutex_trylock(&m));
	TEST_ASSERT_EQUAL_INT(0, os_port_mutex_unlock(&m));
}



int main(void) {
	UNITY_BEGIN();
	RUN_TEST(os_port_mutex_should_init);
	RUN_TEST(os_port_mutex_lock_unlock);
	RUN_TEST(os_port_mutex_lock_trylock_should_fail);
	return UNITY_END();
}
