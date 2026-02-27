/*
Leetcode 94 - Binary Tree Inorder Traversal
Pattern: Tree / Iterative DFS / Stack

Idea:
- Inorder traversal: Left -> Root -> Right.
- Use an explicit stack to simulate recursion iteratively.
- Keep going left, pushing nodes onto stack until NULL.
- Pop from stack, record value, then move to right subtree.
- Repeat until both curr is NULL and stack is empty.

Time Complexity: O(n) 
Space Complexity: O(n)
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while(curr != NULL || !st.empty()){
            while(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }
        return res;
    }
};