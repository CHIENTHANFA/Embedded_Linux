<h1 align="center"> <b>01.General_Knowledge</b></h1>

##  Static & Shared Library trong C

> 🚀 Cách biên dịch, liên kết và sử dụng **static (.a)**, **shared (.so)** libraries trong C.
---

## :brain: **Tổng quan**

Dự án trình bày:
- Khởi tạo và sử dụng **Static Library (`.a`)**, **Shared Library (`.so`)**
- Sử dụng Makefile để tối ưu hóa và tự động hóa quá trình biên dịch và liên kết

---

## 📁 **Cấu trúc dự án**
```text
01.General_Knowledge/
├── bin
│   ├── use_shared_lib
│   └── use_static_lib
├── inc
│   └── strutils.h
├── lib
│   ├── shared
│   │   └── libstrutils.so
│   └── static
│       └── libstrutils.a
├── Makefile
├── obj
│   ├── bstrutils.o
│   └── main.o
├── README.md
└── src
    ├── bstrutils.c
    └── main.c

```
## :blue_book: Các hàm có trong thư viện `strutils`

| Hàm | Mô tả |
|------|-------|
| void str_reverse(char *str) | Đảo ngược chuỗi in-place. |
| void str_trim(char *str) | Xóa khoảng trắng đầu và cuối chuỗi. |
| int str_to_int(const char *str); | Sao chép chuỗi số nguyên an toàn|
---

## ⚙️ Hướng dẫn biên dịch và chạy

### 1. :arrow_forward:Run Makefile

```bash
make all

Sau khi build xong , ta sẽ có :
libstrutils.a      # Static library
libstrutils.so     # Shared library
```
### 2. :link:Liên Shared library với file main.c
``` bash
LD_LIBRARY_PATH=./lib/shared/ ./bin/use_shared_lib
```
### 3. :link:Liên Static library với file main.c
``` bash
LD_LIBRARY_PATH=./lib/shared/ ./bin/use_static_lib
```
 ### :page_facing_up: Kết quả
 ``` text
Original: '  Hello Devlinux  '
Trimmed: 'Hello Devlinux'
Reversed: 'xunilveD olleH'
String to int: 12345
```
---
### 🧹 Các lệnh tiện ích

Dọn dẹp toàn bộ file biên dịch:
```bash
make clean 
```
Build static library and shared library:
```bash
make all
```
---
### :building_construction:Cấu trúc Makefile
Makefile tự động biên dịch hai loại thư viện và chương trình mẫu:
```bash
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

```
### 🧠 Kiến thức củng cố được
```text
Cách tạo thư viện Static library và Shared library.

Sử dụng Makefile để tự động hóa quy trình build.

Làm việc với Git & GitHub.
```
### 🧑‍💻 Tác giả
```text
Nguyễn Minh Chiến
📧 Email: chienctt2k3@gmail.com
```
