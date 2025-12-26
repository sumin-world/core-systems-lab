#include <stdio.h>
#include "my_list_shallow.h"

void print_int(void *data) {
    printf("%d ", *(int*)data);
}

int main() {
    LinkedList *list = create_list();
    
    int a = 10, b = 20, c = 30;
    add_node(list, &a);
    add_node(list, &b);
    add_node(list, &c);
    
    print_list(list, print_int);
    printf("\n");
    
    free_list(list);
    return 0;
}