*This project has been created as part of the 42 curriculum by <tel-atou>.*

# Push Swap

## Description

This project is a clear simple but yet challenging project that defines the understanding of the Software engineer for Algorithme core concepts , It's called push-swap where the developer is asked to sort a set of numbers in a linked list stack in ascending order with instructions limitation (you could use only another stack to manage to sort them in certain limit of moves)
The allowed operations are:

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first 2 elements at the top of stack A |
| `sb` | Swap the first 2 elements at the top of stack B |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push the top element of B onto the top of A |
| `pb` | Push the top element of A onto the top of B |
| `ra` | Rotate A upward — first element becomes last |
| `rb` | Rotate B upward — first element becomes last |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate A — last element becomes first |
| `rrb` | Reverse rotate B — last element becomes first |
| `rrr` | `rra` and `rrb` simultaneously |

### Algorithm

This project uses a hybrid approach combining **chunking** and **push max**:

- **Chunking**: Elements from A are pushed to B in index range chunks, with small-indexed elements within each chunk rotated to the bottom of B to roughly pre-order them.
- **Push max**: Elements are pushed back from B to A by always bringing the current maximum to the top first, resulting in A being sorted in ascending order.
- Small inputs (2, 3, and 5 elements) are handled with dedicated optimized functions.



## Instructions

### Compilation
```bash
make
```

### Usage

Pass the list of integers as a single quoted string or as separate arguments:
```bash
./push_swap "4 3 2 1"
./push_swap 4 3 2 1
```

The program outputs the sequence of operations needed to sort the stack.

### Checking move count (optional)

You can pipe the output into `wc -l` to count the number of moves:
```bash
./push_swap "4 3 2 1" | wc -l
```

### Cleanup
```bash
make fclean   
make re       
```

## Ressources

To understand the core requirements of the project i have read this article on medium : https://medium.com/@ayogun/push-swap-c1f5d2d41e97

### AI Usage

AI (Claude by Anthropic) was used in the following parts of this project:

- **Testing**: Generating advanced test scripts to stress-test edge cases and evaluate move count performance across different input sizes.