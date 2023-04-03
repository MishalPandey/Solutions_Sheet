//Solution 1

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        Node* newLL = new Node(-1), *ntemp = newLL, *temp = head;
        map<Node*, int>add_idx;
        //prev LL address with index stored
        int i=1;
        int size =0;
        while(temp != nullptr)
        {
            size++;
            add_idx[temp] = i;          
            temp= temp->next;
            i++;
        }
        temp = head;
        map<int, Node*>nadd_idx;  //new LL index  with addres stored
        i=1;
        while(temp != nullptr)
        {
            ntemp->next = new Node(temp->val);
            nadd_idx[i] = ntemp->next;
            ntemp = ntemp->next;
            temp= temp->next;
            i++;
            
        }
        temp = head;
        ntemp = newLL->next;
        while(temp != nullptr)
        {
            ntemp->random = nadd_idx[add_idx[temp->random]];
            temp= temp->next;
            ntemp= ntemp->next;
            i++;
            
        }




        return newLL->next;


        
    }
};
