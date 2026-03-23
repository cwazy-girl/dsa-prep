/*
QUESTION:-
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

Example:

Input: s = "egg", t = "add"
Output: true
Explanation:
The strings s and t can be made identical by:
Mapping 'e' to 'a'.
Mapping 'g' to 'd'.
*/

/*
APPROACH:
1. We initiate two vectors of length 256 to store the index value of the last occured element, on the ASCII value of that element.
2. If any of the element's last occured is not the same ith position, then return false.
3. If all elements in both strings, last position of ith element is same, return true.
*/

//CODE:
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int>s1(256, -1);
        vector<int>t1(256, -1);

        for(int i = 0; i < s.length(); i++) {
            if(s1[s[i]] != t1[t[i]]) return false;

            s1[s[i]] = i;
            t1[t[i]] = i;
        }
        return true;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(1)
