import java.util.*;

public class Valid implements Error {
    Stack<Integer> stack = new Stack<>();
    String[] args;

    Valid(String[] args) {
        this.args = args.clone();
    }

    Stack<Integer> valid() {
        String[] split;
        int key = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        ArrayList<Integer> list = new ArrayList<>();

        for (int i = 0; i < args.length; i++) {
            split = args[i].split("\\s+");
            for (int j = 0; j < split.length; j++) {
                if (!split[j].isEmpty()) {
                    int num = 0;
                    long val = 0;
                    try {
                        val = Long.parseLong(split[j]);
                    } catch (Exception e) {
                        error("Error: not integer value: " + split[j]);
                    }
                    try {
                        num = Math.toIntExact(val);
                    } catch (Exception e) {
                        error("Error: not integer value: " + val);
                    }
                    if (list.contains(num))
                        error("Error: duplicate numbers: " + num);
                    list.add(num);
                    map.put(num, key++);
                }
            }
        }
        ArrayList<Integer> list1 = new ArrayList<>(list);
        Collections.reverse(list1);
        Collections.sort(list);
        for (int i = 0; i < list.size(); i++) {
            map.replace(list.get(i), map.get(list.get(i)), (i + 1) * 1024 / list.size());
        }
        for (int i = 0; i < list1.size(); i++) {
            this.stack.push(map.get(list1.get(i)));
        }
        Global.time = 2500 / stack.size();
        return this.stack;
    }
}
