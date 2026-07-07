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
    bool hasCycle(ListNode* head) {
        ListNode * slow = head;
        if(head->next==nullptr || head == nullptr) return false;
        ListNode * fast = head;
        while(slow->next!=nullptr) {
            slow = slow->next;
            if(fast == nullptr||fast->next == nullptr) break;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
        
    }
};
