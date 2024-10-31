#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "single-list.h"



node *initialize_head(){
    node *head = NULL;
    return head;

}

void insert_at_beginning(node **list, int value){
    node *new_node = malloc(sizeof(node));
    if(new_node == NULL){
        printf("Error allocating memory for new node\n");
        return;
    }
    new_node->data = value;
    new_node->next = *list;
    *list = new_node;
}


void insert_at_end(node **list, int value){
    
    node *new_node = malloc(sizeof(node));
    if(new_node == NULL){
        printf("Error allocating memory for new node\n");
        return;
    }
    new_node->data = value;
    new_node->next = NULL;

    if(*list == NULL){
        *list = new_node;
        return;
    }
    node *p = *list;

    for(;p->next!=NULL;p=p->next);
    p->next = new_node;
    
    
}
void insert_at_position(node **list, int idx, int value){
    node *new_node = malloc(sizeof(node));
    if(new_node == NULL){
        printf("Error allocating memory for new node.\n");
        return;
    }
    new_node->data = value;
    if(*list == NULL){
        printf("cannot add item at index %d. List is empty\n");
        free(new_node);
        return;
    }
    
    if(idx == 0){
        new_node->next = *list;
        *list = new_node;
        return;
    }
    int counter = 0;
    node *p = *list;
    for(;counter<idx-1 && p!=NULL; counter++, p=p->next);

    if(p == NULL){
        printf("Index %d out of range for list size\n");
        free(new_node);
        return;
    }

    new_node->next = p->next;
    p->next = new_node;


}
int delete_from_beginning(node **list){
    if(*list == NULL){
        printf("Cannot delete from empty list.\n");
        return -1;
    }


   node *p = *list;
   int return_value = p->data;
   node *temp = p->next;
   free(p);
   *list = temp;
   return return_value;

}
int delete_from_end(node **list){

    if(*list == NULL){
        printf("Cannot delete from empty list\n");
        return -1;
    }

    if((*list)->next == NULL){
        int return_value = (*list)->data;
        free((*list));
        *list = NULL;
        return return_value;

    }

    node *p = *list;

    while(p->next->next != NULL){
        p = p->next;
    }
    free(p->next);
    p->next = NULL;

    
    


}
int delete_from_position(node **list, int idx){
    int return_value;
    if(*list == NULL){
        printf("Cannot delete from empty list\n");
        return -1;
    }
    if(idx == 0){
        return_value = (*list)->data;
        node *new_head = (*list)->next;
        free(*list);
        *list = new_head;
        return return_value;
    }

    int counter = 0;
    node *p = *list;
    while(p != NULL && counter < idx -1){
        counter++;
        p=p->next;
    }

    if(p == NULL){
        printf("Index %d out of range for list size\n", idx);
        return -1;
    }

    node *temp = p->next->next;
    return_value = p->next->data;
    free(p->next);
    p->next = temp;
    return return_value;

}
int search(node *list, int value){
    if(list == NULL){
        printf("List is empty. Cannot Search\n");
        return -1;
    }
    int index = 0;
    for(;list!=NULL;list = list=list->next){
        index++;
        if(list->data == value){
            return index;
        }
    }
    return -1;


}
int print(node *list){
    if(list == NULL){
        printf("Cannot print from an empty list\n");
        return;
    }
    int index = 0;
    for (;list!=NULL;list=list->next){
        // printf("Index %d. %d\n",index, list->data);
        index++;
    }

    return index;
}


void delete_list(node **list){
    if(*list == NULL){
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    while((*list)!= NULL){
        node *temp = (*list)->next;
        free(*list);
        *list = temp;
    }
}

// Tests

void run_all_tests(){
    printf("\033[1;33mRunning all tests...\033[0m\n");
    test_initialize_head();
    test_insert_at_beginning();
    test_insert_at_end();
    test_insert_at_position();
    test_delete_from_beginning();
    test_delete_from_end();
    test_delete_from_position();
    test_search();
    test_print();
    printf("\033[1:32mAll tests passed successfully.\033[0m\n");
}
void test_initialize_head(){
    node *head = initialize_head();
    assert(head == NULL);
}
void test_insert_at_beginning(){
    node *head = initialize_head();
    insert_at_beginning(&head, 3);
    insert_at_beginning(&head, 2);
    insert_at_beginning(&head, 1);
    assert(head->data == 1);
    delete_list(&head);
    assert(head == NULL);
}
void test_insert_at_end(){
    node *head = initialize_head();
    insert_at_end(&head, 8);
    insert_at_end(&head, 5);
    insert_at_end(&head, 2);
    assert(head->data==8);
    delete_list(&head);
}
void test_insert_at_position(){
    node *head = initialize_head();
    insert_at_beginning(&head, 5);
    insert_at_beginning(&head, 5);
    insert_at_beginning(&head, 5);
    insert_at_beginning(&head, 5);
    insert_at_position(&head, 2, 2);
    assert(head->next->next->data == 2);
    delete_list(&head);
}
void test_delete_from_beginning(){
    node *head = initialize_head();
    insert_at_beginning(&head, 2);
    insert_at_beginning(&head, 8);
    insert_at_beginning(&head, 5);
    insert_at_beginning(&head, 4);
    assert(delete_from_beginning(&head)==4);
    delete_list(&head);
}
void test_delete_from_end(){
    node *head = initialize_head();
    insert_at_beginning(&head, 2);
    insert_at_beginning(&head, 8);
    insert_at_beginning(&head, 5);
    insert_at_beginning(&head, 4);
    assert(delete_from_end(&head) == 2);
    delete_list(&head);
}
void test_delete_from_position(){
    node *head = initialize_head();
    insert_at_beginning(&head, 2);
    insert_at_beginning(&head, 8);
    insert_at_beginning(&head, 5);
    insert_at_beginning(&head, 4);
    assert(delete_from_position(&head, 2) == 8);
    delete_list(&head);
}
void test_search(){
    node *head = initialize_head();
    insert_at_beginning(&head, 2);
    insert_at_beginning(&head, 8);
    insert_at_beginning(&head, 5);
    insert_at_beginning(&head, 4);
    assert(search(head, 8)==2);
    delete_list(&head);
}
void test_print(){
    node *head = initialize_head();
    insert_at_beginning(&head, 2);
    insert_at_beginning(&head, 8);
    insert_at_beginning(&head, 5);
    insert_at_beginning(&head, 6);
    insert_at_beginning(&head, 9);
    insert_at_beginning(&head, 2);
    insert_at_beginning(&head, 4);
    assert(print(head)== 6);
    delete_list(&head);
}



