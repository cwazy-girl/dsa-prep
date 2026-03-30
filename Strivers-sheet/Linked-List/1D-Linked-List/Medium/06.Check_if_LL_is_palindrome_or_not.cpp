/*
QUESTION:-
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Example:
Input: head = [1,2,3,2,1]
Output: true
*/

/*
APPROACH:
1. If the linked list is empty or has one node, then it is always a palindrome. Return true.
2. Now, we create three nodes, fast, slow, and prevslow, all initiated from head. We use slow and fast to find the mid of the linked list. And prevslow will represent the node just before slow.
3. Now we get two halves of the linked list, which we can compare to test if it is a palindrome.
4. First, we connect prevslow->next to NULL, so that the first linked list becomes independent of the second one.
5. We also check if fast is not NULL, that means the number of nodes in the linked list is odd. So we move slow to the next node, since the middle node in odd linked lists does not affect being a palindrome.
6. Now, we reassign slow as NULL, and the previous value of slow to newhead {since we now need to reverse the second linked list to check for values}.
7. We reverse the linked list by saving the value of the next node in temp. Then assigning the next variable to slow, and then update slow to newhead and newhead to temp.
8. Now, we have two linked lists, which we have to compare values of to check if it's a palindrome.
9. Checking for each value, if any value is not equal, return false.
10. If all values till end are equal, return true.
*/

//CODE:
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prevslow = head;

        while(fast != NULL && fast->next != NULL) {
            prevslow = slow;
            fast = fast->next->next;
            slow = slow->next;
        }

        prevslow->next = NULL;

        if(fast) slow = slow->next;

        ListNode* newhead = slow;
        slow = NULL;

        while(newhead) {
            ListNode* temp = newhead->next;
            newhead->next = slow;
            slow = newhead;
            newhead = temp;
        }

        while(slow) {
            if(slow->val != head->val) return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(1)
