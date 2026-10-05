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

private:
    ListNode* getKth(ListNode* curr, int k){
        while(curr!=nullptr && k>0){
            curr = curr->next;
            k--;
        }
        return curr;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0,head);
        ListNode* group_prev = dummy;

        while(true){

            //該組的第k個節點
            ListNode* kth = getKth(group_prev, k);
            if(kth == nullptr)break;//表示節點數量不足

            //prev初始化為groupNext
            //反轉後這組的新尾巴就會自動接上後面的節點。
            
            ListNode* group_next = kth->next;
            
            ListNode* prev = group_next;
            ListNode* curr = group_prev->next;

            //// 執行局部反轉，停止條件是走到 group_Next
            while(curr!=group_next){
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            ListNode* tail = group_prev->next;
            group_prev->next = kth;
            group_prev = tail;

        }

        ListNode* newHead = dummy->next;
        delete dummy; //釋放記憶體
        return newHead;

    }
};
