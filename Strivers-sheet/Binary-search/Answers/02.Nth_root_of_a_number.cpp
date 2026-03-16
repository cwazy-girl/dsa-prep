/*
QUESTION:-
Given two numbers N and M, find the Nth root of M. The Nth root of a number M is defined as a number X such that when X is raised to the power of N, it equals M. If the Nth root is not an integer, return -1.

Example:

Input: N = 4, M = 69
Output:-1
Explanation: The 4th root of 69 does not exist. So, the answer is -1.
*/

/*
APPROACH:
Using binary search, we find a number from 0 to M, which multipled N times would result into M.
*/

//CODE:
class Solution {
public:
  int NthRoot(int N, int M) {
        int start = 0;
        int end = M;

        while(start <= end) {
            int mid = start + (end - mid)/2;
            if(pow(mid, N) == M) {
                return mid;
            }
            else if(pow(mid, N) < M) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return -1;
    }
};

//Time Complexity : O(logN)
//Space Complexity : O(1)
