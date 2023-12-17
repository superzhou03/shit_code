// Author: superzhou03
// Created time: 2023-12-17
// 这个题可以参照'leecode No.23.jpg'看
// 黑色线表示断开的链接，同时建立红色线所在的链接
// 1，2，3分别表示交换节点的步骤
// 通过右边三个分步示意图就能很清楚的看到
// 执行完每条语句之后的链表是什么样子的
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* vHead = new ListNode(0);
        vHead->next = head;
        ListNode* cur = vHead;
        while(cur->next &&cur->next->next){
            ListNode* temp1 = cur->next;
            ListNode* temp2 = cur->next->next->next;

            cur->next = cur->next->next;
            temp1->next->next = temp1;
            temp1->next = temp2;

            cur = cur->next->next;
        }
        return vHead->next;
    }
};

