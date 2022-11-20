# TP3 - Programmation avancée en C

## My own implementation of dc (reverse polish notation calculator)

### How to use it

```bash
$ make
# Compile the program
$ ./calc
# Run the program
```

Then you can use it as a normal reverse polish notation calculator like `dc`.

You can use CTRL+D to exit the program.

### Operations

* Addition
* Substraction
* Multiplication
* Division
* Modulo
* Factorial
* Power

### Functions

* `a` : print the stack
* `c` : clear the stack
* `p` : print the top of the stack
* `r` : reverse the stack
* `q` : quit the program

**Note:** Any error on the input will make the line be ignored. An error message will be displayed.

### Examples

```bash
$ ./calc
> 1 2 3 4 5 6 7 8 9 10
> a
1 2 3 4 5 6 7 8 9 10
> +
> a
1 2 3 4 5 6 7 8 19
> -
> a
1 2 3 4 5 6 7 -11
> *
> a
1 2 3 4 5 6 -77
> c
> a
2 6
> p
6
> r
> a
6 2
> /
> a
3
> q
$
```

### Test module

```bash
$ make
# Compile the program
$ ./calc -t
# Run the test module
```
