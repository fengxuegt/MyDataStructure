/*
 * Created 2022-02-21 22:56:30
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#include<iostream>
#include<vector>
using namespace std;
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int ret = INT_MAX;
        int sum = 0;
        while (left <= right && right < nums.size()) {
            if (sum >= target) {
                if (right - left < ret)
                    ret = right - left;
                while (sum > target) {
                    sum -= nums[left];
                    left++;
                    if (right - left < ret)
                        ret = right - left;
                }
            }
            sum += nums[right];
            right++;
        }
        return ret;
    }
int main()
{
    vector<int> vec = {2,3,1,2,4,3};
    int target = 7;
    cout << minSubArrayLen(target, vec) << endl;
    return 0;
}