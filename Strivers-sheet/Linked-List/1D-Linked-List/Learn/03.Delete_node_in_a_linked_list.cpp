/*
QUESTION:-
There is a singly-linked list head and we want to delete a node node in it.
You are given the node to be deleted node. You will not be given access to the first node of head.
All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.
Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:
1. The value of the given node should not exist in the linked list.
2. The number of nodes in the linked list should decrease by one.
3. All the values before node should be in the same order.
4. All the values after node should be in the same order.

Example:

Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.
*/

/*
APPROACH:
1. Since we are not given access to head, we cannot access the node before the given node. So, we cannot change the node it is pointing to.
2. We save the next node of the current node in a new node {nextnode}.
3. We assign value of the next node to the current node.
3. Now, we point the pointer of the current node to the next to next node.
4. Delete nextnode.
*/

//CODE:
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* nextnode = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete nextnode;
    }
};

//Time Complexity : O(1)
//Space Complexity : O(1)
