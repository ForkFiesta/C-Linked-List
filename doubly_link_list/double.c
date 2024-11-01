#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "double.h"

list *initialize_list(){
    list *lst = malloc(sizeof(list));
    if(lst == NULL){
        printf("Error allocating memory.\n");
        exit(1);
    }
    lst->head = NULL;
    lst->tail = NULL;
    lst->size = 0;
    return lst;
}

void insert_at_beginning(list *lst, int value){
    node *new_node = malloc(sizeof(node));
    if(new_node == NULL){
        printf("Error allocating memory\n");
        exit(1);
    }
    new_node->value = value;
    new_node->prev = NULL;
    if((lst->head==NULL) && (lst->tail == NULL)){ // list is empty
        new_node->next = NULL;
        lst->head = new_node;
        lst->tail = new_node;
        lst->size++;
        return;
    }
    new_node->next = lst->head;
    lst->head = new_node;
    lst->size++;

}
void insert_at_end(list *lst, int value){
    node *new_node = malloc(sizeof(node));
    if(new_node == NULL){
        printf("Error allocating memory\n");
        exit(1);
    }
    new_node->value=value;
    new_node->next=NULL;
    if((lst->head==NULL) && (lst->tail == NULL)){ // list is empty
        new_node->prev = NULL;
        lst->head = new_node;
        lst->tail = new_node;
        lst->size++;
        return;
    }

    new_node->prev = lst->tail;
    lst->tail = new_node;
    lst->size++;

    
}
void insert_at_position(list *lst, int value, int idx);

int delete_from_beginning(list *lst);
int delete_from_end(list *lst);
int delete_from_position(list *lst, int idx);
int search(list *lst);
int print(list *lst);
void destroy_list(list *lst);



void test_initialize_list(){
    printf("Testing Initialize List...\n");
    list *lst = initialize_list();
    assert(lst->head==NULL && lst->tail==NULL && lst->size == 0);
}