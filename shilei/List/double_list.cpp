/*
 * Created 2022-07-28 22:56:03
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#include<iostream>
using namespace std;
struct Node {
    Node(int data = 0):m_data(data), m_next(nullptr), m_prev(nullptr) {}
    int m_data;
    Node * m_next;
    Node * m_prev;
};

class DoubleList {
public:
    void InsertHead(int val) {
        Node *newNode = new Node(val);
        newNode->m_next = m_head->m_next;
        m_head->m_next = newNode;
        newNode->m_prev = m_head;
    }
    void InsertTail(int val) {
        Node *newNode = new Node(val);
        Node *cur = m_head;
        while (cur->m_next) {
            cur = cur->m_next;
        }
        cur->m_next = newNode;
        newNode->m_prev = cur;
    }
    void Show() {
        Node *cur = m_head->m_next;
        while (cur) {
            cout << cur->m_data << " ";
            cur = cur->m_next;
        }
        cout << endl;
    }
    // 这种方法和单链表的方法一样，没有用到双向链表的精髓
    void Remove1(int val) {
        Node *cur = m_head;
        while (cur->m_next) {
            if (cur->m_next->m_data == val) {
                Node *t = cur->m_next;
                cur->m_next = t->m_next;
                if (t->m_next != nullptr)
                    t->m_next->m_prev = cur;
                delete t;
                break;
            }
            cur = cur->m_next;
        }
    }
    void Remove(int val) {
        Node *cur = m_head->m_next;
        while (cur) {
            if (cur->m_data == val) {
                if (cur->m_next == nullptr) {
                    // 最后节点
                    cur->m_prev->m_next = nullptr;
                    delete cur;
                    break;
                }
                cur->m_prev->m_next = cur->m_next;
                cur->m_next->m_prev = cur->m_prev;

            }
            cur = cur->m_next;
        }
    }
    void Find() {

    }
public:
    DoubleList() {
        m_head = new Node();
    }
    ~DoubleList() {
        while (m_head) {
            Node *t = m_head;
            m_head = m_head->m_next;
            delete t;
        }
    }
private:
    Node *m_head;
};

int main()
{
    DoubleList dlink;

    dlink.InsertHead(100);

    dlink.InsertTail(20);
    dlink.InsertTail(12);
    dlink.InsertTail(78);
    dlink.InsertTail(32);
    dlink.InsertTail(7);
    dlink.InsertTail(90);
    dlink.Show();

    dlink.InsertHead(200);
    dlink.Show();

    dlink.Remove(200);
    dlink.Show();

    dlink.Remove(90);
    dlink.Show();

    dlink.Remove(78);
    dlink.Show();
    return 0;
}