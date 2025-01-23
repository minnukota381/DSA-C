#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *rear=0;
struct node *front=0;
void enqueue(int x){
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->next=0;
	if(rear==0 && front==0){
		rear=front=newnode;
	}else{
		rear->next=newnode;
		rear=newnode;
	}
}
void display(){
	struct node *temp;
	temp=front;
	if(rear==0 && front==0){
		printf("Underflow\n");
	}else{
		while(temp!=0){
			printf("%d-->",temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}
void dequeue(){
	struct node *temp;
	temp=front;
	if(rear==0 && front==0){
		printf("Underflow\n");
	}
	else{
		front=front->next;
		printf("Deleted element  %d \n",temp->data);
		free(temp);
	}
}
void peek(){
	if(rear==0 && front==0){
		printf("Underflow\n");
	}else{
		printf("The peek element is %d\n",front->data);
	}
}
int main(){
	int ch,k=1,d;
	while(k){
		printf("1. Enqueue\n 2. Dequeue\n 3. peek\n 4. Display\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:	printf("Enter data\n");
					scanf("%d",&d);
					enqueue(d);
					break;
			case 2:dequeue();
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