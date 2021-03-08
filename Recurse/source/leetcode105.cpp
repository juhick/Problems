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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* build(vector<int> preorder, int preStart, int preEnd, vector<int> inorder, int inStart, int inEnd){
        if(preStart > preEnd)
            return nullptr;

        int rootVal = preorder[preStart];

        int index = 0;
        for(int i = inStart; i <= inEnd; ++i){
            if(inorder[i] == rootVal){
                index = i;
                break;
            }
        }

        int leftSize = index - inStart;
        TreeNode* root = new TreeNode(rootVal);

        root->left = build(preorder, preStart + 1, preStart + leftSize, inorder, inStart, index - 1);
        root->right = build(preorder, preStart + leftSize + 1, preEnd, inorder, index + 1, inEnd);

        return root;
    }
};