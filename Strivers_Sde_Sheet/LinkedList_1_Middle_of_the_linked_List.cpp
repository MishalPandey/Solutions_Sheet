//Solution 1 --> T.C{O(n/2)}, S.C{O(n)}
class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!= NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }


        return slow;
    }
};
