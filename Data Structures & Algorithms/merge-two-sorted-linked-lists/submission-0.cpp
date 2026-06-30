/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptrptr) {}
 *     ListNode(int x) : val(x), next(nullptrptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *newHead = new ListNode();
        ListNode *currHead = newHead;
        while( list1!=nullptr && list2!=nullptr) {
            if(list1->val <= list2->val) {
                currHead->next = new ListNode(list1->val);
                list1 = list1->next;
            } else {
                currHead->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            currHead = currHead->next;
        }
        while(list1!=nullptr) {
            currHead->next = new ListNode(list1->val);
            currHead = currHead->next;
            list1 = list1->next;
        }
         while(list2!=nullptr) {
            currHead->next = new ListNode(list2->val);
            currHead = currHead->next;
            list2 = list2->next;
        }
        return newHead->next;
    }
};
