#include <stdio.h>
#include <stdlib.h>

/*
�Ƚ����ڵ�Ԫ�ء������һ���ȵڶ����󣬾ͽ�������������
��ÿһ������Ԫ����ͬ���Ĺ������ӿ�ʼ��һ�Ե���β�����һ�ԡ��ⲽ���������Ԫ�ػ�����������
������е�Ԫ���ظ����ϵĲ��裬�������һ����
����ÿ�ζ�Խ��Խ�ٵ�Ԫ���ظ�����Ĳ��裬ֱ��û���κ�һ��������Ҫ�Ƚϡ�
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
    for (int i = 0; i < len - 1; i++) // ��ѭ��
        for (int j = 0; j < len - 1 - i; j++) // �Ƚϴ�Сѭ�����Ѿ�ð�ݲ��ֲ��ò���ѭ����
            if (arr[j] > arr[j + 1]) // ����Ⱥ���Ĵ��������Ľ���
                swap(arr[j], arr[j + 1]);
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