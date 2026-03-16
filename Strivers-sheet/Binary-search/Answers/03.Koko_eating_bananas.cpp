/*
QUESTION:-
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.

Example:

Input: piles = [3,6,7,11], h = 8
Output: 4
*/

/*
APPROACH:
1. We apply binary search from 1 to the max number of the array {because that would be the max number of bananas koko can eat from any pile}.
2. Now for every mid, we count the ceil division of every array element with the mid element and add them to our variable.
3. If the count is less than equal to h, that means mid can be the answer. So we save it in a variable and check the left part of the array.
4. Else, we check the right part of the array.
5. Return ans.
*/

//CODE:
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = 0;
        int ans = -1;
        for(auto i : piles) {
            end = max(i, end);
        }

        while(start <= end) {
            int mid = start + (end - start)/2;
            long long count = 0;
            for(auto i : piles) {
                count += (i + mid - 1) / mid;
            }
            if(count <= h) {
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

//Time Complexity : O(NlogM) {M being max number of bananas in any pile}
//Space Complexity : O(1)
