public class FirstCommonAncestor {

    static class Node {
	public Node left;
	public Node right;
    }

    public static void main(String[] args) {
	Node tree = new Node();
	tree.left = new Node();
	tree.left.left = new Node();
	tree.left.right = new Node();
	tree.right = new Node();
	tree.right.left = new Node();
	tree.right.right = new Node();
	
    }
}
