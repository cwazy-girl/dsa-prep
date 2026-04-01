/*
QUESTION:-
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
*/

//BRUTE-FORCE CODE:

/*
APPROACH:
1. In this approach, we find the length of the list, and then delete the [L-n+1]th node from the start.
2. To find the length of the linked list, we traverse through the list and do count++.
3. Now, we know that we have to delete the [L-n+1]th node. If that node is the head, we save head in del, move the head pointer and delete del. Return head.
4.If not, we again traverse through the list by initialising temp = head and count = 0. We keep doing count++ till the next node is the node we need to delete {i.e. count + 1 == node}.
5. If so, we save the next node in del, move temp->next to temp->next->next and then, delete del.
6. Return head.
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;

        while(temp) {
            count++;
            temp = temp->next;
        }
        int node = count - n + 1;

        if(node == 1) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        temp = head;
        count = 0;
        while(temp) {
            count++;
            if(count + 1 == node) {
                ListNode* delete_node = temp->next;
                temp->next = temp->next->next;
                delete delete_node;
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};

//Time Complexity : O(N) + O(N-n) {traversing full linked list first, then till the required node}
//Space Complexity : O(1)

//OPTIMAL CODE:

/*
APPROACH:
1. In this approach, we will use two pointers and put them at 'n' distance, so that when one pointer traverses the entire list, the other pointer points at the nth node from the end.
2. We initialise two pointers, fast and slow, both from head pointer.
3. We move the fast pointer n times ahead of the head.
4. Now, if fast has already reached NULL, that means we have to delete the head pointer. So, we save head pointer in temp, move the head pointer and delete temp. Return head.
5. Now, we move the fast pointer while fast->next != NULL, and we simultaneously move slow ahead.
6. Now, our slow points to the node just before the node to be deleted. So, we save the next node in temp, move slow->next to slow->next->next and delete temp.
7. Return head.
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }

        if(fast == NULL) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        while (fast->next != NULL) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return head;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(1)
