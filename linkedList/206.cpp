// Author: superzhou03
// Created time: 2023-12-15
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
    // // method NO.1 头插法
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* vHead = new ListNode();
    //     vHead->next = head;
    //     ListNode* fast;
    //     ListNode* slow = vHead->next;
    //     vHead->next= NULL;
    //     while(slow){
    //         fast = slow->next;
    //         slow->next = vHead->next;
    //         vHead->next = slow;
    //         slow = fast;
    //     }
    //     return vHead->next;
    // }


    // // method NO.2 双指针
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* cur = head;
    //     ListNode* pre = NULL;
    //     while(cur){
    //         ListNode* tmp = cur->next;
    //         cur->next = pre;
    //         pre = cur;
    //         cur = tmp;
    //     }
    //     // 这里head其实是尾节点
    //     // 真正的头节点变成了pre
    //     return pre;
    // }


    // method NO.3 递归
    ListNode* recursion(ListNode* cur, ListNode* pre){
        if(cur==NULL)   return pre;
        ListNode* tmp = cur->next;
        cur->next = pre;
        return recursion(tmp,cur);
    }
    ListNode* reverseList(ListNode* head) {
        return recursion(head, NULL);
    }
};
