class RBTree {
private:
	enum Color { BLACK, RED };
	class Node {
	public:
		int val;
		Color c;
		Node* parent;
		Node* left;
		Node* right;
		Node(int v, Node* p) : val(v), c(RED), parent(p), left(nullptr), right(nullptr) {}
		Node(int v, Node* p, Node* L, Node* R) : val(v), c(RED), parent(p), left(L), right(R) {}

		Node * grandparent() const {
			if (parent != nullptr)
				return parent->parent;
			else
				return nullptr;
		}

		Node* uncle() const {
			Node *g = grandparent();
			if (g == nullptr)
				return nullptr; // No grandparent means no uncle
			return parent == g->left ? g->right : g->left;
		}
		void rb() {
			if (parent->c == BLACK)
				return;
			// case 3: parent and uncle both red colliding with new red node
			Node* u = uncle();
			if (u != nullptr) {
				parent->c = BLACK;
				u->c = BLACK;
				Node* g = grandparent();
				g->c = RED;
				g->rb();
				return;
			}
			// case 4









			
		}
	};
	Node* root;
public:
	RBTree(): root(nullptr) {}
	void add(int v) {
		if (root == nullptr) {
			root = new Node(v);
			root->c = BLACK;
			return;
		}
		Node* p = root; // root is NOT null
		while (true) {
			if (v > p->val) {
				if (p->right == nullptr) {
					p->right = new Node(v, p);
					p->right->rb();
					return;
				}
        p = p->right;
			} else {
				if (p->left == nullptr) {
					p->left = new Node(v, p);
					p->left->rb();
					return;
				}
        p = p->left;
			}
		}
		
	}
};
