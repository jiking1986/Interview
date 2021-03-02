struct obj {
    bool mem1;
    int mem2;
    void *dat;
};

int main()
{
    obj *p = new obj[3];

    int s1 = sizeof(p);
    int s2 = sizeof(*p);
    int s3 = sizeof(p[0]);

    return 0;
}
