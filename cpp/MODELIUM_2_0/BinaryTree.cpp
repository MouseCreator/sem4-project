#include "BinaryTree.h"


namespace expr
{
    void BinaryTree::DeleteNode(Node* parent, Node* node, Node* child)
    {
        if (parent == nullptr)
        {
            this->root = child;
            delete node;
        }
        else if (parent->left == node) {
            Node* temp = child;
            delete node;
            parent->left = temp;
        }
        else {
            Node* temp = child;
            delete node;
            parent->right = temp;
        }
    }


    void BinaryTree::Clear(Node* node)
    {
        if (node == nullptr)
            node = root;
        if (root == nullptr)
            return;

        if (node->left != nullptr)
        {
            Clear(node->left);
            delete node->left;
            node->left = nullptr;
        }
        if (node->right != nullptr)
        {
            Clear(node->right);
            delete node->right;
            node->right = nullptr;
        }
    }

    BinaryTree::~BinaryTree()
    {
        this->Clear();
        delete root;
        root = nullptr;
    }
}
