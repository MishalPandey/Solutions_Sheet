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

// Solution 2 (Iterative)----(T.C{O(N)} , S.C{O(height of tree)}

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int>ans;
        if(root == nullptr) 
            return ans;
        stack<TreeNode* > st1, st2;
        st1.push(root);
        while(st1.size()>0)
        {
             root = st1.top();

                 st1.pop();
                 st2.push(root);

                 if(root->left != nullptr)
                 {
                     st1.push(root->left);

                 }
                 if(root->right != nullptr)
                 {
                     st1.push(root->right);

                 }

        }
        while(st2.size()>0)
        {
             ans.push_back(st2.top()->val);
             st2.pop();
        }
        
        return ans;
        
        
    }
};

// Solution 3 (optimum)----(T.C{O(N)} , S.C{O(height of tree)}

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
    vector<int> postorderTraversal(TreeNode* root) {

        vector<int>ans;
        if(root == nullptr) 
            return ans;
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
                   //pre order
                   ans.push_back(top->root->val);
                   st.pop();
              }

        }

        return ans;
        
    }
};
