//Solution T.C{O(n+m)} S.C{O(1)}

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

            if(list1==nullptr && list2==nullptr)
            {
                return nullptr;
            }
            else if(list1==nullptr)
            {
                return list2;
            }
            else if(list2==nullptr)
            {
                return list1;
            }

                ListNode* head= nullptr;
                ListNode* temp = nullptr;
                while(list1!= nullptr && list2!= nullptr)
                {
                    if(head==nullptr)
                    {
                        if((list2->val) <= (list1->val))
                        {
                            head= list2;
                            temp = list2;
                            list2= list2->next;
                            
                        }
                        else{
                            head= list1;
                            temp = list1;
                            list1= list1->next;
                            
                        }             
                        
                    }
                    else{
                        if(list2->val <=list1->val)
                        {
                            temp->next = list2;
                            temp=list2;
                            list2= list2->next;
                            
                        }
                        else{
                            temp->next = list1;
                            temp=list1;
                            list1= list1->next;
                            
                        }


                    }


                }
                if(list1!=nullptr)
                {
                    temp->next= list1;
                }
                else if(list2!=nullptr)
                {
                    temp->next= list2;
                }
                return head;

        
    }
};
