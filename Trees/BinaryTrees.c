#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node* create(){
	struct node *newnode;
	int x;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter Data\n");
	scanf("%d",&x);
	if(x==-1){
		return 0;
	}else{
		newnode->data=x;
		printf("Enter left child of %d\n",x);
		newnode->left=create();
		printf("Enter right child of %d\n",x);
		newnode->right=create();
		return newnode;
	}
}
void preorder(struct node *root){
	if(root==0){
		return; 
	}else{
		printf("%d-->",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void inorder(struct node *root){
	if(root==0){
		return; 
	}else{
		inorder(root->left);
		printf("%d-->",root->data);
		inorder(root->right);
	}
}
void postorder(struct node *root){
	if(root==0){
		return; 
	}else{
		postorder(root->left);
		postorder(root->right);
		printf("%d-->",root->data);
	}
}
int main(){
	struct node *root;
	root=0;
	root=create();
	printf("Preorder \n");
	preorder(root);
	printf("\nInorder \n");
	inorder(root);
	printf("\nPostorder \n");
	postorder(root);
	return 0;
}