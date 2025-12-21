# My Vector - Dynamic Array Implementation in C

A custom implementation of a dynamic vector (similar to C++ `std::vector`) in pure C, featuring automatic memory management and amortized O(1) insertion.

## Project Structure
```
my_vector/
├── my_vector.h      # Header file (interface/declarations)
├── my_vector.c      # Implementation file
├── main.c           # Test/demo program
└── README.md        # This file
```

## Files Description

### `my_vector.h`
- Defines `MyVector` struct with `data`, `size`, and `capacity` members
- Declares public API functions: `vector_init`, `vector_push_back`, `vector_get`, `vector_free`
- Includes header guards to prevent multiple inclusion
- Includes `<stddef.h>` for `size_t` type

### `my_vector.c`
- Implements all vector operations
- Uses lazy allocation (NULL initially) and doubling strategy (4 → 8 → 16 → ...)
- Includes robust error handling with `malloc`/`realloc` NULL checks
- Uses temporary pointer pattern for safe `realloc` operations

### `main.c`
- Comprehensive test suite demonstrating vector functionality
- Tests initialization, stress testing (50+ insertions), data validation, and cleanup
- Logs capacity expansion events to verify doubling strategy
- Validates data integrity after insertions

## Compilation & Execution

### Compile with strict flags (Google-style):
```bash
gcc -Wall -Wextra -Werror -pedantic -std=c11 -g -o vector_app main.c my_vector.c
```

### Run the program:
```bash
./vector_app
```

### Check for memory leaks:
```bash
valgrind --leak-check=full ./vector_app
```

Expected output: `definitely lost: 0 bytes in 0 blocks`

## API Reference

### `void vector_init(MyVector *v)`
Initializes vector to empty state (size=0, capacity=0, data=NULL)

### `void vector_push_back(MyVector *v, int value)`
Appends value to end of vector. Automatically expands capacity when full.
- First allocation: 4 elements
- Subsequent expansions: doubles current capacity

### `int vector_get(MyVector *v, size_t index)`
Returns element at given index. Returns -1 and prints error if index out of bounds.

### `void vector_free(MyVector *v)`
Releases allocated memory and resets vector to empty state. Prevents dangling pointers by setting `data = NULL`.

## Key Features

- **Dynamic Growth**: Automatically expands when capacity is reached
- **Amortized O(1) Insert**: Doubling strategy ensures efficient insertions
- **Memory Safety**: 
  - NULL checks on all allocations
  - Temporary pointer pattern for `realloc`
  - Dangling pointer prevention in `free`
- **Bounds Checking**: `vector_get` validates index range
- **Zero Memory Leaks**: Clean shutdown with `vector_free`

## Testing

The `main.c` test suite validates:
1. **Initialization**: Proper setup of empty vector
2. **Stress Test**: 50 sequential insertions with capacity monitoring
3. **Data Validation**: Verifies all inserted values are correctly stored
4. **Memory Cleanup**: Ensures clean deallocation with Valgrind

## Example Usage
```c
#include "my_vector.h"
#include <stdio.h>

int main() {
    MyVector v;
    vector_init(&v);
    
    // Add elements
    vector_push_back(&v, 10);
    vector_push_back(&v, 20);
    vector_push_back(&v, 30);
    
    // Access elements
    printf("First element: %d\n", vector_get(&v, 0));  // 10
    printf("Size: %zu\n", v.size);                     // 3
    
    // Cleanup
    vector_free(&v);
    return 0;
}
```

## Implementation Details

- **Initial Capacity**: 4 elements (configurable)
- **Growth Factor**: 2x (doubles on each expansion)
- **Element Type**: `int` (easily modifiable to generic with void*)
- **Error Handling**: `perror` + `exit(1)` on allocation failures

## Known Limitations

- Fixed element type (`int` only)
- No shrinking mechanism (capacity never decreases)
- Single-threaded (no thread safety)
- No iterator support

## Learning Objectives

This implementation demonstrates:
- Manual memory management with `malloc`/`realloc`/`free`
- Pointer arithmetic and struct member access
- Header/implementation file separation
- Amortized analysis and algorithm complexity
- Defensive programming with error checks