#pragma once
#include<iostream>

namespace expr
{
    /// @brief Class for storing and processing data in binary tree structure
    class BinaryTree
    {
    public:
        struct Node
        {
            std::string data;
            Node* left, * right;

            Node() : left(nullptr), right(nullptr) {}
            Node(std::string data) : data(data), left(nullptr), right(nullptr) {}
        };

        Node* root;

        BinaryTree() : root(nullptr) {}

        ~BinaryTree();

        /// @brief Deletes selected node. In order not to break the connectivity of the tree,
        ///  connects node's parent node with node's child node.
        /// @param parent Node's parent
        /// @param node Node to delete
        /// @param child Node's child to reconnect parent to
        void DeleteNode(Node* parent, Node* node, Node* child);

        /// @brief Copies all data of subtree into new tree
        /// @param node Source subtree root
        /// @return Root of the new tree
        Node* Copy(const Node* node) const
        {
            if (!node)
                return nullptr;

            Node* new_node = new Node(node->data);

            new_node->left = Copy(node->left);
            new_node->right = Copy(node->right);

            return new_node;
        }

        /// @brief Deletes all nodes of the tree except the tree's root
        /// @param root Root of the tree to delete
        void Clear(Node* node = nullptr);
    };
}
