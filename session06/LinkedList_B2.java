public class LinkedList_B2 {
	private static class Node {
		int val;
		Node next;
		Node(int v, Node n) { val = v; next = n; }
	}
	private Node head;
	public LinkedList_B2() {
		head = null;
	}
	
	public void addEnd(int v) {
		if (head == null) {
			head = new Node(v, null); //O(1)
			return;
		}
		Node p;
		for (p = head; p.next != null; p = p.next)
			;
		p.next = new Node(v, null);
	}

	public void addStart(int v) {
		head = new Node(v, head);
	}
	public int removeEnd() {
		if (head == null)
			throw new IllegalOutOfBoundsException("Yo! No elements");
		if (head.next == null) {
			int temp = head.val;
			head = null;
			return temp;
		}
			
    Node p;
		for (p = head; p.next.next != null; p = p.next)
			;
		int temp = p.next.val;
		p.next = null;
		return temp;
	}

	public int removeStart() { //O(1)
		if (head == null)
			throw new IllegalOutOfBoundsException("Yo! No elements");
		int temp = head.val;
		head = head.next;
	}

	public int size() { //O(n)
		int count = 0;
		for (Node p = head; p != null; p = p.next)
			count++;
		return count;
	}

	public int get(int i) {
		
	}
	
	public String toString() {
		StringBuilder b = new StringBuilder(32768);
		b.append("[");  // [1, 2, 3, 4, 5,]
		for (Node p = head; p != null; p = p.next) //O(n)
			b.append(p.val).append(",");
		b.append("]");
		return b.toString();
	}
	
	public static void main(String[] a) {
		LinkedList_B2 x = new LinkedList_B2();
		for (int i = 0; i < 10; i++)
			x.addEnd(i);
		for (int i = 0; i < 10; i++)
			x.addStart(i);
		System.out.println(x);
	}
		
}
