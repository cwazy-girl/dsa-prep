/*
QUESTION:-
You are given an integer array bloomDay, an integer m and an integer k.
You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

Example:

Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
Output: 12
Explanation: We need 2 bouquets each should have 3 flowers.
Here is the garden after the 7 and 12 days:
After day 7: [x, x, x, x, _, x, x]
We can make one bouquet of the first three flowers that bloomed. We cannot make another bouquet from the last three flowers that bloomed because they are not adjacent.
After day 12: [x, x, x, x, x, x, x]
It is obvious that we can make two bouquets in different ways.
*/

/*
APPROACH:
1. We first check if [number of bouquets * number of flowers in each] is greater than the total number of elements in array {representing total number of flowers}, we return -1.
2. We use binary search from the minimum day in the array to the maximum day {because that will be the range of answers}.
3. Now, for all elements in the array, if the day is less than or equal to mid, that means the flower has already bloomed. So we do flowers++.
4. If not, then we intiate flowers from 0 again, because we need continuous k flowers.
5. If flowers reach k, we do bouquet++ and initiate flowers from 0 again.
6. Out of the for loop, we check if bouquets are greater than or equal to m, we save mid to ans, and check the left side of the array.
7. Else, we check the right side of the array.
8. Return ans.
*/

//CODE:
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start = *min_element(bloomDay.begin(), bloomDay.end());
        int end = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        if((long long)m * k > bloomDay.size()) return -1;

        while(start <= end) {
            int mid = start + (end - start)/2;
            int flowers = 0;
            int bouquet = 0;

            for(int i = 0; i < bloomDay.size(); i++) {
                if(bloomDay[i] <= mid) {
                    flowers++;
                }
                else {
                    flowers = 0;
                }
                if(flowers == k) {
                    bouquet++;
                    flowers = 0;
                }
            }
            if(bouquet >= m) {
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

//Time Complexity : O(Nlog(maxday - minday))
//Space Complexity : O(1)
