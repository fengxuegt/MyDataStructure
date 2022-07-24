/*
 * Created 2022-05-03 22:20:16
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#include<iostream>
using namespace std;

// 整型数组，把偶数调整到数组的左边，把奇数调整到数组的右边

#include<iostream>
using namespace std;

// 整形数组，把偶数调整到数组的左边；把奇数调整到数组的右边
void AdjustArray(int arr[], int size)
{
    int *p = arr;
    int *q = arr + size - 1;
    while (p < q) {
        while (*p % 2 == 0) {
            p++;
            continue;
        }
        while (*q % 2 != 0) {
            q--;
            continue;
        }
        int t = *p;
        *p = *q;
        *q = t;
        p++;
        q--;
    }
}

int main()
{
    int arr[] = {18, 63, 76, 6, 74, 8, 1, 90, 51, 38};
    AdjustArray(arr, 10);
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
#if 0
void reverse(char str[], int n)
{
    char *p = str;
    char *q = str + n - 1;
    while (p < q) {
        char ch = *p;
        *p = *q;
        *q = ch;
        p++;
        q--;
    }
}

int main()
{
    char arr[] = "hello";
    cout << arr << endl;
    reverse(arr, 5);
    cout << arr << endl;
    return 0;
}
#endif
#if 0

class Array {
public:
    Array(int capacity = 10)
        : m_capacity(capacity), m_cur(0)
    {
        m_arr = new int[capacity]();
    }
    ~Array() {
        delete [] m_arr;
        m_arr = nullptr;
    }
public:
    // add tail element
    void push_back(int val) {
        if (full()) {
            expand(2 * m_capacity);
        }
        m_arr[m_cur++] = val;
    }

    // delete tail element
    void pop_back() {
        if(empty())
            return;
        --m_cur;
    }
    
    // insert element with index
    void insert(int pos, int val) {
        if (pos < 0 || pos > m_cur) {
            return;
        }
        if (full()) {
            expand( 2 * m_capacity);
        }
        for (int i = m_cur; i > pos; i--) {
            m_arr[i] = m_arr[i - 1];
        }
        m_arr[pos] = val;
        m_cur++;
    }

    // delete index in array
    void erase(int pos) {
        if (pos < 0 || pos >= m_cur) {
            return;
        }
        for (int i = pos; i < m_cur - 1; i++) {
            m_arr[i] = m_arr[i + 1];
        }
        m_cur--;
    }

    // element search
    int find(int val) {
        for (int i = 0; i < m_cur; i++) {
            if (m_arr[i] == val) {
                return i;
            }
        }
        return -1;
    }

    // print data
    void show() const {
        for (int i = 0; i < m_cur; i++) {
            cout << m_arr[i] << " ";
        }
        cout << endl;
    }
private:
    // expand data
    void expand(int size) {
        int * t = new int[size];
        for (int i = 0; i < m_capacity; i++) {
            t[i] = m_arr[i];
        }
        delete [] m_arr;
        m_arr = t;
        m_capacity = size;
        t = nullptr;
    }

    bool full() const {
        return m_capacity == m_cur;
    }

    bool empty() const {
        return m_cur == 0;
    }
    int *m_arr;
    int m_capacity;
    int m_cur;
};
int main()
{
    Array array;
    for (int i = 0; i < 15; i++) {
        array.push_back(rand() % 100);
    }
    array.show();
    array.pop_back();
    array.show();
    array.erase(2);
    array.show();
    array.insert(2, 666);
    array.show();

    return 0;
}

#endif