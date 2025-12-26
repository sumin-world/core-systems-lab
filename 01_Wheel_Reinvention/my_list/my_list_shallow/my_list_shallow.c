#include "my_list_shallow.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

LinkedList* create_list(void) {
    LinkedList *list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

void add_node(LinkedList *list, void *data) {
    Node *new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

void print_list(LinkedList *list, PrintFunc print) {
    Node *current = list->head;
    while(current != NULL) {
        print(current->data);
        current = current->next;
    }
}

void free_list(LinkedList *list) {
    Node *current = list->head;
    while(current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
}