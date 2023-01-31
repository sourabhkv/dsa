//grounded header linked list
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};


void printall(struct node *head){
    struct node *p =head->next;
    int i=0;
    while(i<head->data){
        printf("%d\t",p->data);
        p=p->next;
        i++;
    }
    printf("\n");
}

int length(struct node *head){
    return head->data;
}

struct node *insert_beg(struct node *head,int value){
    struct node *q = head->next;
    struct node *ptr = (struct node*) malloc(sizeof(struct node));
    ptr->next = q;
    ptr->data=value;
    head->next=ptr;
    head->data = head->data+1;
    return head;
}

struct node *insert_end(struct node *head,int value){
    struct node *p = head;
    struct node *ptr = (struct node*) malloc(sizeof(struct node));
    while (p->next!=NULL){
        p=p->next;
    }
    ptr->next = NULL;
    ptr->data=value;
    p->next=ptr;
    head->data = head->data+1;
    return head;
}

struct node *insert_between(struct node *head, int pos,int value){
    int i;
    struct node *p = head->next;
    if (pos < head->data){
        i=0;
        while(i!=pos-1){
            p=p->next;
            i++;
        }
        struct node *ptr = (struct node *) malloc(sizeof(struct node));
        ptr->next = p->next;
        ptr->data = value;
        p->next = ptr;
        head->data +=1;
        return head;
    }
    else{
        return head;
    }
}

struct node *delete_beg(struct node *head){
    struct node *p =head->next;
    struct node *q =head->next->next;
    head->next = q;
    free(p);
    head->data -=1;
    return head;
}

struct node *delete_end(struct node *head){
    struct node *p=head;
    struct node *q = head->next;
    while (q->next!=NULL){
        q=q->next;
        p=p->next;
    }
    p->next = NULL;
    free(q);
    head->data=head->data-1;
    return head;
}

void main(){
    struct  node *head;
    struct node *first;
    struct node *second;


    head = (struct node *) malloc(sizeof(struct node));
    first = (struct node *) malloc(sizeof(struct node));
    second = (struct node *) malloc(sizeof(struct node));

    
    head->next = first;


    first->data=10;
    first->next=second;

    second->data=20;
    second->next=NULL;

    head->data=2;

    printall(head);
    head = insert_beg(head,4);
    head = insert_beg(head,5);
    head = insert_beg(head,7);
    printall(head);
    /*head = delete_beg(head);
    printall(head);
    head = delete_end(head);
    printall(head);*/
    head = insert_between(head,2,99);
    printall(head);
}