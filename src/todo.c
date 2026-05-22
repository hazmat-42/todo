//
// Created by hazmat on 5/15/26.
//
#include "todo.h"
#include <string.h>


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
        return;
    }
    if (list->size >= list->capacity) {
        return;
    }
    list->items[list->size] = *current;
}

void remove_item(Item *target, List *list) {
    if (target == NULL) {
        return;
    }
    /* clear the stored Item at the target position instead of assigning NULL to a struct */
    size_t pos = target->position;
    if (list == NULL || pos >= list->capacity) return;
    memset(&list->items[pos], 0, sizeof(Item));
}
