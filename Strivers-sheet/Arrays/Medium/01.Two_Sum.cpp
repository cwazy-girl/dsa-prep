/*
QUESTION:-
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/

//BRUTE-FORCE CODE

/*
APPROACH:
We use two loops, one moves through the array, while the other checks whether the further elements result into the target sum.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i+1; j < nums.size(); j++) {
                if(nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
};

//Time Complexity : O(N^2)
//Space Complexity : O(1)

//BETTER CODE

/*
APPROACH:
1. We sorted the array and initiated two pointers.
2. One pointer was initiated from the beginning of the array and the second one from the end.
3. A loop is run to check if the sum is less than target, then start is increased to increase the sum. Similarly, end was decreased if sum is greater than target.
4. If sum is equal to the target, we save the numbers from the sorted array.
5. Now we move a loop through the initial array to check where those numbers lie, and return their indexes.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        int n = nums.size();

        vector<int>arr = nums;
        sort(arr.begin(), arr.end());

        int start = 0;
        int end = n - 1;
        int i1, i2;

        while(start < end) {
            int sum = arr[start] + arr[end];
            if(sum < target) {
                start++;
            }
            else if(sum > target) {
                end--;
            }
            else {
                i1 = arr[start];
                i2 = arr[end];
                break;
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(nums[i] == i1 || nums[i] == i2) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

//Time Complexity : O(N*logN)
//Space Complexity : O(N);

//OPTIMAL CODE

/*
APPROACH:
1. We initiate an unordered map, which would store the element, and its index.
2. Traversing through the array, we find the complement of the element in the array, and check if it matches any value previously in the map.
3. If yes, we return the index of the current element in the array, and the saved index of the complement element in the map.
4. Else, we save the current element in the map, and move ahead.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;

        for(int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if(mpp.count(complement)) {
                return {i, mpp[complement]};
            }

            mpp[nums[i]] = i;
        }
        
        return {-1, -1};
    }
};

//Time Complexity (Average case) : O(N)
//Space Complexity : O(N)
