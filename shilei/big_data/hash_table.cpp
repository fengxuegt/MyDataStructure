/*
 * Created 2022-08-18 23:03:31
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 * 查重相关的面试题目
 * 1、有两个文件分别是a和b，里面放了很多ip地址或者是email地址，让你找出两个文件中重复的ip，输出出来。
 * ==》 把a文件中的所有ip地址存放在一个哈希表中，然后依次遍历b文件里面的ip，每遍历一个ip，在哈希表中搜索一下，搜到的，就是重复ip
 * 2、有两个文件分别是a和b，各自存放在约1亿条ip地址，每个ip地址是4个字节限制内存使用100M，让找出来两个文件中重复的ip地址并输出
 * ==》 将文件分成小文件，%一个质数，分割成小文件，同样的ip一定会被分到同样索引的文件中。直接对比两个小文件就可以了。
 */

#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<time.h>
#include<string>
#include<stdlib.h>
using namespace std;
int main()
{
    string src = "jjhfgiyuhrtytrs";
    // 查找第一个没有重复出现的字符
    unordered_map<char, int> m_map;
    for (auto ch : src) {
        m_map[ch]++;
    }
    for (auto ch : src) {
        if (m_map[ch] == 1) {
            cout << "key " << ch << endl;
            return 0;
        }
    }
    cout << "can not find" << endl;
    return 0;
}

#if 0
int main()
{
    vector<int> vec;
    srand(time(NULL));
    for (int i = 0; i < 10000; i++) {
        vec.push_back(rand() % 10000);
    }
    // 查找第一个重复出现的数字
    unordered_set<int> m_set;
    for (auto key : vec) {
        auto it = m_set.find(key);
        if (it == m_set.end()) {
            m_set.insert(key); // insert
        } else {
            cout << "key: " << key << endl;
            break;
        }
    }

    // 统计重复数字以及其出现次数
    unordered_map<int, int> m_map;
    for (auto key : vec) {
        m_map[key]++;
    }
    for (auto it : m_map) {
        if (it.second > 1) {
            cout << "key " << it.first << " cout " << it.second << endl;
        }
    }

    //  过滤重复数字
    unordered_set<int> m_set2;
    for (auto key: vec) {
        m_set2.emplace(key);
    }
    return 0;
}
#endif