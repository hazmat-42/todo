//
// Created by hazmat on 5/15/26.
//
#include "todo.h"


// initialize empty list
List* init_list(void) {
    List* list = (List*)malloc(sizeof(List));
    if (list == NULL) return NULL;
    list->name = NULL;
    list->size = 0;
    list->capacity = 4; // default initial capacity
    list->items = (Item*)malloc(list->capacity * sizeof(Item));
    if (list->items == NULL) {
        free(list);
        return NULL;
    }
    // zero-initialize the items array
    memset(list->items, 0, list->capacity * sizeof(Item));
    return list;
}

// create an individual item
Item* create_item(char* name, u16 position, u8 priority, char* description, bool completed) {
    Item* new_item = (Item*)malloc(sizeof(Item));
    if (new_item == NULL) return NULL;
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
        // grow array (double capacity)
        i16 new_capacity = (list->capacity == 0) ? 4 : (list->capacity * 2);
        Item* tmp = (Item*)realloc(list->items, new_capacity * sizeof(Item));
        if (tmp == NULL) {
            return; // allocation failed, leave list unchanged
        }
        // zero the newly allocated portion
        memset(tmp + list->capacity, 0, (new_capacity - list->capacity) * sizeof(Item));
        list->items = tmp;
        list->capacity = new_capacity;
    }
    // place item at end; ensure its position matches its index
    current->position = (u16)list->size;
    list->items[list->size] = *current;
    list->size += 1;
}

// remove an item from the list by shifting subsequent items up one slot
void remove_item(Item *target, List *list) {
    if (list == NULL || target == NULL) {
        return;
    }
    // validate position
    i16 pos = target->position;
    if (pos < 0 || pos >= list->size) {
        return;
    }

    // If the target is not the last element, shift elements left to close the gap
    for (i16 i = pos; i < list->size - 1; ++i) {
        list->items[i] = list->items[i + 1];
        // update the moved item's stored position
        list->items[i].position = (u16)i;
    }

    // Clear the now-unused last slot
    memset(&list->items[list->size - 1], 0, sizeof(Item));

    // reduce the size
    list->size -= 1;
}
