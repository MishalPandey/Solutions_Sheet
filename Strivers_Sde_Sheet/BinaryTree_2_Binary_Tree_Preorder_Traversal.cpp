//Solution 1--(Recursive)----T.C{O(N)} , S.C{O(height of tree)}


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
    void traversal(TreeNode* root, vector<int>&ans)
    {
        if(root== nullptr) return;

        //pre order
        ans.push_back(root->val);
        traversal(root->left, ans);
        

        traversal(root->right, ans);


    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;

        traversal(root, ans);

        return ans;
        
    }
};

//Solution 2--(Iterative)----T.C{O(N)} , S.C{O(height of tree)}

class Solution {
public:
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root == nullptr) 
            return ans;
        stack<TreeNode* > st;
        st.push(root);
        while(st.size()>0)
        {
            root = st.top();
           
                ans.push_back(root->val);
                st.pop();
                if(root->right != nullptr)
                {
                    st.push(root->right);

                }
                if(root->left != nullptr)
                {
                    st.push(root->left);

                }
                
            

            
        }

        return ans;
        
    }
};


//Solution 3--optimum----T.C{O(N)} , S.C{O(height of tree)}

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
    
    vector<int> preorderTraversal(TreeNode* root) {
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
                      ans.push_back(top->root->val);
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

        return ans;
        
    }
};

//Solution 4 --> most optimal----(Morris Preorder Traversal) S.C{O(1)}, T.C{O(3*n)}


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

    
        vector<int> preorderTraversal(TreeNode* root) {

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
                                    ans.push_back(curr->val);
                                    ln->right = curr;
                                    curr = curr->left;

                                }
                                else // means ln== curr
                                {
                                    //cut thread
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


    
