public class Main {
    public static void main(String[] args) throws InterruptedException {
        Global.sortStack = "No yet";
        Global.numOps = -1;
        Global.opsNow = "No";
        Global.time = 0;
        if (args.length > 0)
            new Draw(args).start();
        else
            System.out.println("Error: haven't arguments");
    }
}
