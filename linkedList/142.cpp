// Author: superzhou03
// Created time: 2023-12-23
// 参照'leecode No.142.png'
// 主要思路参照programmercarl.com/0142.%E7%8E%AF%E5%BD%A2%E9%93%BE%E8%A1%A8II.html#%E6%80%9D%E8%B7%AF
// 主要解法是快慢指针,当进入链表的环形部分后,肯定是fast指针追slow指针
// 那么当两指针相遇时，标记该点
// 该点到环形入口的距离和链表起点到该点的距离一样
// 两个index相遇点即为链表入口
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* vHead = new ListNode(0,head);
        ListNode* fast = vHead->next;
        ListNode* slow = vHead->next;

        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow){
                ListNode* index1 = vHead->next;
                ListNode* index2 = fast;

                while(index1 != index2){
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return 0;
    }
};
