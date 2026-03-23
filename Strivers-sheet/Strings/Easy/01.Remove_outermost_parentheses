/*
QUESTION:-
A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.
For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.
Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.
Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

Example:

Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation: 
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".
*/

/*
APPROACH:
1. We initiate a variable start from 0.
2. Traversing through the loop, we check if the element is '('. If yes, we do start++ {since it indicates the start of a parentheses}. Else, we do start--.
3. If our start is equal to 1 and current element is '(', that means it's the primitive starting bracket. So, we do not append this in our new string.
4. If our start is equal to 0 and current element is ')', that means it's a primitive starting bracket. We do not append that too.
5. Else, we append it in the new string.
6. Return new string.
*/

//CODE:
class Solution {
public:
    string removeOuterParentheses(string s) {
        string st;
        int start = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                start++;
            }
            else if(s[i] == ')') {
                start--;
            }
            if(!((start == 1 && s[i] == '(') || (start == 0 && s[i] == ')'))) {
                st += s[i];
            }
        }
        return st;
    }
};

//Time Complexity : O(N)
//Space Compelxity : O(N)
