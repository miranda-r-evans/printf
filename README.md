The first version of this project was co-written with Adekunle, but I rewote a new version from scratch at a later time. 
It is (mostly) compliant with [the betty style guide](https://github.com/holbertonschool/Betty/wiki).

_printf is a clone of printf, with some added features.

conversion specifiers and flags from printf:
* c
* s
* i
* d
* u
* x
* X
* o
* p
* #
* +
* [space]
* l
* h

custom conversion specifiers:
* b (binary)
* S (non-printing chars in a string are printed as ascii value)
* r (prints string in reverse)
* R (prints rot13 encrypted version of string)

Notes:
* _printf handles the case of no conversion specifier after a '%' slightly differently than printf does
* Some conversions, such as printing addresses with the 'p' flag and the use of "long", are OS specific. This was written for Linux.

printf.c:
* _printf

get_func.c:
* get_flags
* get_func

basic_funcs.c:
* pr_char
* pr_str
* pr_int
* pr_unsigned
* pr_format

hex_oct_func.c:
* pr_octal
* pr_hex_low
* pr_hex_cap
* pr_pointer

custom_funcs.c:
* pr_binary
* pr_ascii_of_non_printing
* pr_rev
* pr_rot13

standard_helpers.c:
* _strlen
* str_concat
* _memset
* _atoi

convert_helpers.c:
* hex_convert
* oct_convert
* pointer_convert

custom_helpers.c:
* mask_check
* rev_str
* rot13

itoa.c:
* i_itoa
* li_itoa
* u_itoa
* lu_itoa

test_suite:
* main

holberton.h:
* struct pr_flag
* struct pr_func