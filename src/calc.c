/**
 * @file calc.c
 * @author Bruno SEILLIEBERT
 * @brief Calculator functions
 * @version 0.1
 * @date 2022-10-22
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../include/calc.h"
#include "../include/stack.h"

void add(Stack* s) {
    assert(s != NULL);
    int a = pop(s);
    int b = pop(s);
    push(s, a + b);
}

void sub(Stack* s) {
    assert(s != NULL);
    int a = pop(s);
    int b = pop(s);
    push(s, b - a);
}

void mul(Stack* s) {
    assert(s != NULL);
    int a = pop(s);
    int b = pop(s);
    push(s, a * b);
}

void divi(Stack* s) {
    assert(s != NULL);
    int a = pop(s);
    int b = pop(s);
    push(s, b / a);
}

void mod(Stack* s) {
    assert(s != NULL);
    int a = pop(s);
    int b = pop(s);
    push(s, b % a);
}

/**
 * @brief Return the factorial of a number
 *
 * @param n
 * @return int
 */
int facto(int n) {
    if (n == 0) {
        return 1;
    }
    return n * facto(n - 1);
}

void fac(Stack* s) {
    assert(s != NULL);
    int a = pop(s);
    push(s, facto(a));
}

/**
 * @brief Return the power of two numbers
 *
 * @param a
 * @param b
 * @return int
 */
int pow_nbs(int a, int b) {
    if (b == 0) {
        return 1;
    }
    return a * pow_nbs(a, b - 1);
}

void powi(Stack* s) {
    assert(s != NULL);
    int a = pop(s);
    int b = pop(s);
    push(s, pow_nbs(b, a));
}

int check_add(Stack s) {
    if (s.size < 2) {
        fprintf(stderr, "Not enough elements on the stack to perform the operation.\n");
        return 0;
    }
    int a = get(s, get_size(s) - 1);
    int b = get(s, get_size(s) - 2);
    if (a > 0 && b > 0 && a + b < 0) {
        fprintf(stderr, "Overflow error.\n");
        return 0;
    }
    if (a < 0 && b < 0 && a + b > 0) {
        fprintf(stderr, "Overflow error.\n");
        return 0;
    }
    return 1;
}

int check_sub(Stack s) {
    if (s.size < 2) {
        fprintf(stderr, "Not enough elements on the stack to perform the operation.\n");
        return 0;
    }
    int a = get(s, get_size(s) - 1);
    int b = get(s, get_size(s) - 2);
    if (a < 0 && b > 0 && a - b > 0) {
        fprintf(stderr, "Overflow error.\n");
        return 0;
    }
    if (a > 0 && b < 0 && a - b < 0) {
        fprintf(stderr, "Overflow error.\n");
        return 0;
    }
    return 1;
}

int check_mul(Stack s) {
    if (s.size < 2) {
        fprintf(stderr, "Not enough elements on the stack to perform the operation.\n");
        return 0;
    }
    int a = get(s, get_size(s) - 1);
    int b = get(s, get_size(s) - 2);
    if (a > 0 && b > 0 && a * b < 0) {
        fprintf(stderr, "Overflow error.\n");
        return 0;
    }
    if (a < 0 && b < 0 && a * b > 0) {
        fprintf(stderr, "Overflow error.\n");
        return 0;
    }
    if (a < 0 && b > 0 && a * b > 0) {
        fprintf(stderr, "Overflow error.\n");
        return 0;
    }
    if (a > 0 && b < 0 && a * b > 0) {
        fprintf(stderr, "Overflow error.\n");
        return 0;
    }
    return 1;
}

int check_divi(Stack s) {
    if (s.size < 2) {
        fprintf(stderr, "Not enough elements on the stack to perform the operation.\n");
        return 0;
    }
    int a = get(s, get_size(s) - 1);
    int b = get(s, get_size(s) - 2);
    if (a == 0 || b == 0) {
        fprintf(stderr, "Division by 0.\n");
        return 0;
    }
    if (a > 0 && b > 0 && a / b < 0) {
        fprintf(stderr, "Overflow error.\n");
        return 0;
    }
    if (a < 0 && b < 0 && a / b > 0) {
        fprintf(stderr, "Overflow error.\n");
        return 0;
    }
    if (a < 0 && b > 0 && a / b > 0) {
        fprintf(stderr, "Overflow error.\n");
        return 0;
    }
    if (a > 0 && b < 0 && a / b > 0) {
        fprintf(stderr, "Overflow error.\n");
        return 0;
    }
    return 1;
}

int check_mod(Stack s) {
    if (s.size < 2) {
        fprintf(stderr, "Not enough elements on the stack to perform the operation.\n");
        return 0;
    }
    int a = get(s, get_size(s) - 1);
    int b = get(s, get_size(s) - 2);
    if (a == 0 || b == 0) {
        fprintf(stderr, "Division by 0.\n");
        return 0;
    }
    if (a > 0 && b > 0 && a % b < 0) {
        fprintf(stderr, "Overflow error.\n");
        return 0;
    }
    if (a < 0 && b < 0 && a % b > 0) {
        fprintf(stderr, "Overflow error.\n");
        return 0;
    }
    if (a < 0 && b > 0 && a % b > 0) {
        fprintf(stderr, "Overflow error.\n");
        return 0;
    }
    if (a > 0 && b < 0 && a % b > 0) {
        fprintf(stderr, "Overflow error.\n");
        return 0;
    }
    return 1;
}

int check_fac(Stack s) {
    if (s.size < 1) {
        fprintf(stderr, "Not enough elements on the stack to perform the operation.\n");
        return 0;
    }
    int a = get(s, get_size(s) - 1);
    if (a < 0) {
        fprintf(stderr, "Factorial of a negative number is not defined.\n");
        return 0;
    }
    if (a > 12) {
        fprintf(stderr, "Overflow error.\n");
        return 0;
    }
    return 1;
}

int check_powi(Stack s) {
    if (s.size < 2) {
        fprintf(stderr, "Not enough elements on the stack to perform the operation.\n");
        return 0;
    }
    int a = get(s, get_size(s) - 1);
    int b = get(s, get_size(s) - 2);
    if (a < 0) {
        fprintf(stderr, "Negative power is not defined.\n");
        return 0;
    }
    if (a > 12) {
        fprintf(stderr, "Overflow error.\n");
        return 0;
    }
    if (b > 0 && a > 0 && pow_nbs(b, a) < 0) {
        fprintf(stderr, "Overflow error.\n");
        return 0;
    }
    if (b < 0 && a > 0 && pow_nbs(b, a) > 0) {
        fprintf(stderr, "Overflow error.\n");
        return 0;
    }
    return 1;
}