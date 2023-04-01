//Solution 1----- T.C{O(n)}, S.C{O(1)}

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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head== nullptr || head->next == nullptr) return head;
        int n=0;
      
            ListNode* temp= head, * end= nullptr;
            while(temp != nullptr)
            {
                n++;
                end = temp;
                temp = temp->next;
            }

            k = k % n;
            if(k == 0) return head;
            k = n - k;
            temp = head;
            ListNode* last_end= temp;
                while(k--)
                {
                    last_end = temp;
                    temp = temp->next;
                }
                end->next = head;
                last_end->next = nullptr;



        return temp;
    }
};
Console
