public class LinkedList {
	private static class Node { // LinkedList.Node
		// by default, an inner class automatically contains a pointer to the outer class
		// static classes do not
    int val;
		Node next;
		//		public Node( ...) {}
	}
	private Node head;
	public LinkedList() { // O(1)
    head = null;
	}

	// no need to do this in Java, the garbage collector handles the memory
	public void finalize() {

	}
	public void addEnd(int v) {
		if (head == null) {
			head = new Node();
			head.val = v;
			head.next = null;
			return;
		}
		Node p;
		for (p = head; p.next != null; p = p.next)  //O(n)
			;
		Node temp = new Node();
		temp.val = v;
		temp.next = null;
		p.next = temp;
	}
	
	public void addStart(int v) { //O(1)
		Node temp = new Node();
		temp.val = v;
		temp.next = head;
		head = temp;
	}
	public void insert(int i, int v) {
		Node p = head;
    while (i > 0) {
			if (p == null)
				return;
			p = p.next;
      i--;
		}
    Node temp = new Node();
		temp.val = v;
		temp.next = p.next; // remember the ones after p!
		p.next = temp;
	}
	
	public void removeEnd() {
		if (head == null)
			return;
		if (head.next == null) {
			head = null;
			return;
		}
		Node p;
		for (p = head; p.next.next != null; p = p.next)
			;
		p.next = null;
	}
	public void removeStart() {
		if (head == null)
			return;
		head = head.next;
	}
	//	public void remove(int i) {}
	//	public int get(int i) {  }
	//	public void set(int i, int v) {}
	public String toString() {
		//		"[1,2,3,4,5,6,7,]"

		//		StringBuffer b = new StringBuffer();//size*6  );
		StringBuilder b = new StringBuilder();//size*6  ); // preallocate size, non-thread-safe
		b.append('[');
		for (Node p = head; p != null; p = p.next) { // O(n)
			b.append(p.val).append(","); //O(n)
		}
		b.append(']');
    return b.toString();
	}

	public int size() { //O(n)
		int count = 0;
		for (Node p = head; p != null; p = p.next)
			count++;
		return count;
	}

	public int get(int i) { // O(n)
		Node p = head;
		for ( ; i > 0; i--, p = p.next)
			if (p == null)
				throw new IndexOutOfBoundsException("LinkedList index " + i);
    return p.val;
	}
	// this one is bad, just an example of what NOT to do.
	public String toString2() { // horrible O(n^2)
		StringBuilder b = new StringBuilder();//size*6  ); // preallocate size, non-thread-safe
		b.append('[');
		final int SIZE = size();
		for (int i = 0; i < SIZE; i++) {
			b.append(get(i)).append(","); //O(n)
		}
		b.append(']');
    return b.toString();
	}

	public static void main(String[]args) {
		LinkedList a = new LinkedList();
		for (int i = 0; i < 10; i++)
			a.addStart(i);
		System.out.println(a);
		for (int i = 0; i < 10; i++)
			a.addEnd(i);
		System.out.println(a);
		
			
	}
}	
