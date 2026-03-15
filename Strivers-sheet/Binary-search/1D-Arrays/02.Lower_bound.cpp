/*
QUESTION:-
Given a sorted array of nums and an integer x, write a program to find the lower bound of x.
The lower bound algorithm finds the first and smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.
If no such index is found, return the size of the array.

Example:

Input : nums= [1,2,2,3], x = 2
Output : 1
Explanation : Index 1 is the smallest index such that arr[1] >= x.
*/

/*
APPROACH:
1. By binary search, we check if mid is less than x, we check the right side of the array.
2. Else, we check the left side of the array (including mid).
*/

//CODE:
class Solution{
public:
    int lowerBound(vector<int> &nums, int x){
        int start = 0;
        int end = nums.size() - 1;
        while(start < end) {
            int mid = start + (end - start)/2;
            if(nums[mid] < x) {
                start = mid + 1;
            }
            else {
                end = mid;
            }
        }
        return end;
    }
};

//Time Complexity : O(logN)
//Space Complexity : O(1)
