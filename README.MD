DSA SUBMISSIONS 2026

1. Linked Lists


Single Linked List

• Description: A linear data structure where elements (nodes) are linked using pointers. Each node contains data and a pointer to the next node.
• Time Complexity:
	• Access / Search: \(O(n)\)
	• Insertion / Deletion (at head): \(O(1)\)
	• Insertion / Deletion (at tail/middle): \(O(n)\)
• Test Case:
	• Input: Insert 10, Insert 20, Insert 30, Delete 20
	• Output: 10 -> 30 -> NULL

Doubly Linked List

• Description: An extension of the singly linked list where each node contains data and two pointers: one pointing to the next node and one to the previous node.
• Time Complexity:
	• Access / Search: \(O(n)\)
	• Insertion / Deletion (at head/tail with pointer): \(O(1)\)
• Test Case:
	• Input: Insert 5 at head, Insert 15 at tail, Traverse Forward & Backward
	• Output: Forward: 5 <-> 15 -> NULL, Backward: 15 <-> 5 -> NULL

2. Stacks & Queues


Stacks (Array & Linked List Implementation)

• Description: A Last-In-First-Out (LIFO) data structure where insertions and deletions happen at the same end (top).
• Time Complexity:
	• Push / Pop / Peek: \(O(1)\)
• Test Case:
	• Input: Push 10, Push 20, Pop()
	• Output: Popped: 20, Top element remaining: 10

Queue with Array

• Description: A First-In-First-Out (FIFO) data structure where elements are inserted at the rear and removed from the front. Suffers from memory wastage after deletions.
• Time Complexity:
	• Enqueue / Dequeue: \(O(1)\)
• Test Case:
	• Input: Enqueue 1, Enqueue 2, Dequeue()
	• Output: Dequeued: 1, Front element remaining: 2

Circular Queue with Array

• Description: A FIFO structure optimized to reuse emptied memory slots by wrapping around the end of the array using modulo arithmetic.
• Time Complexity:
	• Enqueue / Dequeue: \(O(1)\)
• Test Case:
	• Input: Size=3. Enqueue A, Enqueue B, Enqueue C, Dequeue(), Enqueue D
	• Output: Successfully inserted D at index 0 without overflow.

Queue using Linked List

• Description: A dynamic FIFO structure that grows and shrinks dynamically using head (front) and tail (rear) pointers.
• Time Complexity:
	• Enqueue / Dequeue: \(O(1)\)
• Test Case:
	• Input: Enqueue 100, Enqueue 200, Dequeue()
	• Output: Dequeued: 100

Parenthesis Matching

• Description: An application of stack to check if an expression has balanced opening and closing brackets.
• Time Complexity: \(O(n)\)
• Test Case:
	• Input: {[()]}
	• Output: Balanced
	• Input: [(])
	• Output: Not Balanced

3. Sorting Algorithms


Algorithm	Best Case	Average Case	Worst Case	Space Complexity	Type
Merge Sort	\(O(n \log n)\)	\(O(n \log n)\)	\(O(n \log n)\)	\(O(n)\)	Comparison, Stable
Quick Sort	\(O(n \log n)\)	\(O(n \log n)\)	\(O(n^2)\)	\(O(\log n)\)	Comparison, Unstable
Heap Sort	\(O(n \log n)\)	\(O(n \log n)\)	\(O(n \log n)\)	\(O(1)\)	Comparison, Unstable
Radix Sort	\(O(d \cdot (n + k))\)	\(O(d \cdot (n + k))\)	\(O(d \cdot (n + k))\)	\(O(n + k)\)	Non-comparison
Bucket Sort	\(O(n + k)\)	\(O(n)\)	\(O(n^2)\)	\(O(n + k)\)	Non-comparison
Bin / Count Sort	\(O(n + k)\)	\(O(n + k)\)	\(O(n + k)\)	\(O(k)\)	Non-comparison


Sorting Test Cases (Applicable to all sorting algorithms)

• Test Case:
	• Input: [38, 27, 43, 3, 9, 82, 10]
	• Output: [3, 9, 10, 27, 38, 43, 82]

4. Advanced Topics & Trees


K-Smallest Element (Partitioning / QuickSelect)

• Description: Finds the \(k\)-th smallest element in an unsorted array using the QuickSort partitioning logic without sorting the entire array.
• Time Complexity: Average: \(O(n)\), Worst: \(O(n^2)\)
• Test Case:
	• Input: Array = [7, 10, 4, 3, 20, 15], \(k = 3\)
	• Output: 7 (3rd smallest element)

Tower of Hanoi

• Description: A classic mathematical puzzle solved using recursion, moving a stack of disks from a source rod to a destination rod using an auxiliary rod.
• Time Complexity: \(O(2^n)\)
• Test Case:
	• Input: \(n = 2\) disks (Source=A, Helper=B, Destination=C)
	• Output:text
Move disk 1 from A to B
Move disk 2 from A to C
Move disk 1 from B to C
Use code with caution.

Binary Trees

• Description: A hierarchical structure where each node has at most two children (left and right). Supports traversals: Inorder, Preorder, Postorder.
• Time Complexity: Traversals take \(O(n)\)
• Test Case:
	• Input: Tree with root 1, left child 2, right child 3
	• Output: Inorder Traversal: 2 -> 1 -> 3

Binary Search Tree (BST)

• Description: A binary tree where the left subtree contains values less than the root, and the right subtree contains values greater than the root.
• Time Complexity: Access / Search / Insertion: Average \(O(\log n)\), Worst \(O(n)\)
• Test Case:
	• Input: Insert 50, 30, 70, 20, 40. Search 40
	• Output: Element 40 Found

AVL Trees

• Description: A self-balancing Binary Search Tree where the difference between heights of left and right subtrees (Balance Factor) cannot exceed 1. Uses rotations (LL, RR, LR, RL) to balance.
• Time Complexity: Access / Search / Insertion / Deletion: Always \(O(\log n)\)
• Test Case:
	• Input: Insert 10, 20, 30 (Triggers an RR rotation)
	• Output: Root balances to 20, with left child 10 and right child 30.
