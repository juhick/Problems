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
    ListNode* reverse(ListNode* left, ListNode* right){
        ListNode *pre, *cur, *nxt;
        pre = nullptr;
        cur = left;
        nxt = right;
        while(cur != right){
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr){
            return head;
        }
        ListNode *left = head, *right = head;
        for(int i = 0; i < k; ++i){
            if(right == nullptr){
                return head;
            }
            right = right->next;
        }
        ListNode* newHead = reverse(left, right);
        left->next = reverseKGroup(right, k);
        return newHead;
    }
};