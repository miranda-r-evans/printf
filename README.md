# Printf
The first version of this project was co-written with [Adekunle](https://github.com/flourishcodes), but I rewote a new version from scratch at a later time.
It is (mostly) compliant with [the betty style guide](https://github.com/holbertonschool/Betty/wiki).
_printf is an imitation of printf, with some added features.

## Usage
In your C file, use the 'holberton.h' header file.
```
#include "holberton.h"
```

## Conversion Specifiers and Flags from Printf

* c
* s
* i
* d
* u
* x
* X
* o
* p
* [#]
* [+]
* [space]
* l
* h

## Custom Conversion Specifiers

* b (binary)
```
_printf("%b", 98); \\1100010
```
* S (non-printing chars in a string are printed as ascii value)
```
_printf("%S", "Holberton\nSchool"); \\Holberton\x0ASchool
```
* r (prints string in reverse)
```
_printf("%r", "Hello"); \\olleH
```
* R (prints rot13 encrypted version of string)
 ```
_printf("%R", "Hello"); \\Uryyb
 ```

## Notes

* _printf handles the case of no conversion specifier after a '%' slightly differently than printf does
* Some conversions, such as printing addresses with the 'p' flag and the use of "long", are OS specific. This was written for Linux.
