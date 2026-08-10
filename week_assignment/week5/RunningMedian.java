import java.util.PriorityQueue;
import java.util.Collections;
public class RunningMedian {
    public static void main(String[] args) {
        Median m = new Median();
        m.add(5);
        System.out.println(m.median());
        m.add(15);
        System.out.println(m.median());
        m.add(1);
        System.out.println(m.median());
        m.add(3);
        System.out.println(m.median());
    }
    static class Median {
        PriorityQueue<Integer> left;
        PriorityQueue<Integer> right;
        Median() {
            left = new PriorityQueue<>(Collections.reverseOrder());
            right = new PriorityQueue<>();
        }
        void add(int x) {
            if(left.isEmpty() || x <= left.peek())
                left.offer(x);
            else
                right.offer(x);
            if(left.size() > right.size()+1)
                right.offer(left.poll());
            else if(right.size() > left.size())
                left.offer(right.poll());
        }
        double median() {
            if(left.size() == right.size())
                return (left.peek()+right.peek())/2.0;
            return left.peek();
        }
    }
}