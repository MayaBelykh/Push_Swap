import java.util.Stack;

public interface PushSwap {
    void pa();

    void pb();

    void sa();

    void sb();

    void ss();

    void ra();

    void rb();

    void rr();

    void rra();

    void rrb();

    void rrr();

    default Stack<Integer> swap(Stack<Integer> stack) {
        if (stack.size() < 2)
            return stack;
        int a, b;
        a = stack.pop();
        b = stack.pop();
        stack.push(a);
        stack.push(b);
        return stack;
    }

    default Stack<Integer> rotate(Stack<Integer> stack) {
        if (stack.size() < 2)
            return stack;
        int a = stack.pop();
        Stack<Integer> temp = new Stack<>();
        while (stack.size() > 0) {
            temp.push(stack.pop());
        }
        stack.push(a);
        while (temp.size() > 0) {
            stack.push(temp.pop());
        }
        return stack;
    }

    default Stack<Integer> reverseRotate(Stack<Integer> stack) {
        if (stack.size() < 2)
            return stack;
        int a;
        Stack<Integer> temp = new Stack<>();
        while (stack.size() > 1) {
            temp.push(stack.pop());
        }
        a = stack.pop();
        while (temp.size() > 0) {
            stack.push(temp.pop());
        }
        stack.push(a);
        return stack;
    }
}
