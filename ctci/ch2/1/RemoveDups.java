class Node {
    Node next = null;
    int data;

    public Node(int d) {
	data = d;
    }

    void appendToTail(int d) {
	Node end = new Node(d);
	Node n = this;
	while (n.next != null) {
	    n = n.next;
	}
	n.next = end;
    }

    static Node deleteNode(Node head, int d) {
	Node n = head;

	if (n.data == d) {
	    return head.next;
	}

	while (n.next != null) {
	    if (n.next.data == d) {
		n.next = n.next.next;
		return head;
	    }
	    n = n.next;	    
	}
	return head;
    }

    static void printNodes(Node head) {
	Node n = head;

	while (n != null) {
	    System.out.println(n.data);
	    n = n.next;
	}
    }
}

class RemoveDups {

    List<int> elementList = new ArrayList<>();
    
    public static void main(String[] args) {
	Node head = new Node(5);
	head.appendToTail(5);
	head.appendToTail(6);
	head.appendToTail(7);
	head.appendToTail(7);
	head.appendToTail(8);
	Node.printNodes(head);
    }
}
