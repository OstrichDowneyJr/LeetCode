#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

 typedef struct node {
     int val;
     struct node* next;
 }node_t;
 
 void print_list_node(node_t* head) {

     node_t* current = head;
     while (current != NULL) {
         printf("%d\n", current->val);
         current = current->next;
     }
 }

 void push_node(node_t** head, int val) {

     node_t* new_node = malloc(sizeof(node_t));
     if (new_node == NULL) {
         fprintf(stderr, "Memory allocation failed\n");
         exit(EXIT_FAILURE);
     }

     new_node->val = val;
     new_node->next = NULL;

     if (*head == NULL) {
         *head = new_node;
     }
     else {
         node_t* current = *head;
         while (current->next != NULL) {
             current = current->next;
         }
         current->next = new_node;
     }
 }


 node_t* init_node(int size, int* numb) {
     if (size <= 0 || numb == NULL) {
         fprintf(stderr, "Invalid input\n");
         exit(EXIT_FAILURE);
     }

     node_t* head = malloc(sizeof(node_t));
     if (head == NULL) {
         fprintf(stderr, "Memory allocation failed\n");
         exit(EXIT_FAILURE);
     }
     node_t* current = head;
     for (int i = 0; i < size - 1; i++) {
         current->val = numb[i];
         current->next = malloc(sizeof(node_t));
         if (current->next == NULL) {
             fprintf(stderr, "Memory allocation failed\n");
             exit(EXIT_FAILURE);
         }
         current = current->next;
     }
     // Assign value to the last node
     current->val = numb[size - 1];
     current->next = NULL;
     return head;
 }

 void push_at_beginning(node_t** head, int val) {
     node_t* new_node = malloc(sizeof(node_t));
     if (new_node == NULL) {
         fprintf(stderr, "Memory allocation failed\n");
         exit(EXIT_FAILURE);
     }
     new_node->val = val;
	 new_node->next = *head;
     *head = new_node;
 }

 
 node_t* mergeTwoLists(node_t* list1, node_t* list2) {
     node_t* root = (node_t*)malloc(sizeof(node_t));
     if (root == NULL)
         return NULL; 
     root->val = 0;
     root->next = NULL;

     node_t* iter = root;

     if (list1 == NULL)
         return list2;
     if (list2 == NULL)
         return list1;

     if (list1 == NULL && list2 == NULL)
         return NULL;

     if (list1->val < list2->val) {
         root->val = list1->val;
         list1 = list1->next; 
     }
     else {
         root->val = list2->val;
         list2 = list2->next;
     }

     while (list1 != NULL && list2 != NULL) {
         iter->next = (node_t*)malloc(sizeof(node_t));
         iter = iter->next;
         if (list1->val > list2->val) {
             iter->val = list2->val;
             list2 = list2->next;
         }
         else {
         if (iter == NULL) {
			 fprintf(stderr, "Memory allocation failed\n");
			 exit(EXIT_FAILURE);
         }
             iter->val = list1->val;
             list1 = list1->next;
         }

     }

     while (list2 != NULL) {
         iter->next = (node_t*)malloc(sizeof(node_t));
         iter = iter->next;
         if (iter == NULL) {
			 fprintf(stderr, "Memory allocation failed\n");
			 exit(EXIT_FAILURE);
         }
         iter->val = list2->val;
         list2 = list2->next;
     }

     while (list1 != NULL) {
         iter->next = (node_t*)malloc(sizeof(node_t));
         iter = iter->next;
         if (iter == NULL) {
			 fprintf(stderr, "Memory allocation failed\n");
			 exit(EXIT_FAILURE);
         }
         iter->val = list1->val;
         list1 = list1->next;
     }

     iter->next = NULL;
     return root;
 }

int main(int argc, char** argv) {

    int val1[] = { 1,2,3 };
    int val2[] = { 2,3,4 };
    node_t* l1 = init_node(3, val1);
    node_t* l2 = init_node(3, val2);
    print_list_node(l1);
    push_node(&l1, 4);
    print_list_node(l1);
    push_at_beginning(&l1, 0);
    print_list_node(l1);
    node_t* l3 = mergeTwoLists(l1, l2);
    print_list_node(l3);
	return 0;
}