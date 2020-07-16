import javax.swing.*;
import java.awt.*;
import java.util.Scanner;
import java.util.Stack;
import java.util.concurrent.TimeUnit;

public class Draw extends JFrame implements Error {
    static Stack<Integer> a;
    static Stack<Integer> b;

    Draw(String[] args) {
        super("Visual sort");
        a = (new Valid(args)).valid();
        b = new Stack<>();
        setSize(new Dimension(2100, 1200));
        setLocationRelativeTo(null);
        setLocation(0, 0);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setResizable(false);
        setVisible(true);
    }

    void start() throws InterruptedException {
        Scanner scan = new Scanner(System.in);
        doOpAndDraw("no");
        while (scan.hasNextLine()) {
            String op = scan.nextLine();
            doOpAndDraw(op);
        }
    }

    void doOpAndDraw(String op) throws InterruptedException {
        MyStack myStack = new MyStack();
        if (op.equals("pa")) {
            myStack.pa();
        } else if (op.equals("pb")) {
            myStack.pb();
        } else if (op.equals("sa")) {
            myStack.sa();
        } else if (op.equals("sb")) {
            myStack.sb();
        } else if (op.equals("ss")) {
            myStack.ss();
        } else if (op.equals("ra")) {
            myStack.ra();
        } else if (op.equals("rb")) {
            myStack.rb();
        } else if (op.equals("rr")) {
            myStack.rr();
        } else if (op.equals("rra")) {
            myStack.rra();
        } else if (op.equals("rrb")) {
            myStack.rrb();
        } else if (op.equals("rrr")) {
            myStack.rrr();
        } else if (op.equals("no")) {
            myStack.pa();
        } else
            return;
        Global.opsNow = op;
        Global.numOps++;
        Panel panel = new Panel(a, b);
        panel.add(new JLabel("Number of operations: " + Global.numOps, Label.LEFT));
        panel.add(new JLabel("                 Last operation: " + Global.opsNow, Label.RIGHT));
        getContentPane().add(panel);
        validate();
        TimeUnit.MILLISECONDS.sleep(Global.time);
        getContentPane().remove(panel);
    }

}
