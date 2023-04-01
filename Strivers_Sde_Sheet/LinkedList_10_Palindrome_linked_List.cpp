// Solution 1 ----T.C{O(n + n + n)},  S.C{O(n)}

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

    ListNode* reverse(ListNode* head)
    {
            ListNode* prev= nullptr, *curr = head, *next = nullptr;

            while(curr!= nullptr)
            {
                    next = curr->next;
                    curr->next = prev;

                    prev= curr;
                    curr= next;
            }

            return prev;

    }
    bool isPalindrome(ListNode* head) {

        
            ListNode* newLL = new ListNode(head->val), *temp = head->next, *newtemp= newLL;

            while(temp!= nullptr)
            {
                ListNode* create = new ListNode(temp->val);
                newtemp->next = create;
                newtemp = newtemp->next;

                temp= temp->next;
                    
            }

            ListNode* reversed_LL = reverse(newLL);

            while(reversed_LL != nullptr)
            {
                    if(reversed_LL->val != head->val)
                    {
                        return false;
                    }
                    else{
                    reversed_LL= reversed_LL->next;
                    head= head->next; 
                    }
            }

        return true;


        
    }
};



//Solution 2 - optimum ----T.C{O(n/2 + n/2 + n/2)}, S.C{O(1)}



class Solution {
public:

    ListNode* reverse(ListNode* head)
    {
            ListNode* prev= nullptr, *curr = head, *next = nullptr;

            while(curr!= nullptr)
            {
                    next = curr->next;
                    curr->next = prev;

                    prev= curr;
                    curr= next;
            }

            return prev;

    }
    bool isPalindrome(ListNode* head) {

       
            ListNode* slow = head;
            ListNode* fast = head;

            while(fast!= nullptr )
            {
                    if(fast->next ==nullptr)
                    {
                        slow= slow->next;
                        break;
                    }
                    slow= slow->next;
                    fast= fast->next->next;
            }

            ListNode* half_reversed_LL = reverse(slow);

            while(half_reversed_LL != nullptr)
            {
                    if(half_reversed_LL->val != head->val)
                    {
                        return false;
                    }
                    else{
                    half_reversed_LL= half_reversed_LL->next;
                    head= head->next; 
                    }
            }

        return true;


        
    }
};
