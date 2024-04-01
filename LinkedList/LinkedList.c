#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

 typedef struct node {
     int val;
     struct node* next;
 }node_t;
 
struct node_t* mergeTwoLists(node_t* list1, node_t* list2) { 
    
    node_t* root = (node_t*)malloc(sizeof(node_t));
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

     node_t* l1 = (node_t*)malloc(sizeof(node_t));
     node_t* l2 = (node_t*)malloc(sizeof(node_t));

    l1->val = 0;
    l1->next = (node_t*)malloc(sizeof(node_t));
    l1 = l1->next;
    l1->val = 1;
    l1->next = (node_t*)malloc(sizeof(node_t));
    l1 = l1->next;
    l1->val = 4;
    l1->next = NULL;

    l2->val = 0;
    l2->next = (node_t*)malloc(sizeof(node_t));
    l2 = l2->next;
    l2->val = 3;
    l2->next = (node_t*)malloc(sizeof (node_t));
    l2 = l2->next;
    l2->val = 2;
    l2->next = NULL;

    mergeTwoLists(l1, l2);



	return 0;
}