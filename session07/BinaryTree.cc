#include <iostream>
using namespace std;

class BinaryTree {
private:
  class Node {
  public:
    int val;
    Node* left;				// int* a,b; a is pointer to int, b is just int
    Node* right;
    Node(int v, Node* L, Node* R) : val(v), left(L), right(R) {}


		void inorder(ostream& s) { // first do left, then me, then right
			if (left != nullptr)
				left->inorder(s);
			s << val;
			if (right != nullptr)
				right->inorder(s);
		}

		void preorder(ostream& s) { // first do me, then left right, then right child
			s << val;
			if (left != nullptr)
				left->inorder(s);
			if (right != nullptr)
				right->inorder(s);
		}

		void postorder(ostream& s) { // first do left, then right, then me
			if (left != nullptr)
				left->inorder(s);
			if (right != nullptr)
				right->inorder(s);
			s << val;
		}
		void addRecursive(int v) {
			if (v > val) {
				right->addRecursive(v);
			} else {
				left->addRecursive(v);
			}
		}

  };
  Node * root;
public:
	BinaryTree() : root(nullptr) {}
	~BinaryTree() {}	
  void add(int v) {  // O(n)
    if (root == nullptr) {
      root = new Node(v, nullptr, nullptr);
      return;
    }
		Node* p = root;
		while(true) {
			if (v > p->val) {
				if (p->right == nullptr) {
					p->right = new Node(v, nullptr, nullptr);
					return;
				} else
					p = p->right;
			} else {
				if (p->left == nullptr) {
					p->left = new Node(v, nullptr, nullptr);
					return;
				} else
					p = p->left;
			}
		}
	}
public:
	void addRecursive(int v) {
    if (root == nullptr) {
      root = new Node(v, nullptr, nullptr);
      return;
    }
		root->addRecursive(v);
	}


  void preorder(ostream& s) {
		if (root == nullptr)
			return;
		root->preorder(s);
	}

	void postorder(ostream& s) {
		if (root == nullptr)
			return;
		root->postorder(s);
	}
	void inorder(ostream& s) {
		if (root == nullptr)
			return;
		root->inorder(s);
	}


	friend ostream& operator <<(ostream& s, const BinaryTree& tree) {
		tree.root->inorder(s);
		//tree.root->postorder(s);
		//tree.root->preorder(s);
    return s;
	}
};

int main(){
  BinaryTree b;
	b.add(5);
	for (int i = 0; i < 10; i++)
		b.add(i);
	cout << b;
}
