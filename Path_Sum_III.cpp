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
    void dfs(TreeNode* root,int sum,int curr,int &res){
        if(root){
            curr+=root->val;
            if(curr==sum)
                res++;
        
            dfs(root->left,sum,curr,res);
            dfs(root->right,sum,curr,res);
        }
    }
    void find(TreeNode* root,int sum, int &res){
        if(root){
            dfs(root,sum,0,res);
            find(root->left,sum,res);
            find(root->right,sum,res);
        }
    }
    int pathSum(TreeNode* root, int sum) {
        int res=0;
        find(root,sum,res);
        return res;
    }
};
