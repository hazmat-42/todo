//
// Created by hazmat on 5/15/26.
//
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>

typedef int8_t i8;
typedef uint8_t u8;
typedef int16_t i16;
typedef uint16_t u16;
typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;

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
    i16      size;
    i16      capacity;
} List;
