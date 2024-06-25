# ft_printf

## Overview
ft_printf is a project for Codam College that involves recreating the C standard library function `printf`. This custom version, `ft_printf`, aims to mimic the behavior of the original `printf` function, supporting a subset of its format specifiers and flags. The project is part of a broader curriculum designed to deepen understanding of variadic functions in C, string manipulation, and more.

## Features
- **Custom Implementation**: Recode the `printf()` function to understand its inner workings.
- **Format Specifiers**: Supports printing of characters, strings, pointers, and numbers in various bases (`c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%`).
- **Variadic Functions**: Utilizes variadic functions to accept an undefined number of arguments.
- **Libft Integration**: Leverages the custom libft library which is the recoded version of  the C standard library for foundational operations, enhancing understanding of library creation and usage.

## Requirements
- **Authorized Functions**: `malloc`, `free`, `write`, `va_start`, `va_arg`, `va_copy`, `va_end`.
- **External Libraries**: Only `libft` is authorized for this project.
- **Compilation**: The project includes a Makefile with the rules: `all`, `clean`, `fclean`, and `re`.

## Installation

Clone the repository to your local machine:

```bash
git clone https://github.com/yourusername/ft_printf.git
cd ft_printf
```

Compile the library:
```bash
make
```

## Usage
Include `ft_printf` in your C project by including its header:

`#include "ft_printf.h"`


Compile your project with the `ft_printf.a` library:
```bash
gcc your_files.c ft_printf.a -o your_program
```
Use `ft_printf` just like you would use the standard printf:

`ft_printf("Hello, %s!", "world");`

## Supported Conversions

`%c`: Prints a single character.

`%s`: Prints a string.

`%p`: Prints a pointer's address in hexadecimal.

`%d` and `%i`: Print a signed integer.

`%u`: Prints an unsigned decimal number.

`%x`: Prints a number in hexadecimal (lowercase).

`%X`: Prints a number in hexadecimal (uppercase).

`%%`: Prints a percent sign.