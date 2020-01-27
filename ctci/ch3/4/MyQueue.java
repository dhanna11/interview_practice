import java.util.*;
public class MyQueue<T> {

    MyQueue() {
	inStack = new ArrayDeque<T>();
	outStack = new ArrayDeque<T>();
    }

    public void add(T item) {
	inStack.push(item);
    }
    
    public T remove() {
	moveInToOut();
	return outStack.pop();
    }

    public T peek() {
	moveInToOut();
	return outStack.peek();
    }

    public boolean isEmpty() {
	return inStack.isEmpty() && outStack.isEmpty();
    }
    
    private void moveInToOut() {
	if (outStack.isEmpty())
	    while (!inStack.isEmpty()) outStack.push(inStack.pop());
    }
    
    Deque<T> inStack, outStack;
    public static void main(String[] args) {
	MyQueue<Integer> queue = new MyQueue<Integer>();
	queue.add(1);
	queue.add(2);
	queue.add(3);
	while (!queue.isEmpty())
	    System.out.println(queue.remove());
    }
}
