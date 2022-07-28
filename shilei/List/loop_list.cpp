/*
 * Created 2022-07-27 23:06:45
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 * 单向循环链表
 */

#include<iostream>
using namespace std;
struct Node {
    Node(int data = 0):m_data(data), next_(nullptr) {}
    int m_data;
    Node * next_;
};

void Joseph(Node *head, int k, int m)
{
    Node *p = head;
    Node *q = head;
    // q 指向最后一个节点，因此是p的上一个节点
    while (q->next_ != head) {
        q = q->next_;
    }
    // 移动到第k个人
    for (int i = 1; i < k ; i++) {
        q = p;
        p = p->next_;
    }
    while (true) {
        for (int i = 1; i < m; i++) {
            q = p;
            p = p->next_;
        }
        cout << p->m_data << " ";
        if (p == q) {
            delete p;
            break;
        }
        q->next_ = p->next_;
        delete p;
        p = q->next_;
    }

}

int main()
{
    Node* head = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    Node* n7 = new Node(7);
    Node* n8 = new Node(8);

    head->next_ = n2;
    n2->next_ = n3;
    n3->next_ = n4;
    n4->next_ = n5;
    n5->next_ = n6;
    n6->next_ = n7;
    n7->next_ = n8;
    n8->next_ = head;

    Joseph(head, 1, 3);
    
}

#if 0
class CircleLink {
public:
    CircleLink() {
        m_head = new Node();
        m_head->m_next = m_head;
        m_tail = m_head;
    }
    ~CircleLink() {
        Node *real_head = m_head->m_next; // 指向真正的数据节点
        while (real_head != m_head) { // 循环删除所有的数据节点
            m_head->m_next = real_head->m_next;
            delete real_head;
            real_head = m_head->m_next;
        }
        delete m_head; // 最终删除头节点
    }

    void InsertTail(int val) {
        Node *newNode = new Node(val);
        newNode->m_next = m_tail->m_next; // 这里一定要记得，新建节点并不是指向nullptr，而是指向头节点
        m_tail->m_next = newNode;
        m_tail = newNode;
    }

    void InsertHead(int val) {
        Node *newNode = new Node(val);
        newNode->m_next = m_head->m_next;
        m_head->m_next = newNode;
        if (newNode->m_next == m_head) { // 这里一定要注意，如果是初始链表插入的话要更改一下mtail指针
            m_tail = newNode;
        }
    }

    void Remove(int val) {
        Node *cur = m_head;
        while (cur->m_next != m_head) {
            if (cur->m_next->m_data == val) {
                Node *t = cur->m_next;
                cur->m_next = t->m_next;
                delete t;
                if (cur->m_next == m_head) { // 考虑这种特殊情况
                    m_tail = cur;
                }
                return;
            }
            cur = cur->m_next;
        }
    }
    void Show() {
        Node* p = m_head->m_next;
        while (p != m_head)
        {
            cout << p->m_data << " ";
            p = p->m_next;
        }
        cout << endl;   
    }

private:
    struct Node {
        Node(int data = 0):m_data(data), m_next(nullptr) {}
        int m_data;
        Node * m_next;
    };
    Node *m_head;
    Node *m_tail;
};

int main()
{
    CircleLink clink;
    srand(time(NULL));

    clink.InsertHead(100);

    for (int i = 0; i < 10; i++)
    {
        clink.InsertTail(rand() % 100);
    }

    clink.InsertTail(200);
    clink.Show();

    clink.Remove(200);
    clink.Show();

    clink.InsertTail(300);
    clink.Show();
    return 0;
}
#endif