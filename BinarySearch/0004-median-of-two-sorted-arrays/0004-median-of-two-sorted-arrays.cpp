/*
Leetcode 4 - Median of Two Sorted Arrays
Pattern: Binary Search on Partition

Idea:
- Ensure nums1 is the smaller array to binary search on it.
- Partition both arrays into left and right halves.
- Ensure left partition has (m + n + 1) / 2 elements.

- Let i be partition in nums1, then:
    j = (m + n + 1) / 2 - i

- Define:
    maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1]
    minRight1 = (i == m) ? INT_MAX : nums1[i]
    maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1]
    minRight2 = (j == n) ? INT_MAX : nums2[j]

- Valid partition when:
    maxLeft1 <= minRight2 && maxLeft2 <= minRight1

- If valid:
    - Odd total → median = max(maxLeft1, maxLeft2)
    - Even total → median = (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2

- If maxLeft1 > minRight2 → move left
- Else → move right

Time Complexity: O(log(min(m, n)))
Space Complexity: O(1)
*/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

    int m = nums1.size(), n = nums2.size();
    int left = 0, right = m;

    while (left <= right) {
        int i = (left + right) / 2;
        int j = (m + n + 1) / 2 - i;

        int maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1];
        int minRight1 = (i == m) ? INT_MAX : nums1[i];

        int maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1];
        int minRight2 = (j == n) ? INT_MAX : nums2[j];

        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            if ((m + n) % 2 == 0) {
                return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
            } else {
                return max(maxLeft1, maxLeft2);
            }
        }
        else if (maxLeft1 > minRight2) {
            right = i - 1;
        } else {
            left = i + 1;
        }
    }

    return 0.0;
    }
};