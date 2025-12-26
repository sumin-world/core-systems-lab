#ifndef MY_LIST_SHALLOW
#define MY_LIST_SHALLOW

#include <stddef.h>

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node *head;
    size_t size;
} LinkedList;

typedef void (*PrintFunc) (void*);

LinkedList* create_list(void);
void add_node(LinkedList *list, void *data);
void print_list(LinkedList *list, PrintFunc print);
void free_list(LinkedList *list);

#endif