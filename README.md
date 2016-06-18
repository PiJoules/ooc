# Object Oriented C


## Compiler
- gcc (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4
- C99 Standard


## Rules/Assumptions/Standards
- All class methods that return Any type must create a new object that must be destroyed.
- All classes must have `ClassProperties properties;` as the first member of the struct.
- All class methods must have `Any self` as the first argument in order to use the macros properly.

## Usage
```sh
$ make  # create release version
$ make debug  # create debug version
$ make test  # run tests; uses valgrind
```
