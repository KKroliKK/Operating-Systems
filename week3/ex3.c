#include <stdio.h>
#include <stdlib.h>


struct node{

    struct node *next;
    int v; // value
};


void push_back(struct node *head, int value){
    struct node *tmp = head;

    while(1){
        if (tmp->next == 0){
        tmp->next = (struct node*) malloc(sizeof(struct node));
        tmp->next->v = value;

        return;
    }
        tmp = tmp->next;
    }   
}


void insert_node(struct node *head, int index_value, int value){
    struct node *tmp = head->next;

    while(tmp != 0){
        if(tmp->v == index_value){

            struct node *new_node = (struct node*) malloc(sizeof(struct node));
            new_node->v = value;

            new_node->next = tmp->next;
            tmp->next = new_node;

            return;
        }
        tmp = tmp->next;
    }   
}


void delete_node(struct node *head, int index_value){
    struct node *tmp = head->next;
    struct node *previous;

    while(tmp != 0){
        if(tmp->v == index_value){

            previous->next = tmp->next;

            free(tmp);

            return;
        }
        previous = tmp;
        tmp = tmp->next;
    }   
}


void print_list(struct node *head){
    struct node *tmp = head->next;

    while(tmp != 0){
        printf("%d ", tmp->v);
        tmp = tmp->next;
    }

    printf("\n");
}


int main(){

    struct node *head = (struct node*) malloc(sizeof(struct node));
    
    head->next = 0;
    

    push_back(head, 1);
    push_back(head, 2);
    push_back(head, 3);   
    print_list(head);
    insert_node(head, 2, 4);
    insert_node(head, 1, 5);
    print_list(head);
    delete_node(head, 2);
    print_list(head);

    return 0;
}