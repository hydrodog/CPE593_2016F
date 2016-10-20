public class RBTree {
	private static class Node {
		int val;
		boolean red;
		Node parent;
		Node left;
		Node right;
		Node(int v, Node left, Node right) {
			red = false;
			val = v;
			this.left = left;
			this.right = right;
		}

		Node grandparent() {
			if (parent != null)
				return parent.parent;
			return null;
		}

		Node uncle() {
			Node g = grandparent();
			if (g == null)
				return null;
			if (g.left == parent)
				return g.right;
			else
				return g.left;
		}

	private Node root;
	public RBTree() { root = null; }

	void add(int v) {
		if (root == null) {
			root = new Node(v, null, null);
			root.red = false; // root is black
			return;
		}
		Node p = root;
		while (true)
			if (v > p.val) {
				if (p.right == null) {
					p.right = new Node(v, null, null);
					if (p.parent.red == false)
						return;
					// at this point your parent must be red
					Node g = grandparent();
					Node u = uncle();
					if (u.red == true) { // if uncle is also red....
						p.parent.red = false;
						u.red = false;
						g.red = true;
						// now call recursively for grandparent...
					}

					return;
				}
				
				p = p.right;
			} else {
				if (p.left == null) {
					p.left = new Node(v, null, null);
					rb();
				return;
				}
				p = p.left;
			}		

	}

}
