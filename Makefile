.PHONY: all app_data test clean

APP_DATA_OBJ = app_data.o

app_data:
	@echo $(APP_DATA_OBJ)

$(APP_DATA_OBJ): app_data.c app_data.h
