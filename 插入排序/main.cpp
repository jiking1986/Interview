#include <stdio.h>
#include <stdlib.h>

/*
����һ���������е�һ��Ԫ�ؿ���һ���������У��ѵڶ���Ԫ�ص����һ��Ԫ�ص�����δ�������С�
��ͷ��β����ɨ��δ�������У���ɨ�赽��ÿ��Ԫ�ز����������е��ʵ�λ�á�������������Ԫ�������������е�ĳ��Ԫ����ȣ��򽫴�����Ԫ�ز��뵽���Ԫ�صĺ��档��
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
    for (i = 1; i < len; i++) // �ڶ���Ԫ�ص����һ��Ԫ������������
    {
        int k = arr[i]; // ��ȡһ��ֵ

        for (j = i - 1; j >= 0; j--) // �������Ŀ��ֵ���������е�λ��
        {
            if (k >= arr[j]) // �ҵ�Ŀ��ֵ���������е�λ��
                break;
            arr[j + 1] = arr[j]; // Ŀ��ֵС�ڵ�ǰ��������ֵ������ǰ��������ֵ����
        }

        arr[j + 1] = k; // ����Ŀ��ֵ��j + 1����Ϊ for ѭ�� j--��
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