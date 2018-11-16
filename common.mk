.PHONY: all app_data test clean

INC_DIRS := os_isolation

test:
	@make -C tests
