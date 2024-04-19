a program in C that implements the bst_construct() function:

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* create_node(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int search(int arr[], int start, int end, int value) {
    int i;
    for (i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

Node* construct_tree(int inorder[], int postorder[], int start, int end, int* post_index) {
    if (start > end) {
        return NULL;
    }
    Node* node = create_node(postorder[*post_index]);
    (*post_index)--;
    if (start == end) {
        return node;
    }
    int index = search(inorder, start, end, node->data);
    node->right = construct_tree(inorder, postorder, index + 1, end, post_index);
    node->left = construct_tree(inorder, postorder, start, index - 1, post_index);
    return node;
}

Node* bst_construct(int inorder[], int postorder[], int size) {
    int post_index = size - 1;
    return construct_tree(inorder, postorder, 0, size - 1, &post_index);
}

void bfs_traversal(Node* root) {
    if (root == NULL) {
        return;
    }
    Node* queue[100];
    int front = 0, rear = 0;
    queue[rear] = root;
    rear++;
    while (front < rear) {
        Node* current = queue[front];
        front++;
        printf("%d ", current->data);
        if (current->left) {
            queue[rear] = current->left;
            rear++;
        }
        if (current->right) {
            queue[rear] = current->right;
            rear++;
        }
    }
}

int main() {
    int inorder[] = {5, 10, 15, 20, 25, 30, 45};
    int postorder[] = {5, 15, 10, 25, 45, 30, 20};
    int size = sizeof(inorder) / sizeof(inorder[0]);
    Node* root = bst_construct(inorder, postorder, size);
    bfs_traversal(root);
    return 0;
}
```
