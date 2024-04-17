// Daily 17.4.2024
// 988. Smallest String Starting From Leaf
// https://leetcode.com/problems/smallest-string-starting-from-leaf/submissions/1234742888

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
    void traverseDown(TreeNode* node, string& result, string acc){
        acc.push_back(97+node->val);
        if(!(node->left || node->right)){
            reverse(acc.begin(), acc.end());
            if(acc<result || result.empty()) result = acc;
        }
        else{
            if(node->left) traverseDown(node->left, result, acc);
            if(node->right) traverseDown(node->right, result, acc);
        }
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        string res;
        traverseDown(root, res, "");
        return res;
    }
};