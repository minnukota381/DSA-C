#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head,*newnode,*tail;
void insert() {
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data\n");
    scanf("%d", &newnode->data);
    newnode->next = 0;

    if (head == 0) {
        head = tail = newnode;
        tail->next = head; 
    } else {
        tail->next = newnode; 
        tail = newnode;       
        tail->next = head;    
    }
}
void display(){
	struct node *temp;
	temp=head;
	while(temp->next!=head){
		printf("%d-->",temp->data);
		temp=temp->next;
	}
	printf("%d-->\n",temp->data);
	printf("%d\n",tail->next->data);
}
void beginInsert() {
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter Data\n");
    scanf("%d", &newnode->data);

    if (head == 0) {
        head = tail = newnode;
        tail->next = head; 
    } else {
        newnode->next = head;
        head = newnode;
        tail->next = head; 
    }
}
void endInsert(){
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter data\n");
	scanf("%d",&newnode->data);
	if(head==0){
		head=tail=newnode;
		tail->next=head;
	}
	else{
		tail->next=newnode;
		tail=newnode;
		tail->next=head;
	}
}
void posInsert(){
	int pos,i=1,length=0;
	struct node *temp,*temp1;
	temp=temp1=head;
	newnode=(struct node*)malloc(sizeof(struct node));
	while(temp1->next!=head){
		length++;
		temp1=temp1->next;
	}
	length=length+1;
	printf("length is %d\n",length);
	
	printf("Enter position\n");
	scanf("%d",&pos);
	
	if(pos<0|| pos>length+1){
		printf("Invalid\n");
	}
	else{
		if(pos==1 ){
			beginInsert();
		}
		else if(pos==length+1){
			endInsert();
		}
		else{
			while(i<pos-1){
				temp=temp->next;
				i++;
			}
			printf("Enter Data\n");
			scanf("%d",&newnode->data);	
			newnode->next=temp->next;
			temp->next=newnode;
			}
		}
}
void beginDelete(){
    struct node *temp;
    if(head == 0) {
        printf("List is empty\n");
    } else if(head->next == head) { 
        printf("Deleted element is %d\n", head->data);
        free(head);
        head = tail = 0; 
    } else {
        temp = head;
        head = head->next;
        tail->next = head; 
        printf("Deleted element is %d\n", temp->data);
        free(temp);
    }
}
void endDelete(){
	struct node *temp1,*temp;
	temp=head;
	if(head == 0) {
        printf("List is empty\n");
    } else if(head->next == head) { 
        printf("Deleted element is %d\n", head->data);
        free(head);
        head = tail = 0; 
    } else {
    	while(temp->next!=head){
    		temp1=temp;
    		temp=temp->next;
		}
		tail=temp1;
		tail->next=head;
        printf("Deleted element is %d\n", temp->data);
        free(temp);
    }
}
void posDelete(){
	int pos,length=0,i=1;
	struct node *temp1,*temp;
	printf("Enter position\n");
	scanf("%d",&pos);
	temp1=temp=head;
	
	while(temp1->next!=head){
		length++;
		temp1=temp1->next;
	}
	length=length+1;
	if(pos<1 || pos>length){
		printf("Invalid\n");
	}else{
		if(pos==1){
			beginDelete();
		}else if(pos==length){
			endDelete();
		}
		else{
			while(i<pos){
				temp1=temp;
				temp=temp->next;
				i++;
			}
			temp1->next=temp->next;
			printf("The deleted element is %d\n",temp->data);
			free(temp);
		}
	}
}
void reverse(){
	struct node *current,*prev,*nextnode;
	current=tail->next;
	nextnode=current->next;
	if(tail==0){
		printf("List is empty\n");
	}
	else{
		while(current!=tail){
			current->next=prev;
			prev=current;
			current=nextnode;
			nextnode=current->next;
			current->next=prev;
		}
		nextnode->next=tail;
		tail=nextnode;
	}
	head=tail->next;
}
int main(){
	int ch,k=1;
	while(k){
		printf("Enter\n 1. Insertion\n 2. Display\n 3. Begin insert\n 4. End Insert\n 5. Positional Insert\n 6. Begin delete\n 7. End delete\n 8. Positional delete\n 9. reverse\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:insert();
					break;
			case 2:display();
					break;
			case 3:beginInsert();
					break;
			case 4:endInsert();
					break;
			case 5:posInsert();
					break;
			case 6:beginDelete();
					break;
			case 7:endDelete();
					break;
			case 8:posDelete();
					break;
			case 9:reverse();
					break;
			default:printf("Invalid\n");
					break;
		}
		printf("Press 1 for continue and 0 for exit\n");
		scanf("%d",&k);
	}
	return 0;
}