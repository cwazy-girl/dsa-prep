/*
QUESTION:-
Given an integer array nums and a non-negative integer k, rotate the array to the left by k steps.

Example:

Input: nums = [1, 2, 3, 4, 5, 6], k = 2
Output: nums = [3, 4, 5, 6, 1, 2]
Explanation:
rotate 1 step to the left: [2, 3, 4, 5, 6, 1]
rotate 2 steps to the left: [3, 4, 5, 6, 1, 2]
*/

//BRUTE-FORCE CODE

/*
APPROACH:
Run the loop upto k times, and left-rotate array by one each time.
*/

class Solution {
public:
    void rotateArray(vector<int>& nums, int k) {
        for(int j = 1; j <= k; j++) {
            int temp = nums[0];
            for(int i = 0; i < nums.size() - 1; i++) {
                nums[i] = nums[i + 1];
            }
            nums[nums.size() - 1] = temp;
        }
    }
};

//Time Complexity : O(N*k)
//Space Complexity : O(1)

//OPTIMAL CODE

/*
APPROACH:
1. We find the remainder of k with size of the array, to find out how many times the array is rotated efficiently. (Every time it gets rotated {size of array} number of times, it becomes the same array.)
2. Now we reverse the first k elements.
3. Then, we reverse the last n-k elements.
4. Now, we reverse the entire array.
{This method helps in reversing AB type array to BA.}
*/

class Solution {
public:
    void rotateArray(vector<int>& nums, int k) {
        k = k % nums.size();

        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

//Time Complexity : O(N)
//Space Complexity : O(1)
