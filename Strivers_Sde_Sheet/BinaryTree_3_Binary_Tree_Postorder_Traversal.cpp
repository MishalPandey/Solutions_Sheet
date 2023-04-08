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
                   //post order
                   ans.push_back(top->root->val);
                   st.pop();
              }

        }

        return ans;
        
    }
};


//Solution 4 --> most optimal----(Morris Postorder Traversal) S.C{O(1)}, T.C{O(3*n)}
class Solution {
public:

    TreeNode* get_rightmost_node(TreeNode* node, TreeNode* curr)
    {
            while(node->left != nullptr && node->left != curr)
            {
                node= node->left;
            }

            return node;

    }

    vector<int> postorderTraversal(TreeNode* root) {

        vector<int>ans;
        TreeNode *curr = root;

        while(curr != nullptr)
        {
                TreeNode *ln = curr->right; 

                if(ln != nullptr)
                {
                        ln = get_rightmost_node(ln, curr); //righmost node of right child
                        if(ln->left == nullptr)
                        {
                            //create thread
                            ans.push_back(curr->val);
                            ln->left = curr;
                            curr = curr->right;

                        }
                        else // means ln== curr
                        {
                            //cut thread
                            curr= curr->left;
                            ln->left = nullptr;

                        }

                }
                else
                {
                    ans.push_back(curr->val);
                    curr = curr->left;

                }
                
        }
        reverse(ans.begin(), ans.end());

                
        return ans;
        
    }
};
