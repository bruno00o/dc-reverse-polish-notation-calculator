/**
 * @file main.c
 * @author Bruno SEILLIEBERT
 * @brief TP3 - Programmation avancée en C
 * My own implementation of dc (reverse polish notation calculator)
 * @version 0.1
 * @date 2022-10-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/parser.h"
#include "include/test.h"

/**
 * @brief Main function
 *
 * @param argc
 * @param argv
 * @return int
 */
int main(int argc, char const* argv[]) {
    if (argc > 1 && strcmp(argv[1], "-t") == 0) {
        int res = test();
        if (res == 0) {
            printf("\nAll tests passed\n");
        }
        else {
            printf("\n%d tests failed\n", res);
        }
        return 0;
    }
    parser();
    return 0;
}
