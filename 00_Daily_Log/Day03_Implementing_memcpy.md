# My Memory: Implementing memcpy

## Learning Objectives
Understanding core system programming concepts by directly manipulating memory at byte level

---

## Implementation

### Function Signature
```c
void *my_memcpy(void *dest, const void *src, size_t n);
```

---

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

---

## Implementation Logic
```c
void *my_memcpy(void *dest, const void *src, size_t n) {
    char *c_dest = (char *)dest;
    const char *c_src = (const char *)src;

    for (size_t i = 0; i < n; i++) {
        c_dest[i] = c_src[i];
    }
    return dest;
}
```

**Key Points:**
- Cast `void*` to `char*` to enable byte-by-byte operations
- `c_dest` and `c_src` are working pointers (char* type, arithmetic enabled)
- `dest` is preserved for return value (void* type, original address keeper)
- Iterate `n` times, copying one byte at a time

---

## Test Results

### Case A: int array copy
```c
int src[] = {1, 2, 3};
int dest[3];
my_memcpy(dest, src, 3 * sizeof(int));  // 12 bytes
```
```
Source: [1, 2, 3]
Result: [1, 2, 3] ✓
```

### Case B: String copy
```c
char s1[] = "Google";
char s2[10];
my_memcpy(s2, s1, strlen("Google") + 1);  // 7 bytes (including '\0')
```
```
Source: "Google"
Result: "Google" ✓
```

### Case C: Struct copy
```c
struct Student { int id; int score; };
struct Student a = {20241234, 100};
struct Student b;
my_memcpy(&b, &a, sizeof(struct Student));
```
```
Source: {id: 20241234, score: 100}
Result: {id: 20241234, score: 100} ✓
```

---

## Insights from Implementation

### Question 1: Why can we use array notation with pointers?
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

They point to the same address but have different types. The working pointer (`c_dest`) is discarded when function returns, but the actual memory it modified remains changed.

---

## Advanced Study: memcpy vs memmove

### The Overlap Problem

**Problem scenario:**
```c
char str[] = "123456";
my_memcpy(str + 1, str, 4);  // Copy "1234" one position right
```

**Expected result:** `"112346"`  
**Actual result:** `"111116"` ❌

**Why does it fail?**
```
Initial:  [1][2][3][4][5][6]
           ↑src
               ↑dest

i=0: Copy str[0]→str[1]: [1][1][3][4][5][6]  ✓
i=1: Copy str[1]→str[2]: [1][1][1][4][5][6]  ✗ (str[1] already changed!)
i=2: Copy str[2]→str[3]: [1][1][1][1][5][6]  ✗ (str[2] already changed!)
i=3: Copy str[3]→str[4]: [1][1][1][1][1][6]  ✗ (str[3] already changed!)
```

**Root cause:** Forward copying destroys source data before reading it when regions overlap.

### memcpy vs memmove

| Feature | memcpy | memmove |
|---------|--------|---------|
| **Speed** | Fast | Slightly slower |
| **Safety** | Undefined behavior on overlap | Safe with overlap |
| **Implementation** | Simple forward copy | Direction check + conditional copy |
| **Use case** | Non-overlapping regions | Potentially overlapping regions |

### How memmove Solves It

**Strategy: Choose copy direction based on overlap**
```c
void *memmove(void *dest, const void *src, size_t n) {
    char *d = (char *)dest;
    const char *s = (const char *)src;
    
    if (d < s) {
        // dest is before src → forward copy is safe
        for (size_t i = 0; i < n; i++) {
            d[i] = s[i];
        }
    } else if (d > s && d < s + n) {
        // dest overlaps with src → backward copy required
        for (size_t i = n; i > 0; i--) {
            d[i-1] = s[i-1];
        }
    }
    return dest;
}
```

**Overlap detection condition:**
```c
if (dest > src && dest < src + n) {
    // Overlapping region detected!
    // Must copy backwards
}
```

**Backward copy example:**
```
Initial:  [1][2][3][4][5][6]
           ↑src
               ↑dest

i=3: Copy str[3]→str[4]: [1][2][3][4][4][6]  ✓ (str[3] not yet modified)
i=2: Copy str[2]→str[3]: [1][2][3][3][4][6]  ✓ (str[2] not yet modified)
i=1: Copy str[1]→str[2]: [1][2][2][3][4][6]  ✓ (str[1] not yet modified)
i=0: Copy str[0]→str[1]: [1][1][2][3][4][6]  ✓ Success!
```

### Defensive Programming Considerations

**NULL pointer checks:**
```c
if (!dest || !src) return NULL;
```

**Trade-offs:**
- **Pro:** Prevents segmentation faults
- **Con:** Performance overhead on every call
- **Standard library choice:** Most implementations skip checks for performance
- **Our implementation:** Follows standard library behavior (no checks)

---

## Realization

**"All data is merely a sequence of bytes in memory"**

Types are abstractions for programmers. Memory knows no types. Whether it's an `int`, a `struct`, or a string - everything is just a contiguous sequence of bytes. `my_memcpy` reveals this fundamental truth by treating all data uniformly at the byte level.

**Key takeaway:** Understanding memory at byte level is essential for:
- System programming
- Performance optimization
- Debugging memory issues
- Implementing low-level utilities

---

## Notes

- This implementation behaves like standard `memcpy` (fast but unsafe for overlapping regions)
- For production code with potential overlap, use `memmove` instead
- The choice between safety and performance depends on use case and guarantees about input data