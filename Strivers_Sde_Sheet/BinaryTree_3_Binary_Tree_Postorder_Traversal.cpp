// Solution 1 (Recursive)----(T.C{O(N)} , S.C{O(height of tree)}
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

 void traversal(TreeNode* root, vector<int>&ans)
    {
        if(root== nullptr) return;

        
        traversal(root->left, ans);
        

        traversal(root->right, ans);
        //post order
        ans.push_back(root->val);


    }
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;

        traversal(root, ans);

        return ans;
        
    }
};
