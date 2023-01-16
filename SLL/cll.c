#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void printall(struct node *ptr){
    struct node *p = ptr;
    while(p->next!=ptr){
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("%d",p->data);
    printf("\n");
}

int length(struct node *ptr){
    int len=0;
    struct node *p = ptr;
    while(p->next!=ptr){
        len++;
        p=p->next;
    }
    return len+1;
}

struct node *insert_beg(struct node *head, int value){
    struct node *ptr = (struct node*) malloc(sizeof(struct node));
    struct node *p = head;
    while(p->next!=head){
        p=p->next;
    }
    ptr->next = head;
    p->next =ptr;
    head = ptr;
    ptr->data = value;
    return head;
}

struct node *insert_between(struct node *head, int value, int index){
    struct node *ptr = (struct node *) malloc(sizeof(struct node));
    struct node *p = head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    ptr->data = value;
    return head;
}

struct node *insert_end(struct node *head, int value){
    struct node *ptr = (struct node *) malloc(sizeof(struct node));
    struct node *p = head;
    while(p->next!=head){
        p=p->next;
    }
    ptr->next = head;
    p->next = ptr;
    ptr->data = value;
    return head;
}

struct node *delete_beg(struct node *head){
    struct node *p =head;
    while(p->next!=head){
        p=p->next;
    }
    struct node *q = p->next;
    head = q->next;
    p->next = head;
    free(q);
    return head;
}

struct node *delete_between(struct node *head,int index){
    int i=0;
    struct node *p=head;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    struct node *q = p->next;
    p->next = q->next;
    free(q);
    return head;
}

struct node *delete_end(struct node *head){
    struct node *p = head;
    struct node *q = p->next;
    while(q->next!=head){
        q = q->next;
        p = p->next;
    }
    p->next = head;
    free(q);
    return head;
}

void main(){
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head = (struct node *) malloc(sizeof(struct node));
    second = (struct node *) malloc(sizeof(struct node));
    third = (struct node *) malloc(sizeof(struct node));
    fourth = (struct node *) malloc(sizeof(struct node));

    head->data = 13;
    head->next = second;

    second->data = 14;
    second->next = third;

    third->data = 15;
    third->next = fourth;

    fourth->data =16;
    fourth->next = head;

    printf("Before operations\n");
    printf("length = %d\n",length(head));
    printall(head);

    printf("After insertion\n");
    //head = insert_beg(head,45);
    //head = insert_end(head,3);
    //printall(head);
    head = insert_between(head,45,3);
    //head = delete_end(head);
    printf("length = %d\n",length(head));
    printall(head);
}
