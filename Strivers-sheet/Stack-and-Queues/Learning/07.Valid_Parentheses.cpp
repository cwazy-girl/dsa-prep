/*
QUESTION:-
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

Example:

Input: s = "([])"
Output: true

Input: s = "([)]"
Output: false
*/

/*
APPROACH:
1. We create a character stack st. We use the idea that for every bracket, if it's closing counterpart appears, it's opening counterpart must be at the top of the stack and then, we pop it out and continue.
2. For all characters of string, if they are opening brackets, we push them in stack.
3. Else, if closing brackets appear but stack is empty, return false.
4. We first save the top element of the stack, and then pop it out.
5. Then, if that character is not the opening counterpart of the string character, return false.
6. At the end, stack must be empty. Hence, return st.empty().
*/

//CODE:
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c : s) {

            if(c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {
                if(st.empty()) return false;

                char top = st.top();
                st.pop();

                if((c == ')' && top != '(') ||
                   (c == '}' && top != '{') ||
                   (c == ']' && top != '[')) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

//Time Complexity : O(N) {all characters are visited once}
//Space Complexity : O(N) {stack}
