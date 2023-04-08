//Solution 1 --> Concept of travesal with S.C{O(1)}, T.C{O(3*n)}

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

    TreeNode* get_rightmost_node(TreeNode* node, TreeNode* curr)
    {
            while(node->right != nullptr && node->right != curr)
            {
                node= node->right;
            }

            return node;

    }
    
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int>ans;
        TreeNode *curr = root;

        while(curr != nullptr)
        {
                TreeNode *ln = curr->left; 

                if(ln != nullptr)
                {
                        ln = get_rightmost_node(ln, curr); //righmost node of left child
                        if(ln->right == nullptr)
                        {
                            //create thread
                            ln->right = curr;
                            curr = curr->left;

                        }
                        else // means ln== curr
                        {
                            //cut thread
                            ans.push_back(curr->val);
                            curr= curr->right;
                            ln->right = nullptr;

                        }

                }
                else
                {
                    ans.push_back(curr->val);
                    curr = curr->right;

                }
        }

        return ans;
    }
};
