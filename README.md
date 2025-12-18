*This project has been created as part of the 42 curriculum by ebin-ahm.*

# ft_printf

---

## Description

---

### Purpose

To recode `printf` function from scratch, stylised as `ft_printf` in accordance to 42 standard without using the internal buffering system of the original `printf`, while supporting all mandatory format specifiers.

### Brief Overview

`printf` is a key function in C that takes in a format string, prints and output a formatted string . `printf` reads a string, character by character, while interpreting `%` as format specifiers.

Each format specifier tells `printf` what type of argument to retrieve from the variadic argument list (using `va_list`, `va_start`, `va_arg`, and `va_end`) and how to convert that value into text. 


| Specifier | Description |
|----------|-------------|
| `%c`     | Print a single character |
| `%s`     | Print a string |
| `%p`     | Print a pointer address (`0x` + hex) |
| `%d` / `%i` | Print a signed integer |
| `%u`     | Print an unsigned integer |
| `%x`     | Print a lowercase hexadecimal number |
| `%X`     | Print an uppercase hexadecimal number |
| `%%`     | Print a literal `%` character |


The final output is written to standard output, and `printf` returns the total number of characters printed. 

### Structure of ft_printf

**Makefile** – builds the libftprintf.a library

**ft_printf.h** – contains function prototypes and required headers

**ft_printf.c** – parses the format string and handles variadic arguments

**print_*.c files** – handle printing for each format specifierr 

---

## Instructions

### Compilation
To compile the library, run:
```bash
make
```

To remove object files:
```bash
make clean
```

To remove object files AND the library:
```bash
make fclean
```

To rebuild everything:
```bash
make re
```

### How to Compile Your Program (main.c) With ft_printf()
```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o program
./program

```

---

# printf structure & algorithm

## Structure 
ft_printf/
├── Makefile
├── README.md
├── ft_printf.h
├── ft_printf.c
├── print_char.c
├── print_string.c
├── print_int.c
├── print_unsigned.c
├── print_hex.c
├── print_pointer.c
└── print_percent.c

*Each print_*.c file implements the logic for a specific format specifier, keeping the design modular and easy to maintain.*

## Algorithm

1. `ft_printf` iterates through the format string character by character while managing a va_list.

2. Regular characters are written directly to standard output using `write()` and counted.

3. When a % is encountered, the next character is treated as a format specifier and dispatched to the appropriate handler using `va_arg`.

4. Each handler prints its value (handling special cases such as NULL) and returns the number of characters printed, which is added to the total count.

5. After processing the entire format string, va_end is called and **ft_printf returns the total number of characters written**.

## Resources

### Classic References
- man pages for standard library functions  
- 42 Norminette rules
- 42 ft_printf PDF version 12.0

### AI-Assisted Learning
AI (ChatGPT) was used for:
1. Clarifying concepts such as pointers, memory operations, and linked list operations  
2. Explaining algorithms, edge cases, and debugging  

All code was manually written and verified by ebin-ahm.
