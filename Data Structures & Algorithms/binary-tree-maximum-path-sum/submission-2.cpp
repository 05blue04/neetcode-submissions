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

    int maxSum(TreeNode* root, int& maxi){
        if(root == nullptr)
            return 0;
        
        int l = max(0,maxSum(root->left,maxi));
        int r = max(0,maxSum(root->right,maxi));

        int sum = root->val + l + r;
        if(sum > maxi)
            maxi = sum;
        
        return root->val + max(l,r);
    }
    int maxPathSum(TreeNode* root) {

        int res = INT_MIN;
        maxSum(root, res);

        return res;

    }
};
