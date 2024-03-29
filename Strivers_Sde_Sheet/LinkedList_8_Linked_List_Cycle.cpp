// Solution 1---> T.C{O(n)} , S.C{O(n)}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {

        if(head== nullptr)
            return false;

        set<ListNode* >s;
        int size_before=0;
        s.insert(head);
        int size_after= s.size();
        head= head->next;
        
        while(head!= nullptr && size_before != size_after)
        {
                size_before= s.size();
                s.insert(head);
                 size_after= s.size();
                head= head->next;

        }
        if(size_before == size_after && head!= nullptr)
            return true;

        return false;
        
    }
};

//Imp Solution 2 ---> optimum  T.C{O(n)} , S.C{O(1)}
class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode* slow= head;
        ListNode* fast= head;

        while(fast!= nullptr && fast->next!= nullptr)
        {
            slow= slow->next;
            fast= fast->next->next;

            if(slow== fast)
            {
                return true;
            }

        }

        return false;
    }
};
