/*
 * Created 2022-08-03 22:13:47
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

// 冒泡排序
void BubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        bool flag = false;
        for (int j = 0; j < size - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j+1]);
                flag = true;
            }
        }
        if (!flag) {
            return;
        }
    }
}

// 选择排序
void ChoiceSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

// 插入排序
// 如果数据趋近于有序，那么插入排序是所有排序算法中，效率最高的排序算法
// 在基础排序算法中，插入排序 > 冒泡排序 & 选择排序 ； 不仅仅没有交换，比较的次数也少
void InsertSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0; j--) {
            if (arr[j] <= temp) {
                break;
            }
            arr[j + 1] = arr[j];

        }
        arr[j + 1] = temp;
    }
}

// 希尔排序
// 对数据进行分组插入排序
void ShellSort(int arr[], int size) {
    for (int gap = size/2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j = i - gap;
            for (; j >= 0; j-=gap) {
                if (arr[j] <= temp) {
                    break;
                }
                arr[j + gap] = arr[j];

            }
            arr[j + gap] = temp;
        }
    }

}

int main()
{
	const int COUNT = 100000;
	int* arr = new int[COUNT];
	int* brr = new int[COUNT];
	int* crr = new int[COUNT];
	int* drr = new int[COUNT];

	srand(time(NULL));

	for (int i = 0; i < COUNT; i++)
	{
		int val = rand() % COUNT;
		arr[i] = val;
		brr[i] = val;
		crr[i] = val;
		drr[i] = val;
	}

	clock_t begin, end;

	begin = clock();
	BubbleSort(arr, COUNT);
	end = clock();
	cout << "BubbleSort spend:" << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;

	begin = clock();
	ChoiceSort(brr, COUNT);
	end = clock();
	cout << "ChoiceSort spend:" << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;

	begin = clock();
	InsertSort(crr, COUNT);
	end = clock();
	cout << "InsertSort spend:" << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;

	begin = clock();
	ShellSort(drr, COUNT);
	end = clock();
	cout << "ShellSort spend:" << (end - begin) * 1.0 / CLOCKS_PER_SEC << "s" << endl;
}


#if 0
int main()
{
    int arr[] = {1,3,2,5};
    //BubbleSort(arr, 4);
    //ChoiceSort(arr, 4);
    //InsertSort(arr, 4);
    ShellSort(arr, 4);
    for (auto i: arr) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
#endif