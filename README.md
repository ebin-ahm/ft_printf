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

- **Makefile** – automates compilation into `libftprintf.a`
- **ft_printf.h** – header file containing prototypes and required includes (`stdarg.h`,`unistd.h`,`stddef.h`)
- **ft_printf.c** – main parser and variadic argument handler
- **Handler files** – implement printing logic for each format specifier
- **Utility files** – low-level output helpers (write wrappers, conversions, etc.)

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
│
├── `Makefile`
├── `ft_printf.h`
├── `ft_printf.c`
│
├── handlers/
│   ├── `handle_char.c`
│   ├── `handle_string.c`
│   ├── `handle_pointer.c`
│   ├── `handle_decimal.c`
│   ├── `handle_unsigned.c`
│   ├── `handle_hex_lower.c`
│   ├── `handle_hex_upper.c`
│   └── `handle_percent.c`
│
└── utility/
    ├── `ft_putchar.c`
    ├── `ft_putstr.c`
    ├── `ft_putnbr.c`
    ├── `ft_putnbr_unsigned.c`
    ├── `ft_puthex.c`
    ├── `ft_strlen.c`
    └── `ft_itoa_base.c (optional)`

*Note: "handlers and "utility" are shown as categories for clarity.*

## Algorithm

1. ft_printf reads the format string from start to end using an index or pointer.

2. If the current character is not '%', it writes that character using write() and increments the character counter. If the current character is '%', it looks at the next character to determine which type to print (c, s, d, x, p, etc.).

3. va_arg is used to fetch the next value from the variadic argument list with the correct type.

4. A handler function for that specifier prints the value using utility functions (for characters, strings, numbers, and hexadecimal). Each handler returns the number of characters it printed, and this value is added to the running total.

5. After the whole format string is processed, va_end is called and ft_printf returns the total count.

## Handlers & Utility

For this `ft_printf` project, the implementation is divided into two functionals layer; handlers & utility
- Handlers manage format-specific behaviour for each specifier.
They are responsible for deciding how to handle %c, %s, %p, %d, %u, %x, %X, and %%.

- Utility functions perform low-level operations such as:
	- character output
	- string handling
	- number to string and number to hex conversions

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
