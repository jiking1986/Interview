#include <iostream>
#include <stack>
#include <queue>

// ----------------------------------------------------------------

typedef struct st_node {
    int data;
    struct st_node *left;
    struct st_node *right;
} *st_tree;

st_tree g_tree;

// ----------------------------------------------------------------

int init()
{
    st_node **nodes = new st_node*[10];

    for (int i = 0; i < 10; i++)
    {
        nodes[i] = new st_node;
        nodes[i]->data = i;
        nodes[i]->left = nodes[i]->right = nullptr;
    }

    nodes[0]->left = nodes[1];
    nodes[0]->right = nodes[2];

    nodes[1]->left = nodes[3];
    nodes[1]->right = nodes[4];

    nodes[2]->left = nodes[5];
    nodes[2]->right = nodes[6];

    nodes[3]->left = nodes[7];
    nodes[3]->right = nodes[8];

    nodes[4]->left = nodes[9];

    /*
    0
    1         2
    3     4     5 6
    7 8   9
    */

    g_tree = nodes[0];

    delete[] nodes;
    nodes = nullptr;

    return 0;
}

int clean()
{
    return 0;
}

// ----------------------------------------------------------------

// Pre-Order Traversal
int xian(st_node *node)
{
    if (!node)
        return 0;

    std::cout << node->data << " ";
    xian(node->left);
    xian(node->right);

    return 0;
}

// In-Order Traversal
int zhong(st_node *node)
{
    if (!node)
        return 0;

    zhong(node->left);
    std::cout << node->data << " ";
    zhong(node->right);

    return 0;
}

// Post-Order Traversal
int hou(st_node *node)
{
    if (!node)
        return 0;

    hou(node->left);
    hou(node->right);
    std::cout << node->data << " ";

    return 0;
}

// ----------------------------------------------------------------

int xian2(st_node *node)
{
    if (!node)
        return 0;

    std::stack<st_node *> s;

    while (node || !s.empty())
    {
        while (node)
        {
            std::cout << node->data << " ";
            s.push(node);
            node = node->left;
        }

        if (!s.empty())
        {
            node = s.top();
            s.pop();
            node = node->right;
        }
    }

    return 0;
}

int zhong2(st_node *node)
{
    if (!node)
        return 0;

    std::stack<st_node *> s;

    while (node || !s.empty())
    {
        while (node)
        {
            s.push(node);
            node = node->left;
        }

        if (!s.empty())
        {
            node = s.top();
            s.pop();
            std::cout << node->data << " ";
            node = node->right;
        }
    }

    return 0;
}

int hou2(st_node *node)
{
    if (!node)
        return 0;

    hou(node->left);
    hou(node->right);
    std::cout << node->data << " ";

    return 0;
}

// ----------------------------------------------------------------

int ceng(st_node *node)
{
    if (!node)
        return 0;

    std::queue<st_node *> q;

    q.push(node);

    while (!q.empty())
    {
        st_node *it = q.front();
        q.pop();

        std::cout << it->data << " ";

        if (it->left)
            q.push(it->left);
        if (it->right)
            q.push(it->right);
    }

    return 0;
}

// ----------------------------------------------------------------

int test()
{
    init();

    xian(g_tree); std::cout << std::endl << std::endl;
    zhong(g_tree); std::cout << std::endl << std::endl;
    hou(g_tree); std::cout << std::endl << std::endl;

    xian2(g_tree); std::cout << std::endl << std::endl;
    zhong2(g_tree); std::cout << std::endl << std::endl;
    hou2(g_tree); std::cout << std::endl << std::endl;

    ceng(g_tree); std::cout << std::endl << std::endl;

    clean();

    return 0;
}

int main()
{
    return test();
}
