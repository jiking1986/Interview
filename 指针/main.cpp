#include <memory>

int test()
{
    int **array;
    array = new int *[10];
    for (int i = 0; i<10; i++)
    {
        array[i] = new int[5];
        memset(array[i], i, 5 * sizeof(int));
    }

    for (int i = 0; i < 10; i++)
    {
        delete[] array[i];
        array[i] = nullptr;
    }
    delete[] array;
    array = nullptr;

    return 0;
}

int main()
{
    return test();
}
