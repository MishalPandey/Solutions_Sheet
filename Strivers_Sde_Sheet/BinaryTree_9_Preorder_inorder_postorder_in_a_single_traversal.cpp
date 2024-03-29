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

        //preorder
        traversal(root->left, ans);
        
         //inorder
        traversal(root->right, ans);
        //post order


    }
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;

        traversal(root, ans);

        return ans;
        
    }
};




// Solution 2 (Iterative)----(T.C{O(N)} , S.C{O(height of tree)}

 class Pair{
     public:
     int state;
     TreeNode* root;

     Pair(TreeNode* root, int state)
     {
         this->root = root;
         this->state = state;
     }
     

 };

class Solution {
public:
    void postorderTraversal(TreeNode* root) {

      
        if(root == nullptr) 
            return ;
        stack<Pair* > st;
        st.push( new Pair(root, 1));

        while(st.size()>0)
        {
                Pair* top = st.top();
                if(top->state == 1)
                {
                    //pre order
                    top->state++;
                    if(top->root->left != nullptr)
                    {
                        st.push(new Pair(top->root->left, 1));
                    }

                }
                else if(top->state == 2)
                {
                    //in order
                    top->state++;
                    if(top->root->right != nullptr)
                    {
                        st.push(new Pair(top->root->right, 1));
                    }

                }
                else{
                    //post order
                    st.pop();
                }

        }

        
    }
};
