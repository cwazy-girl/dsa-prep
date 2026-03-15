/*
QUESTION:-
Given a sorted array nums and an integer x. Find the floor and ceil of x in nums. The floor of x is the largest element in the array which is smaller than or equal to x. The ceiling of x is the smallest element in the array greater than or equal to x. If no floor or ceil exists, output {-1, -1}.

Example:

Input : nums =[3, 4, 4, 7, 8, 10], x= 5
Output: {4, 7}
Explanation: The floor of 5 in the array is 4, and the ceiling of 5 in the array is 7.
*/

/*
APPROACH:
We find floor and ceil separately by using binary search.
*/

//CODE:
class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {
        int start = 0;
        int end = nums.size() - 1;
        int ans1 = -1;
        int ans2 = -1;

        while(start <= end) {
            int mid = start + (end - start)/2;
            if(nums[mid] > x) {
                end = mid - 1;
            }
            else if (nums[mid] <= x){
                ans1 = mid;
                start = mid + 1;
            }
        }

        start = 0;
        end = nums.size() - 1;

        while(start <= end) {
            int mid = start + (end - start)/2;
            if(nums[mid] >= x) {
                ans2 = mid;
                end = mid - 1;
            }
            else if (nums[mid] < x) {
                start = mid + 1;
            }
        }
        return {nums[ans1], nums[ans2]};
    }
};

//Time Complexity : O(logN)
//Space Complexity : O(1)
