/*
QUESTION:-
Given the head of a linked list, return the list after sorting it in ascending order.

Example:
Input: head = [4,2,1,3]
Output: [1,2,3,4]
*/

//BRUTE-FORCE CODE:

/*
APPROACH:
1. In this approach, we will create a vector, and save all values of the linked list in it, and then we will create a new linked list with those values {after sorting the array}.
2. Creating a vector, we traverse through the linked list and save all the values in the array.
3. Now, we sort the array. We had created a new linked list with the initial value node 0.
4. Now, we traverse the array and move to the next pointer, create a new listnode and append the value of note[i] in it.
5. Finally, we move the pointer of last note to NULL.
6. Return newhead->next {since first node is 0}.
*/

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode* newhead = new ListNode(0);
        ListNode* temp = newhead;
        ListNode* move = head;
        vector<int>note;
        while(move != NULL){
            note.push_back(move->val);
            move = move->next;
        }
        sort(note.begin(), note.end());
        for(int i = 0; i < note.size(); i++) {
            temp->next = new ListNode(note[i]);
            temp = temp->next;
        }
        temp->next = NULL;
        return newhead->next;
    }
};

//Time complexity : O(NlogN) {due to sorting}
//Space Complexity : O(N) {extra vector + new list}
