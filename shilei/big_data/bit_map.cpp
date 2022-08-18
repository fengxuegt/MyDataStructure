/*
 * Created 2022-08-18 23:23:12
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 * 有1亿个整数，最大值不超过1亿，问都有哪些元素重复了？谁是第一个重复的？谁是第一个不重复的(1个位保存数据的状态，2个位保存数据的状态)？   内存限制100M
 * 1亿 = 100M
 * 100M * 4 = 400M * 2 = 800M
 * 
 * 位图算法     
 * int bitmap[100000000/32+1]   3.2M
 * 
 * 缺陷:   int 20亿    unsigned int 40亿
 * 1 3 1000000000
 * int bitmap[1000000000/32+1]  30M
 * 
 * 3*4 = 12 * 2 = 24byte
 * 
 * 推荐的数据序列：数据的个数 >= 序列里面数字的最大值相当
 */

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec{12,78,90,78,123,8,9,90};
    auto max_item = vec[0];
    for (auto it : vec) {
        if (it > max_item) {
            max_item = it;
        }
    }
    // 查找重复出现的数字
    int *bitmap = new int[max_item/32 + 1]();
    //int bitmap[max_item/32 + 1] = {0};
    for (auto num : vec) {
        int index = num / 32;
        int offset = num % 32;
        if ((bitmap[index] & (1 << offset)) == 0) {
            bitmap[index] |= (1 << offset);
        } else {
            cout << "num  " << num << endl;
        }
    }
    delete bitmap;
    return 0;
}