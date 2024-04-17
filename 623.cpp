// Daily 16.4.2024
// 623. Add One Row to Tree
// https://leetcode.com/problems/add-one-row-to-tree/submissions/1233853083/

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
private:
    void findDepth(TreeNode* node, int val, int depth){
        if(depth == 0){
            TreeNode* newLeft = new TreeNode(val);
            TreeNode* newRight = new TreeNode(val);
            
            if(node){
                TreeNode* tempLeft = node->left;
                TreeNode* tempRight = node->right;
                newLeft->left = tempLeft;
                newRight->right = tempRight;
            }
            node->left = newLeft;
            node->right = newRight;

        }
        else{
            if(node->left) findDepth(node->left, val, depth-1);
            if(node->right) findDepth(node->right, val, depth-1);
        }
    }
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        else findDepth(root, val, depth-2);
        return root;
    }
};