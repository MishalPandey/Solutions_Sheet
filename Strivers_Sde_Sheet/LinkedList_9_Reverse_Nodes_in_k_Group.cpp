//Solution 1 --T.C{O(n)}, S.C{O(length of LL/k)}
// By recursion

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


    
    ListNode* reverseKGroup(ListNode* head, int k) {

         int length =k;
         ListNode* first= head;
         while(first!= nullptr && length--)
         {
             first= first->next;
         }
         if(first==nullptr && length)
         {
             return head;

         }

         ListNode* smallans = reverseKGroup(first,k);

              ListNode* prev = nullptr;
              ListNode* curr = head;
              ListNode* next = head->next;
              length= k;
              while(length--)
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

        head->next= smallans;

        
        return prev;   


        
    }
};
