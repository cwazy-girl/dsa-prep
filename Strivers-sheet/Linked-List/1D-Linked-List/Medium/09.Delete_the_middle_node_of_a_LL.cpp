/*
QUESTION:-
You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.
The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

Example:
Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]
Explanation:
Since n = 7, node 3 with value 7 is the middle node, which is marked in red.
We return the new list after removing this node. 
*/

/*
APPROACH:
1. To delete the middle node, we will use the tortoise-hare method.
2. We intialise three nodes, all starting from head. Slow will move one node at a time, and fast will move two nodes at a time. Temp will store the value of the previous slow value.
3. While fast != NULL && fast->next != NULL, we store node of slow in temp, move fast by two nodes and slow by one node.
4. When fast traverses the entire linked list, temp will point to the node just before slow.
5. So, we move temp->next to temp->next->next, and delete slow.
6. Return head.
*/

//CODE:
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;

        while(fast != NULL && fast->next != NULL) {
            temp = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        temp->next = temp->next->next;
        delete slow;
        return head;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(1)
