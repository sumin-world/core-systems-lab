# Day 2: Algorithm Foundation & Problem Solving Patterns

## 1. Baekjoon Step-by-Step Progress

### 00. Step by Step
- **1000 A+B**
  - Practiced C++ basic I/O structure (`cin`, `cout`)
  - Established PS template for `main()` function
  - Key takeaway: Fast I/O with `ios::sync_with_stdio(false)`

### 01. Array / String
- **10818 Min, Max**
  - Algorithm: Single-pass traversal O(N)
  - Space optimization: Process input on-the-fly → O(1) space
  - Implementation: Track `min` and `max` during input phase

### 02. Bitmask
- **12813 Binary Operations**
  - String-based bitwise operations (AND, OR, XOR, NOT)
  - Character-level comparison using index-based loop
  - Result accumulation using `+=` operator
  - Learned: Treat binary strings as char arrays for digit-by-digit logic

## 2. Algorithm Patterns Learned

- **Single-Pass Optimization**: Update min/max variables during input → no auxiliary storage needed
- **String Indexing**: Access individual bits using `str[i]` for bitwise simulation
- **C++ I/O Best Practices**: `cin`/`cout` with `ios::sync_with_stdio(false)` for competitive programming

## 3. Issues & Resolutions

- **Issue**: Initially stored all inputs in `vector<int>` for 10818, causing unnecessary O(N) space
  - **Resolution**: Rewrote logic to update min/max during input phase → achieved O(1) space

- **Issue**: Confusion about string concatenation vs. character appending in 12813
  - **Resolution**: Used `result += (char)` for character-by-character construction instead of string operations

- **Issue**: Forgot to handle edge cases (e.g., N=1 for min/max problem)
  - **Resolution**: Added explicit checks and tested with minimal inputs

## 4. Tools & Environment

- **Editor**: VS Code with C++ extension
- **Compiler**: `g++ -std=c++17 -Wall -Werror`
- **Testing**: Manual test case creation and Baekjoon submission validation

## 5. Next Steps

- Continue with BFS/DFS module (03_BFS_DFS)
- Study two-pointer and sliding window techniques
- Review time complexity analysis for graph algorithms