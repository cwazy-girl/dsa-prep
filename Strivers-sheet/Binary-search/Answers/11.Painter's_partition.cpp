/*
QUESTION:-
You are given A painters and an array C of N integers where C[i] denotes the length of the ith board. Each painter takes B units of time to paint 1 unit of board. You must assign boards to painters such that:
1. Each painter paints only contiguous segments of boards.
2. No board can be split between painters.
3. The goal is to minimize the time to paint all boards.
Return the minimum time required to paint all boards modulo 10000003.

Example:

Input: A = 2, B = 5, C = [1, 10]
Output: 50
Explanation:
Painter 1 paints board 0 (length = 1), time = 5
Painter 2 paints board 1 (length = 10), time = 50
Max time = 50
Return 50 % 10000003 = 50
*/

/*
APPROACH:
1. We first initialise a function, which checks if mid is a possible answer for the parition of painters.
2. We initialise count and initiate it from 1, because there will be a min. of 1 painter. We initialise board to check the sum of all segments of boards to be less than mid.
3. Traversing through the array, we check if adding C[i] to board will be less than or equal to mid. If yes, we add C[i] to board.
4. Else, we reinitialise board from C[i] and do count++. If count becomes more than A, we return false.
5. If the loop is broken without any return, we return true.
6. In our main function, we check if the number of elements in our array {i.e. the number of total boards} is less than the number of painters. If so, we return -1.
7. We apply binary search from the max element in the array {because thats the minimum number of time/segment of board we need, so that we can assign it to a painter} to the sum of all segments of all boards in the array.
8. If mid is a possible solution, we save it in ans, and check for a smaller mid.
9. Else, we check for a greater mid {i.e. the right part}.
10. Return ans.
*/

//CODE:
class Solution {
public:
    bool isPossible(int A, vector<int>& C, long long mid) {
        int count = 1;
        long long board = 0;

        for(int i = 0; i < C.size(); i++) {
            if(C[i] + board <= mid) {
                time += C[i];
            }
            else {
                time = C[i];
                count++;

                if(count > A) {
                    return false;
                }
            }
        }
        return true;
    }
    
    int paint(int A, int B, vector<int>& C) {
        long long start = *max_element(C.begin(), C.end());
        long long end = 0;
        long long ans = -1;
        for(auto i : C) {
            end += i;
        }

        while(start <= end) {
            long long mid = start + (end - start)/2;

            if(isPossible(A, C, mid)) {
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return (ans*B) % 10000003;
    }
};

//Time Complexity : O(Nlog(sum))
//Space Complexity : O(1)
