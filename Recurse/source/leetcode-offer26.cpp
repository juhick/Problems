/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(B == NULL) return false;
        queue<TreeNode*> q;
        q.push(A);
        while(!q.empty()){
            TreeNode* first = q.front();
            q.pop();
            if(first->val == B->val){
                if(isSame(first, B))
                    return true;
            }
            if(first->left != NULL) q.push(first->left);
            if(first->right != NULL) q.push(first->right);
        }
        return false;
    }

    bool isSame(TreeNode* A, TreeNode* B){
        if(B == NULL){
            return true;
        }
        if(A == NULL){
            return false;
        }

        if(A->val != B->val) return false;
        return isSame(A->left, B->left) && isSame(A->right, B->right);
    }
};