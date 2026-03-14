/*
QUESTION:-
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example:

Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/

//BETTER CODE

/*
APPROACH:
1. We initate an unordered map, which maps the element and the frequency with which it occurs.
2. As we iterate through the array, we keep adding the frequency to the mapped element.
3. As soon as any frequency reaches over n/2, we return the iterator.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int n = nums.size();

        for(auto i : nums) {
            mpp[i]++;
            if(mpp[i] > (n/2)) {
            return i;
            }
        }
        return -1;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(N)

//SPACE-OPTIMAL CODE

/*
APPROACH:
1. We initialise two variables, element and count.
2. While iterating through the array, if count = 0, we update element by the current element.
3. If the current element is equal to the element variable, we do count++, else, count--.
4. At the end, only that element will be left in the element variable, which was in the majority in the array.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int element = 0;
        int count = 0;
        for(auto i : nums) {
            if(count == 0) {
                element = i;
            }
            if(i == element) {
                count++;
            }
            else {
                count--;
            }
        }
        return element;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(1)
