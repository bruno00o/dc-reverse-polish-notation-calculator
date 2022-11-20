/**
 * @file test.c
 * @author Bruno SEILLIEBERT
 * @brief Test file for the project
 * @version 0.1
 * @date 2022-10-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/parser.h"
#include "../include/stack.h"
#include "../include/calc.h"

/**
 * @brief Test the check_line function
 * Tests:
 * - "1 2 4 + p" -> 1
 * - "1 +" -> 0
 *
 * @return int
 */
int test_check_line() {
    int res, res2;
    Stack s = init(10);
    char* line = malloc(10);
    line = strcpy(line, "1 2 4 + p");
    res = check_line(line, s);
    clear_stack(&s);
    line = strcpy(line, "1 +");
    res2 = check_line(line, s);
    free_stack(&s);
    free(line);
    if (res == 1 && res2 == 0) {
        return 0;
    }
    fprintf(stderr, "\ntest_check_line failed\n");
    return 1;
}

/**
 * @brief Test the manage_line function
 *
 * @return int
 */
int test_manage_line() {
    int res;
    Stack s = init(10);
    char* line = malloc(10);
    line = strcpy(line, "1 2 4 +");
    res = manage_line(line, &s);
    if (s.data[0] == 1 && s.data[1] == 6 && s.size == 2 && res == 1) {
        free(line);
        free_stack(&s);
        return 0;
    }
    fprintf(stderr, "\ntest_manage_line failed\n");
    free(line);
    free_stack(&s);
    return 1;
}

/**
 * @brief Test the init (stack) function
 *
 * @return int
 */
int test_init() {
    Stack s = init(10);
    if (s.size == 0 && s.total_size == 10) {
        free_stack(&s);
        return 0;
    }
    fprintf(stderr, "\ntest_init failed\n");
    free_stack(&s);
    return 1;
}

/**
 * @brief Test the push function
 *
 * @return int
 */
int test_push() {
    Stack s = init(10);
    push(&s, 1);
    if (s.data[0] == 1 && s.size == 1) {
        free_stack(&s);
        return 0;
    }
    fprintf(stderr, "\ntest_push failed\n");
    free_stack(&s);
    return 1;
}

/**
 * @brief Test the pop function
 *
 * @return int
 */
int test_pop() {
    Stack s = init(10);
    push(&s, 1);
    int res = pop(&s);
    if (res == 1 && s.size == 0) {
        free_stack(&s);
        return 0;
    }
    fprintf(stderr, "\ntest_pop failed\n");
    free_stack(&s);
    return 1;
}

/**
 * @brief Test the get_size function
 *
 * @return int
 */
int test_get_size() {
    Stack s = init(10);
    push(&s, 1);
    int res = get_size(s);
    if (res == 1) {
        free_stack(&s);
        return 0;
    }
    fprintf(stderr, "\ntest_get_size failed\n");
    free_stack(&s);
    return 1;
}

/**
 * @brief Test the get function
 *
 * @return int
 */
int test_get() {
    Stack s = init(10);
    push(&s, 1);
    int res = get(s, 0);
    if (res == 1) {
        free_stack(&s);
        return 0;
    }
    fprintf(stderr, "\ntest_get failed\n");
    free_stack(&s);
    return 1;
}

/**
 * @brief Test the reverse_stack function
 *
 * @return int
 */
int test_reverse_stack() {
    Stack s = init(10);
    push(&s, 1);
    push(&s, 2);
    reverse_stack(&s);
    if (s.data[0] == 2 && s.data[1] == 1) {
        free_stack(&s);
        return 0;
    }
    fprintf(stderr, "\ntest_reverse_stack failed\n");
    free_stack(&s);
    return 1;
}

/**
 * @brief Test the clear_stack function
 *
 * @return int
 */
