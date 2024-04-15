// Leetcode daily 15.4.2024
// 129. Sum Root to Leaf Numbers
// https://leetcode.com/problems/sum-root-to-leaf-numbers/submissions/1233075556/

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
    int sumNumbers(TreeNode* root, int carry=0) {
        if(root == NULL) return 0;
        if(!(root->left || root->right)) return carry + root->val;
        int newCarry = (carry + root->val) * 10;
        return sumNumbers(root->left, newCarry) + sumNumbers(root->right, newCarry);
        
    }
};