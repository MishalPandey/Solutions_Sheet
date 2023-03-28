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

            if(head == nullptr)
                return nullptr;

            ListNode* prev = nullptr;
            ListNode* curr = head;
            ListNode* next = head->next;

            while(curr!= nullptr)
            {
                    next = curr->next;
                    curr->next = prev;

                    prev= curr;
                    curr= next;

                    if(next!= nullptr)
                    {
                        next= next->next;
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
