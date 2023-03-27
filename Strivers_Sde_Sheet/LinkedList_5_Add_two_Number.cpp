// Solution 1 ----> T.c{ O(n) } , S.c{ O(n) }
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* head1 = l1;
        ListNode* head2 = l2;

        int x = 0;
        ListNode* final_list = nullptr;
        int value=0;
        ListNode* temp = nullptr;
      
        while(head1!= nullptr || head2!= nullptr)
        {
                if(head1== nullptr)
                {
                    value = head2->val + x; 
                    head2 = head2->next;

                }
                else if(head2== nullptr)
                {
                    value = head1->val + x; 
                    head1 = head1->next;

                }
                else{
                    value = head1->val + head2->val + x;
                    head1 = head1->next;
                    head2 = head2->next;
                }
            
                x= value/10;
                value= value %10;
                if(final_list == nullptr)
                {
                    final_list = new ListNode(value);
                    temp = final_list;
                    
                }
                else{
                    temp->next = new ListNode(value);
                    temp = temp->next;

                }        
        }

        
            
        if(x>0){
            temp->next = new ListNode(x);

        }
       

        return final_list;

    }
};
