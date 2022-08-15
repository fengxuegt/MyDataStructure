/*
 * Created 2022-07-15 21:33:09
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 * 
 * 有序的关联容器  set map —— 红黑树 O（n）
 * 无序的关联容器  unordered_set unordered_map O（1）
 * 
 * 元素的值=》通过映射关系=》元素在表中的存储位置
 * 哈希函数：除留余数法
 *  哈希冲突或者说哈希碰撞，是不可避免的。解决方法为：线性探测法、链式地址法
 *  降低哈希冲突的方法之一：将哈希桶的长度取素数。
 *  降低哈希冲突的方法之二：哈希表的装载因子大于0.75时，要进行扩容。扩容的时候需要重新哈希，所以代价比较大。
 * 
 * 线性探测哈希表的实现
 *  增加：
 *      通过哈希函数计算数据存放的位置
 *      该位置空闲：直接存储元素，完成
 *      该位置被占用，从当前位置向后找空闲的位置，存放该元素
 *  查询：
 *      通过哈希函数计算数据存放的位置
 *      该值=要查询的元素，找到了
 *      该值！=要查询的元素（那就是发生哈希冲突了），继续遍历向后找元素；
 *      向后找的时候要看空的位置是不是一直是空的。
 *          一直是空的：不要再找了
 *          不是：要继续向后找元素
 *  删除：
 *      通过哈希函数计算数据存放的位置，从该位置取值，判断状态为state_using
 *      该值=要删除的值，直接修改当前位置的状态为used就可以了
 *      该值！=要删除的值，（之前发生过哈希冲突），从当前位置向后遍历，找到该元素，修改状态，如果遇到state_unuse，结束
 */
// 


#include<iostream>
using namespace std;

enum State {
    STATE_USING,
    STATE_UNUSE,
    STATE_USED
};

struct Bucket {
    Bucket(int key = 0, State state= STATE_UNUSE)
        : m_key(key), m_state(state){

    }
    int m_key;
    State m_state;
};

class HashTable {

public:
    // find
    bool Find(int key) {
        int index = key % m_table_size;
        int i = index;
        do {
            if (m_table[i].m_state == STATE_USING && m_table[i].m_key == key) {
                return true;
            }
            i = (i + 1) % m_table_size;
        } while(m_table[i].m_state != STATE_UNUSE && i != index);
        return false;
    }

    // delete ele
    bool Erase(int key) { // 注意这种写法
        int index = key % m_table_size;
        int i = index;
        do {
            if (m_table[i].m_state == STATE_USING && m_table[i].m_key == key) {
                m_table[i].m_state = STATE_USED;
                m_use_table_num--;
            }
            i = (i + 1) % m_table_size;
        } while (m_table[i].m_state != STATE_UNUSE && i != index);
        return true;
    }

    // Insert ele
    bool Insert(int key) {
        // 考虑扩容
        double factor = m_use_table_num * 1.0 / m_table_size;
        cout << "factor: " << factor << endl;
        if (factor > m_load_factor) {
            // 哈希表扩容
            Expand();
        }
        // 插入正常逻辑lw
        // int index = key % m_table_size;
        // if (m_table[index].m_state == STATE_USING) {
        //     // tance
        //     for (int i = (index + 1) % m_table_size; ;i++) {
        //         if (m_table[i].m_state != STATE_USING) {
        //             m_table[i] = key;
        //             m_table[i].m_state = STATE_USING;
        //             break;
        //         }
        //     }
        // } else {
        //     m_table[index] = key;
        //     m_table[index].m_state = STATE_USING;
        // }
        // 插入逻辑sl
        int index = key % m_table_size;
        int i = index;
        do {
            if (m_table[i].m_state != STATE_USING) {
                m_table[i].m_key = key;
                m_table[i].m_state = STATE_USING;
                m_use_table_num++;
                return true;
            }
            i = (i + 1) % m_table_size;
        } while (i != index); // 直到遍历完成。注意这种写法
        return false;
    }


public:
    HashTable(int size = prime_sizes_arr[0], double load_factor = 0.75) 
    : m_table_size(size), m_use_table_num(0), m_load_factor(load_factor), m_prime_index(0){
        if (size != prime_sizes_arr[0]) {
            for (; m_prime_index < prime_size; m_prime_index++) {
                if (prime_sizes_arr[m_prime_index] > size) {
                    break;
                }
            }
            if (m_prime_index == prime_size) { // 
                m_prime_index--;
            }
        }
        m_table = new Bucket[prime_sizes_arr[m_prime_index]];
        m_table_size = prime_sizes_arr[m_prime_index];
    }

    ~HashTable() {
        delete[] m_table;
        m_table = nullptr;
    }
private:
    void Expand() {
        ++m_prime_index;
        if (m_prime_index == prime_size) {
            throw "HashTable is too large, can't expand anymore!\n";
        }
        Bucket *new_table = new Bucket[prime_sizes_arr[m_prime_index]];
        for (int i = 0; i < m_table_size; i++) {
            if (m_table[i].m_state == STATE_USING) {
                int index = m_table[i].m_key % prime_sizes_arr[m_prime_index];
                int p = index;
                do {
                    if (new_table[p].m_state != STATE_USING) {
                        new_table[p].m_key = m_table[i].m_key;
                        new_table[p].m_state = STATE_USING;
                        break;
                    }
                    p = (p + 1) % prime_sizes_arr[m_prime_index];
                } while (p != index);
            }
        }
        delete []m_table;
        m_table = new_table;
        m_table_size = prime_sizes_arr[m_prime_index];
    }
private:
    Bucket *m_table; // 指向动态开辟的哈希表
    int m_table_size; // 哈希表当前的长度
    int m_use_table_num; // 哈希表已经使用桶的个数
    double m_load_factor; // 哈希表的装载因子

    static const int prime_size = 10; // 素数表的大小
    static int prime_sizes_arr[prime_size]; // 素数表
    int m_prime_index; // 当前使用的素数下标
};

int HashTable::prime_sizes_arr[prime_size] = { 3, 7, 23, 47, 97, 251, 443, 911, 1471, 42773 };


int main()
{
	HashTable htable;
	htable.Insert(21);
	htable.Insert(32);
	htable.Insert(14);
	htable.Insert(15);

	htable.Insert(22);

	cout << htable.Find(21) << endl;
	htable.Erase(21);
	cout << htable.Find(21) << endl;
    return 0;
}