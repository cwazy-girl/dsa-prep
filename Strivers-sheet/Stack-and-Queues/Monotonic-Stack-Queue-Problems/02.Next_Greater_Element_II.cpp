/*
QUESTION:-
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.
The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

Example:

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.
*/

/*
APPROACH:
1. We initialise a stack and a vector of size n and all initialised to -1 {to store the ans}.
2. We need to find the greater element using circular array, hence, we will traverse the array twice.
3. So, in the for loop till 2n - 1, if stack is not empty and the current element is greater than the top element of the stack, we push that element into the ans at the position of the top element, and then pop the stack.
4. We don't want to push the same elements twice in the stack, hence, if i > n, we do not push the element. We only push when i < n. {Note that we are not exactly pushing elements but their indexes, but we can access the elements by nums[index].}
5. Return ans.
*/

//CODE:
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans (n, -1);

        for(int i = 0; i < 2 * n; i++) {
            while(!st.empty() && nums[i % n] > nums[st.top()]) {
                ans[st.top()] = nums[i % n];
                st.pop();
            }
            if(i < n) st.push(i);
        }
        return ans;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(N)
