<h1 align="center"> <b>02.Linux File System</b></h1>

## 🧠 File Metadata Inspector (filestat)

> 🧾 A simple C program that reads and displays essential metadata (information stored in inodes) of a given file or directory using the `lstat()` system call.

---

## :brain: **Overview**

This project demonstrates how to:
- Access **file metadata** directly from the Linux file system.
- Use the **`lstat()`** system call from `<sys/stat.h>` to retrieve information.
- Format and display data such as **file type**, **size**, and **last modification time**.
- Practice Linux system programming with proper error handling and modular code.

---

## 📁 **Project Structure**
```text
02.Linux_File_System/
├── filestat.c           # Main C source file
├── hello.txt            # Test file
└── README.md            # Documentation
```
## 🧰 **Build & Run**

### 🥇 1. Compile
```bash
gcc filestat.c -o filestat
```
### 🥈 2. Run program
```bash
./filestat <file_path>
```
### 🧪 Example:
```bash
./filestat hello.txt
```
### 🖥️ Output:
```bash
========== File Metadata ==========
File Path      : hello.txt
File Type      : Regular File
Size           : 16 bytes
Last Modified  : 11-11-2025 10:13:45
===================================
```
### 🧠 Concepts Reinforced
```text
✔ Understanding of Linux inode-based file metadata.
✔ Use of lstat(), struct stat, and macros (S_ISREG, S_ISDIR, S_ISLNK).
✔ Formatting timestamps using localtime() and strftime().
✔ Command-line argument handling and error checking.
✔ Good modular C programming practices.

### 🧑‍💻 Tác giả
```text
Nguyễn Minh Chiến
📧 Email: chienctt2k3@gmail.com
```
