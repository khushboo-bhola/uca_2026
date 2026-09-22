class Node {
    int data;
    Node next;
    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class SearchInALinkedlist {
    public int findLength(Node head) {
        int len = 0;
        while (head != null) {
            head = head.next;
            len++;
        }
        return len;
    }

    public boolean isPresent(Node list1, Node list2) {
        if (list1 == null && list2 == null) {
            return true;
        }
        if (list1 == null || list2 == null) {
            return false;
        }
        int len1 = findLength(list1);
        int len2 = findLength(list2);
        if (len2 > len1) {
            return false;
        }
        Node temp1 = list1;
        while (temp1 != null) {
            if (temp1.data == list2.data) {
                Node p1 = temp1;
                Node p2 = list2;
                while (p1 != null && p2 != null) {
                    if (p1.data != p2.data) {
                        break;
                    }
                    p1 = p1.next;
                    p2 = p2.next;
                }
                if (p2 == null) {
                    return true;
                }
            }
            temp1 = temp1.next;
        }
        return false;
    }

    public static void main(String[] args) {
        Node list1 = new Node(10);
        list1.next = new Node(20);
        list1.next.next = new Node(30);
        list1.next.next.next = new Node(40);
        list1.next.next.next.next = new Node(50);
        Node list2 = new Node(20);
        list2.next = new Node(50);
        SearchInALinkedlist obj = new SearchInALinkedlist();
        System.out.println(obj.isPresent(list1, list2));
    }
}