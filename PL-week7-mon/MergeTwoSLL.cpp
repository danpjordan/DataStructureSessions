// Solution to LeetCode problem #21 - Merge Two Sorted Lists

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* head = new ListNode;
        ListNode* tail = head;
        tail->next = nullptr;
        
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                // if first value of list1 < first value of list2
                // add value after tail pointer of new list
                tail->next = list1;
                list1 = list1->next;
            } else {
                // if first value of list1 >= first value of list2
                // add value after tail pointer of new list
                tail->next = list2;
                list2 = list2->next;
            }
            // move tail forward
            tail = tail->next;
        }

        // 1 (p) -> 2 -> 3 -> null
        // 2 (p) -> 4 -> 6 -> null
        // (t) -> null


        // add remaining elements
        if (list1 == nullptr) {
            tail->next = list2;
        }

        if (list2 == nullptr) {
            tail->next = list1;
        }
    
        return head->next;
    }
};
