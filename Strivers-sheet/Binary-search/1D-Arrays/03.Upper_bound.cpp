/*
QUESTION:-
Given a sorted array of nums and an integer x, write a program to find the upper bound of x.
The upper bound of x is defined as the smallest index i such that nums[i] > x.
If no such index is found, return the size of the array.

Example:

Input : n= 4, nums = [1,2,2,3], x = 2
Output:3
Explanation: Index 3 is the smallest index such that arr[3] > x.
*/

/*
APPROACH:
Similar binary search
*/

//CODE:
class Solution{
public:
    int upperBound(vector<int> &nums, int x){
        int start = 0;
        int end = nums.size() - 1;
        while(start < end) {
            int mid = start + (end - start)/2;
            if(nums[mid] > x) {
                end = mid;
            }
            else {
                start = mid + 1;
            }
        }
        return end;
    }
};

//Time Complexity : O(logN)
//Space Complexity : O(1)
