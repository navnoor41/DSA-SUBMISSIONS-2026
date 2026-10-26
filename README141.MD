# Data Structures Lab (CS-251)
A repository of Data Structures and Algorithms implementations in C++, covering linked lists, stacks, queues, sortingS, trees, and classic algorithmic problems.

**Name:** Navnoor Kaur Dhillon  
**Roll No.:** UEM253141  
**Section:** CSE Sec 2  
**Department:** CSE, UIET, Panjab University, Chandigarh  
**Batch:** 2026  
**Submitted to:** Prof. Mukesh Kumar Rai

## Table of Contents

1. [Single Linked List](#experiment-1-single-linked-list)
2. [Double Linked List](#experiment-2-double-linked-list)
3. [Stack using Array](#experiment-3-stack-using-array)
4. [Stack using Linked List](#experiment-4-stack-using-linked-list)
5. [Queue using Array](#experiment-5-queue-using-array)
6. [Circular Queue using Array](#experiment-6-circular-queue-using-array)
7. [Queue using Linked List](#experiment-7-queue-using-linked-list)
8. [Merge Sort](#experiment-8-merge-sort)
9. [Quick Sort](#experiment-9-quick-sort)
10. [Towers of Hanoi](#experiment-10-towers-of-hanoi)
11. [Radix Sort](#experiment-11-radix-sort)
12. [Heap Sort](#experiment-12-heap-sort)
13. [Bucket Sort](#experiment-13-bucket-sort)
14. [K Smallest Elements (Partitioning)](#experiment-14-k-smallest-elements-partitioning)
15. [Bin Sort](#experiment-15-bin-sort)
16. [Parenthesis Matching](#experiment-16-parenthesis-matching)
17. [Binary Trees](#experiment-17-binary-trees)
18. [Binary Search Tree (BST)](#experiment-18-binary-search-tree-bst)
19. [AVL Trees](#experiment-19-avl-trees)

---

## Experiment 1: Single Linked List

**Code:** [singlelinkedlist.cpp](./01_single_linked_list.cpp)

**Description:** A linear data structure in which every node stores data and a pointer to the next node. This program inserts at the head, tail, before a value and after a value, and displays the list.

**Test Cases:**

- **Test 1**
  - Input: Insert 10, 20, 30 at tail; insert 15 before 20; insert 25 after 20
  - Output: 10 -> 15 -> 20 -> 25 -> 30 -> NULL

**Time Complexity:**

- Access / Search: O(n)
- Insert / Delete at head: O(1)
- Insert / Delete at tail or middle: O(n)

**Space Complexity:** O(n) for n nodes; O(1) extra space per operation

---

## Experiment 2: Double Linked List

**Code:** [02_double_linked_list.cpp](./02_double_linked_list.cpp)

**Description:** An extension of the singly linked list where each node holds data, a next pointer and a previous pointer, so the list can be traversed in both directions. Supports insertion and deletion at the beginning, end, a position or a value.

**Test Cases:**

- **Test 1**
  - Input: Insert 10, 20 at end; 5 at beginning; 15 at position 3; delete front, end, then value 15
  - Output: 5 <-> 10 <-> 15 <-> 20 <-> NULL, then 10 <-> 15 <-> 20, then 10 <-> 15, then 10 <-> NULL

**Time Complexity:**

- Access / Search: O(n)
- Insert / Delete at head or tail (head and tail pointers kept): O(1)
- Delete a given value: O(n)

**Space Complexity:** O(n) for n nodes (extra prev pointer per node); O(1) extra per operation

---

## Experiment 3: Stack using Array

**Code:** [03_stack_using_array.cpp](./03_stack_using_array.cpp)

**Description:** A Last-In-First-Out (LIFO) structure where insertion and deletion happen at the same end (top). Implemented with a fixed-size array of 100 elements and an integer top index.

**Test Cases:**

- **Test 1**
  - Input: Push 10, 20, 30; peek; pop; peek
  - Output: Top element is: 30, Popped: 30, Top element after pop is: 20

**Time Complexity:**

- Push / Pop / Peek / isEmpty: O(1)

**Space Complexity:** O(n) for the array of size MAX_SIZE; O(1) extra per operation

---

## Experiment 4: Stack using Linked List

**Code:** [04_stack_using_linked_list.cpp](./04_stack_using_linked_list.cpp)

**Description:** A LIFO stack built from dynamically allocated nodes. The top pointer always refers to the most recently pushed node, so the stack grows and shrinks without a fixed size limit.

**Test Cases:**

- **Test 1**
  - Input: Push 100, 200, 300; peek; pop; peek; pop all remaining
  - Output: Top element is: 300, Popped: 300, Top element after pop is: 200, Popped: 200, Popped: 100

**Time Complexity:**

- Push / Pop / Peek / isEmpty: O(1)

**Space Complexity:** O(n) for n nodes; O(1) extra per operation

---

## Experiment 5: Queue using Array

**Code:** [05_queue_using_array.cpp](./05_queue_using_array.cpp)

**Description:** A First-In-First-Out (FIFO) structure where elements are inserted at the rear and removed from the front. With a linear array the slots freed at the front are not reused until the queue becomes empty (memory wastage).

**Test Cases:**

- **Test 1**
  - Input: Enqueue 10, 20, 30; display; dequeue; display
  - Output: 10 20 30, Dequeued: 10, 20 30

**Time Complexity:**

- Enqueue / Dequeue: O(1)
- Display: O(n)

**Space Complexity:** O(n) for the array of size MAX_SIZE; O(1) extra per operation

---

## Experiment 6: Circular Queue using Array

**Code:** [06_circular_queue_using_array.cpp](./06_circular_queue_using_array.cpp)

**Description:** A FIFO structure that reuses emptied array slots by wrapping the front and rear indices around the end of the array using the modulo operator, which removes the wastage of a linear array queue. The queue is empty when front = -1 and full when (rear + 1) % SIZE == front; enqueue moves rear to (rear + 1) % SIZE and dequeue moves front to (front + 1) % SIZE.

**Test Cases:**

- **Test 1**
  - Input: Size = 5. Enqueue 10, 20, 30, 40; display
  - Output: 10 20 30 40
- **Test 2**
  - Input: Dequeue twice; enqueue 50, 60; display
  - Output: Dequeued: 10, Dequeued: 20, 30 40 50 60 (50 and 60 wrap around to index 0 and 1)
- **Test 3**
  - Input: Enqueue 70; display; enqueue 80
  - Output: 30 40 50 60 70; Circular Queue Full! Cannot enqueue 80

**Time Complexity:**

- Enqueue / Dequeue: O(1)
- Display: O(n)

**Space Complexity:** O(n) for the array of size SIZE; O(1) extra per operation

---

## Experiment 7: Queue using Linked List

**Code:** [07_queue_using_linked_list.cpp](./07_queue_using_linked_list.cpp)

**Description:** A dynamic FIFO queue that grows and shrinks at run time using a front pointer (for removal) and a rear pointer (for insertion).

**Test Cases:**

- **Test 1**
  - Input: Enqueue 10, 20, 30; peek; dequeue; dequeue all remaining
  - Output: 10 -> 20 -> 30 -> NULL, Front element is: 10, Dequeued: 10, 20 -> 30 -> NULL

**Time Complexity:**

- Enqueue / Dequeue / Peek: O(1)
- Display: O(n)

**Space Complexity:** O(n) for n nodes; O(1) extra per operation

---

## Experiment 8: Merge Sort

**Code:** [08_merge_sort.cpp](./08_merge_sort.cpp)

**Description:** A divide-and-conquer, stable comparison sort. The array is split recursively into halves, each half is sorted, and the two sorted halves are merged using a temporary array.

**Test Cases:**

- **Test 1**
  - Input: [30, 12, 9, 55, 23, 77, 11, 90]
  - Output: [9, 11, 12, 23, 30, 55, 77, 90]

**Time Complexity:**

- Best: O(n log n)
- Average: O(n log n)
- Worst: O(n log n)

**Space Complexity:** O(n) auxiliary array for merging (plus O(log n) recursion stack)

---

## Experiment 9: Quick Sort

**Code:** [09_quick_sort.cpp](./09_quick_sort.cpp)

**Description:** A divide-and-conquer comparison sort. The first element is taken as pivot, the array is partitioned so smaller elements lie left of the pivot and larger ones right, and both parts are sorted recursively. Not stable.

**Test Cases:**

- **Test 1**
  - Input: [30, 12, 9, 55, 23, 77, 11, 90]
  - Output: [9, 11, 12, 23, 30, 55, 77, 90]

**Time Complexity:**

- Best: O(n log n)
- Average: O(n log n)
- Worst: O(n^2) (already sorted input with first-element pivot)

**Space Complexity:** O(log n) recursion stack on average; O(n) in the worst case

---

## Experiment 10: Towers of Hanoi

**Code:** [10_towers_of_hanoi.cpp](./10_towers_of_hanoi.cpp)

**Description:** A classic recursive puzzle: move n disks from the source rod to the destination rod using an auxiliary rod, never placing a larger disk on a smaller one. Solution: move n-1 disks aside, move the largest disk, then move the n-1 disks on top of it.

**Test Cases:**

- **Test 1**
  - Input: n = 3 disks (A = source, B = helper, C = destination)
  - Output: 7 moves: disk 1 A->C, disk 2 A->B, disk 1 C->B, disk 3 A->C, disk 1 B->A, disk 2 B->C, disk 1 A->C

**Time Complexity:**

- O(2^n)
- exactly 2^n - 1 moves

**Space Complexity:** O(n) recursion stack depth

---

## Experiment 11: Radix Sort

**Code:** [11_radix_sort.cpp](./11_radix_sort.cpp)

**Description:** A non-comparison sort that sorts numbers digit by digit, from the least significant digit to the most significant, using a stable counting sort for each digit.

**Test Cases:**

- **Test 1**
  - Input: [170, 45, 75, 90, 802, 24, 2, 66]
  - Output: [2, 24, 45, 66, 75, 90, 170, 802]

**Time Complexity:**

- Best / Average / Worst: O(d * (n + k)), where d = number of digits and k = base (10)

**Space Complexity:** O(n + k) for the output and count arrays

---

## Experiment 12: Heap Sort

**Code:** [12_heap_sort.cpp](./12_heap_sort.cpp)

**Description:** A comparison sort that first builds a max-heap from the array and then repeatedly swaps the root (largest element) with the last element of the heap and restores the heap property. In-place and not stable.

**Test Cases:**

- **Test 1**
  - Input: [38, 27, 43, 3, 9, 82, 10]
  - Output: [3, 9, 10, 27, 38, 43, 82]

**Time Complexity:**

- Best: O(n log n)
- Average: O(n log n)
- Worst: O(n log n)

**Space Complexity:** O(1) auxiliary space (in-place; O(log n) for recursive heapify)

---

## Experiment 13: Bucket Sort

**Code:** [13_bucket_sort.cpp](./13_bucket_sort.cpp)

**Description:** A non-comparison sort that distributes elements into buckets by range (value / 10 here), sorts every bucket individually, and then concatenates the buckets in order.

**Test Cases:**

- **Test 1**
  - Input: [42, 32, 33, 52, 37, 47, 51]
  - Output: [32, 33, 37, 42, 47, 51, 52]

**Time Complexity:**

- Best: O(n + k)
- Average: O(n + k)
- Worst: O(n^2) (all elements fall in one bucket)

**Space Complexity:** O(n + k) for the buckets

---

## Experiment 14: K Smallest Elements (Partitioning)

**Code:** [14_k_smallest_elements_partitioning.cpp](./14_k_smallest_elements_partitioning.cpp)

**Description:** Uses the QuickSort partition step (quick-select) to bring the k smallest elements to the front of the array without sorting the whole array. Only the side of the pivot that contains position k is processed further.

**Test Cases:**

- **Test 1**
  - Input: Array = [3, 2, 10, 5, 4, 7, 8, 9, 1, 6, 15, 11], k = 8
  - Output: 8 smallest elements: 1 2 3 4 5 6 7 8

**Time Complexity:**

- Average: O(n)
- Worst: O(n^2)

**Space Complexity:** O(1) auxiliary space (iterative, in-place)

---

## Experiment 15: Bin Sort

**Code:** [15_bin_sort.cpp](./15_bin_sort.cpp)

**Description:** A non-comparison sort in which every possible value has its own bin. Each element is dropped into its bin (count incremented), and the bins are then read back in increasing order. Works for integers in a known range.

**Test Cases:**

- **Test 1**
  - Input: [38, 27, 43, 3, 9, 82, 10], values in range 0 to 99
  - Output: [3, 9, 10, 27, 38, 43, 82]

**Time Complexity:**

- Best / Average / Worst: O(n + k), where k = range of values

**Space Complexity:** O(k) for the bins

---

## Experiment 16: Parenthesis Matching

**Code:** [16_parenthesis_matching.cpp](./16_parenthesis_matching.cpp)

**Description:** An application of the stack that checks whether an expression has balanced brackets. Opening brackets are pushed; every closing bracket must match the bracket on top of the stack, and the stack must be empty at the end.

**Test Cases:**

- **Test 1**
  - Input: {()}[] and {(})
  - Output: {()}[] is Balanced; {(}) is Not Balanced

**Time Complexity:**

- O(n) for an expression of length n

**Space Complexity:** O(n) for the stack in the worst case

---

## Experiment 17: Binary Trees

**Code:** [17_binary_trees.cpp](./17_binary_trees.cpp)

**Description:** A hierarchical structure in which every node has at most two children (left and right). The tree is built recursively from user input, and the Preorder, Inorder and Postorder traversals are displayed.

**Test Cases:**

- **Test 1**
  - Input: Root 1, left child 2, right child 3
  - Output: Preorder: 1 2 3, Inorder: 2 1 3, Postorder: 2 3 1

**Time Complexity:**

- Creation / each traversal: O(n)

**Space Complexity:** O(n) for n nodes; O(h) recursion stack, h = height of the tree

---

## Experiment 18: Binary Search Tree (BST)

**Code:** [18_binary_search_tree_bst.cpp](./18_binary_search_tree_bst.cpp)

**Description:** A binary tree in which, for every node, all values in the left subtree are smaller and all values in the right subtree are larger (duplicates are ignored). This program builds a BST with recursive insertion, searches for a key, and deletes nodes covering all three structural cases: a leaf node, a node with one child, and a node with two children (replaced by its inorder successor, the smallest value of the right subtree). The inorder traversal prints the values in sorted order after every operation.

**Test Cases:**

- **Test 1**
  - Input: Insert 50, 30, 20, 40, 70, 60, 80, 90; display inorder
  - Output: 20 30 40 50 60 70 80 90
- **Test 2**
  - Input: Search 40
  - Output: Element 40 found in the BST.
- **Test 3**
  - Input: Delete 20 (leaf node)
  - Output: 30 40 50 60 70 80 90
- **Test 4**
  - Input: Delete 80 (one child, 90)
  - Output: 30 40 50 60 70 90
- **Test 5**
  - Input: Delete 50 (two children)
  - Output: 30 40 60 70 90

**Time Complexity:**

- Search / Insert / Delete: Average O(log n), Worst O(n) (skewed tree)
- Inorder traversal: O(n)

**Space Complexity:** O(n) for n nodes; O(h) recursion stack, h = height of the tree

---

## Experiment 19: AVL Trees

**Code:** [19_avl_trees.cpp](./19_avl_trees.cpp)

**Description:** An AVL tree is a self-balancing binary search tree in which the balance factor (height of left subtree minus height of right subtree) of every node is -1, 0 or 1. This program computes node heights and balance factors, checks whether a tree is AVL (isAVL), and implements AVL deletion: normal BST deletion (leaf, one child, two children using the inorder successor) followed by rebalancing on the way back up using right rotation (LL case), left rotation (RR case), and the double rotations LR and RL.

**Test Cases:**

- **Test 1**
  - Input: Tree 30 (root), left child 20, right child 40, 10 as left child of 20
  - Output: Original tree (Inorder): 10 20 30 40; Initial status: Tree is AVL
- **Test 2**
  - Input: Delete 40 (imbalance at 30, LL case, right rotation)
  - Output: Inorder: 10 20 30; Tree remains balanced and is AVL

**Time Complexity:**

- Rotation: O(1)
- Deletion in a height-balanced AVL tree: O(log n)
- as written (heights recomputed at every node): O(n)
- isAVL check as written: O(n^2) worst case

**Space Complexity:** O(n) for the nodes; O(h) = O(log n) recursion stack