int test_clear_stack() {
    Stack s = init(10);
    push(&s, 1);
    clear_stack(&s);
    if (s.size == 0) {
        free_stack(&s);
        return 0;
    }
    fprintf(stderr, "\ntest_clear_stack failed\n");
    free_stack(&s);
    return 1;
}

/**
 * @brief Test the copy_stack function
 *
 * @return int
 */
int test_copy_stack() {
    Stack s = init(10);
    push(&s, 1);
    Stack s2 = copy_stack(s);
    if (s2.data[0] == 1 && s2.size == 1) {
        free_stack(&s);
        free_stack(&s2);
        return 0;
    }
    fprintf(stderr, "\ntest_copy_stack failed\n");
    free_stack(&s);
    free_stack(&s2);
    return 1;
}

/**
 * @brief Test the add function
 *
 * @return int
 */
int test_add() {
    Stack s = init(10);
    push(&s, 1);
    push(&s, 2);
    add(&s);
    if (s.data[0] == 3 && s.size == 1) {
        free_stack(&s);
        return 0;
    }
    fprintf(stderr, "\ntest_add failed\n");
    free_stack(&s);
    return 1;
}

/**
 * @brief Test the sub function
 *
 * @return int
 */
int test_sub() {
    Stack s = init(10);
    push(&s, 1);
    push(&s, 2);
    sub(&s);
    if (s.data[0] == -1 && s.size == 1) {
        free_stack(&s);
        return 0;
    }
    fprintf(stderr, "\ntest_sub failed\n");
    free_stack(&s);
    return 1;
}

/**
 * @brief Test the mul function
 *
 * @return int
 */
int test_mul() {
    Stack s = init(10);
    push(&s, 1);
    push(&s, 2);
    mul(&s);
    if (s.data[0] == 2 && s.size == 1) {
        free_stack(&s);
        return 0;
    }
    fprintf(stderr, "\ntest_mul failed\n");
    free_stack(&s);
    return 1;
}

/**
 * @brief Test the divi function
 *
 * @return int
 */
int test_divi() {
    Stack s = init(10);
    push(&s, 4);
    push(&s, 2);
    divi(&s);
    if (s.data[0] == 2 && s.size == 1) {
        free_stack(&s);
        return 0;
    }
    fprintf(stderr, "\ntest_divi failed\n");
    free_stack(&s);
    return 1;
}

/**
 * @brief Test the mod function
 *
 * @return int
 */
int test_mod() {
    Stack s = init(10);
    push(&s, 4);
    push(&s, 2);
    mod(&s);
    if (s.data[0] == 0 && s.size == 1) {
        free_stack(&s);
        return 0;
    }
    fprintf(stderr, "\ntest_mod failed\n");
    free_stack(&s);
    return 1;
}

/**
 * @brief Test the fac function
 *
 * @return int
 */
int test_fac() {
    Stack s = init(10);
    push(&s, 5);
    fac(&s);
    if (s.data[0] == 120 && s.size == 1) {
        free_stack(&s);
        return 0;
    }
    fprintf(stderr, "\ntest_fac failed\n");
    free_stack(&s);
    return 1;
}

/**
 * @brief Test the powi function
 *
 * @return int
 */
int test_powi() {
    Stack s = init(10);
    push(&s, 2);
    push(&s, 3);
    powi(&s);
    if (s.data[0] == 8 && s.size == 1) {
        free_stack(&s);
        return 0;
    }
    fprintf(stderr, "\ntest_powi failed\n");
    free_stack(&s);
    return 1;
}

int test() {
    int res = 0;
    res += test_check_line();
    res += test_manage_line();
    res += test_init();
    res += test_push();
    res += test_pop();
    res += test_get_size();
    res += test_get();
    res += test_reverse_stack();
    res += test_clear_stack();
    res += test_copy_stack();
    res += test_add();
    res += test_sub();
    res += test_mul();
    res += test_divi();
    res += test_mod();
    res += test_fac();
    res += test_powi();
    return res;
}