// #include <stdio.h>
// #include <stdlib.h>

// struct Node {
//     int data;
//     struct Node* next;
// };

// struct Node* initializeStack() {
//     return NULL;
// }

// int isEmpty(struct Node* top) {
//     return top == NULL;
// }

// void push(struct Node** top, int value) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     if (newNode == NULL) {
//         printf("Memory allocation failed.\n");
//         return;
//     }
//     newNode->data = value;
//     newNode->next = *top;
//     *top = newNode;
//     printf("%d pushed onto the stack.\n", value);
// }

// int pop(struct Node** top) {
//     if (isEmpty(*top)) {
//         printf("Stack Underflow! Cannot pop.\n");
//         return -1;
//     }
//     struct Node* temp = *top;
//     int poppedValue = temp->data;
//     *top = temp->next;
//     free(temp);
//     return poppedValue;
// }

// int peek(struct Node* top) {
//     if (isEmpty(top)) {
//         printf("Stack is empty.\n");
//         return -1;
//     }
//     return top->data;
// }

// void display(struct Node* top) {
//     if (isEmpty(top)) {
//         printf("Stack is empty.\n");
//         return;
//     }
//     printf("Stack elements: ");
//     struct Node* temp = top;
//     while (temp != NULL) {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }
//     printf("\n");
// }

// int main() {
//     struct Node* stack = initializeStack();

//     push(&stack, 10);
//     push(&stack, 20);
//     push(&stack, 30);
//     push(&stack, 40);
//     push(&stack, 50);

//     display(stack);

//     printf("%d popped from the stack.\n", pop(&stack));

//     printf("Top element is %d.\n", peek(stack));

//     display(stack);

//     pop(&stack);
//     pop(&stack);
//     pop(&stack);
//     pop(&stack);

//     pop(&stack);

//     return 0;
// }

#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node *top=0;
void push(int x){
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x; 
	newnode->link=top;
	top=newnode;
}
void pop(){
	struct node *temp;
	temp=top;
	if(top==0){
		printf("Underflow\n");
	}else{
		printf("Deleted element is %d\n",top->data);
		top=top->link;
		free(temp);
	}
}
void display(){
	struct node *temp;
	temp=top;
	if(top==0){
		printf("List is empty\n");
	}else{
		while(temp!=0){
		printf("%d-->",temp->data);
		temp=temp->link;
		}
		printf("\n");
	}
}
void peek(){
	if(top==0){
		printf("Underflow\n");
	}else{
		printf("The top element in the stack is %d\n",top->data);
	}
}
int main(){
	int ch,k=1,d;
	while(k){
		printf("1. push\n 2. pop\n 3. peek\n 4. Display\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:	printf("Enter data\n");
					scanf("%d",&d);
					push(d);
					break;
			case 2:pop();
					break;
			case 3:peek();
					break;
			case 4:display();
					break;
			default:printf("Invaid\n");
					break;
		}
		printf("Press 1 for continue and 0 for exit\n");
		scanf("%d",&k);
	}
	return 0;
}
