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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode *current = head;
        while(current!=nullptr) {
            length++;
            current = current->next;
        }
        int pos = length - n;

        if(pos==0) return head->next;
        current = head;
        while(pos>1) {
            current = current->next;
            pos--;
        }
        current->next = current->next->next;
        return head;
    }
};
