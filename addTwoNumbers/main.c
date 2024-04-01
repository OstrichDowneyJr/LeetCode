#include <stdio.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

 struct ListNode {
     int val;
     struct ListNode *next;
 };

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

	struct ListNode* l3;
	int val;
	int overflow;

	val= l1->val + l2->val;
	if (val > 9){
		overflow = 1;
		val = val%10;
	}


			return l3;
}

int main(int argc, char** argv) {

	struct ListNode* num1;
	struct ListNode* num2;

    addTwoNumbers(num1, num2);
	return 0;
}