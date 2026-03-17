/*
QUESTION:-
Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
Return the kth positive integer that is missing from this array.

Example:

Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
*/

/*
APPROACH:
1. We use binary search from 0 to the last index in the array.
2. Now, we know that the number of elements missing in the array till the mid point would be the [element at the mid position - (mid+1)].
3. Now, if the missing number of elements is greater than or equal to k, that means we need to check for the left side of the array {i.e. lower elements}.
4. Else, check the right side of the array.
5. We return start + k {because if the array was empty, k would be the kth missing number. But since, just when missing >= k, there are [start] numbers before kth missing number. So, we increase k by [start]. So, kth missing number is given by [start + k]}.
*/

//CODE:
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start = 0;
        int end = arr.size() - 1;

        while(start <= end) {
            int mid = start + (end - start)/2;
            int missing = arr[mid] - (mid + 1);

            if(missing >= k) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return start + k;
    }
};

//Time Complexity : O(logN)
//Space Complexity : O(1)
