#ifndef __ARRAY_H__
#include "common.h"

enum array_default {
    INIT_BODY_LENGTH = 128,
};

struct _array {
    size_t length;
    size_t capacity;
    size_t type_size;

    byte* body;
};

typedef struct _array array;

bool array_new(array** arr, size_t type_size);
array* new_array(size_t type_size);
bool array_destroy(array* arr);

void* array_get(array* arr, size_t index);
bool array_set(array* arr, size_t index, void* element);
bool array_has(array* arr, void* element);
int array_find(array* arr, void* element);

#endif /* __ARRAY_H__ */
