/*******************************************************************************************
* File Name          : assign2skeleton.c
* Description        : Prog8130 - Assignment 2: Binary Trees
*                      This program uses binary tree to hold and print a list of numbers
*
* Author:              Gaurav Kalia
* Date:                18th Febuary, 2022
********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// structure defining a binary tree node. 
// Lower sorted values will go the the left
// Otherwise to the right.
typedef struct node {
	int    data;			// the number this node holds
	struct node* left;		// pointer to the left node in the tree that is less than current node OR NULL if empty
	struct node* right;		// pointer to the right node in the tree that is greater than current node OR NULL if empty
} Node;

void addToBinaryTree(Node** head, const int number);
void printBinaryTreeInOrder(Node* head);

int main(int argc, char* argv[]) {
	Node* head = NULL;	// head of the binary tree
	int number;			// to store new number
	int i;				// used in for loop as index

	// put all the numbers into the binary tree
	// numbers will be provided from command line
	for (i = 1; i < argc; i++) {
		number = atoi(argv[i]);
		addToBinaryTree(&head, number);
	}

	// print the entire tree using In-Order
	printBinaryTreeInOrder(head);

	return 0;
}

//====================== You should not modify anything above ==============================//
//==================== You should only modify following functions ==========================//

// FUNCTION      : addToBinaryTree
//
// DESCRIPTION   : Recusion method will first compare the numbers and then pass right side pointer and number
//	 Similarly, left side pointer and number.
//
//   This function will store the data in newNode into a binary tree
//
// PARAMETERS    : Node** head, const int number
//   number - the number that is to be stored in the binary tree
//
// RETURNS       : Order of the numbers
//   Nothing
void addToBinaryTree(Node** head, const int number) {
	// add code to put the new number into the binary tree
	Node* p = *head;
	Node* node = (Node*)malloc(sizeof(Node));				// create a new node
	if (node == NULL) {
		return; // don't handle the error for now
	}
	node->data = number;
	node->left = NULL;
	node->right = NULL;

	// in case it is the first node
	// Think: why do we use *head?
	//        comparing to assignment 1, can you think of a way 
	// 		  by changing the function signature to not use *head?
	//        (however, don't change here, show it during demo)
	if (*head == NULL) {
		*head = node;
		return;
	}

	// implement your logic
	//Using Recusion 
	while (1)
	{
		/* If number from previous node is greater then number already in node */
		if (node->data > p->data)
		{
			/* code */
			if (p->right != NULL)					// Condition runs when number entered at right is not null 
			{
				/* code */
				p = p->right;					    // recursion to access right side number first
			}
			else{
				p->right = node;
				return;
			}
		}
		    /* If number from previous node is lesser then number already in node */
			else if (node->data < p->data){
				if (p->left != NULL)				// Condition runs when number entered at left is not null 
				{
					/* code */
					p = p->left;					// recursion to access left side number first
				}
				else{
					p->left = node;
					return;
				}
			}
				else{
					return;
				}
		
	}

	return;
}

// FUNCTION      : printBinaryTreeInOrder
//
// DESCRIPTION   : This function takes an input of the head from the numbers entered by user, then loops through
//   if condition to check whether head is null and then print the numbers from left to right
//
//   This function will print the entire binary tree out using In-Order.
//   See lecture slide if you cannot remember what In-Order is.
//
// PARAMETERS    : Node* head
//   None
//
// RETURNS       : Void
//   Nothing
void printBinaryTreeInOrder(Node* head) {
	// add code to print data using In-Order starting at the "head" pointer
	// one number per line
	if (head == NULL)
	{
		/* code */
		return;
	}
	/*	Printing the binary tree from left to right */
	printBinaryTreeInOrder(head->left);				
	printf("%d\n",head->data);
	printBinaryTreeInOrder(head->right);
	return;
}
