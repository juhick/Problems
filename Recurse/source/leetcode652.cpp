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
    unordered_map<string, int> map; 
    vector<TreeNode*> res;
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traverse(root);
        reverse(res.begin(), res.end());
        return res;
    }

    string traverse(TreeNode *root){
        if(root == nullptr){
            return "#";
        }

        string left = traverse(root->left);
        string right = traverse(root->right);

        string subTree = left + "," + right + "," + to_string(root->val);
        int freq = map[subTree];
        if(freq == 1){
            res.push_back(root);
        }
        map[subTree]++;
        return subTree;
    }
    
};