CUR_DIR := .
INC_DIR := $(CUR_DIR)/inc
SRC_DIR := $(CUR_DIR)/src
OBJ_DIR := $(CUR_DIR)/obj
BIN_DIR := $(CUR_DIR)/bin
LIB_DIR := $(CUR_DIR)/lib
LIB_STATIC_DIR := $(LIB_DIR)/static
LIB_SHARED_DIR := $(LIB_DIR)/shared

LIB_NAME := strutils
BIN_NAME1 := use_shared_lib
BIN_NAME2 := use_static_lib



create_obj:
	gcc -c -o $(OBJ_DIR)/main.o $(SRC_DIR)/main.c -I $(INC_DIR)
	gcc -c -fPIC $(SRC_DIR)/bstrutils.c -o $(OBJ_DIR)/bstrutils.o -I $(INC_DIR)

create_lib:
	gcc -shared $(OBJ_DIR)/bstrutils.o -o $(LIB_SHARED_DIR)/lib$(LIB_NAME).so
	ar rcs $(LIB_STATIC_DIR)/lib$(LIB_NAME).a $(OBJ_DIR)/bstrutils.o 

linking:
	gcc $(OBJ_DIR)/main.o -L$(LIB_SHARED_DIR) -l$(LIB_NAME) -o $(BIN_DIR)/$(BIN_NAME1)
	gcc $(OBJ_DIR)/main.o -L$(LIB_STATIC_DIR) -l$(LIB_NAME) -o $(BIN_DIR)/$(BIN_NAME2)

all: create_obj create_lib linking
	@echo "Build Project"

clean:
	rm -rf $(OBJ_DIR)/*.o
	rm -rf $(LIB_SHARED_DIR)/*
	rm -rf $(BIN_DIR)/*
