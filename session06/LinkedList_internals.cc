#include <iostream>
using namespace std;
									 
class LinkedList {
private:
	class Node {
	public:
    int val;
		Node* next;
		Node(int v, Node* n) : val(v), next(n) {}
	};
	Node* head;
public:
	LinkedList() : head(nullptr) {}  //O(1)
	~LinkedList() { //O(n)
		Node* q;
		for (Node* p = head; p != nullptr; p = q) {
			q = p->next;
			delete p; //O(1)
		}
	}

	void addEnd(int v) { //O(n)
		if (head == nullptr) {
			head = new Node(v, nullptr); //O(1)
			return;
		}
		Node* p;
		for (p = head; p->next != nullptr; p = p->next)  //O(n)
			;
		p->next = new Node(v, nullptr); //O(1)
	}
	
	 void addStart(int v) { //O(1)
		head = new Node(v, head);
	}
	 void insert(int i, int v) {
		Node* p = head;
    while (i > 0) {
			if (p == nullptr)
				return;
			p = p->next;
      i--;
		}
    p->next = new Node(v, p->next);
	}
	
	void removeEnd() {
		if (head == nullptr)
			return;
		if (head->next == nullptr) {
			delete head;
			head = nullptr;
			return;
		}
		Node* p;
		for (p = head; p->next->next != nullptr; p = p->next)
			;
		delete p->next;
		p->next = nullptr;
	}
	void removeStart() {
		if (head == nullptr)
			return;
		head = head->next;
	}

	friend ostream& operator<<(ostream& s, const LinkedList& list) {
		for (Node* p = list.head; p != nullptr; p = p->next) {
			s << p->val << ',';
		}
		return s;
	}
 int size() const { //O(n)
		int count = 0;
		for (Node* p = head; p != nullptr; p = p->next)
			count++;
		return count;
	}

	int get(int i) const { // O(n)
		Node* p = head;
		for ( ; i > 0; i--, p = p->next)
			if (p == nullptr)
				throw "LinkedList index out of bounds";
    return p->val;
	}
	class Iter {
	private:
		Node* cur;
	public:
		Iter(LinkedList& list) {
			cur = list.head;
		}
		bool operator !() const { return cur != nullptr; }
		void operator ++() { cur = cur ->next; }
		int& operator *() { return cur->val; }
	};

	class Const_Iter {
	private:
		Node* cur;
	public:
		Const_Iter(const LinkedList& list) {
			cur = list.head;
		}
		bool operator !() const { return cur != nullptr; }
		void operator ++() { cur = cur ->next; }
		int operator *() const { return cur->val; }
	};

}	;


int main() {
	LinkedList a;
	for (int i = 0; i < 10; i++)
		a.addStart(i);
	cout << a << '\n';
	for (int i = 0; i < 10; i++)
		a.addEnd(i);
	for (LinkedList::Iter i = a; !i; ++i)
		*i *= 2;
	cout << a << '\n';
}
	


