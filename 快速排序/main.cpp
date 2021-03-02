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
    int pos = start; // ����ƶ�λ��
    for (int i = start; i < end; i++)
    {
        if (arr[i] < arr[end]) // end����λ������Ҫ�Ƚϵı��ֵ������Ԫ�������Ƚ�
        {
            swap(arr[pos], arr[i]); // ���������
            pos++;                  // �ƶ�������
        }
    }
    swap(arr[end], arr[pos]); // ���ֵ�뽻���㻥��
    return pos;
}

int sort(int arr[], int start, int end)
{
    if (!arr || start > end)
        return -1;

    if (start == end)
        return 0;

    int pos = partition(arr, start, end); // ��ȡ���λ
    if (pos > start)
        sort(arr, start, pos - 1); // ������
    if (pos < end)
        sort(arr, pos + 1, end); // ������

    return 0;
}
#else
template <typename T>
void quick_sort_recursive(T arr[], int start, int end) {
    if (start >= end)
        return;
    T mid = arr[end];
    int left = start, right = end - 1;
    while (left < right) { //��������Χ����Ѱ����ŦԪֵС����Ԫ�أ�Ȼ�����Ԫ�����Ҳ�Ԫ�ؽ���
        while (arr[left] < mid && left < right) //��ͼ������ҵ�һ������ŦԪ�����Ԫ��
            left++;
        while (arr[right] >= mid && left < right) //��ͼ���Ҳ��ҵ�һ������ŦԪ��С��Ԫ��
            right--;
        std::swap(arr[left], arr[right]); //����Ԫ��
    }
    if (arr[left] >= arr[end])
        std::swap(arr[left], arr[end]);
    else
        left++;
    quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left + 1, end);
}
template <typename T> //�������c���Կ�ʹ��,��Ҫʹ�����(class)�r����O��"С�"(<)��"���"(>)��"��С�"(>=)���\���ӹ���
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