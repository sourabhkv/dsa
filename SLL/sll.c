#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node * insert_beg(struct node *head, int data){
    struct node *ptr = (struct node *) malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct node * insert_at_index(struct node *head, int data,int index){
    struct node *ptr = (struct node *) malloc(sizeof(struct node));
    struct node *p =head;
    int i=0;
    while(i!=index-1){
        p=p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    ptr->data =data;
    return head;
}

struct node * insert_at_end(struct node *head, int data){
    struct node *ptr = (struct node *) malloc(sizeof(struct node));
    struct node *p = head;
    while (p->next!=NULL){
        p=p->next;
    }
    p->next = ptr;
    ptr->data = data;
    ptr->next = NULL;
    return head;
}

struct node * insert_at_node(struct node *head,struct node *prenode, int data){
    struct node *ptr = (struct node *) malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=prenode->next;
    prenode->next = ptr;
    return head;
}

struct node * delete_beginning(struct node *head){
    struct node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct node * delete_between(struct node *head,int index){
    struct node *ptr =head;
    int i=0;
    while(i<index-1){
        ptr=ptr->next;
        i++;
    }
    struct node *q = ptr->next;
    ptr->next = q->next;
    free(q);
    return head;
}

struct node *delete_end(struct node *head){
    struct node *p = head;
    struct node *q = p->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next =NULL;
    free(q);
    return head;
}

struct node *delete_at_node(struct node *head,int value){
    struct node *p =head;
    struct node *q= p->next;
    while(q->next!=NULL && q->data!=value){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}

void printall(struct node *ptr){
    if (ptr == NULL){
        printf("SLL is empty\n");
        return;
    }
    else{
        while(ptr!=NULL){
            printf("%d\t",ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

int length(struct node *ptr){
    int len=0;
    while(ptr!=NULL){
        ptr = ptr->next;
        len++;
    }
    return len;
}

void main(){
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    head = (struct node*) malloc(sizeof(struct node));
    second = (struct node*) malloc(sizeof(struct node));
    third = (struct node*) malloc(sizeof(struct node));
    fourth = (struct node*) malloc(sizeof(struct node));

    head->data = 45;
    head->next = second;

    second->data = 46;
    second->next = third;

    third->data = 47;
    third->next = fourth;

    fourth->data = 48;
    fourth->next = NULL;
    printf("before operations\n");
    printf("length = %d\n",length(head));
    printall(head);

    //head = insert_at_end(head,49);
    //head = insert_beg(head,67);
    printf("\nInserting\n");
    printf("current length = %d\n",length(head));
    head = insert_at_node(head,second,97);
    printall(head);

    /*printf("\nDeleting between\n");
    head = delete_between(head,3);
    printall(head);*/
    printf("\nDeleting end\n");
    printf("final length = %d\n",length(head));
    head = delete_at_node(head,97);
    printall(head);
}
