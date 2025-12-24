# Memory Hierarchy & Spatial Locality

## 1. 실험 내용
- 2차원 배열을 '가로 순회(Row-major)' vs '세로 순회(Column-major)' 할 때 속도 차이 비교.

## 2. 결과
- Good Case (가로): 약 2.42초
- Bad Case (세로): 약 2.58초
- 이론적으로 Bad Case가 캐시 미스(Cache Miss)가 훨씬 많이 발생함.

## 3. 트러블 슈팅 (Issue)
- 환경: MacBook Air M4 (ARM64) + Ubuntu VM
- 문제: `Valgrind(Cachegrind)`가 ARM64 VM 환경에서 Data Cache Miss 이벤트를 제대로 수집하지 못함 (Instruction 실행 횟수만 잡힘).
- 결론: VM 환경의 한계를 확인하고, 추후 리눅스 네이티브 머신이나 클라우드 환경에서 재도전하기로 함.

# Implementing my_memcpy

## Learning Objectives
Understanding core system programming concepts by directly manipulating memory at byte level

## Implementation

### Function Signature
```c
void *my_memcpy(void *dest, const void *src, size_t n);
```

## Core Concepts

### 1. What is void* pointer?

`void*` is a pointer without a specified type.

**Characteristics:**
- Can accept any pointer type (generic)
- Cannot perform pointer arithmetic
- Reason: Compiler does not know the size of "one step"

**Why cast to char*?**
- `char` is always 1 byte
- To traverse memory precisely in 1-byte increments
- Casting = "setting stride"
```c
void *ptr;      // No stride → cannot walk
char *cptr;     // 1-byte stride → can move 1 byte at a time
```

### 2. Pointer Arithmetic

Adding an integer to a pointer increases the address by "type size".
```c
int *iptr;      // int is 4 bytes
iptr + 1;       // address + 4

char *cptr;     // char is 1 byte
cptr + 1;       // address + 1
```

**Example:**
```c
int arr[3];     // Starting address: 0x1000
int *ptr = arr;

ptr + 0  →  0x1000
ptr + 1  →  0x1004  (4-byte increment)
ptr + 2  →  0x1008  (4-byte increment)
```

### 3. Why Return dest?

**Function Chaining**
```c
// Can pass copy result directly to another function
process_data(my_memcpy(buffer, data, size));

// Copy and print immediately
printf("%s", (char*)my_memcpy(dest, src, n));
```

**Matches Standard Library Pattern**
- `strcpy`, `strcat`, `memcpy` all return destination address
- Consistent API design

## Insights from Implementation

### Question 1: Why can we use array notation?
```c
char *ptr;
ptr[i]  ==  *(ptr + i)
```

A pointer holds the starting address of memory. Array notation in C is syntactic sugar for pointer arithmetic.

### Question 2: Why return dest instead of *dest?

- `dest`: address (void* type)
- `*dest`: value at that address (but cannot dereference void type)

Since return type is `void*`, we must return an address.

### Question 3: Difference between c_dest and dest

- `dest`: Original address keeper (void* type, no arithmetic)
- `c_dest`: Working pointer (char* type, arithmetic enabled)

They point to the same address but have different types.

## Test Results

### Case A: int array copy
```
Source: [1, 2, 3]
Result: [1, 2, 3] ✓
```

### Case B: String copy
```
Source: "Google"
Result: "Google" ✓
```

### Case C: Struct copy
```
Source: {id: 20241234, score: 100}
Result: {id: 20241234, score: 100} ✓
```

## Realization

"All data is merely a sequence of bytes in memory"

Types are abstractions for programmers. Memory knows no types. `my_memcpy` reveals this fundamental truth.