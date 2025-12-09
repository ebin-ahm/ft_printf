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

1. Start by initializing a counter to track the total number of printed characters.

2. Move along the format string one character at a time.
   - If the current character is not '%', output it directly using `write()` 
     and update the printed character count.

3. When a '%' character is detected, switch into *format parsing mode*:
   - Look at the next character to determine which format specifier is being used 
     (e.g., 'c', 's', 'd', 'x', etc.).

4. Using the identified specifier, retrieve the next argument from the variadic
   argument list with `va_arg`. This step converts the "..." arguments into 
   usable C types, such as `int`, `char *`, or `unsigned int`.

5. Pass the extracted value to the corresponding handler function:
   - Each handler is responsible for one specific conversion type.
   - This keeps format-specific logic isolated and readable.

6. Within each handler, call the appropriate utility functions:
   - These helpers perform the actual printing and data conversion.
   - For example:
       • `ft_putchar` prints a single character  
       • `ft_putstr` prints a string  
       • `ft_putnbr` prints an integer  
       • `ft_puthex` prints a number in hexadecimal  
     All output is ultimately performed using `write()`.

7. Each handler returns the number of characters it printed.
   Add this value to the running total.

8. Continue scanning the format string until the end is reached.

9. After processing all characters and specifiers, return the accumulated count,
   which represents the total number of characters written — mirroring the behavior
   of the standard `printf`.

## Handlers & Utility

For this `ft_printf` project, the implementation is divided into two functionals layer; handlers & utility
- Handlers manages format specific behaviour for each specifier
- Utility performs low-level operations such as character output. string handling and number to string conversion.

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

