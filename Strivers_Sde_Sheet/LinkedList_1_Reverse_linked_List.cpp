//Solution 1-->  Iterative
//T.C{O(n)}, S.C[O(1)}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        
        if(head==nullptr)
        {
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr= head;
        ListNode* nexxtt= curr->next;

        while(curr!=nullptr)
        {
            nexxtt=curr->next;
           
            curr->next = prev;

            prev= curr;
            curr= nexxtt;
            if(nexxtt!=nullptr)
            {
                nexxtt= nexxtt->next;

            }
            
            
        }

        return prev;

        
    }
};




//Solution 2-- Recursive
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if(head==NULL || head->next==NULL)
       {
            return head;
       }


        ListNode * Smallans = reverseList(head->next);
        ListNode * tail= head->next ;
        tail->next= head;
        head->next= NULL;

        return Smallans;
        
    }
};
