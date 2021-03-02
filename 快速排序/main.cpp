#include <stdio.h>
#include <stdlib.h>

#include <algorithm>

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

#if 0
int partition(int arr[], int start, int end)
{
    int pos = start; // 标记移动位置
    for (int i = start; i < end; i++)
    {
        if (arr[i] < arr[end]) // end所在位置是需要比较的标记值，所有元素与它比较
        {
            swap(arr[pos], arr[i]); // 交换至左边
            pos++;                  // 移动交换点
        }
    }
    swap(arr[end], arr[pos]); // 标记值与交换点互换
    return pos;
}

int sort(int arr[], int start, int end)
{
    if (!arr || start > end)
        return -1;

    if (start == end)
        return 0;

    int pos = partition(arr, start, end); // 获取标记位
    if (pos > start)
        sort(arr, start, pos - 1); // 左排序
    if (pos < end)
        sort(arr, pos + 1, end); // 右排序

    return 0;
}
#else
template <typename T>
void quick_sort_recursive(T arr[], int start, int end) {
    if (start >= end)
        return;
    T mid = arr[end];
    int left = start, right = end - 1;
    while (left < right) { //在整个范围内搜寻比枢纽元值小或大的元素，然后将左侧元素与右侧元素交换
        while (arr[left] < mid && left < right) //试图在左侧找到一个比枢纽元更大的元素
            left++;
        while (arr[right] >= mid && left < right) //试图在右侧找到一个比枢纽元更小的元素
            right--;
        std::swap(arr[left], arr[right]); //交换元素
    }
    if (arr[left] >= arr[end])
        std::swap(arr[left], arr[end]);
    else
        left++;
    quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left + 1, end);
}
template <typename T> //整數或浮點數皆可使用,若要使用物件(class)時必須設定"小於"(<)、"大於"(>)、"不小於"(>=)的運算子功能
void sort(T arr[], int len) {
    quick_sort_recursive(arr, 0, len - 1);
}
#endif
void test()
{
    //int arr[] = { 3,2,1,6,5,1,9,8,4,7 };
    int arr[] = { 3,2,1,6,5,1,9,8,4,70 };
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