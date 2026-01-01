# push_swap

## Overview

**push_swap** is a 42 School algorithmic project whose goal is to sort a stack of integers using a very limited set of operations, while producing the **smallest possible number of moves**.

You must write two programs:

* **push_swap**: outputs a sequence of operations that sorts the given numbers.
* **checker** (bonus): verifies whether a sequence of operations correctly sorts the numbers.

This project focuses on:

* Algorithmic thinking
* Time and space complexity
* Data structures (linked lists / stacks)
* Optimization under constraints

---

## Rules

* You are given a list of integers as program arguments.
* Two stacks are used:

  * **Stack A**: initially contains all numbers
  * **Stack B**: initially empty
* The goal is to sort Stack A in ascending order.
* Only specific operations are allowed.

---

## Allowed Operations

### Swap

* `sa` : swap the first two elements of stack A
* `sb` : swap the first two elements of stack B
* `ss` : `sa` and `sb` at the same time

### Push

* `pa` : push the first element of B to A
* `pb` : push the first element of A to B

### Rotate

* `ra` : rotate stack A up (first element becomes last)
* `rb` : rotate stack B up
* `rr` : `ra` and `rb` at the same time

### Reverse Rotate

* `rra` : rotate stack A down (last element becomes first)
* `rrb` : rotate stack B down
* `rrr` : `rra` and `rrb` at the same time

---

## Program Usage

### push_swap

```bash
./push_swap 3 2 1
```

Output:

```text
sa
rra
```

### checker (bonus)

```bash
./push_swap 3 2 1 | ./checker 3 2 1
```

Output:

```text
OK
```

---

## Input Rules

* Arguments must be valid integers
* Integers must fit in a 32-bit signed range
* No duplicate numbers are allowed
* If input is invalid, the program must output:

```text
Error
```

---

## Data Structures

Stacks are usually implemented using **linked lists** for efficient push and rotate operations.

Example structure:

```c
typedef struct s_list
{
    int             content;
    int             cost_a;
    int             cost_b;
    int             total;
    struct s_stack *next;
}   t_list;
```

The `index` field is commonly used to normalize values and simplify comparisons.

---

## Algorithm Strategy

### Small Cases

* **2 numbers**: simple swap if needed
* **3 numbers**: hard-coded optimal solution
* **5 numbers**: push smallest elements to stack B, sort A, then push back

### Large Cases (100 / 500 numbers)

A common and efficient strategy is the **chunk-based algorithm**:

1. Copy stack A into an array
2. Sort the array
3. Assign each value an index
4. Divide the range into chunks
5. Push elements chunk by chunk to stack B
6. Push back to stack A in descending order

This reduces the total number of operations significantly.

---

## Complexity Considerations

* Simple algorithms (bubble/selection style): **O(n²)** → not acceptable
* Chunk-based solutions: approximately **O(n log n)**
* Fewer operations = higher score

---

## Makefile Targets

Typical targets:

```bash
make        # compile push_swap
make bonus  # compile checker
make clean  # remove object files
make fclean # remove binaries
make re     # recompile
```

---

## Error Management

Your program must:

* Exit immediately on error
* Free all allocated memory
* Never crash (no segfaults)

---

## Example

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | wc -l
```

Counts the number of operations produced.

---

## Project Requirements

* Language: **C**
* Functions like `printf` are forbidden (use `write`)
* No memory leaks
* Respect 42 Norm

---

## Sources

* 42 School official *push_swap* subject PDF
* 42 Network Intranet documentation
* *Introduction to Algorithms* – Cormen et al.
* GNU C Library documentation

---

## Author

**Abdellah Chtaibi**

42 Network Student
