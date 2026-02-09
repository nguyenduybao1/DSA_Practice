/*
Leetcode 88 - Merge Sorted Array
Pattern: Two Pointers

Idea:
- nums1 has enough space to hold all elements (size = m + n).
- Use three pointers:
  - i: last valid element in nums1 (m - 1)
  - j: last element in nums2 (n - 1)
  - k: last index of nums1 (m + n - 1)
- Compare nums1[i] and nums2[j] from the back:
  - Place the larger value at nums1[k].
  - Move pointers accordingly.
- If nums2 still has remaining elements, copy them.

Time Complexity: O(m + n)
Space Complexity: O(1)
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; 
        int j = n - 1; 
        int k = m + n - 1;
        
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};
