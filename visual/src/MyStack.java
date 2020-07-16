public class MyStack implements PushSwap {

    @Override
    public void pa() {
        if (!Draw.b.empty())
            Draw.a.push(Draw.b.pop());
    }

    @Override
    public void pb() {
        if (!Draw.a.empty())
            Draw.b.push(Draw.a.pop());
    }

    @Override
    public void sa() {
        Draw.a = swap(Draw.a);
    }

    @Override
    public void sb() {
        Draw.b = swap(Draw.b);
    }

    @Override
    public void ss() {
        Draw.a = swap(Draw.a);
        Draw.b = swap(Draw.b);
    }

    @Override
    public void ra() {
        Draw.a = rotate(Draw.a);
    }

    @Override
    public void rb() {
        Draw.b = rotate(Draw.b);
    }

    @Override
    public void rr() {
        Draw.a = rotate(Draw.a);
        Draw.b = rotate(Draw.b);
    }

    @Override
    public void rra() {
        Draw.a = reverseRotate(Draw.a);
    }

    @Override
    public void rrb() {
        Draw.b = reverseRotate(Draw.b);
    }

    @Override
    public void rrr() {
        Draw.a = reverseRotate(Draw.a);
        Draw.b = reverseRotate(Draw.b);
    }
}