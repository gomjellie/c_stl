
# vector

## vector functions

 - [`new_vector`](#new_vector) vector 생성자. 초기에 capacity는 128을 갖는다.
 - [`vector_destructor`](#vector_destructor) 소멸자
 - [`get`](#vector_get) index번째 원소를 새로 할당한 메모리에 딥카피해서 할당된 주소를 반환한다. idx번째 원소가 존재하지 않으면 NULL을 리턴한다.
 - [`at`](#vector_at) index번째 원소의 주소를 반환한다. 메모리가 할당되지 않은 영역은 NULL을 참조하게 된다.
 - [`front`](#vector_front) 첫번째 원소를 참조한다.
 - [`back`](#vector_back) 마지막 원소를 참조한다.
 - [`set`](#vector_set) index번째 원소를 element로 설정한다. index번째 원소는 인자로 넘긴 주소만 갖는게 아닌 주소에서부터 template_size만큼 딥카피한다.
 - [`push_back`](#vector_push_back) 마지막 원소 뒤에 원소 element를 삽입한다.
 - [`vector_pop_back`](#vector_pop_back) 마지막 원소를 제거한다.
 - [`clear`](#vector_clear) 모든 원소를 0으로 리셋한다. length는 0으로 줄었지만 capacity와 메모리는 그대로 유지한다.
 - [`empty`](#vector_empty) 비어있으면 true, 원소가 하나라도 있으면 false
 - [`has`](#vector_has) python에서 사용하는 if elem in list: 같은 표현을 가능하게 해줌 (시간복잡도: O(N))
 - [`index`](#vector_index) python에서 사용하는 [1, 2, 3].index(3) 같은 표현을 가능하게 해줌

## vector memeber variables

 - `length` (`size_t`) 
 - `capacity` (`size_t`)
 - `template_size` (`size_t`)

## new_vector

Prototype: `vector* new_vector(size_t template_size);`

vector 생성자. 초기에 capacity는 128을 갖는다

Usage:

```c
vector* v = new_vector(sizeof(int)); // vector<int> v 와 동일함.
```

## vector_destructor
Prototype: `bool vector_destructor(vector* this);`

소멸자

Usage:
```c
vector* v = new_vector(sizeof(int)); // vector<int> v;
vector_destructor(v);
```

## vector_get
Prototype: `void* vector_get(vector* this, size_t index);`

index번째 원소를 새로 할당한 메모리에 딥카피해서 할당된 주소를 반환한다. idx번째 원소가 존재하지 않으면 NULL을 리턴한다.

Usage:
```c
int *ret = vector_get(v, 10); // int ret = v[10];

if (ret == NULL) return 0; // if index is out of boundary
printf("%d", *ret); // cout << ret
```

## vector_at
Prototype: `void* vector_at(vector* this, size_t index);`

index번째 원소의 주소를 반환한다. 메모리가 할당되지 않은 영역은 NULL을 참조하게 된다.

Usage:
```c
int *ret = vector_at(v, 10); // int ret = v[10];

if (ret == NULL) return 0; // if index is out of boundary
printf("%d", *ret); // cout << ret
```

## vector_front
Prototype: `void* vector_front(vector* this);`

첫번째 원소를 참조한다.

## vector_back
Prototype: `void* vector_back(vector* this);`

마지막 원소를 참조한다.

## vector_set
Prototype: `bool vector_set(vector* this, size_t index, void* element);`

index번째 원소를 element로 설정한다. index번째 원소는 인자로 넘긴 주소만 갖는게 아닌 주소에서부터 template_size만큼 딥카피한다.

Usage:
```c
for (int i = 0; i < 10; i++) {
    vector_set(v, i, &i); /* v[i]] = i; */
}

```

## vector_push_back
Prototype: `bool vector_push_back(vector* this, void* element);`

마지막 원소 뒤에 원소 element를 삽입한다.

Usage:
```c
for (int i = 0; i < 10; i++) {
    vector_push_back(v, &i);
}
```

## vector_pop_back
Prototype: `void* vector_pop_back(vector* this);`

마지막 원소를 제거합니다.

Usage:
```c
while (!vector_empty(v)) {
    vector_pop_back(v);
}
```

## vector_clear
Prototype: `bool vector_clear(vector* this);`

모든 원소를 0으로 리셋한다.
length는 0으로 줄었지만 capacity와 메모리는 그대로 유지한다.

```c
vector_clear(v);
```

## vector_empty
Prototype: `bool vector_empty(vector* this, void* element);`

비어있으면 true, 원소가 하나라도 있으면 false

## vector_has
Prototype: `bool vector_has(vector* this, void* element);`

python에서 사용하는 if elem in list: 같은 표현을 가능하게 해줌
python과 마찬가지로 실제 동작은 리스트안의 모든 원소를 순회하며 비교한다.

```c
if (vector_has(v, element)) { // if elem in v:

}
```

## vector_index
Prototype: `int vector_index(vector* this, void* element);`

python에서 사용하는 [1, 2, 3].index(3) 같은 표현을 가능하게 해줌

```c
for (int i = 0; i < 3; i++) {
    vector_push_back(v, &i);
}
int elem = 2;
int* idx = vector_index(v, &elem); // [0, 1, 2] 중에서 2의 인덱스인 2를 리턴합니다.

```
