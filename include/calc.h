/**
 * @file calc.h
 * @author Bruno SEILLIEBERT
 * @brief Header file for the calculator
 * @version 0.1
 * @date 2022-10-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __CALC__
#define __CALC__

#include "stack.h"

/**
 * @brief Add the last two values of the stack
 *
 * @param s
 */
void add(Stack* s);

/**
 * @brief Substract the last two values of the stack
 *
 * @param s
 */
void sub(Stack* s);

/**
 * @brief Multiply the last two values of the stack
 *
 * @param s
 */
void mul(Stack* s);

/**
 * @brief Divide the last two values of the stack
 *
 * @param s
 */
void divi(Stack* s);

/**
 * @brief Modulo the last two values of the stack
 *
 * @param s
 */
void mod(Stack* s);

/**
 * @brief Factorial of the last value of the stack
 *
 * @param s
 */
void fac(Stack* s);

/**
 * @brief Power of the last two values of the stack
 *
 * @param s
 */
void powi(Stack* s);

/**
 * @brief Check if the add operation is possible
 *
 * @param s
 * @return int
 */
int check_add(Stack s);

/**
 * @brief Check if the sub operation is possible
 *
 * @param s
 * @return int
 */
int check_sub(Stack s);

/**
 * @brief Check if the mul operation is possible
 *
 * @param s
 * @return int
 */
int check_mul(Stack s);

/**
 * @brief Check if the divi operation is possible
 *
 * @param s
 * @return int
 */
int check_divi(Stack s);

/**
 * @brief Check if the mod operation is possible
 *
 * @param s
 * @return int
 */
int check_mod(Stack s);

/**
 * @brief Check if the fac operation is possible
 *
 * @param s
 * @return int
 */
int check_fac(Stack s);

/**
 * @brief Check if the powi operation is possible
 *
 * @param s
 * @return int
 */
int check_powi(Stack s);

#endif