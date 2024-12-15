#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    
    return root;
}

struct node* search(struct node *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    
    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

void inorder(struct node *root) {
    if (root == NULL) {
        return;
    }
    
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct node *root = NULL;
    int value, numberOfNodes;
    
    printf("Enter the number of nodes to insert: ");
    scanf("%d", &numberOfNodes);
    
    for (int i = 0; i < numberOfNodes; i++) {
        printf("Enter value to insert: ");
        scanf("%d", &value);
        root = insert(root, value);
    }
    
    printf("In-order Traversal: ");
    inorder(root);
    printf("\n");
    
    printf("Enter value to search: ");
    scanf("%d", &value);
    
    struct node *result = search(root, value);
    if (result != NULL) {
        printf("Found %d in the BST\n", result->data);
    } else {
        printf("%d not found in the BST\n", value);
    }
    
    return 0;
}
