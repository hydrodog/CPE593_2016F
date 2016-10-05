public class LinkedList_B {

	private static class Node { // LinkedList_B.Node
		// 12 bytes overhead
		int val; // 4
		Node next; // 4 bytes
		// hidden pointer to parent (LinkedList_B) 4  (not with static)
	}

  Node head;
	public LinkedList_B() {
		head = null;
	}
	
	public void addEnd(int v) {
		if (head == null) {
			head = new Node();
			head.val = v;
			head.next = null;
			return;
		}
		Node p;
		for (p = head; p.next != null; p = p.next)
			;
		Node temp = new Node();
		temp.val = v;
		temp.next = null;
		p.next = temp;
	}

	public void addStart(int v) {
		Node temp = new Node();
		temp.val = v;
		temp.next = head;
		head = temp;
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
		LinkedList_B x = new LinkedList_B();
		for (int i = 0; i < 10; i++)
			x.addEnd(i);
		for (int i = 0; i < 10; i++)
			x.addStart(i);
		System.out.println(x);
	}
		
}
