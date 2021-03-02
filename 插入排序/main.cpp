#include <stdio.h>
#include <stdlib.h>

/*
将第一待排序序列第一个元素看做一个有序序列，把第二个元素到最后一个元素当成是未排序序列。
从头到尾依次扫描未排序序列，将扫描到的每个元素插入有序序列的适当位置。（如果待插入的元素与有序序列中的某个元素相等，则将待插入元素插入到相等元素的后面。）
*/

void print(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int &n1, int &n2)
{
    int temp = n1;
    n1 = n2;
    n2 = temp;
}

void sort(int arr[], int len)
{
    int i, j;
    for (i = 1; i < len; i++) // 第二个元素到最后一个元素是无序序列
    {
        int k = arr[i]; // 提取一个值

        for (j = i - 1; j >= 0; j--) // 逆向查找目标值在有序序列的位置
        {
            if (k >= arr[j]) // 找到目标值在有序序列的位置
                break;
            arr[j + 1] = arr[j]; // 目标值小于当前有序序列值，将当前有序序列值后移
        }

        arr[j + 1] = k; // 插入目标值（j + 1，因为 for 循环 j--）
    }
}

void test()
{
    int arr[] = { 3,2,1,6,5,1,9,8,4,7 };
    int len = 10;
    print(arr, len);
    sort(arr, len);
    print(arr, len);
}

void main()
{
    test();

#ifdef _DEBUG
    system("pause");
#endif
}