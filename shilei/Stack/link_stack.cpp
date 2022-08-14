/*
 * Created 2022-07-31 20:32:02
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#include<iostream>
using namespace std;

struct Node {
    Node(int data = 0) : m_data(data), m_next(nullptr) {}
    int m_data;
    Node *m_next;
};

class LinkStack {
public:
    LinkStack() {
        m_head = new Node();
    }
    ~LinkStack() {
        Node *cur = m_head;

    }

    bool Empty() {
        return m_head->m_next == nullptr;
    }

    // 头插法
    void Push(int val) {

    }

    void Pop() {

    }

    int Top() {

    }

private:
    Node *m_head;
};

int main()
{
    
    return 0;
}