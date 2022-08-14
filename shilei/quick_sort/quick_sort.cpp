/*
 * Created 2022-08-11 23:40:54
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 * 重点：判断是否要移动指针时，等于基准数字也是移动条件的一种，换种说法就是
 * while (right > left && arr[right] >= pivot)条件中，一定是>=而不只是>
 */

#include<iostream>
using namespace std;

int Partition(int arr[], int left, int right) {
    int t = left;
    int pivot = arr[t];
    while (left < right) {
        while (right > left && arr[right] >= pivot) {
            right--;
        }
        while (arr[left] <= pivot && left < right) {
            left++;
        }
        if (left < right) {
            swap(arr[left], arr[right]);
        }
        
    }
    arr[t] = arr[left];
    arr[left] = pivot;
    return left;
}

void QuickSort_(int arr[], int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = Partition(arr, left, right);
    QuickSort_(arr, left, pivot - 1);
    QuickSort_(arr, pivot + 1, right);
}

void QuickSort(int arr[], int size) {
    QuickSort_(arr, 0, size - 1);
}

int main()
{
    int *arr = new int[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 10;
        cout << arr[i] << " ";
    }
    cout<< endl;

    QuickSort(arr, 10);
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}