//Solution 1 --- //T.C{O(n)}, S.C{O(n)}
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
   
    ListNode *detectCycle(ListNode *head) {

        ListNode* temp = head;
        set<ListNode* > s;
        while(temp!= nullptr)
        {
            if(s.find(temp) != s.end())
            {
                return temp;
            }
            s.insert(temp);
            temp= temp->next;

        }
        return nullptr;
    
        
    }
};


//Solution 2 optimum------//T.C{O(n)}, S.C{O(1)}

class Solution {
public:
    
    ListNode *detectCycle(ListNode *head) {
        if(head==nullptr || head->next == nullptr) return nullptr;

        ListNode* slow= head;
        ListNode* fast= head;

        while(fast!= nullptr && fast->next!= nullptr)
        {
            slow= slow->next;
            fast= fast->next->next;

            if(slow== fast)
            {
                break;
            }

        }

        if(slow != fast) return nullptr;

        ListNode* entry= head;

        while(entry != slow)
        {
            entry = entry->next;
            slow= slow->next;
        }

        return entry;
    
        
    }
};
