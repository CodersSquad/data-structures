---
xmarp: true
theme: gaia
_class: lead
paginate: true
backgroundColor: #fff
backgroundImage: url('https://marp.app/assets/hero-background.svg')
---

![bg left fit](https://www.geeksforgeeks.org/wp-content/uploads/binary-tree-to-DLL.png)

# **Binary Trees**
## ...

https://talks.obedmr.com/


---

# What is a tree?

- It's a hierarchical data structure.
- The relationship between elements is one-to-many.
- One natural way to define a tree is recursively.
- A tree is a collection of nodes. 

![bg vertical](.)
![bg](.)
![bg fit](./images/generic_tree.png)


---

- A tree consists of a distinguished `node`, $r$, called the `root`, and zero or more nonempty (sub)trees $T1, T2, ... , Tk$, each of whose roots are connected by a directed `edge` from $r$.
- The `root` of each subtree is said to be a `child` of $r$, and $r$ is the `parent` of each subtree root. 

![bg vertical](.)
![bg fit](./images/a_tree.png)


---

- Nodes with no children are known as `leaves`; the leaves in the tree below are ${B, C, H, I, P, Q, K, L, M, N}$. Nodes with the same parent are `siblings`; thus, ${K, L, M}$ are all siblings.
- `Grandparent` and `grandchild` relations can be defined in a similar manner.

![bg vertical](.)
![bg fit](./images/a_tree.png)

---

- A `path` from node $n_1$ to $n_k$ is defined as a sequence of nodes $n_1, n_2, ... , n_k$ such that ni is the parent of $n_i+1$ for $1 ≤ i < k$.
- The `length` of this path is the number of edges on the path, namely, $k − 1$. There is a path of length zero from every node to itself.


![bg vertical](.)
![bg fit](./images/a_tree.png)

---

- For any node ni, the `depth` of $n_i$ is the length of the unique path from the root to $n_i$. Thus, the root is at depth $0$.
- The `height` of $n_i$ is the length of the longest path from $n_i$ to a `leaf`. Thus all leaves are at height $0$.

![bg vertical](.)
![bg fit](./images/a_tree.png)

---

## Implementation of a tree

```
struct TreeNode {
  Object element;
  TreeNode *firstChild;
  TreeNode *nextSibling;
};
```

![bg vertical](.)
![bg fit](./images/tree_implementation.png)


---

![bg vertical contain](./images/unix_dirs.png)
![bg contain](./images/list_dir_pseudo.png)

---

## Binary Trees

A binary tree is a tree in which no node can have more than **two children.**

![bg vertical contain](.)
![bg contain](./images/binary_tree.png)

---

## Binary Search Trees

- An important application of binary trees is their use in searching.

- The property that makes a binary tree into a binary search tree is that for every node, $X$, in the tree:
  - the values of all the items in its `left` subtree are `smaller` than the item in $X$,
  - and the values of all the items in its `right` subtree are `larger` than the item in $X$.


---

![bg contain](./images/bst.png)


---

## Binary Search Tree: `Node`

```
struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int item) {
        key = item;
        left = NULL;
        right = NULL;
    }
};
```

Source Code: [`binary_search_tree.cpp`](./src/binary_search_tree.cpp)

---

## Binary Search Tree: Insert

```
Node* insert(Node* node, int key) {
    if (node == NULL) 
        return new Node(key);    
    
    if (node->key == key) 
        return node;
    
    if (node->key < key) 
        node->right = insert(node->right, key);    
    else 
        node->left = insert(node->left, key);
    return node;
}
```

Play at: [Tree Visualizer](https://treeconverter.com/?input=21,13,33,10,18,25,40), Source Code:  [`binary_search_tree.cpp`](./src/binary_search_tree.cpp)

---


## Binary Search Tree: Insert - _let's play_

Let's try with the following list of elements

```
100, 164, 130, 189, 244, 42, 141, 231, 20, 153
```

At the end, verify at: [Tree Visualizer](https://treeconverter.com/?input=100,164,130,189,244,42,141,231,20,153)

---

## Binary Search Tree: Insert - _comments_

- The order of insertions will define the form of the tree
- The form of the tree will define the eficiency of searching process

**Think about it:**
- What would happen if we insert all nodes in order?

```
1,2,3,4,5,5,6,7,8,9
```

Check it out at: [Tree Visualizer](https://treeconverter.com/?input=1,2,3,4,5,6,7,8,9)

_So, the higher the tree, the less efficient that search will be_

---

## Binary Search Tree: Search

Do you remember the binary search algorithm?

_Yes, it's the same but with trees_
```
Node* search(Node* root, int val) {
    if (root == nullptr || root->key == val) {
        return root;
    }
    if (val < root->key) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}
```

---

## Binary Search Tree: Delete

There are three cases to consider when deleting a node:
- The target node is a `leaf`
- The target node has a single `child`
- The target node has 2 `children`

---


## Binary Search Tree: Delete - Let's code

There are 2 ways to arrange a tree after deletion of a node with 2 children.
- Replacing deleted node by its immeditate predecessor
- Replacing deleted node by its immediate successor  

In our [sample code](./src/binary_search_tree.cpp) we implemented the `findMin` function to help the `deleteNode`. The `findMin` will get the in-order minimum successor, and then use it to replace the deleted node.


---


How would you implement `findSuccessor` and `findPredecessor`?

![](./images/remove_successor_predecessor.png)

---

Test with this tree
Remove `8`, `3` and `10`

[Visualizer link](https://treeconverter.com/?input=8,3,1,6,4,7,10,14,13)

![bg contain](./images/sample_complete_tree.png)

---

# Traversals in Binary Trees

---

# Resources and Credits
This material is genereated thanks to some extracts from following resources:

- Weiss, Mark Allen. *Data Structures and Algorithm Analysis in C++*. 4th ed. Boston: Pearson, 2014.
- Humberto González, Luis. *Abstraccion de Datos*
- Erickson, Jeff. *Algorithms* ...
- Google-generated code with `AI Overview`

---

# Thanks

- **Obed N Muñoz Reynoso**
	- obed.n.munoz@tec.com
	- @obedmr
