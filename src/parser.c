/**
 * @file parser.c
 * @author Bruno SEILLIEBERT
 * @brief Parser
 * @version 0.1
 * @date 2022-10-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <readline/readline.h>
#include <readline/history.h>

#include "../include/parser.h"
#include "../include/stack.h"
#include "../include/calc.h"

/**
 * @brief Return 1 if the token is valid, 0 otherwise
 *
 * @param token
 * @param s
 * @return int
 */
int check_token(char* token, Stack s) {
    assert(token != NULL);
    assert(&s != NULL);
    char* endptr;
    if (strlen(token) <= 0) {
        return 0;
    }
    if (strlen(token) == 1) {
        switch (token[0]) {
        case '+':
            return check_add(s);
        case '-':
            return check_sub(s);
        case '*':
            return check_mul(s);
        case '/':
            return check_divi(s);
        case '%':
            return check_mod(s);
        case '!':
            return check_fac(s);
        case '^':
            return check_powi(s);
        case 'q':
        case 'p':
        case 'c':
        case 'a':
        case 'r':
            return 1;
        }
    }
    strtol(token, &endptr, 10);
    if (*endptr != '\0') {
        return 0;
    }
    else {
        return 1;
    }
    return 0;
}

/**
 * @brief Manage the token (push or apply the operation)
 *
 * @param token
 * @param s
 * @param commands
 */
void manage_token(char* token, Stack* s, int commands) {
    assert(token != NULL);
    assert(s != NULL);
    int nb;
    char* endptr;
    if (strlen(token) == 1) {
        switch (token[0]) {
        case '+':
            add(s);
            break;
        case '-':
            sub(s);
            break;
        case '*':
            mul(s);
            break;
        case '/':
            divi(s);
            break;
        case '%':
            mod(s);
            break;
        case '!':
            fac(s);
            break;
        case '^':
            powi(s);
            break;
        case 'p':
            if (commands) print_first(*s);
            break;
        case 'c':
            if (commands) clear_stack(s);
            break;
        case 'a':
            if (commands) print_stack(*s);
            break;
        case 'r':
            if (commands) reverse_stack(s);
            break;
        }
    }
    nb = strtol(token, &endptr, 10);
    if (*endptr == '\0') {
        push(s, nb);
    }
}

/**
 * @brief Return 1 if the line is fully valid, 0 otherwise
 *
 * @param line
 * @param s
 * @return int
 */
int check_line(char* line, Stack s) {
    assert(line != NULL);
    assert(&s != NULL);
    char* token;
    Stack tmp = copy_stack(s);
    token = strtok(line, " ");
    while (token != NULL) {
        if (!check_token(token, tmp)) {
            fprintf(stderr, "Error: invalid token '%s'\nPlease retry the line.\n", token);
            free_stack(&tmp);
            return 0;
        }
        manage_token(token, &tmp, 0);
        token = strtok(NULL, " ");
    }
    free_stack(&tmp);
    return 1;
}

/**
 * @brief Manage the line (push or apply operations)
 *
 * @param line
 * @param s
 * @return int
 */
int manage_line(char* line, Stack* s) {
    assert(line != NULL);
    assert(s != NULL);
    char* token;
    token = strtok(line, " ");
    while (token != NULL) {
        if (token[0] == 'q') {
            return 0;
        }
        manage_token(token, s, 1);
        token = strtok(NULL, " ");
    }
    return 1;
}

/**
 * @brief Free lines
 *
 * @param line
 * @param line_copy
 */
void free_lines(char* line, char* line_copy) {
    if (line != NULL) {
        free(line);
        line = NULL;
    }
    if (line_copy != NULL) {
        free(line_copy);
        line_copy = NULL;
    }
}

/**
 * @brief Parser (init the stack and manage lines)
 *
 */
void parser() {
    char* line;
    char* line_copy;
    Stack s = init(10);
    do {
        line = readline("");
        if (line) {
            add_history(line);
            line_copy = strcpy(malloc(strlen(line) + 1), line);
            if (line_copy == NULL) {
                fprintf(stderr, "Error: malloc failed.\n");
                free_lines(line, line_copy);
                return;
            }
            if (check_line(line, s)) {
                if (!manage_line(line_copy, &s)) {
                    free_lines(line, line_copy);
                    clear_history();
                    break;
                }
            }
            free_lines(line, line_copy);
        }
    } while (line != NULL);
    free_stack(&s);
    clear_history();
}