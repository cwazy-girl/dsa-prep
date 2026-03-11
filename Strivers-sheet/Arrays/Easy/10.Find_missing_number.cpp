/*
QUESTION:-
Given an integer array of size n containing distinct values in the range from 0 to n (inclusive), return the only number missing from the array within this range.

Example:

Input: nums = [0, 1, 2, 4, 5, 6]
Output: 3
Explanation: nums contains 0, 1, 2, 4, 5, 6 thus leaving 3 as the only missing number in the range [0, 6].
*/

//BRUTE-FORCE CODE

/*
APPROACH:
1. Initialise two pointers.
2. One pointer will traverse through the array, and as soon as any element match with "j", we increase j by 1, and reinitialise i by 0.
3. Whenever any i will will exceed the while loop condition, we return j {since it is not there throughout the array}.
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int j = 0;
        int i = 0;
        while(i < nums.size()) {
            if(nums[i] == j) {
                j++;
                i = 0;
            }
            else {
                i++;
            }
        }
        return j;
    }
};

//Time Complexity : O(N^2)
//Space Complexity : O(1)

//OPTIMAL CODE:

/*
APPROACH:
1. Initialise a variable "ans".
2. Traversing numbers from 0 to array size and xor-ing all and saving them in ans.
3. Traversing through the array, we xor all elements of the array with ans.
4. This will result in cancelling out of all common elements in the two and return the missing number.
5. Return ans.
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i <= nums.size(); i++) {
            ans = ans ^ i;
        }
        for(int i = 0; i < nums.size(); i++) {
            ans = ans ^ nums[i];
        }
        return ans;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(1)
