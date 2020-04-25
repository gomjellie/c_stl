# c_stl

c++의 stl을 c에서 구현한 라이브러리

# deep_vector

원소를 deep_copy 해서 저장하는 vector. 주소를 저장하는것이 아닌 값을 저장해서 원본이 사라지거나 변경되어도 벡터안에서 변화가 없다.

동적으로 할당된 객체들은 메모리관리를 함께 해주는 shallow_vector를 사용해야함. 주소값을 저장하기때문에 외부에서 변경되면 내부 원소값이 변할 수 있다.

shallow_vector는 set할때 기존에 주소값이 있던곳에 overwrite하면 기존의 원소를 메모리에서 자동으로 해재해준다.

## deep_vector functions

 - [`new_deep_vector`](#new_deep_vector) vector 생성자. 초기에 capacity는 128을 갖는다.
 - [`destroy`](#deep_vector_destroy) 소멸자
 - [`get`](#deep_vector_get) index번째 원소를 새로 할당한 메모리에 딥카피해서 할당된 주소를 반환한다. idx번째 원소가 존재하지 않으면 NULL을 리턴한다.
 - [`at`](#deep_vector_at) index번째 원소의 주소를 반환한다. 메모리가 할당되지 않은 영역은 NULL을 참조하게 된다.
 - [`front`](#deep_vector_front) 첫번째 원소를 참조한다.
 - [`back`](#deep_vector_back) 마지막 원소를 참조한다.
 - [`set`](#deep_vector_set) index번째 원소를 element로 설정한다. index번째 원소는 인자로 넘긴 주소만 갖는게 아닌 주소에서부터 template_size만큼 딥카피한다.
 - [`push_back`](#deep_vector_push_back) 마지막 원소 뒤에 원소 element를 삽입한다.
 - [`deep_vector_pop_back`](#deep_vector_pop_back) 마지막 원소를 제거한다.
 - [`clear`](#deep_vector_clear) 모든 원소를 0으로 리셋한다. length는 0으로 줄었지만 capacity와 메모리는 그대로 유지한다.
 - [`empty`](#deep_vector_empty) 비어있으면 true, 원소가 하나라도 있으면 false
 - [`has`](#deep_vector_has) python에서 사용하는 if elem in list: 같은 표현을 가능하게 해줌 (시간복잡도: O(N))
 - [`index`](#deep_vector_index) python에서 사용하는 [1, 2, 3].index(3) 같은 표현을 가능하게 해줌

## deep_vector memeber variables

 - `length` (`size_t`) 
 - `capacity` (`size_t`)
 - `template_size` (`size_t`)

## new_deep_vector

Prototype: `deep_vector* new_deep_vector(size_t template_size);`

vector 생성자. 초기에 capacity는 128을 갖는다

Usage:

```c
deep_vector* v = new_deep_vector(sizeof(int)); // deep_vector<int> v 와 동일함.
```

## deep_vector_destroy
Prototype: `bool deep_vector_destroy(deep_vector* this);`

소멸자

Usage:
```c
deep_vector* v = new_deep_vector(sizeof(int)); // deep_vector<int> v;
deep_vector_destroy(v);
```

## deep_vector_get
Prototype: `void* deep_vector_get(deep_vector* this, size_t index);`

index번째 원소를 새로 할당한 메모리에 딥카피해서 할당된 주소를 반환한다. idx번째 원소가 존재하지 않으면 NULL을 리턴한다.

Usage:
```c
int *ret = deep_vector_get(v, 10); // int ret = v[10];

if (ret == NULL) return 0; // if index is out of boundary
printf("%d", *ret); // cout << ret
```

## deep_vector_at
Prototype: `void* deep_vector_at(deep_vector* this, size_t index);`

index번째 원소의 주소를 반환한다. 메모리가 할당되지 않은 영역은 NULL을 참조하게 된다.

Usage:
```c
int *ret = deep_vector_at(v, 10); // int ret = v[10];

if (ret == NULL) return 0; // if index is out of boundary
printf("%d", *ret); // cout << ret
```

## deep_vector_front
Prototype: `void* deep_vector_front(deep_vector* this);`

첫번째 원소를 참조한다.

## deep_vector_back
Prototype: `void* deep_vector_back(deep_vector* this);`

마지막 원소를 참조한다.

## deep_vector_set
Prototype: `bool deep_vector_set(deep_vector* this, size_t index, void* element);`

index번째 원소를 element로 설정한다. index번째 원소는 인자로 넘긴 주소만 갖는게 아닌 주소에서부터 template_size만큼 딥카피한다.

Usage:
```c
for (int i = 0; i < 10; i++) {
    deep_vector_set(v, i, &i); /* v[i]] = i; */
}

```

## deep_vector_push_back
Prototype: `bool deep_vector_push_back(deep_vector* this, void* element);`

마지막 원소 뒤에 원소 element를 삽입한다.

Usage:
```c
for (int i = 0; i < 10; i++) {
    deep_vector_push_back(v, &i);
}
```

## deep_vector_pop_back
Prototype: `void* deep_vector_pop_back(deep_vector* this);`

마지막 원소를 제거합니다.

Usage:
```c
while (!deep_vector_empty(v)) {
    deep_vector_pop_back(v);
}
```

## deep_vector_clear
Prototype: `bool deep_vector_clear(deep_vector* this);`

모든 원소를 0으로 리셋한다.
length는 0으로 줄었지만 capacity와 메모리는 그대로 유지한다.

```c
deep_vector_clear(v);
```

## deep_vector_empty
Prototype: `bool deep_vector_empty(deep_vector* this, void* element);`

비어있으면 true, 원소가 하나라도 있으면 false

## deep_vector_has
Prototype: `bool deep_vector_has(deep_vector* this, void* element);`

python에서 사용하는 if elem in list: 같은 표현을 가능하게 해줌
python과 마찬가지로 실제 동작은 리스트안의 모든 원소를 순회하며 비교한다.

```c
if (deep_vector_has(v, element)) { // if elem in v:

}
```

## deep_vector_index
Prototype: `int deep_vector_index(deep_vector* this, void* element);`

python에서 사용하는 [1, 2, 3].index(3) 같은 표현을 가능하게 해줌

```c
for (int i = 0; i < 3; i++) {
    deep_vector_push_back(v, &i);
}
int elem = 2;
int* idx = deep_vector_index(v, &elem); // [0, 1, 2] 중에서 2의 인덱스인 2를 리턴합니다.

```
