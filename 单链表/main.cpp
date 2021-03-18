#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

typedef struct __SLink
{
    char data[100];
    __SLink *next;
}SLink;

void printfSLink(SLink *p)
{
    while (p)
    {
        printf("%s ", p->data);
        p = p->next;
    }
    printf("\n");
}

SLink *init()
{
    SLink *head = nullptr, *cursor = nullptr;
    for (int i = 0; i < 20; i++)
    {
        SLink *p = new SLink;
        sprintf(p->data, "%d", i);
        p->next = nullptr;

        if (cursor)
        {
            cursor->next = p;
            cursor = p;
        }

        if (!cursor || !head)
            cursor = head = p;
    }
    return head;
}

void clean(SLink *node)
{
    while (node)
    {
        SLink *p = node;
        node = node->next;
        delete p;
        p = nullptr;
    }
}

SLink *reverse1(SLink *node)
{
    SLink *prev = nullptr, *next = nullptr; // һ��ʼ��ת����һ���ڵ�Ϊ��
    while (node)
    {
        next = node->next; // �����һ���ڵ�
        node->next = prev; // ����ǰ�ڵ��nextָ����һ���ڵ㣨��ʼ��ת��
        prev = node;       // �������棩����һ���ڵ�ָ��ǰ�ڵ�
        node = next;       // ��ǰ�ڵ�ָ���¸��ڵ�
    }
    return prev;
}

SLink *reverse2(SLink *node)
{
    if (!node || !node->next) // ��ǰ�ڵ�Ϊ�� | ��һ���ڵ�Ϊ�� | Ϊ���һ���ڵ�
        return node; // �˽ڵ�Ϊ��ת�������ͷ
    SLink *head = reverse2(node->next);
    node->next->next = node; // �ӵڶ����ڵ㿪ʼ��תָ��
    node->next = NULL; // ��ǰ�ڵ��nextָ��ڵ��Ѿ���ת����ǰ�ڵ��nextָ����Ҫ�Ͽ���ָ��
                       //���������Ϊ��ǰ�ڵ�Ϊ��δ��ת�����ֵ����һ���ڵ��ˣ�
                       // �����ָ��գ���ԭ�����ͷ��ת����β��next��Ϊ������γɻ���
    return head;
}

SLink *reverse3(SLink *node)
{
    SLink *head = nullptr;
    while (node)
    {
        SLink *next = node->next;
        node->next = head;
        head = node;
        node = next;
    }
    return head;
}

// Q�� ����ָ��
bool hasCycle(SLink *head) {
    auto walker = head;
    auto runner = head;
    while (runner && runner->next)
    {
        walker = walker->next;
        runner = runner->next->next;
        if (walker == runner)
            return true;
    }
    return false;
}

SLink *reverseex(SLink *node, int start, int end)
{
    SLink *head = node;

    if (!node || start >= end)
        return node;

    // ��ȡ�ؼ��ڵ����
    SLink *subLinkStartPrev = nullptr;
    SLink *subLinkEndNext = nullptr;
    SLink *subLinkStart = nullptr;
    SLink *subLinkEnd = nullptr;
    {
        int counter = 0;

        while (node)
        {
            if (start && start - 1 == counter)
                subLinkStartPrev = node;

            if (counter == start)
                subLinkStart = node;

            if (counter == end || !node->next)
            {
                subLinkEnd = node;
                subLinkEndNext = subLinkEnd->next;
                break;
            }

            node = node->next;
            counter++;
        }
    }

    // ��ת����
    SLink *subLink = nullptr;
    {
        subLinkEnd->next = nullptr;
        subLink = reverse1(subLinkStart);
    }

    // ��������
    {
        if (subLinkStartPrev)
            subLinkStartPrev->next = subLink;

        SLink *subNode = subLink;
        while (subNode && subNode->next)
            subNode = subNode->next;
        subNode->next = subLinkEndNext;

        if (subLinkStartPrev == nullptr)
            head = subLink;
    }

    return head;
}

int test()
{
    SLink *head = init();
    printfSLink(head);

    SLink *head0 = reverseex(head, 0, 10);
    printfSLink(head0);

    SLink *head1 = reverse1(head);
    printfSLink(head1);

    SLink *head2 = reverse2(head1);
    printfSLink(head2);

    SLink *head3 = reverse3(head2);
    printfSLink(head3);

    clean(head);

    return 0;
}

int main()
{
    test();
    return 0;
}