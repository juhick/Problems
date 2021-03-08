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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return build(nums, 0, nums.size() - 1);
    }

    TreeNode* build(vector<int> nums, int left, int right){
        if(left > right) return nullptr;

        int index = -1, maxVal = INT_MIN;
        for(int i = left; i <= right; ++i){
            if(nums[i] > maxVal){
                index = i;
                maxVal = nums[i];
            }
        }

        TreeNode *root = new TreeNode(maxVal);
        root->left = build(nums, left, index - 1);
        root->right = build(nums, index + 1, right);

        return root;

    }
};