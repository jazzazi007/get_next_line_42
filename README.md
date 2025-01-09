# 📚 **Get Next Line Project** 🌟

Welcome to the **Get Next Line** project! This README will guide you through understanding, compiling, and using the project with ease. Dive into the code and experience the magic of reading files line by line in C! 🚀

---

## 📝 **Project Overview**

The **Get Next Line** project implements a function, `get_next_line`, that reads a single line from a file descriptor at a time, handling memory efficiently. It is designed to work with any file, socket, or input stream. 🎯

---

## 📂 **File Structure**

### 📄 `get_next_line.c`
Contains the main logic for:
- Reading data from a file.
- Storing remaining data for subsequent calls.
- Extracting and returning individual lines.

### 📄 `get_next_line_utils.c`
Utility functions for:
- String operations (`ft_strlen`, `ft_strdup`, `ft_strjoin`, etc.).
- Memory handling.

### 📄 `get_next_line.h`
The header file with:
- Function prototypes.
- Macros like `BUFFER_SIZE`.

---

## ⚙️ **Compilation**

Compile your files using `gcc` with the following command:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c -o gnl
```

Replace `32` with your desired buffer size. 📏

---

## 🚀 **Usage**

1. **Compile the program** using the command above.
2. **Run the program** with a test file:
   ```bash
   ./gnl <filename>
   ```
3. Observe how each line is read and processed. 📜

---

## 🛠️ **Core Functions**

### 🔹 `get_next_line(int fd)`
Reads and returns the next line from a file descriptor.

### 🔹 Utility Functions:
- `ft_strlen`: Calculate the length of a string.
- `ft_strdup`: Duplicate a string.
- `ft_strjoin`: Concatenate two strings.
- `ft_strchr`: Locate a character in a string.
- `ft_memcpy`: Copy memory blocks.

---

## 📖 **Code Workflow**

1. **Allocate a buffer** for reading.
2. **Read data** into the buffer and save it.
3. Check for a **newline character**:
   - If found, extract the line.
   - Otherwise, continue reading.
4. **Return the line** or NULL when EOF is reached.

---

## 📌 **Examples**

### Input File (`input.txt`):
```txt
Hello, world!
42 Network Rocks!
EOF is near.
```

### Program Output:
```bash
$ ./gnl input.txt
Hello, world!
42 Network Rocks!
EOF is near.
```

---

## 🔍 **Debugging Tips**

- Use `valgrind` to check for memory leaks:
  ```bash
  valgrind --leak-check=full ./gnl input.txt
  ```
- Modify `BUFFER_SIZE` for different performance benchmarks.

---

## 🌟 **Extras**

- Emoji support in comments for fun and clarity! 😄
- Extensive error handling for file operations. 🛑
- Modular and reusable utility functions. 🔄

---

🚀 Enjoy coding with **Get Next Line**! 🌟 Reach out if you have questions or need assistance. Happy coding! 👨‍💻
