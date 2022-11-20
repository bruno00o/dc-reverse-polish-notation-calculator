/**
 * @file stack.c
 * @author Bruno SEILLIEBERT
 * @brief Stack functions
 * @version 0.1
 * @date 2022-10-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../include/stack.h"

Stack init(int size) {
    assert(size > 0);
    Stack s;
    s.size = 0;
    s.total_size = size;
    s.data = malloc(size * sizeof(int));
    if (s.data == NULL) {
        printf("Error: malloc failed\n");
        exit(1);
    }
    return s;
}

void push(Stack* s, int value) {
    assert(s != NULL);
    if (s->size == s->total_size) {
        s->total_size *= 2;
        s->data = realloc(s->data, s->total_size * sizeof(int));
        if (s->data == NULL) {
            printf("Error: realloc failed\n");
            exit(1);
        }
    }
    s->data[s->size] = value;
    s->size++;
}

int pop(Stack* s) {
    assert(s != NULL);
    if (s->size == 0) {
        return 0;
    }
    s->size--;
    return s->data[s->size];
}

int get_size(Stack s) {
    return s.size;
}

int get(Stack s, int index) {
    assert(index >= 0 && index < s.size);
    return s.data[index];
}

void reverse_stack(Stack* s) {
    assert(s != NULL);
    int tmp = s->data[s->size - 1];
    s->data[s->size - 1] = s->data[s->size - 2];
    s->data[s->size - 2] = tmp;
}

void print_first(Stack s) {
    if (s.size == 0) {
        printf("Stack is empty.\n");
        return;
    }
    printf("%d\n", s.data[s.size - 1]);
}

void print_stack(Stack s) {
    int i;
    if (s.size == 0) {
        printf("Stack is empty");
    }
    for (i = 0; i < s.size; i++) {
        printf("%d ", s.data[i]);
    }
    printf("\n");
}

void clear_stack(Stack* s) {
    assert(s != NULL);
    s->size = 0;
}

void free_stack(Stack* s) {
    assert(s != NULL);
    free(s->data);
}

Stack copy_stack(Stack s) {
    Stack new_stack = init(s.total_size);
    int i;
    for (i = 0; i < s.size; i++) {
        push(&new_stack, s.data[i]);
    }
    return new_stack;
}