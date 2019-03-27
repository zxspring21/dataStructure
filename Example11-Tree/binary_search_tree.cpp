#include <iostream>
#include <cstdlib>
using namespace std;

template<class ElemType>
class BinarySearchTree {
  public:
    BinarySearchTree() { root_ = NULL; }
    BinarySearchTree(const BinarySearchTree<ElemType> &rhs) {
      this->root_ = CopyTree(rhs.root_);
    }

    ~BinarySearchTree() {
      DeleteTree(root_);
    }

    void Insert(const ElemType &elem) {
      Node *new_node = new Node;
      new_node->data = elem;
      new_node->left = new_node->right = NULL;
      if (root_ == NULL) {
        root_ = new_node;
      } else {
        Node *cur = root_;
        Node *par;
        while (cur != NULL) {
          par = cur;
          if (elem < cur->data) {
            cur = cur->left; 
          } else {
            cur = cur->right;
          }
        }
        if (elem < par->data) {
          par->left = new_node;
        } else {
          par->right = new_node;
        }
      }
    }

    bool Search(const ElemType &elem) const {
      Node *cur = root_;
      bool found = false;
      while (cur != NULL && found != true) {
        if (elem == cur->data) {
          found = true;
        } else if (elem < cur->data) {
          cur = cur->left;
        } else {
          cur = cur->right;
        }
      }
      return found;
    } 

    void Erase(const ElemType &elem) {
      Node *cur = root_;
      Node **par = &root_;
      bool found = false;
      while (cur != NULL && found != true) {
        if (elem == cur->data) {
          if (cur->left == NULL && cur->right == NULL) {
            // Case 1
            *par = NULL;
          } else if (cur->left == NULL) {
            // Case 2
            *par = cur->right;
          } else if (cur->right == NULL) {
            // Case 3
            *par = cur->left;
          } else {
            // Case 4
            Node *rep = cur->left;
            par = &cur->left;
            while (rep->right != NULL) {
              par = &rep->right;
              rep = rep->right;
            }
            *par = rep->left;
            cur->data = rep->data;
            cur = rep;
          }
          delete cur;
          found = true;
        } else if (elem < cur->data) {
          par = &cur->left;
          cur = cur->left;
        } else {
          par = &cur->right;
          cur = cur->right;
         } 
      }
    }

    const BinarySearchTree<ElemType> &operator=(
        const BinarySearchTree<ElemType> &rhs) {
      if (this != &rhs) {
        DeleteTree(this->root_);
        this->root_ = CopyTree(rhs->root_);
      }
      return *this;
    }

  private:
    struct Node {
      ElemType data;
      Node *left;
      Node *right;
    };

    static Node* CopyTree(Node *p) {
      if (p == NULL) return p;
      Node *ret = new Node(p->data);
      ret->left = copy_tree(p->left);
      ret->right = copy_tree(p->right);
      return ret;
    }

    static void DeleteTree(Node *p) {
      if (p == NULL) return;
      DeleteTree(p->left);
      DeleteTree(p->right);
      delete p;
    }

    Node *root_;

};

int main() {
  BinarySearchTree<int> tree;

  tree.Insert(4);
  tree.Insert(2);
  tree.Insert(6);
  tree.Insert(1);
  tree.Insert(3);
  tree.Insert(5);
  tree.Insert(7);

  for (int i = 0; i < 10; ++i) {
    if (tree.Search(i)) {
      cout << i << " 被找到了. " << endl; 
    } else {
      cout << i << " 沒有被找到. " << endl;
    } 
  }
  cout << endl;

  tree.Erase(2);
  tree.Erase(1);
  tree.Erase(3);
  tree.Erase(7);

  for (int i = 0; i < 10; ++i) {
    if (tree.Search(i)) {
      cout << i << " 被找到了. " << endl; 
    } else {
      cout << i << " 沒有被找到. " << endl;
    } 
  }
  cout << endl; 

  system("pause");
  return 0;
}
