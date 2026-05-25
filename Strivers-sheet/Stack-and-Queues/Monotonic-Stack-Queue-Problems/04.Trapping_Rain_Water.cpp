/*
QUESTION:-
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example:

Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
*/

/*
APPROACH:
1. We initialise a stack, an index variable, and water variable to store the trapped water.
2. Traversing through the array, if stack is not empty and height of current bar is greater than height of bar at top of stack, then we call the top bar as middle and pop the stack. Then, we call the now top bar as left and the width is i - left - 1.
3. If the stack was empty in between itself, break the loop.
4. Now, h {height of the trapped water} will be minimum of height of current bar and height of left bar, subtracted by height of middle bar. The final trapped water will be h * width.
5. Then, we push the element, regardless of the conditions.
6. Return water at the end of the loop.
*/

//CODE:
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        stack<int> st;

        int i = 0;
        int water = 0; 

        for(int i = 0; i < n; i++) {
            while(!st.empty() && height[i] > height[st.top()]) {
                int middle = st.top();
                st.pop();

                if(st.empty()) break;

                int left = st.top();
                int width = i - left - 1;

                int h = min(height[i], height[left]) - height[middle];
                water += h * width;
            }
            st.push(i);
        }
        return water;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(N)
