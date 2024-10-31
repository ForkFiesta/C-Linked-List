#ifndef SINGLE_LIST_H
#define SINGLE_LIST_H
#include <stdbool.h>

typedef struct node{
    struct node *next;
    int data;
}node;

node *initialize_head();

void insert_at_beginning(node **list, int value);
void insert_at_end(node **list, int value);
void insert_at_position(node **list, int idx, int value);
int delete_from_beginning(node **list);
int delete_from_end(node **list);
int delete_from_position(node **list, int idx);
int search(node *list, int value);
int print(node *list);
void delete_list(node **list);



/* Tests */

void run_all_tests();
void test_initialize_head();
void test_insert_at_beginning();
void test_insert_at_end();
void test_insert_at_position();
void test_delete_from_beginning();
void test_delete_from_end();
void test_delete_from_position();
void test_search();
void test_print();


#endif