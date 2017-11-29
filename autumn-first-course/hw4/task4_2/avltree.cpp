#include "avltree.h"

struct Node
{
    char key;
    unsigned char height;
    Node *left;
    Node *right;
    Node(int value)
    {
        key = value;
        left = right = nullptr;
        height = 1;
    }
};

struct AVLTree
{
    Node *root;
};

AVLTree *createAVLTree()
{
    AVLTree *tree = new AVLTree;
    tree->root = nullptr;
    return tree;
}

unsigned char getHeight(Node *node)
{
    return (node == nullptr) ? 0 : node->height;
}

int getBalanceFactor(Node *node)//получение разницы высот правого и левого поддеревьев дерева с корнем node
{
    return getHeight(node->right) - getHeight(node->left);
}

void setCorrectHeight(Node* node)
{
    unsigned char hLeft = getHeight(node->left);
    unsigned char hRight = getHeight(node->right);
    node->height = ((hLeft > hRight) ? hLeft : hRight) + 1;
}

bool contains(AVLTree *tree, char value)
{
    Node *currNode = tree->root;
    while (currNode != nullptr)
    {
        if (value > currNode->key)
        {
            currNode = currNode->right;
        }
        else if (value < currNode->key)
        {
            currNode = currNode->left;
        }
        else
        {
            return true;
        }
    }
    return false;
}

Node *rotateRight(Node *node)
{
    Node *newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    setCorrectHeight(node);
    setCorrectHeight(newRoot);
    return newRoot;
}

Node *rotateLeft(Node *node)
{
    Node *newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    setCorrectHeight(node);
    setCorrectHeight(newRoot);
    return newRoot;
}

Node *balance(Node *node)
{
    setCorrectHeight(node);
    if (getBalanceFactor(node) == 2)
    {
        if (getBalanceFactor(node->right) < 0)
        {
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }
    if (getBalanceFactor(node) == -2)
    {
        if (getBalanceFactor(node->left) > 0)
        {
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }
    return node;
}

Node *insert(Node *root, char value)
{
    if (root == nullptr)
    {
        return new Node(value);
    }
    if (value < root->key)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }
    return balance(root);
}

void add(AVLTree *tree, char value)
{
    Node *root = tree->root;
    tree->root = insert(root, value);
}

void clear(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    if ((root->left == nullptr) && (root->right == nullptr))
    {
        delete root;
        return;
    }
    clear(root->left);
    clear(root->right);
    delete root;
}
void clearAVLTree(AVLTree *tree)
{
     Node *root = tree->root;
     clear(root);
     tree->root = nullptr;
}


