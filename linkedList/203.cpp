// Author: superzhou03
// Created time: 2023-12-14
// 使用原链表删除头节点和中间节点操作不一样
// 所以修改链表时最好新建一个虚拟头节点vHead进行操作
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *vHead = new ListNode();
        vHead->next = head;
        ListNode *current = vHead;
        while (current->next != NULL) {
            if (current->next->val == val)
                Listnode* tmp = current->nextl
                current->next = current->next->next;
                delete tmp;
            else
                current = current->next;
        }
        // 不明白为什么释放current的空间之后代码会运行不起来
        // delete current;
        // return vHead->next;
        head = vHead->next;
        delete vHead;
        return head;
    }
};
