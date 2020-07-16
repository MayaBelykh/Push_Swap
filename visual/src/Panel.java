import javax.swing.*;
import java.awt.*;
import java.util.Stack;

public class Panel extends JPanel {
    Stack<Integer> a;
    Stack<Integer> b;
    JPanel panel;
    int x, y, width = 1, height;

    Panel(Stack<Integer> a, Stack<Integer> b) {
        super();
        this.a = new Stack<>();
        this.b = new Stack<>();
        this.a.addAll(a);
        this.b.addAll(b);
        panel = new JPanel();
        height = ((a.empty() ? 0 : a.size()) + (b.empty() ? 0 : b.size()));
        height = 1100 / (height > 0 ? height : 1);
        x = 1050;
        y = (1200 - height * ((a.empty() ? 0 : a.size()) + (b.empty() ? 0 : b.size()))) / 2;
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);
        setPreferredSize(new Dimension(width, height));
        if (!this.a.empty())
            paintNewRectsA(g, y);
        if (!this.b.empty())
            paintNewRectsB(g, y);
    }

    private void paintNewRectsA(Graphics g, int y) {
        while (this.a.size() > 0) {
            g.setColor(Color.decode("#FA8072"));
            width = this.a.peek();
            g.fillRoundRect(x - this.a.peek(), y, width, height, 8, 8);
            g.setColor(Color.decode("#FFDA00"));
            g.drawRoundRect(x - this.a.peek(), y, width, height, 8, 8);
            y += height;
            this.a.pop();
        }
    }

    private void paintNewRectsB(Graphics g, int y) {
        while (this.b.size() > 0) {
            g.setColor(Color.ORANGE);
            width = this.b.peek();
            g.fillRoundRect(x, y, width, height, 8, 8);
            g.setColor(Color.decode("#FFDAB9"));
            g.drawRoundRect(x, y, width, height, 8, 8);
            y += height;
            this.b.pop();
        }
    }
}
