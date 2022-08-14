/*
 * Created 2022-08-03 21:58:48
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#include<iostream>
using namespace std;

int BinarySearch01(int arr[], int l, int r, int key) {
    if (l >= r) {
        return -1;
    }
    int mid = (l + r) / 2;
    if (arr[mid] > key) {
        return BinarySearch01(arr, l, mid, key);
    } else if (arr[mid] == key) {
        return mid;
    } else {
        return BinarySearch01(arr, mid + 1, r, key);
    }
}

int BinarySearch02(int arr[], int l, int r, int key) {
    while (l < r) {
        int mid = (l + r) / 2;
        if (arr[mid] > key) {
            r = mid;
        } else if (arr[mid] == key) {
            return mid;
        } else {
            l = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {12, 25, 34, 39, 45, 57, 63, 78, 82, 96, 100};
    int size = sizeof arr / sizeof arr[0];
    int res = BinarySearch01(arr, 0, size, 39);
    cout << BinarySearch01(arr, 0, size, 39) << endl;
    cout << BinarySearch01(arr, 0, size, 45) << endl;
    cout << BinarySearch02(arr, 0, size, 12) << endl;
    cout << BinarySearch02(arr, 0, size, 64) << endl;

    return 0;
}