//Solution 1--- T.C{O(n)}, S.C{O(1)}

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

Node* merge_sortedLL(Node* L1, Node* L2)
{
    
    if(L1==nullptr && L2==nullptr)
    {
        return nullptr;
    }
    else if(L1==nullptr)
    {
        return L2;
    }
    else if(L2==nullptr)
    {
        return L1;
    }
    
    Node* ans= nullptr, *temp=nullptr;
    
    while(L1 != nullptr && L2 != nullptr)
    {
        if(L1->data < L2->data)
        {
            if(ans== nullptr)
            {
                ans= L1;
                temp= L1;
                L1= L1->bottom;
            }
            else{
                temp->bottom = L1;
                temp = temp->bottom;
                L1= L1->bottom;
            }
        }
        else{
            
            if(ans== nullptr)
            {
                ans= L2;
                temp= L2;
                L2= L2->bottom;
            }
            else{
                temp->bottom = L2;
                temp = temp->bottom;
                L2= L2->bottom;
            }
            
        }
        
    }
    if(L1==nullptr && L2 != nullptr)
    {
        temp->bottom= L2;
    }
    else if(L2==nullptr && L1 != nullptr)
    {
        temp->bottom= L1;
    }
        
    return ans;
    
}
    

Node *flatten(Node *root)
{
        if(root == nullptr || root->next == nullptr)
        {
            return root;
        }
       
        root-> next = flatten(root-> next);
        
        root = merge_sortedLL(root, root-> next);
        
        
        return root;
   
   
   
}
