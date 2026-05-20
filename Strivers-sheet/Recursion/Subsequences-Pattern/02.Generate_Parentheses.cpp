/*
QUESTION:-
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
*/

/*
APPROACH:
1. We create a new function generate with arguments : int n, string curr, open bracket number, close bracker number, and answer string.
2. If length of curr has reached 2 * n, we push curr in ans, and return.
3. If open brackets = close brackets, that means we can only add an open bracket. So, push '(' in curr, and call the function recursively with open + 1.
4. If open brackets = n, that means we no longer can add open brackets. So, push ')' in curr, and call the function recursively with close + 1.
5. Else, we can add both close and open brackets. So, push '(' and call the function recursively with open + 1. Then pop curr and push ')', and call the function recursively with close + 1.
6. Return.
7. Now, in our original function, we create answer vector.
8. Now we call generate function with arguments : n, open = 0, close = 0, ans.
9. Return ans.
*/

//CODE:
class Solution {
public:
    void generate(int n, string curr, int open, int close, vector<string> &ans) {
        if(curr.length() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        if(open == close) {
            curr.push_back('(');
            generate(n, curr, open + 1, close, ans);
        }
        else if (open == n) {
            curr.push_back(')');
            generate(n, curr, open, close + 1, ans);
        }
        else {
            curr.push_back('(');
            generate(n, curr, open + 1, close, ans);
            curr.pop_back();
            curr.push_back(')');
            generate(n, curr, open, close + 1, ans);
        }
        return;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(n, "", 0, 0, ans);
        return ans;
    }
};

//Time Complexity : O(N * 2^N) {loose upper bound, since our function does not go through all possibilities of parantheses arrangements}
//Space Complexity : O(N) {recursion stack}
