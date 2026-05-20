/*
QUESTION:-
Given an integer n, return all binary strings of length n that do not contain consecutive 1s. Return the result in lexicographically increasing order.
A binary string is a string consisting only of characters '0' and '1'.

Example:

Input: n = 3
Output: ["000", "001", "010", "100", "101"]
Explanation: All strings are of length 3 and do not contain consecutive 1s.
*/

/*
APPROACH:
1. We create a new function solve with arguments : int n, string curr, and ans vector.
2. We create a variable len to save the length of curr.
3. If length of string has reached n, we push curr into ans, and return.
4. If the curr string is still empty, we push 0 and recursively call the function. And then, we pop 0 and push 1, and recursively call the function.
5. Else if the last element of curr is 1, we push 0 and recursively call the function.
6. Else if the last element of curr is 0, we push 0 and recursively call the function. And then, we pop 0 and push 1, and recursively call the function.
7. Now, in the original function, we create an answer vector, and call the solve function.
8. Return ans.
*/

//CODE:
class Solution {
public:
    void solve(int n, string curr, vector<string>& ans) {
        int len = curr.length();

        if(len == n) {
            ans.push_back(curr);
            return;
        }

        if(len == 0) {
            curr.push_back('0');
            solve(n, curr, ans);
            curr.pop_back();
            curr.push_back('1');
            solve(n, curr, ans);
        }
        else if(curr[len - 1] == '1') {
            curr.push_back('0');
            solve(n, curr, ans);
        }
        else {
            curr.push_back('0');
            solve(n, curr, ans);
            curr.pop_back();
            curr.push_back('1');
            solve(n, curr, ans);
        }
        return;
    }
    
    vector<string> generateBinaryStrings(int n) {
        vector<string> ans;
        solve(n, "", ans);
        return ans;
    }
};

//Time Complexity : O(number of valid strings * N)
//Space Complexity : O(N) {recursion stack}
