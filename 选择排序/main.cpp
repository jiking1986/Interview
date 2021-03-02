#include <stdio.h>
#include <stdlib.h>

/*
首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置。
再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。
重复第二步，直到所有元素均排序完毕。
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
    for (int i = 0; i < len; i++) // 大循环
    {
        int min = i; // 最小值位置标记

        for (int j = i + 1; j < len; j++) // 从后面的元素开展枚举
            if (arr[min] > arr[j]) // 如果最小值大于当前枚举值
                min = j; // 交换最小值位置

        if (i != min)
            swap(arr[i], arr[min]); // 将最小值移到当前循环位置
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