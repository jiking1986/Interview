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
    for (int i = 0; i < 100; i++)
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
    SLink *prev = nullptr, *next = nullptr; // 一开始翻转的上一个节点为空
    while (node)
    {
        next = node->next; // 缓存后一个节点
        node->next = prev; // 将当前节点的next指向上一个节点（开始翻转）
        prev = node;       // 将（缓存）的上一个节点指向当前节点
        node = next;       // 当前节点指向下个节点
    }
    return prev;
}

SLink *reverse2(SLink *node)
{
    if (!node || !node->next)
        return node;
    SLink *head = reverse2(node->next);
    node->next->next = node;
    node->next = NULL;
    return head;
}

int test()
{
    SLink *head = init();
    printfSLink(head);

    SLink *head1 = reverse1(head);
    printfSLink(head1);

    SLink *head2 = reverse2(head1);
    printfSLink(head2);

    clean(head);

    return 0;
}

int main()
{
    test();
    return 0;
}