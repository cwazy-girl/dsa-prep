/*
QUESTION:-
Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.
Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

Example:

Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
*/

/*
APPROACH:
1. Initiate a variable from the last element in the string.
2. Traversing through the string backwards, while an element is ' ', we decrease i {since we don't want to print extra spaces}.
3. If i becomes less than 0, we break the loop {because the string is already fully traversed}.
4. When the spaces end, we store the value of i {which stores the last index of the word we want to print} in a new variable.
5. Now, we decrease i again till the elements are not ' '.
6. Now, our index i + 1 to j indicate a full word from the string.
7. If the array is not empty, we add a space in front of the last word added.
8. From i + 1 to j, we add the word to the string.
9. Return ans.
*/

//CODE:
class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int i = s.length() - 1;

        while(i >= 0) {
            while(i >= 0 && s[i] == ' ') i--;
            if (i < 0) break;
            int end = i;
            while(i >= 0 && s[i] != ' ') i--;

            if(!ans.empty()) ans += ' ';

            for(int x = i + 1; x <= end; x++) {
                ans += s[x];
            }
        }
        return ans;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(N)
