#include <iostream>
#include <fstream>
using namespace std;

class LinkedList {
private:
	class Node { // LinkedList::Node
	public:
		int val;
		Node* next;
		Node(int v, Node* n): val(v), next(n) {}
	};
	Node* head;
public:
	LinkedList() {
		head = nullptr;
	}
	
	void addEnd(int v) {
		if (head == nullptr) {
			head = new Node(v, nullptr); //O(1)
			return;
		}
		Node* p;
		// (*p).  is equivalent to p->
		for (p = head; p->next != nullptr; p = p->next)
			;
		p->next = new Node(v, nullptr);
	}

	void addStart(int v) {
		head = new Node(v, head);
	}
	int removeEnd() {
		if (head == nullptr)
			throw "Yo! No elements";
		if (head->next == nullptr) {
			int temp = head->val;
			head = nullptr;
			return temp;
		}
		
    Node* p;
		for (p = head; p->next->next != nullptr; p = p->next)
			;
		int temp = p->next->val;
		p->next = nullptr;
		return temp;
	}

	int removeStart() { //O(1)
		if (head == nullptr)
			throw "Yo! No elements";
		int temp = head->val;
		head = head->next;
		return temp;
	}

	int size() { //O(1)

	}

	int operator[](int i) const {
		Node* p;
		for (p = head; i > 0; i--, p = p->next) 
			;
		return p->val;
	}
	int& operator[](int i) {
		Node* p;
		for (p = head; i > 0; i--, p = p->next) 
			;
		return p->val;
	}
  friend ostream& operator <<(ostream& s, const LinkedList& list) {
		for (Node* p = list.head; p != nullptr; p = p->next)
			s << p->val << ',';
    return s;
	}

	
		
};

int main() {
	LinkedList x;
	for (int i = 0; i < 10; i++)
		x.addEnd(i);
	for (int i = 0; i < 10; i++)
		x.addStart(i);
	cout << x << '\n';
	ofstream f("test.dat");
	f << x;	
}
