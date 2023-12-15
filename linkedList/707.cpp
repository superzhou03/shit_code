// Author: superzhou03
// Created time: 2023-12-14
class MyLinkedList {
public:
    struct LinkedNode {
        int val;
        LinkedNode* next;
        LinkedNode(int value):val(value),next(nullptr){}
    };
    MyLinkedList() {
        vHead = new LinkedNode(0);
        size = 0;
    }
    
    int get(int index) {
        if(index < 0 || index > (size - 1))
            return -1;
        
        LinkedNode* cur = vHead->next;
        // 如果是--index,会陷入死循环
        while(index--)
            cur = cur->next;
        
        return cur->val;
    }
    
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = vHead->next;
        vHead->next = newNode;
        size++;
    }
    
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = vHead;
        while(cur->next)
            cur=cur->next;
        cur->next = newNode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0)
            index = 0;
        if(index > size)
            return;
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = vHead;
        while(index--)
            cur = cur->next;
        newNode->next = cur->next;
        cur->next=newNode;
        size++;
        // 这里为什么不能释放内存
        // delete(newNode);
        // delete(cur);
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size)
            return;
        // LinkedNode* cur = vHead->next;
        LinkedNode* cur = vHead;
        while(index--)
            cur = cur->next;
        LinkedNode* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        // delete命令释放了tmp指针原本所指的那部分内存
        // 被delete后的指针tmp的值(地址)并非是NULL而是随机值
        // 被delete后,如果不加上一句tmp=nullptr,tmp会成为野指针
        // 如果之后的程序不小心使用了tmp,会指向难以预想的内存空间
        tmp=nullptr;
        size--;
    }
private:
    int size;
    LinkedNode* vHead;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

