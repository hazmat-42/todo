//
// Created by hazmat on 5/15/26.
//
#include "todo.h"

// individual items on the list
typedef struct item {
    char    *item;
    u16     position;
    u8      priority;
    char    *description;
    bool    completed;
} Item;

// Struct for actual list
typedef struct list {
    char    *name;
    Item    *items;
} List;