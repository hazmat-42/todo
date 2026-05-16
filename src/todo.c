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

// initialize empty list
List* init_list(void) {
    List* list = (List*)malloc(sizeof(List));
    return list;
}

// create an individual item
Item* create_item(char* name, u16 position, u8 priority, char* description, bool completed) {
    Item* new_item = (Item*)malloc(sizeof(Item));
    new_item->item = name;
    new_item->position = position;
    new_item->priority = priority;
    new_item->description = description;
    new_item->completed = completed;
    return new_item;
}

// add pending item onto list
void add_item(List* list, Item* current) {
    /*
     * 1. check both ends pointers 2. check size and position of array 3. place item at end 4. increase size of array
     */
    if (list == NULL || current == NULL) {
        fprintf(stderr, "Invalid list and/or list item. Exiting 2.\n");
        exit(2);
    }
}