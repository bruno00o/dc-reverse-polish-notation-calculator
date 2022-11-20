/**
 * @file stack.h
 * @author Bruno SEILLIEBERT
 * @brief Header file for the stack
 * @version 0.1
 * @date 2022-10-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __STACK__
#define __STACK__

/**
 * @brief Stack structure
 *
 */
typedef struct stack {
    int size;
    int total_size;
    int* data;
} Stack;

/**
 * @brief Initialize a stack
 *
 * @param size
 * @return Stack
 */
Stack init(int size);

/**
 * @brief Push a value to the stack
 *
 * @param s
 * @param value
 */
void push(Stack* s, int value);

/**
 * @brief Pop a value from the stack
 *
 * @param s
 * @return int
 */
int pop(Stack* s);

/**
 * @brief Get the size of the stack
 *
 * @param s
 * @return int
 */
int get_size(Stack s);

/**
 * @brief Get the value at the index
 *
 * @param s
 * @return int
 */
int get(Stack s, int index);

/**
 * @brief Reverse the last two values of the stack
 *
 * @param s
 */
void reverse_stack(Stack* s);

/**
 * @brief Print the last value of the stack
 *
 * @param s
 */
void print_first(Stack s);

/**
 * @brief Print the stack
 *
 * @param s
 */
void print_stack(Stack s);

/**
 * @brief Free the stack
 *
 * @param s
 */
void clear_stack(Stack* s);

/**
 * @brief Free the stack
 *
 * @param s
 */
void free_stack(Stack* s);

/**
 * @brief Copy a stack
 *
 * @param s
 * @return Stack
 */
Stack copy_stack(Stack s);

#endif