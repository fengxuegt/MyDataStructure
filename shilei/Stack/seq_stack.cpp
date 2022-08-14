/*
 * Created 2022-07-29 19:47:27
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 * 顺序栈 C++容器适配器 stack
 * 
 */
#include<iostream>
using namespace std;
class SeqStack {
public:
    SeqStack(int size = 10) {
        m_arr = new int[size];
        m_size = size;
        m_top = 0;
    }
    void push(int val) {
        if (m_top == m_size)
        {
            expand(2 * m_size);
        }
        m_arr[m_top++] = val;
    }

    void pop() {
        if (m_top == 0) {
            throw "stack is empty";
        }
        m_top--;
    }

    int Top()
    {
        if (m_top == 0) {
            throw "stack is empty";
        }
        return m_arr[m_top - 1];
    }

    void expand(int new_size) {
        int *newArr = new int[new_size];
        for (int i = 0; i < m_top; i++) {
            newArr[i] = m_arr[i];
        }
        delete []m_arr;
        m_arr = newArr;
        m_size = new_size;
    }

    bool empty() {
        return m_top == 0;
    }

private:
    int *m_arr;
    int m_top;
    int m_size;
};

int main()
{
	int arr[] = { 12,4,56,7,89,31,53,75 };
	SeqStack s;
	
	for (int v : arr)
	{
		s.push(v);
	}

	while (!s.empty())
	{
		cout << s.Top() << " ";
		s.pop();
	}
	cout << endl;
    return 0;
}
