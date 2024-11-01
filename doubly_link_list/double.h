#ifndef DOUBLE_H
#define DOUBLE_H


/* Type definition for node structure with a pointer to a next and previous element */
typedef struct node{
    struct node *next;
    struct node *prev;
    int value;
}node;

typedef struct list{
    struct node *head;
    struct node *tail;
    int size;
}list;

/* Prototypes */
list *initialize_list();
void insert_at_beginning(list *lst, int value);
void insert_at_end(list *lst, int value);
void insert_at_position(list *lst, int value, int idx);
int delete_from_beginning(list *lst);
int delete_from_end(list *lst);
int delete_from_position(list *lst, int idx);
int search(list *lst);
int print(list *lst);
void destroy_list(list *lst);




/* Tests */

void run_all_test();
void test_initialize_list();
void test_initialize_tail();
void test_insert_at_beginning();
void test_insert_at_end();
void test_insert_at_position();
void test_delete_from_beginning();
void test_delete_from_end();
void test_delete_from_pos();
void test_search();
void test_print();
void test_destroy_list();


#endif