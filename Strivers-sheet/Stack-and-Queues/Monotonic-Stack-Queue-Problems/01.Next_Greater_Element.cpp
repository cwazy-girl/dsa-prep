/*
QUESTION:-
The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.
You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.
For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.
Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

Example:

Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]
Explanation: The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
*/

/*
APPROACH:
1. We initialise an ans vector, a stack, and an unordered map {to map greater value for all elements}.
2. For all elements of nums2, if stack is empty and the element is greater than top element of stack, that means it is the next greater element for that element. So, map the element in the unordered map and pop it.
3. Now, if the next element is smaller, we simply push that into the stack.
4. If at the end, stack is still not empty, we pop all elements and map them with -1.
5. Then, for all values in nums2, we push mpp[num] into ans. Return ans.
*/

//CODE:
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> st;
        unordered_map<int, int> mpp;

        for(int num : nums2) {
            while(!st.empty() && num > st.top()) {
                mpp[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        while(!st.empty()) {
            mpp[st.top()] = -1;
            st.pop();
        }

        for(int num : nums1) {
            ans.push_back(mpp[num]);
        }

        return ans;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(N)
