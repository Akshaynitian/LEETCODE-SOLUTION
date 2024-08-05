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
    int findLevel(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(findLevel(root->left) ,findLevel(root->right));
    }
    void lOrder(TreeNode* root,vector<vector<int> > &ans,int level){
        if(root==NULL) return ;
        ans[level].push_back(root->val);
        lOrder(root->left,ans,level+1);
        lOrder(root->right,ans,level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int n=findLevel(root);
        vector<vector<int> > ans(n);
        // for(int i=1; i<=n; i++){
        //     vector<int> temp;
        //     ans.push_back(temp);
        // }
        lOrder(root,ans,0);
        return ans;
    }
};