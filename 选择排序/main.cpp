#include <stdio.h>
#include <stdlib.h>

/*
������δ�����������ҵ���С����Ԫ�أ���ŵ��������е���ʼλ�á�
�ٴ�ʣ��δ����Ԫ���м���Ѱ����С����Ԫ�أ�Ȼ��ŵ����������е�ĩβ��
�ظ��ڶ�����ֱ������Ԫ�ؾ�������ϡ�
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
    for (int i = 0; i < len; i++) // ��ѭ��
    {
        int min = i; // ��Сֵλ�ñ��

        for (int j = i + 1; j < len; j++) // �Ӻ����Ԫ�ؿ�չö��
            if (arr[min] > arr[j]) // �����Сֵ���ڵ�ǰö��ֵ
                min = j; // ������Сֵλ��

        if (i != min)
            swap(arr[i], arr[min]); // ����Сֵ�Ƶ���ǰѭ��λ��
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