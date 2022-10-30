/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*

Approach:

Since each list, followed by the bottom pointer, are in sorted order. Our main aim is to make a single list in sorted order of all nodes. So, we can think of a merge algorithm of merge sort.

The process to flatten the given linked list is as follows:-

    We will recurse until the head pointer moves null. The main motive is to merge each list from the last.
    Merge each list chosen using the merge algorithm. The steps are

    Create a dummy node. Point two pointers, i.e, temp and res on dummy node. res is to keep track of dummy node and temp pointer is to move ahead as we build the flattened list.
    We iterate through the two chosen. Move head from any of the chosen lists ahead whose current pointed node is smaller. 
    Return the new flattened list found.

*/

/*  Function which returns the  root of 
    the flattened linked list. */

Node* mergeTwoLists(Node* a, Node* b) {
    if(!a || !b) return (!a) ? b : a;
    
    Node* dummy = new Node(-1);
    Node* tmp = dummy;
    
    while(a && b) {
        if(a->data <= b->data) {
            tmp->bottom = a;
            tmp = tmp->bottom;
            a = a->bottom;
        }
        else {
            tmp->bottom = b;
            b = b->bottom;
            tmp = tmp->bottom;
        }
    }
    
    tmp->bottom = (!a) ? b : a;
    
    return dummy->bottom;
}

Node* flattenLastTwoLists(Node* head) {
    if(!head || !head->next) return head;
    
    Node* mergedList = flattenLastTwoLists(head->next);
    
    return mergeTwoLists(head, mergedList);
}

Node *flatten(Node *root)
{
   return flattenLastTwoLists(root);
}
