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

int search(int arr[], int len, int s)
{
    int left = 0;
    int right = len - 1;
    int mid, pos = -1;

    while (left <= right)
    {
        mid = (left + right + 1) / 2;

        printf("min = %d(%d)\n", mid, arr[mid]);

        if (s == arr[mid])
        {
            pos = mid;
            break;
        }
        else if (s < arr[mid])
        {
            right = mid - 1;
        }
        else if (s > arr[mid])
        {
            left = mid + 1;
        }
    }

    return pos;
}

int search2(int arr[], int len, int s)
{
    print(arr, len);

    if (len == 1 && arr[0] == s)
        return 0;

    if (len > 1)
    {
        int pos = len / 2;

        printf("pos = %d(%d)\n", pos, arr[pos]);

        if (s == arr[pos])
            return pos;
        else if (s < arr[pos])
            return search(arr, len - pos, s);
        else // (s > arr[pos])
            return search(&arr[pos], len - pos, s) + pos;
    }

    return -1; // len <= 0 | len == 1 && arr[0] != s
}

void test()
{
    int arr[] = { 2,3,6,8,21,69,72,99,100,101 };
    int len = 10;
    //int len = 5;
    print(arr, len);
    int pos = search(arr, len, 72);
    printf("%d(%d)\n", pos, pos >= 0 ? arr[pos] : -1);
}

void main()
{
    test();

#ifdef _DEBUG
    system("pause");
#endif
}