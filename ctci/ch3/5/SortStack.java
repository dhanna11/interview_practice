import java.util.*;
public class SortStack {

    public static Deque<Integer> sortStack(Deque<Integer> stack) {
	Deque<Integer> tempStack = new ArrayDeque<Integer>();

	while (!stack.isEmpty()) {
	    int element = stack.pop();
	    while (!tempStack.isEmpty() && tempStack.peek() > element) {
		stack.push(tempStack.pop());
	    }
	    tempStack.push(element);
	}
	while (!tempStack.isEmpty())
	    stack.push(tempStack.pop());
	return stack;
    }

    public static void swapStacks(Deque<Integer> src, Deque<Integer> dst) {
	while (!src.isEmpty()) dst.push(src.pop());
    }
    
    public static void main(String[] args) {
	Deque<Integer> stack = new ArrayDeque<Integer>();
	stack.push(3);
	stack.push(4);
	stack.push(10);
	stack.push(6);
	stack.push(22);
	Deque<Integer> sortedStack = sortStack(stack);
	for (Integer i: sortedStack) {
	    System.out.println(i);
	}
    }
}
