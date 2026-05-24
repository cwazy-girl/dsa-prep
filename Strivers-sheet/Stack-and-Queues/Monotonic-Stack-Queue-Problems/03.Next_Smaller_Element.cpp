/*
QUESTION:-
Given an array of integers arr, your task is to find the Next Smaller Element (NSE) for every element in the array.
The Next Smaller Element for an element x is defined as the first element to the right of x that is smaller than x.
If there is no smaller element to the right, then the NSE is -1.

Example:

Input: arr = [4, 8, 5, 2, 25]
Output: [2, 5, 2, -1, -1]
Explanation:
- For 4, the next smaller element is 2.
- For 8, the next smaller element is 5.
- For 5, the next smaller element is 2.
- For 2, there is no smaller element to its right → -1.
- For 25, no smaller element exists → -1.
*/

/*
APPROACH:
1. We initialise a stack and a vector of size n to store the ans {all elements initialised to -1}.
2. While traversing through all elements of arr, while stack is not empty and the current element is lesser than the top element of the stack, we update the ans at index at the top of the stack to the current element, and then pop the stack.
3. Else, we push i into the stack.
4. Return ans.
*/

//CODE:
class Solution {
public:
    vector<int> nextSmallerElements(const vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n, -1);

        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[i] < arr[st.top()]) {
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(N)
