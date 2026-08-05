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
    ListNode* reverseList(ListNode* head) {
        vector<int> v;
        ListNode* curr = head;
        ListNode* ans;
        while(curr != nullptr){
            v.push_back(curr->val);
            curr = curr->next;
        }
        reverse(v.begin(),v.end());
        
        curr=head;//從頭走訪串列，把反轉後的數值依序寫入

        for(int i=0;i<v.size();i++){
            curr->val = v[i];
            curr = curr->next;
        }
        return head; //結構沒變，直接回傳原來的 head

    }
};
