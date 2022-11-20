/**
 * @file parser.h
 * @author Bruno SEILLIEBERT
 * @brief Header file for the parser
 * @version 0.1
 * @date 2022-10-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef __PARSER__
#define __PARSER__

#include "stack.h"

/**
 * @brief Check if the line is fully valid
 *
 * @param line
 * @param s
 * @return int
 */
int check_line(char* line, Stack s);

/**
 * @brief Manage the line
 * Return 0 if the toke 'q' is found
 *
 * @param line
 * @param s
 * @return int
 */
int manage_line(char* line, Stack* s);

/**
 * @brief Parser (init the stack and manage lines)
 *
 */
void parser();

#endif