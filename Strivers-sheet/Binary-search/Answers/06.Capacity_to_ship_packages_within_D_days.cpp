/*
QUESTION:-
A conveyor belt has packages that must be shipped from one port to another within days days.
The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

Example:

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10
Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
*/

/*
APPROACH:
1. We apply binary search from the max element in the array to the sum of all elements {because the minimum weight that should be allowed is the maximum of the array, and the maximum will be when all days weight is added and sent in a single day}.
2. We initiate two variables, sum and numday.
3. For all elements in the array, we check if adding the current element will be less than or equal to mid. If yes, then we add i to sum.
3. Else, we reinitiate sum from i {current element} and increase numday to +1.
4. Now, if the total numdays are less than or equal to [days], we save mid to ans, and then check the left part of the array.
5. Else, check the right side of the array.
6. Return ans.
*/

//CODE:
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(), weights.end());
        int end = 0;
        for(auto i : weights) {
            end += i;
        }
        int ans = -1;

        while(start <= end) {
            int mid = start + (end - start)/2;
            int sum = 0;
            int numday = 1;

            for(auto i : weights) {
                if(sum + i <= mid) {
                    sum += i;
                }
                else {
                    sum = i;
                    numday++;
                }
            }
            if(numday <= days) {
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return ans;
    }
};

//Time Complexity : O(N * log(sum-of-elements))
//Space Complexity : O(1)
