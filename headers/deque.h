#ifndef DEQUEUE_H
#define DEQUEUE_H
#include "common.h"

typedef struct _deque{
    void** buff;
    
    element_type type;
    
    size_t template_size;
    int front;
    int rear;
    size_t capacity;
    
    void (*destructor) (void*);
} deque;

deque* new_deque_primitive(size_t template_size);
deque* new_deque_object(void (*destructor) (void* this));

// 함수 오버로딩, 인자가 sizeof(타입)인지 함수포인터인지 구분해서 전처리기가 함수를 스위치함
#define new_deque(dynamic_param) _Generic(dynamic_param, \
    size_t: new_deque_primitive, \
    int: new_deque_primitive, \
    unsigned int: new_deque_primitive, \
    default: new_deque_object\
) (dynamic_param)

void deque_destructor(deque* this);

void* deque_front(deque* this);
void* deque_back(deque* this);
bool deque_push_front(deque* this, void* element);
bool deque_push_back(deque* this, void* element);
bool deque_pop_front(deque* this);
bool deque_pop_back(deque* this);
size_t deque_size(deque* this);
bool deque_empty(deque* this);

#endif // DEQUEUE_H
