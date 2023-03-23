// Solution 1---> T.C{O(n+n)}, S.C{O(1)}
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int size=0;
        ListNode* temp = head;
        while(temp!= nullptr)
        {
            size++;
            temp= temp->next;
        }
        int nth_removed_from_end= size- n;
        temp = head;

        if(nth_removed_from_end== 0)
        {
            head = head->next;
            delete temp;
            return head;
        }
    
        while(--nth_removed_from_end)
        {
            temp= temp->next;
        }
        ListNode* Find= temp->next;
        temp->next= temp->next->next;
        delete Find;

        return head;
        
    }
};

// Solution 1---> Optimum  T.C{O(n)}, S.C{O(1)} 

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode * start = new ListNode();
        start -> next = head;
        ListNode* fast = start;
        ListNode* slow = start;     

        for(int i = 1; i <= n; ++i)
            fast = fast->next;
    
        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return start->next;
    }
};
