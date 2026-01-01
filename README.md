# 🔄 Push_swap

<div align="center">

![42 School Badge](https://img.shields.io/badge/1337-Coding%20School-000000?style=for-the-badge&logo=42&logoColor=white)
![Language](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c)
![Grade](https://img.shields.io/badge/Grade-Pending-yellow?style=for-the-badge)

*A sorting algorithm project from 1337 (42 Network) coding school in Morocco*

</div>

---

## 📋 Table of Contents

- [About](#about)
- [The Push_swap Challenge](#the-push_swap-challenge)
- [Available Operations](#available-operations)
- [Algorithm Approach](#algorithm-approach)
- [Installation](#installation)
- [Usage](#usage)
- [Performance Requirements](#performance-requirements)
- [Testing](#testing)
- [Bonus Part](#bonus-part)
- [Resources](#resources)
- [Author](#author)

---

## 🎯 About

**Push_swap** is a sorting algorithm project from the 1337 coding school curriculum (part of the global 42 Network). The objective is to sort a stack of integers using a limited set of operations while optimizing for the minimum number of moves.

This project teaches:
- Algorithm optimization
- Stack manipulation
- Problem-solving with constraints
- Complexity analysis
- Edge case handling

### 🏫 About 1337 School

[1337](https://1337.ma/) is a coding school based in Morocco, part of the global 42 Network. It offers a peer-to-peer, project-based learning approach with no teachers, no courses, and no traditional lectures. Students learn by working on progressively challenging projects.

---

## 🎮 The Push_swap Challenge

You are given two stacks: **stack A** and **stack B**.

- **Stack A** contains a random set of unique integers (positive and/or negative)
- **Stack B** is initially empty
- **Goal**: Sort stack A in ascending order using the smallest number of operations

### Rules

1. Only the operations listed below are allowed
2. The fewer operations used, the better the score
3. The program must handle edge cases (duplicates, empty input, non-numeric input, etc.)

---

## ⚙️ Available Operations

| Operation | Description |
|-----------|-------------|
| `sa` | **Swap A** - Swap the first 2 elements at the top of stack A |
| `sb` | **Swap B** - Swap the first 2 elements at the top of stack B |
| `ss` | **Swap both** - Execute `sa` and `sb` simultaneously |
| `pa` | **Push A** - Take the first element from stack B and put it on top of stack A |
| `pb` | **Push B** - Take the first element from stack A and put it on top of stack B |
| `ra` | **Rotate A** - Shift all elements of stack A up by one (first becomes last) |
| `rb` | **Rotate B** - Shift all elements of stack B up by one |
| `rr` | **Rotate both** - Execute `ra` and `rb` simultaneously |
| `rra` | **Reverse Rotate A** - Shift all elements of stack A down by one (last becomes first) |
| `rrb` | **Reverse Rotate B** - Shift all elements of stack B down by one |
| `rrr` | **Reverse Rotate both** - Execute `rra` and `rrb` simultaneously |

---

## 🧠 Algorithm Approach

The project can be solved using various algorithms. Here are some popular approaches:

### 1. **Small Stack (≤ 5 elements)**
   - Use hardcoded optimal solutions
   - Brute force approach is acceptable for small inputs

### 2. **Medium to Large Stacks**

#### **Chunk/Range Method**
- Divide the numbers into chunks
- Push chunks to stack B
- Sort and push back to stack A

#### **Turk Algorithm**
- Calculate the cost of moving each element
- Choose the element with the minimum cost
- Optimize rotations using combined operations

#### **Quick Sort Approach**
- Use stack B as a pivot holder
- Partition elements efficiently

---

## 🔧 Installation

### Prerequisites
- GCC compiler
- Make
- Unix-like operating system (Linux, macOS)

### Clone and Compile

```bash
# Clone the repository
git clone https://github.com/abdellahchtai/push_swap.git

# Navigate to the project directory
cd push_swap

# Compile the project
make

# Compile with bonus (if applicable)
make bonus
```

---

## 🚀 Usage

### Basic Usage

```bash
# Run push_swap with a list of integers
./push_swap 3 2 5 1 4

# Output: sequence of operations
pb
pb
sa
pa
pa
```

### Using with Checker (Bonus)

```bash
# Generate operations and verify with checker
./push_swap 3 2 5 1 4 | ./checker 3 2 5 1 4

# Should output: OK (if sorted) or KO (if not sorted)
```

### Test with Random Numbers

```bash
# Generate random numbers and test
ARG=$(shuf -i 0-100 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l
```

---

## 📊 Performance Requirements

To get a perfect score, your algorithm should perform within these limits:

| Stack Size | Maximum Operations | Points |
|------------|-------------------|--------|
| 3 numbers  | 3 operations or less | ✓ |
| 5 numbers  | 12 operations or less | ✓ |
| 100 numbers | Less than 700: 5 points<br>Less than 900: 4 points<br>Less than 1100: 3 points<br>Less than 1300: 2 points<br>Less than 1500: 1 point | Variable |
| 500 numbers | Less than 5500: 5 points<br>Less than 7000: 4 points<br>Less than 8500: 3 points<br>Less than 10000: 2 points<br>Less than 11500: 1 point | Variable |

---

## 🧪 Testing

### Manual Testing

```bash
# Test with 3 numbers
./push_swap 2 1 3

# Test with 5 numbers
./push_swap 5 4 3 2 1

# Test with 100 random numbers
ARG=$(shuf -i 0-500 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l
```

### Edge Cases to Test

```bash
# Already sorted
./push_swap 1 2 3 4 5

# Reverse sorted
./push_swap 5 4 3 2 1

# Duplicates (should output Error)
./push_swap 1 2 2 3

# Non-numeric input (should output Error)
./push_swap 1 2 abc

# Empty input (should do nothing)
./push_swap

# Single number (should do nothing)
./push_swap 42
```

### Automated Testing Tools

```bash
# Push_swap visualizer (external tool)
git clone https://github.com/o-reo/push_swap_visualizer.git
cd push_swap_visualizer
mkdir build && cd build
cmake .. && make
./bin/visualizer

# Push_swap tester (external tool)
git clone https://github.com/LeoFu9487/push_swap_tester.git
cd push_swap_tester
bash push_swap_tester.sh [path_to_push_swap]
```

---

## 🎁 Bonus Part

The bonus part involves creating a **checker** program that:
- Reads a list of integers
- Reads operations from standard input
- Executes the operations
- Outputs `OK` if the stack is sorted, `KO` otherwise
- Outputs `Error` for invalid input

### Checker Usage

```bash
# Manual verification
./checker 3 2 1
pb
ra
pa
[Ctrl+D]
# Output: OK or KO
```

---

## 📚 Resources

### Algorithm Resources
- [Push_swap Tutorial](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [Sorting Algorithm Visualization](https://www.cs.usfca.edu/~galles/visualization/Algorithms.html)
- [42 Docs - Push_swap](https://harm-smits.github.io/42docs/projects/push_swap)

### Testing Tools
- [Push_swap Visualizer](https://github.com/o-reo/push_swap_visualizer)
- [Push_swap Tester](https://github.com/LeoFu9487/push_swap_tester)
- [Push_swap Checker](https://github.com/SimonCROS/push_swap_tester)

### 42/1337 Network
- [1337 School Website](https://1337.ma/)
- [42 Network](https://www.42.fr/)
- [42 Cursus Guide](https://42-cursus.gitbook.io/)

---

## 👨‍💻 Author

**Abdellah CHTAIBI**
- GitHub: [@abdellahchtai](https://github.com/abdellahchtai)
- Email: chtaibiabdellah048@gmail.com
- School: 1337 Coding School (42 Network) - Morocco

---

## 📝 License

This project is part of the 1337 school curriculum. Feel free to use it for learning purposes.

---

<div align="center">

**Made with ❤️ at 1337 School, Morocco**

*"The only way to learn a new programming language is by writing programs in it."* - Dennis Ritchie

</div>
