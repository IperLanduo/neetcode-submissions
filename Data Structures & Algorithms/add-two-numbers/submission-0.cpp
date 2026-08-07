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
        ListNode dummy(0);
        ListNode* curr= &dummy;
        int temp=0;
        int carry=0;

        while(l1!=nullptr || l2!=nullptr || carry!=0){
            int val1,val2;
            if(l1!=nullptr)val1=l1->val;
            else val1=0;

            if(l2!=nullptr)val2=l2->val;
            else val2=0;
            
            int sum = val1 + val2 +carry;
            carry = sum/10;
            temp = sum%10;

            curr->next=new ListNode(temp);

            curr=curr->next;
            if(l1!=nullptr)l1=l1->next;
            if(l2!=nullptr)l2=l2->next;
        }
        return dummy.next;

    }
};
