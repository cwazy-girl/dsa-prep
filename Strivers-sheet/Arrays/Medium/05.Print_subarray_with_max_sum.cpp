/*
QUESTION:-
Given an integer array nums, find the subarray with the largest sum and return all elements of the subarray.

Example:

Input: nums = [2, 3, 5, -2, 7, -4]
Output: [2, 3, 5, -2, 7]
Explanation: The subarray from index 0 to index 4 has the largest sum = 15, which is the maximum sum of any contiguous subarray.
*/

/*
APPROACH:
1. We initialise sum and maxsum to compare previous sums with current sum, and we initialise start, end variable to save the final indices of the result subarray. We initialise tempstart to save the temperory start of any subarray.
2. Traversing through the array, we keep adding elements and take out max of the current sum and the previous maxsum.
3. If the new sum is greater than the previous maxsum, we assign start with the tempstart value, and the end with the current element index.
4. If sum becomes less than 0, it will only decrease the further sums. So, we initialise sum with 0 again. And assign new value of tempstart, that is the next index than the current element, which is making the sum negative.
5. Finally, we have the first index of the subarray in start, and the last index in end.
6. Traversing from start to end, we pushback elements in out result array.
7. Return result.
*/

//CODE
vector<int> printSubarray(vector<int> nums) {
    vector<int> result;
    int sum = 0;
    int maxsum = INT_MIN;
    int start = 0;
    int end = 0;
    int tempstart = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (maxsum < sum) {
            start = tempstart;
            end = i;
        }
        maxsum = max(maxsum, sum);

        if (sum < 0) {
            sum = 0;
            tempstart = i + 1;
        }
    }
    for (int i = start; i <= end; i++) {
        result.push_back(nums[i]);
    }
    return result;
}

//Time Complexity : O(N)
//Space Complexity : O(1)
