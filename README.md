# Prime Headers
## Header-only, type-safe, generic data structures and algorithms for C.

Prime Headers is (aiming to be) a headers-only, easy to use, strongly typed way to use generic data structures and algorithms in C Projects.

It works primarily by ~~ab~~using the C preprocessor to a scale hitherto undreamt of (I have later realised that this scale was indeed dreamt to).

### To Do
- [ ] Look into GitHub actions based testing
- [ ] Write primitive as well as pointer-to-structs examples
- [ ] Examples should try to break the framework as much as possible

### Data structures and algorithms implemented

> The project is a work in progress, with an emphasis on getting things working first. Apologies for the ugly/(currently wrong) code.

- [x] Vector
- [x] Stack using Vector
- [x] Stack using Linked List
- [x] Queue using Vector
- [x] Queue using Linked List
- [x] Deque (Double Ended Queue) using Vector (using existing vector interface)
- [x] Deque (Double Ended Queue) using Doubly Linked List
- [x] Singly Linked List
- [-] Set
- [-] Unordered Set
- [-] Map
- [-] Unordered Map (Hashmap)
- [ ] Circular Singly Linked List
- [x] Doubly Linked List
- [ ] Circular Doubly Linked List
- [ ] Generalized Linked List
- [ ] Heap
- [x] Binary Tree (Generation using 2 traversals left)
- [x] Binary Search Tree (Done recursively, TODO delete for all 3 cases)
- [ ] AVL Tree
- [ ] RB Tree

### Algorithms implemented

- [x] Linear Search in Vector
- [x] Linear Search in SLL
- [ ] Binary Search
- [x] Bubble Sort
- [x] Selection Sort
- [x] Insertion Sort
- [ ] Merge Sort
- [ ] Quick sort


### Pros

1. Relatively easy use of generic data structures and algorithms while being type-safe.
2. Is cool, I mean what is cooler than preprocessor hijinks.

### Cons

1. This method is optimised for ease of use (probably for beginners/learners because it primarily works with pointers to structs), however, defining multiple data structures in the same file may (read WILL) lead to **slower compilation times** due to large compilation units because of the coupling of interfaces (headers & prototypes) and the actual functionality (function definitions) itself.
2. **Poor support** (slow) for Intellisense and similar code intelligence tools.

> This project is a side-effect of trying to develop a command-line tool for easier use of generic data structures, which splits the interface and the function definitions, leading to better compilation times.

## Some helpful projects which helped me develop this

1. Thought this was an original idea, but this repository I found later implemented this already - https://github.com/mystborn/GenericDataStructures

2. I got the idea for the need of type-safe data structures by seeing this repository, otherwise it is perfect, especially the error handling is **chef's kiss** - https://github.com/MostafaTwfiq/C-DataStructures-And-Algorithms