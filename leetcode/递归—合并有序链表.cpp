/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x)
        , next(nullptr) {};
};
class Solution {
public:
    //没必要管里面的细节，只需要关注：这个函数能将两个链表合并成一个有序链表，输出是两个head, 输出是一个链表
    //这时候采取递归的策略，只关心上层，不关心细节
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        //递归调用的出口
        if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
        //递归的逻辑
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};