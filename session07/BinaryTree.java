public class BinaryTree {
	private static class Node {
		private int val;
		Node left, right;

		Node(int v) { val = v; left = null; right = null; }

		public void preorder(StringBuilder b) {
			b.append(val);			
			if (left != null)
				left.preorder();
			if (right != null)
				right.preorder(b);
		}

		public void postorder(StringBuilder b) {
			if (left != null)
				left.postorder();
			if (right != null)
				right.postorder(b);
			b.append(val);			
		}

		public void inorder(StringBuilder b) { // x + y
			if (left != null)
				left.inorder(b);
			b.append(val);
			if (right != null)
				right.inorder(b);
			
		}
	}

	private Node root;
	public BinaryTree() {
		root = null;
	}

	public void add(int v) {
		if (root == null) { // O(1)
			root = new Node(v);
			return;
		}
		Node p = root;
		while(true)
			if (v > p.val) {
				if (p.right == null) {
					p.right = new Node(v);
					return;
				}
				p = p.right;
			} else {
				if (p.left == null) {
					p.left = new Node(v);
					return;
				}
				p = p.left;
			}

	}
	
	public static void main(String[] args) {
		BinaryTree b = new BinaryTree();
		b.add(3);
	}

