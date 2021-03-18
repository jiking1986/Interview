#include <stdio.h>
#include <string>
#include <memory>

// ----------------------------------------------------------------

template<typename T>
struct DNode {
    DNode *prev;
    DNode *next;
    T data;
};

// ----------------------------------------------------------------

template<typename T>
class CDLink {
public:
    CDLink();
    CDLink(CDLink<T> &other);
    ~CDLink();

public:
    //CDLink &operator=(const CDLink& other);

    int size();
    bool isEmpty();

    DNode<T> *head();
    T get(int index);

    void insert(int index, const T& t);
    void push_back(const T &t);

    void erase(int index);
    void clear();

private:
    DNode<T> *getNode(int index);

private:
    DNode<T> *m_head;
    int m_count;
};

// ----------------------------------------------------------------

template <typename T>
CDLink<T>::CDLink() : m_head(nullptr), m_count(0)
{
    printf("CDLink()\r\n");
}

template <typename T>
CDLink<T>::CDLink(CDLink<T> &other) : m_head(nullptr), m_count(0)
{
    printf("CDLink(const CDLink &other)\r\n");

    other.size();

    //DNode<T> *p = m_head;
    //DNode<T> *pOther = other.head();
    //while (pOther)
    //{
    //    DNode<T> *node = new DNode<T>;

    //    node->data = p->data;
    //    node->next = nullptr;

    //    if (!p)
    //        p = node;
    //    else
    //    {
    //        node->prev = p;
    //        p->next = node;
    //    }

    //    m_count++;
    //}
}

template <typename T>
CDLink<T>::~CDLink()
{
    this->clear();
}

//template <typename T>
//CDLink<T> &CDLink<T>::operator=(const CDLink<T>& other)
//{
//    return *this;
//}

template <typename T>
DNode<T> *CDLink<T>::getNode(int index)
{
    if (index < 0 || index >= m_count)
        return nullptr;

    DNode<T> *p = m_head;
    int i = 0;
    while (i++ < index)
        p = p->next;

    return p;
}

template <typename T>
int CDLink<T>::size()
{
    return m_count;
}

template <typename T>
bool CDLink<T>::isEmpty()
{
    return m_count == 0;
}

template <typename T>
DNode<T> *CDLink<T>::head()
{
    return m_head;
}

template <typename T>
T CDLink<T>::get(int index)
{
    DNode<T> *p = getNode(index);
    if (p)
        return p->data;
    else
        throw;
}

template <typename T>
void CDLink<T>::insert(int index, const T& t)
{
    if (index == 0)
    {
        DNode<T> *node = new DNode<T>;

        node->data = t;
        node->prev = nullptr;
        node->next = m_head;

        if (m_head)
            m_head->prev = node;
        m_head = node;
        m_count++;
    }
    else
    {
        DNode<T> *p = getNode(index);
        if (p)
        {
            DNode<T> *node = new DNode<T>;

            node->data = t;
            node->prev = p->prev;
            node->next = p;

            p->prev->next = node;
            p->prev = node;

            m_count++;
        }
    }
}

template <typename T>
void CDLink<T>::push_back(const T &t)
{
    if (m_count == 0)
    {
        DNode<T> *node = new DNode<T>;

        node->data = t;
        node->prev = nullptr;
        node->next = nullptr;

        m_head = node;
        m_count = 1;
    }
    else
    {
        DNode<T> *p = getNode(m_count - 1);
        if (p)
        {
            DNode<T> *node = new DNode<T>;

            node->data = t;
            node->prev = p;
            node->next = nullptr;

            p->next = node;
            m_count++;
        }
    }
}

template <typename T>
void CDLink<T>::erase(int index)
{
    DNode<T> *p = getNode(index);
    if (p)
    {
        if (p->prev)
            p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;

        delete p;
        p = nullptr;
        m_count--;
        if (m_count == 0)
            m_head = nullptr;
    }
}

template <typename T>
void CDLink<T>::clear()
{
    DNode<T> *p = m_head;
    while (p)
    {
        DNode<T> *cur = p;
        p = p->next;
        delete cur;
        cur = nullptr;
    }
    m_head = nullptr;
    m_count = 0;
}

// ----------------------------------------------------------------

int main()
{
    //std::shared_ptr<int> test = std::make_shared<int>(1);

    {
        CDLink<int> link;

        link.insert(0, 10);
        link.erase(0);

        link.push_back(0);
        link.push_back(1);
        link.push_back(2);
        link.push_back(3);
        link.push_back(4);
        link.push_back(5);

        link.insert(5, 15);
        link.erase(5);

        DNode<int> *head = link.head();

        CDLink<int> link2 = link;

        CDLink<int> link3;
        link3 = link;

        link.clear();
    }

    {
        CDLink<std::string> link;

        link.push_back("string0");
        link.push_back("string1");
        link.push_back("string2");
        link.push_back("string3");
        link.push_back("string4");
        link.push_back("string5");
    }

    return 0;
}
