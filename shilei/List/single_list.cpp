/*
 * Created 2022-07-25 23:02:00
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 * 
 * LeetCode：
 * 翻转链表
 * 求链表倒数第k个节点
 * 合并两个有序链表
 * 判断单链表是否有环以及入口节点
 * 判断两个链表是否相交
 * 删除链表倒数第k个节点
 * 旋转链表
 */

#include<iostream>
using namespace std;
struct Node {
    Node(int data = 0) : m_data(data), m_next(nullptr) {}
    int m_data;
    Node *m_next;
};

class SingleList {
public:
    // 尾部插入法
    void InsertTail(int val) {
        // 首先找到末尾节点
        Node *cur = m_head;
        while (cur->m_next != nullptr) {
            cur = cur->m_next;
        }
        Node *newNode = new Node(val);
        cur->m_next = newNode;
    }

    // 头部插入法
    void InsertHead(int val) {
        Node *newNode = new Node(val);
        newNode->m_next = m_head->m_next;
        m_head->m_next = newNode;
    }

    // delete 删除链表中第一个为val的节点
    // 也可以使用两个指针的方式记录上一个节点；
    void remove(int val) {
        Node * cur = m_head;
        while (cur != nullptr && cur->m_next != nullptr) {
            if (cur->m_next->m_data == val) {
                Node *t = cur->m_next;
                cur->m_next = t->m_next;
                delete t;
                return;
            }
            cur = cur->m_next;
        }
    }

    // 删除所有值为val的节点
    void removeAll(int val) {
        Node *cur = m_head;
        while (cur != nullptr && cur->m_next != nullptr) {
            if (cur->m_next->m_data == val) {
                Node *t = cur->m_next;
                cur->m_next = t->m_next;
                delete t;
                
            } else {
                cur = cur->m_next;
            }
        }
    }
    // Find
    // 略

    // Reverse
    void ReverseList()
    {
        Node *cur = m_head->m_next;
        Node *pre = nullptr;
        while (cur) {
            Node *next = cur->m_next;
            cur->m_next = pre;
            pre = cur;
            cur = next;
        }
        m_head->m_next = pre;
    }

    // show
    void Show() {
        Node *cur = m_head->m_next;
        while (cur) {
            cout << cur->m_data << " ";
            cur = cur->m_next;
        }
        cout << endl;
    }
public:
    SingleList() {
        // 指向头节点
        m_head = new Node(-1);
    }

    ~SingleList() {
        // 节点的释放
        Node *cur = m_head;
        while (cur) {
            Node *t = cur;
            cur = cur->m_next;
            delete t;
        }
    }

private:
    Node *m_head;
};

void ReverseList(Node *head) {
    Node *pre = nullptr;
    Node *cur = head;
    while (cur) {
        Node *next = cur->m_next;
        cur->m_next = pre;
        pre = cur;
        cur = next;
    }
    head = pre;
}


int main()
{
    SingleList list;
    list.InsertHead(1);
    list.InsertHead(2);
    list.InsertHead(2);
    list.InsertHead(2);
    list.InsertHead(2);
    list.InsertHead(2);
    list.InsertTail(3);
    list.InsertHead(3);
    list.InsertHead(4);
    list.InsertTail(8);
    list.Show();
    list.ReverseList();
    list.Show();
    list.remove(1);
    list.removeAll(2);
    list.removeAll(3);
    list.Show();
    
    return 0;
}

#if 0
int main()
{
    SingleList list;
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        int val = rand() % 100;
        cout << val << " ";
        // list.InsertHead(val);
        list.InsertTail(val);
    }
    cout << endl;
    list.Show();
    return 0;
}
#endif

