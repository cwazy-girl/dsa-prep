/*
QUESTION:-
Given two sorted arrays nums1 and nums2, return an array that contains the union of these two arrays. The elements in the union must be in ascending order.

Example:

Input: nums1 = [3, 4, 6, 7, 9, 9], nums2 = [1, 5, 7, 8, 8]
Output: [1, 3, 4, 5, 6, 7, 8, 9]
Explanation: The element 7 is common to both, 3, 4, 6, 9 are from nums1 and 1, 5, 8 is from nums2.
*/

/*
APPROACH:
1. We initiate two pointers for each of the arrays.
2. In a while loop limiting the pointers, we check which element is lesser and push it into the array.
3. We also need to check if the previous element we added does not overlap with the next element.
4. After the loop ends, one of the arrays is fully traversed.
5. We add two more while loops to traverse through the remaining array and add the elements to the "ans" array.
6. Return ans.
*/

//CODE:
class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        int i = 0;
        int j = 0;

        while(i < nums1.size() && j < nums2.size()) {

            if(nums1[i] < nums2[j]) {
                if(ans.size() == 0 || ans.back() != nums1[i])
                    ans.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i] > nums2[j]) {
                if(ans.size() == 0 || ans.back() != nums2[j])
                    ans.push_back(nums2[j]);
                j++;
            }
            else {
                if(ans.size() == 0 || ans.back() != nums1[i])
                    ans.push_back(nums1[i]);
                i++;
                j++;
            }
        }

        while(i < nums1.size()) {
            if(ans.size() == 0 || ans.back() != nums1[i])
                ans.push_back(nums1[i]);
            i++;
        }

        while(j < nums2.size()) {
            if(ans.size() == 0 || ans.back() != nums2[j])
                ans.push_back(nums2[j]);
            j++;
        }

        return ans;
    }
};

//Time Complexity : O(n+m) {We traverse through both the arrays of length n and m}
//Space Complexity : O(n+m) {Array initiated of the length n+m}
