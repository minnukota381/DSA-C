#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head, *newnode, *tail;

void Endinsert() {
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL) {
        head = tail = newnode;
        tail->next = head; 
    } else {
        tail->next = newnode;
        tail = newnode;
        tail->next = head;
    }
}

void display() {
    struct node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp->next != head) {
        printf("%d --> ", temp->data);
        temp = temp->next;
    }
    printf("%d --> HEAD\n", temp->data);
}

void beginInsert() {
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (head == NULL) {
        head = tail = newnode;
        tail->next = head; 
    } else {
        newnode->next = head;
        head = newnode;
        tail->next = head; 
    }
}

void posInsert() {
    int pos, i = 1, length = 0;
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty. Use insertion at the beginning.\n");
        return;
    }

    while (temp->next != head) {
        length++;
        temp = temp->next;
    }
    length++;

    printf("Enter position (1 to %d): ", length + 1);
    scanf("%d", &pos);

    if (pos < 1 || pos > length + 1) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        beginInsert();
    } else if (pos == length + 1) {
        endInsert();
    } else {
        temp = head;
        for (i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void beginDelete() {
    struct node *temp;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    } else if (head->next == head) {
        printf("Deleted element is %d\n", head->data);
        free(head);
        head = tail = NULL; 
    } else {
        temp = head;
        head = head->next;
        tail->next = head;
        printf("Deleted element is %d\n", temp->data);
        free(temp);
    }
}

void endDelete() {
    struct node *temp = head, *prev = NULL;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    } else if (head->next == head) {
        printf("Deleted element is %d\n", head->data);
        free(head);
        head = tail = NULL;
    } else {
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        tail = prev;
        printf("Deleted element is %d\n", temp->data);
        free(temp);
    }
}

void posDelete() {
    int pos, i = 1, length = 0;
    struct node *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp->next != head) {
        length++;
        temp = temp->next;
    }
    length++;

    printf("Enter position (1 to %d): ", length);
    scanf("%d", &pos);

    if (pos < 1 || pos > length) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        beginDelete();
    } else if (pos == length) {
        endDelete();
    } else {
        temp = head;
        for (i = 1; i < pos; i++) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = temp->next;
        printf("Deleted element is %d\n", temp->data);
        free(temp);
    }
}

void reverse() {
    struct node *prev = NULL, *current = head, *nextnode;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    tail = head;
    while (current->next != head) {
        nextnode = current->next;
        current->next = prev;
        prev = current;
        current = nextnode;
    }
    current->next = prev;
    head->next = current;
    head = current;
}

int main() {
    int ch, k = 1;

    while (k) {
        printf("\nEnter\n 1. Insert\n 2. Display\n 3. Begin Insert\n 4. End Insert\n 5. Positional Insert\n");
        printf(" 6. Begin Delete\n 7. End Delete\n 8. Positional Delete\n 9. Reverse\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1: Endinsert(); break;
            case 2: display(); break;
            case 3: beginInsert(); break;
            case 4: endInsert(); break;
            case 5: posInsert(); break;
            case 6: beginDelete(); break;
            case 7: endDelete(); break;
            case 8: posDelete(); break;
            case 9: reverse(); break;
            default: printf("Invalid choice\n"); break;
        }

        printf("Press 1 to continue or 0 to exit: ");
        scanf("%d", &k);
    }

    return 0;
}
