---
xmarp: true
theme: gaia
_class: lead
paginate: true
backgroundColor: #fff
backgroundImage: url('https://marp.app/assets/hero-background.svg')
---

![bg left fit](https://upload.wikimedia.org/wikipedia/commons/thumb/3/38/Max-Heap.svg/1000px-Max-Heap.svg.png)

# **Heaps**
## An improve to BST

https://talks.obedmr.com/

---

# Let's start with the Priority Queues

A priority queue is a data structure that allows at least the following two operations:
- `insert`, which does the obvious thing;
- `deleteMin`, which finds, returns, and removes the minimum element in the priority queue

![bg vertical](.)
![bg](.)
![bg](.)
![bg contain](./images/priority_queues.png)

---


# So, now, Heaps

- A **heap** is a type of data structure. One of the interesting things about heaps is that they allow you to find the largest (or smallest) element in the heap in $O(1)$ time.
- Remember **Priority Queues**?
  - A `max` (or `min`) `heap` is a complete (or almost complete) binary tree such that the data stored in each node is greater (or smaller) than the data stored in its children, if any

- What's the similarity you see between heaps and priority queues?

---


# Binary Heaps

The binary heaps have 2 properties:

- Structure property
- A Heap-Order property

_As with AVL trees (remember the invariants?), an operation on a heap can destroy one of the properties, so a heap operation must not terminate until all heap properties are in order. This turns out to be simple to do._ 

---


## Binary Heaps - Structure property

A **heap** is a binary tree that is completely filled, with the possible exception of the bottom level, which is filled from _left to right_. Such a tree is known as a **complete binary tree**.

A **complete binary tree** of height $h$ has between $2^h$ and $2^{h+1} − 1$ nodes. This implies that the height of a complete binary tree is logN, which is clearly $O(log~N)$.

**Important Observation**: Because a complete binary tree is so regular, it can be represented in an array and no links (or pointers) are necessary.

---


![bg contain](./images/heap_array.png)

---


## Binary Heaps - Heap-Order property

- Allows operations to be performed quickly
- The smallest element should be at the root
- If we consider that any subtree should also be a heap, then any node should be smaller than all of its descendants.

---

![bg contain](./images/complete_trees.png)

---


![bg contain](./images/not_complete_tree.png)

---


## Since a **heap** is a _Complete Binary Tree_ ...

In the array representation, the element at position `k` represents a node in the tree whose child nodes will be at positions $2k$ and $2k+1$ of the array

![bg vertical](.)
![bg contain](./images/heap_array_indexes.png)

---

## Binary Heaps: Array Implementation

Consider the following rules:

- $parent(i) = \lfloor i/2 \rfloor$
- $left(i) = 2i$
- $right(i) = 2i + 1$

![bg right contain](./images/array_implementation.png)

---


![bg contain brightness:1.5](./images/array_imp_exc.png)

---

## So, let's think about it

- Every **ordered list** is a **heap**
- Any **list** can be converted into a **heap** and from there, the corresponding applications can be obtained.
- Which of the following lists are a heap?

```
8, 3, 2, 1, 2, 1
1, 2, 3, 4, 5, 6, 7, 8
5, 8, 9, 7, 5, 4
3, 4, 3, 4, 4, 3, 5
```


---

![bg contain](./images/where_to_add.png)

---


## Basic Operations: `insert`

- To insert an element `X` into the heap, we create a `hole` in the next available location, since otherwise, the tree will not be complete.
- **If** `X` can be placed in the hole without violating heap order, then we do so and are done. 
- **Otherwise,**
  - We slide the element that is in the hole’s parent node into the hole, thus _bubbling_ the hole up toward the root. We continue this process until `X` can be placed in the hole.
- This general strategy is known as a **percolate up**; the new element is percolated up the heap until the correct location is found.

---


![bg contain](./images/insert_14.png)

---


## `insert(20)`

![bg right:70% contain](./images/insert_20_1.png)

---


## `insert(20)`

![bg right:70% contain](./images/insert_20_2.png)

---


## `insert(20)`

Verify with the parent (17)

![bg right:70% contain](./images/insert_20_3.png)

---


## `insert(20)`

Verify with the parent (28)

![bg right:70% contain](./images/insert_20_4.png)

---


## `insert(20)`

**DONE!**

![bg right:70% contain](./images/insert_20_5.png)

---


## `insert(15)`

![bg right:70% contain](./images/insert_15_1.png)

---


## `insert(15)`

![bg right:70% contain](./images/insert_15_2.png)

---


## `insert(15)`

Verify with the parent (19)

![bg right:70% contain](./images/insert_15_3.png)

---


## `insert(15)`

**DONE!**

![bg right:70% contain](./images/insert_15_4.png)

---


## Basic Operations `delete`

Let's consider the case of removing the `root`

- When the minimum is removed, a hole is created at the root.
- Since the heap now becomes one smaller, it follows that the last element X in the heap must move somewhere in the heap.
- If X can be placed in the hole, then we are done.
- This is unlikely, so we slide the smaller of the hole’s children into the hole, thus pushing the hole down one level.

---


- We repeat this step until X can be placed in the hole.
- Thus, our action is to place X in its correct spot along a path from the root containing minimum children
 This general strategy is known as a **percolate down**.

---


![bg contain](./images/delete_13_1.png)

---


![bg contain](./images/delete_13_2.png)

---


![bg contain](./images/delete_13_3.png)

---


# Let's Code

Consider the implementation of heaps from [Geeks for Geeks](https://www.geeksforgeeks.org/cpp/implement-heap-in-c/)

- In your own words, explain what's the function of the `heapify(int i)` function
- Implement the `find(int value)` function
- Implement the `delete(int value)` function

---


# Resources and Credits
This material is genereated thanks to some extracts from following resources:

- González, Luis Humberto. *Abstraccion de Datos*
- Allen Weiss, Mark. *Data Structures and Algorithm Analysis in C++*
- Google-generated code with `AI Overview`

---

# Thanks

- **Obed N Muñoz Reynoso**
  - obed.n.munoz@tec.com
  - @obedmr
