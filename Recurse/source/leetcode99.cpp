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
    TreeNode *pre = nullptr, *s = nullptr, *t = nullptr;
    void recoverTree(TreeNode* root) {
        traverse(root);
        int temp = s->val;
        s->val = t->val;
        t->val = temp;
    }

    void traverse(TreeNode* node){
        if(!node) return;

        traverse(node->left);

        if(pre != nullptr && node->val < pre->val){
            s = (s == nullptr)?pre:s;
            t = node;
        }
        pre = node;

        traverse(node->right);
    }
};