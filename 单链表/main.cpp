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
    if (!node || !node->next) // 当前节点为空 | 下一个节点为空 | 为最后一个节点
        return node; // 此节点为反转后链表的头
    SLink *head = reverse2(node->next);
    node->next->next = node; // 从第二个节点开始反转指针
    node->next = NULL; // 当前节点的next指向节点已经反转，当前节点的next指向需要断开并指空
                       //（可以理解为当前节点为还未反转链表部分的最后一个节点了，
                       // 如果不指向空，则原链表的头反转后变成尾后，next不为空则会形成环）
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

// Q： 快慢指针
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

    // 获取关键节点变量
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

    // 反转子链
    SLink *subLink = nullptr;
    {
        subLinkEnd->next = nullptr;
        subLink = reverse1(subLinkStart);
    }

    // 连接子链
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