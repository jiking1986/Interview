#include <stdio.h>
#include <stdlib.h>

void print(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

#if 0
int min(int x, int y) {
    return x < y ? x : y;
}

void merge_sort(int arr[], int len) {
    int *a = arr;
    int *b = (int *)malloc(len * sizeof(int)); // 申请临时空间
    int seg, start;
    for (seg = 1; seg < len; seg += seg) { // 分段
        for (start = 0; start < len; start += seg * 2) {
            int low = start, mid = min(start + seg, len), high = min(start + seg * 2, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        int *temp = a;
        a = b;
        b = temp;
    }
    if (a != arr) {
        int i;
        for (i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }
    free(b);
}
#endif
#if 0
void merge_sort_recursive(int arr[], int reg[], int start, int end) {
    if (start >= end)
        return;
    int len = end - start, mid = (len >> 1) + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    merge_sort_recursive(arr, reg, start1, end1);
    merge_sort_recursive(arr, reg, start2, end2);
    int k = start;
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    while (start1 <= end1)
        reg[k++] = arr[start1++];
    while (start2 <= end2)
        reg[k++] = arr[start2++];
    for (k = start; k <= end; k++)
        arr[k] = reg[k];
}

void merge_sort(int arr[], const int len) {
    int *reg = new int[len];
    merge_sort_recursive(arr, reg, 0, len - 1);
}
#endif

#if 1
void mergeSort(int nums[], int left, int right) {  // 需要左右边界确定排序范围
    if (left >= right) return;
    int mid = (left + right) / 2;

    mergeSort(nums, left, mid);                           // 先对左右子数组进行排序
    mergeSort(nums, mid + 1, right);

    int length = right - left + 1;
    int *temp = new int[length];                   // 临时数组存放合并结果
    int i = left, j = mid + 1;
    int cur = 0;
    while (i <= mid&&j <= right) {                            // 开始合并数组
        if (nums[i] <= nums[j])
            temp[cur] = nums[i++];
        else
            temp[cur] = nums[j++];
        cur++;
    }
    while (i <= mid)
        temp[cur++] = nums[i++];
    while (j <= right)
        temp[cur++] = nums[j++];

    for (int k = 0; k < length; k++) {             // 合并数组完成，拷贝到原来的数组中
        nums[left + k] = temp[k];
    }
}
void merge_sort(int arr[], const int len) {
    mergeSort(arr, 0, len - 1);
}
#endif

void test()
{
    int arr[] = { 3,2,1,6,5,1,9,8,4,7 };
    int len = 10;
    print(arr, len);
    merge_sort(arr, len);
    print(arr, len);
}

void main()
{
    test();

#ifdef _DEBUG
    system("pause");
#endif
}