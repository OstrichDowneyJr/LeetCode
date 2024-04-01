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

 void push_node(node_t* head, int val) {
     node_t* current = head;
     while (current->next != NULL) {
         current = current->next;
     }
     current->next = (node_t*)malloc(sizeof(node_t));
     current->next->val = val;
     current->next->next = NULL;
 }

 void init_node(node_t* head,int size, int* val) {
     node_t* current = head;
     while (current->next != NULL) {
         current = current->next;
     }

     current->next = (node_t*)malloc(sizeof(node_t));
     current->next->val = val;
     current->next->next = NULL;
 }

 void push_at_beginning(node_t** head, int val) {

     node_t* new_node;
     new_node = (node_t*)malloc(sizeof(node_t));
     new_node->val = val;
     new_node->next = *head;
     *head = new_node;
 }

 
 node_t* mergeTwoLists(node_t* list1, node_t* list2) { 
   
    node_t* root = NULL;
    root = (node_t*)malloc(sizeof(node_t));
    if (root == NULL)
        return 1;
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
        list1 = list2->next;
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
            iter->val = list1->val;
            list1 = list1->next;
        }
    }
	if (list1 == NULL && list2 != NULL) {
		iter->next = (node_t*)malloc(sizeof(node_t));
		iter = iter->next;
		iter->val = list2->val;
		list2 = list2->next;
	}
	else if (list1 != NULL && list2 == NULL) {
		iter->next = (node_t*)malloc(sizeof(node_t));
		iter = iter->next;
		iter->val = list1->val;
		list1 = list1->next;
	}
    iter->next = NULL;
    return root;
}

int main(int argc, char** argv) {

    node_t* l1 = (node_t*)malloc (sizeof(node_t));
    l1->val = 1;
    l1->next = NULL;
    push_node(l1, 3);
    print_list_node(l1);
    push_node(l1, 30);
    print_list_node(l1);

	return 0;
}