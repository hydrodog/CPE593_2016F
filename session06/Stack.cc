class Stack {
private:
	GrowArray a;
public:

	Stack() {}

	void push(int v) {  a.addEnd(v); }
	int pop() { return a.removeEnd(); }

	int size() const { return a.getUsed(); } // return the number of elements on the stack
	bool isEmpty() const {} //
};

// For hW: think about how to do a stack using a LinkedList?
// what is teh minimum possible linkedlist to implement a stack?

GrowArray a;

a.addStart(3); // O(n)
a.addEnd(3); //O(1)
a.removeStart(); //O(n)
a.removeEnd() //O(1)


