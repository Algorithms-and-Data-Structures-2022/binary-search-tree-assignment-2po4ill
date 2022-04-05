#include "assignment/binary_search_tree.hpp"

namespace assignment {

  BinarySearchTree::~BinarySearchTree() {
    BinarySearchTree::Clear();
  }

  void BinarySearchTree::Insert(int key, int value) {
    insert(key, value, root_);
  }

  bool BinarySearchTree::Remove(int key) {
    return remove(key, root_);
  }

  void BinarySearchTree::Clear() {
    clear(root_);
    root_ = nullptr;
  }

  std::optional<int> BinarySearchTree::Find(int key) const {
    Node* current = find(key, root_);
    if (current == nullptr)
    {
      return std::nullopt;
    }
    return current->value;
  }

  bool BinarySearchTree::Contains(int key) const {
    Node* current = find(key, root_);
    if (current == nullptr)
    {
      return false;
    }
    return true;
  }

  bool BinarySearchTree::IsEmpty() const {
    if(root_ == nullptr)
    {
      return true;
    }
    return false;
  }

  std::optional<int> BinarySearchTree::FindMin() const {
    if (root_ == nullptr)
    {
      return std::nullopt;
    }
    Node* minim = find_min(root_);
    return minim->value;
  }

  std::optional<int> BinarySearchTree::FindMax() const {
    if (root_ == nullptr)
    {
      return std::nullopt;
    }
    Node* maxim = find_max(root_);
    return maxim->value;
  }

  Node* BinarySearchTree::root() const {
    return root_;
  }

  // вспомогательные методы

  void BinarySearchTree::insert(int key, int value, Node*& node) {
    if (node == nullptr)
    {
      Node* new_Node = new Node(key, value);
      node = new_Node;
    }
    if (key < node->key)
    {
      insert(key, value, node->left);
    }
    else if (key > node->key)
    {
      insert(key, value, node->right);
    }
    else if (key == node->key)
    {
      node->value = value;
    }
  }

  bool BinarySearchTree::remove(int key, Node*& node) {
    if (node == nullptr)
    {
      return false;
    }
    if (key == node->key)
    {
      if (node->left != nullptr && node->right != nullptr)
      {
        Node* minim = find_min(node->right);
        node->key = minim->key;
        node->value = minim->value;
        return remove(minim->key, node->right);
      }
      else if (node->left != nullptr)
      {
        Node* lefty = node->left;
        delete node;
        node = lefty;
        return true;
      }
      else
      {
        Node* righty = node->right;
        delete node;
        node = righty;
        return true;
      }
    }
    if (key < node->key)
    {
      return remove(key, node->left);
    }
    return remove(key, node->right);
  }

  void BinarySearchTree::clear(Node* node) {
    if (node != nullptr)
    {
      clear(node->left);
      clear(node->right);
      delete node;
    }
  }

  Node* BinarySearchTree::find(int key, Node* node) const {
    if (node == nullptr)
    {
      return nullptr;
    }

    if (key == node->key)
    {
      return node;
    }

    if (key < node->key)
    {
      return find(key, node->left);
    }

    if (key > node->key)
    {
      return find(key, node->right);
    }
  }

  Node* BinarySearchTree::find_min(Node* node) const {
    while (node->left != nullptr)
    {
      node = node->left;
    }
    return node;
  }

  Node* BinarySearchTree::find_max(Node* node) const {
    while(node->right != nullptr)
    {
      node = node->right;
    }
    return node;
  }

}  // namespace assignment