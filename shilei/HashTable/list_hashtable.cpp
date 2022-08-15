/*
 * Created 2022-08-15 22:41:29
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 * 线性探测哈希表的缺陷：
 *      1、发生哈希冲突的时候，会趋近于O（n）的复杂度，会越来越慢
 *      2、多线程执行的过程中，线性探测所用到的基于数组实现的哈希表，只能给全局的表用互斥锁来保证哈希表的原子操作，保证线程安全
 * 链式哈希表
 *      1、可以使用分段锁，既保证了线程安全，又有一定的并发量，可以提高效率（库上并没有实现多线程）
 *      指的是，锁只用于每个桶即可，不同桶的操作可以并发执行
 * 每个桶的链表越长，搜索耗费越大。
 * 优化方式一：
 *      当链表节点个数大于一定值时，将链表转化成红黑树
 */

#include<iostream>
#include<vector>
#include<list>
using namespace std;
// 链式哈希表
class HashTable {
public:
    // no repeat
    void Insert(int key) {
        // 
        double factor = m_use_num * 1.0 / m_table.size();
        cout << "factor:" << factor << endl;
        if (factor > m_load_factor) {
            expand();
        }

        int index = key % m_table.size();
        if (m_table[index].empty()) {
            m_use_num++;
            m_table[index].emplace_front(key);
        } else {
            // is repeat?
            auto it = ::find(m_table[index].begin(), m_table[index].end(), key);
            if (it == m_table[index].end()) {
                // no repeat
                m_table[index].emplace_front(key);
            }
        }

    }

    void Erase(int key) {
        int index = key % m_table.size();
        auto it = ::find(m_table[index].begin(), m_table[index].end(), key);
        if (it != m_table[index].end()) {
            m_table[index].erase(it);
            if(m_table[index].empty()) {
                m_use_num--;
            }
        }
    }

    bool Find(int key) {
        int index = key % m_table.size();
        auto it = ::find(m_table[index].begin(), m_table[index].end(), key);
        return it != m_table[index].end();
    }

public:
    HashTable(int size = prime_arr[0], double load_factor = 0.75)
    : m_use_num(0), m_load_factor(load_factor), prime_index(0) {
        if (size != prime_arr[0]) {
            for (; prime_index < PRIME_SIZE; prime_index++) {
                if (prime_arr[prime_index] >= size) {
                    break;
                }
            }
            if (prime_index == PRIME_SIZE) { // too large
                prime_index--;
            }
        }
        m_table.resize(prime_arr[prime_index]);

    }

    ~HashTable() {
        // do nothing
    }
private:
    void expand() {
        ++prime_index;
        if (prime_index == PRIME_SIZE) {
            throw "too large";
        }
        vector<list<int>> oldTable;
        m_table.swap(oldTable);
        m_table.resize(prime_arr[prime_index]);
        for (auto list : oldTable) {
            for (auto key : list) {
                int index = key % m_table.size();
                if (m_table[index].empty()) {
                    m_use_num++;
                }
                m_table[index].emplace_front(key);
            }
        }
    }

private:
    vector<list<int>> m_table; // hashtable
    int m_use_num; // used bucket num
    double m_load_factor; // 装载因子
    static const int PRIME_SIZE = 10;
    static int prime_arr[PRIME_SIZE];
    int prime_index;
};
int HashTable::prime_arr[PRIME_SIZE] = { 3, 7, 23, 47, 97, 251, 443, 911, 1471, 42773 };
int main()
{
	HashTable htable;
	htable.Insert(21);
	htable.Insert(32);
	htable.Insert(14);
	htable.Insert(15);

	htable.Insert(22);

	htable.Insert(67);

	cout << htable.Find(67) << endl;
	htable.Erase(67);
	cout << htable.Find(67) << endl;
    return 0;
}

