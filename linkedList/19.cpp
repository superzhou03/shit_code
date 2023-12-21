// Author: superzhou03
// Created time: 2023-12-21
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
**/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 快慢指针
        ListNode* vHead = new ListNode(0,head);
        ListNode* fast = vHead;
        ListNode* slow = vHead;
        
        // 这里不加'!=NULL'执行时间会多4ms
        // 不知道为什么,可能涉及底层原理
        while(n-- && fast != NULL){
            fast = fast->next;
        }
        
        // 删除节点时slow在待删除结点前一个结点
        // 所以fast要多走一步
        fast = fast->next;
       
        while(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *tmp = slow->next; 
        slow->next = tmp->next;
        delete tmp;

        return vHead->next;
    }
};
