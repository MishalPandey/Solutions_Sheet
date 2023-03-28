//Solution 1----> T.C{O(n+m)}, S.C{O(n)}

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

    
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {

       
            unordered_set<ListNode*> st;
            while(head1 != nullptr)
             {
                st.insert(head1);
                head1 = head1->next;
            }
            while(head2 != nullptr) {
                if(st.find(head2) != st.end()) 
                    return head2;
                head2 = head2->next;
            }
            return nullptr;
    }
};

// Solution 2---> T.C { O(n) }, S.C{ O(1) }
int getDifference(ListNode* head1, ListNode* head2) {
     int len1 = 0,len2 = 0;
        while(head1 != NULL || head2 != NULL) {
            if(head1 != NULL) {
                ++len1; head1 = head1->next;
            }
            if(head2 != NULL) {
                ++len2; head2 = head2->next;
            }
            
        }
        return len1-len2;//if difference is neg-> length of list2 > length of list1 else vice-versa
    }

    
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {

            int diff = getDifference(head1,head2);
            if(diff < 0) 
                while(diff++ != 0) head2 = head2->next; 
            else while(diff-- != 0) head1 = head1->next;
            while(head1 != NULL) {
                if(head1 == head2) return head1;
                head2 = head2->next;
                head1 = head1->next;
            }
            return head1;
    }
};


//Solution 3----> T.C{ O(2*max(length of list1,length of list2)) }, S.C{ O(1)}

class Solution {
public:

    
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {

       
            ListNode* d1 = head1;
            ListNode* d2 = head2;
            
            while(d1 != d2) {
                d1 = d1 == NULL? head2:d1->next;
                d2 = d2 == NULL? head1:d2->next;
            }
            
            return d1;
    }
};
