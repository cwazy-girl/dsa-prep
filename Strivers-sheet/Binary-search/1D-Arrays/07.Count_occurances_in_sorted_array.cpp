/*
QUESTION:-
You are given a sorted array of integers arr and an integer target. Your task is to determine how many times target appears in arr.
Return the count of occurrences of target in the array.

Example:

Input: arr = [0, 0, 1, 1, 1, 2, 3], target = 1
Output: 3
Explanation: The number 1 appears 3 times in the array.
*/

/*
APPROACH:
1. Apply binary search to find the first and last occurance.
2. Return last - first + 1
*/

//CODE:
class Solution {
public:
    int countOccurrences(const vector<int>& arr, int target) {
        int first = -1;
        int last = -1;
        int start = 0;
        int end = arr.size() - 1;
        
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(arr[mid] > target) {
                end = mid - 1;
            }
            else if (arr[mid] < target) {
                start = mid + 1;
            }
            else {
                first = mid;
                end = mid - 1;
            }
        }
        start = 0;
        end = arr.size() - 1;
        while(start <= end) {
            int mid = start + (end-start)/2;
            if(arr[mid] > target) {
                end = mid - 1;
            }
            else if (arr[mid] < target) {
                start = mid + 1;
            }
            else {
                last = mid;
                start = mid + 1;
            }
        }
        if(first == -1) {
            return 0;
        }

        return last - first + 1;
    }
};

//Time Complexity : O(logN)
//Space Complexity : O(1)
