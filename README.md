# push_swap (42 Project)
#### Stack-based sorting algorithm puzzle in C

This project had me investigating the world of sorting algorithms to find the most efficient way to sort random integers in a stack using only a secondary stack and a set of limited instructions. The less instructions used, the higher the score. Additionally, I also programmed a bonus checker program that executes the instruction the main push_swap generates and checks of the stack is sorted. I managed to score 125% on this project.

**Sorting Strategy:**

After trying various approaches such as quick-sort, radix-sort and even my own algorithm, I eventually realized these alone were not enough to lower move counts. After some deliberation I figured, why reinvent the wheel, and looked at what others had done. I found this quite well known algorithm by fellow (ex)42-Heilbronn student [Ali Ogun](https://github.com/ayogun). The algorithm is named "Mechanical Turk Sort" and it is essentially a _smart_ version of insertion-sort that is specifically designed to minimize operations. This [article](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) by Ali goes into detail, but in short; we insert everything in B based on target nodes of A nodes and rotate efficiently based on the median node of each stack.

**Allowed Operations:**

- SA - Swap the top two nodes of A
- SB - Swap the top two nodes of B
- SS - Both swap operations in one
- PA - Push the top node of B to the top of A
- PB - Push the top node of A to the top of B
- RA - Rotate all nodes in A down by one, moving the bottom to the top
- RB - Rotate all nodes in B down by one, moving the bottom to the top
- RR - Both rotation operations in one
- RRA - Rotate all nodes in A up by one, moving the top to the bottom
- RRB - Rotate all nodes in B up by one, moving the top to the bottom
- RRR - Both reverse rotation operations in one

At the end, B must be empty and all numbers must be back in A sorted in ascending order.

**Performance:**

My program is capable of sorting 500 random integers in approximately 5200 - 5600 operations. The threshold for the maximum score is < 5500 with 500 numbers, so I barely squeezed by (admittedly, a bit of luck was on my side).

**Additional Info:**

The checker makes use of my get_next_line implementation within my [libft](https://github.com/N03l-MG/libft) and the stack manipulation functions are altered versions of the Libft project bonus involving linked list functions (my stacks are single linked lists).
