/*
Leetcode 104 - Maximum Depth of Binary Tree
Pattern: Tree / Recursive DFS

Idea:
- Use DFS recursively to find the depth of left and right subtrees.
- Base case: if root is NULL, return 0.
- At each node, depth = 1 + max(leftDepth, rightDepth).
- The recursion naturally bubbles up the maximum depth to the root.

Time Complexity: O(n)
Space Complexity: O(h) - h is height of tree, O(log n) balanced / O(n) skewed
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return 1 + max(left,right);
    }
};