#include <stdio.h>
#include <stdlib.h>


struct node{

    struct node *prev;
    struct node *next;
    
    int v;
};


void push_back(struct node *tail, int value){
    struct node *tmp = (struct node*) malloc(sizeof(struct node));
    tmp->v = value;

    tmp->next = tail;
    tmp->prev = tail->prev;
    
    tail->prev->next = tmp;
    tail->prev = tmp;
}


void insert_node(struct node *head, struct node *tail, int index_value, int value){
    struct node *tmp = head->next;

    while(tmp != tail){
        if(tmp->v == index_value){

            struct node *new_node = (struct node*) malloc(sizeof(struct node));
            new_node->v = value;

            new_node->next = tmp->next;
            new_node->prev = tmp;

            new_node->next->prev = new_node;
            tmp->next = new_node;

            return;
        }
        tmp = tmp->next;
    }   
}


void delete_node(struct node *head, struct node *tail, int index_value){
    struct node *tmp = head->next;

    while(tmp != tail){
        if(tmp->v == index_value){

            struct node *pr_node = tmp->prev;
            struct node *ne_node = tmp->next;

            pr_node->next = tmp->next;
            ne_node->prev = tmp->prev;

            free(tmp);

            return;
        }
        tmp = tmp->next;
    }   
}


void print_list(struct node *head, struct node *tail){
    struct node *tmp = head->next;

    while(tmp != tail){
        printf("%d ", tmp->v);
        tmp = tmp->next;
    }

    printf("\n");
}


int main(){

    struct node *head = (struct node*) malloc(sizeof(struct node));
    struct node *tail = (struct node*) malloc(sizeof(struct node));
    
    head->next = tail;
    head->prev = 0;
    tail->prev = head;
    tail->next = 0;


    push_back(tail, 1);
    push_back(tail, 2);
    push_back(tail, 3);   
    print_list(head, tail);
    insert_node(head, tail, 2, 4);
    insert_node(head, tail, 1, 5);
    print_list(head, tail);
    delete_node(head, tail, 2);
    print_list(head, tail);

    return 0;
}
