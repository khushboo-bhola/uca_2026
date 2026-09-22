class Node {
    int data;
    Node next;
    Node(int data) {
        this.data = data;
        this.next = null;
    }
}

public class intersectioninLL {
    public Node intersectioninLL (Node list1, Node list2){
        Node temp1=list1;
        Node temp2=list2;
        Node dummy=new Node(0);
        Node temp3=dummy;
        while(temp1!=null && temp2!=null){
            if(temp1.data<=temp2.data){
                if(temp1.data==temp2.data){
                   temp3.next=new Node(temp1.data);
                   temp1=temp1.next;
                   temp2=temp2.next;
                   temp3=temp3.next;
                }
                else{
                    temp1=temp1.next;
                }
            }
            else{
                temp2=temp2.next;
            }
        }
        return dummy.next;
    }
   
    public static void main(String[] args) {
    Node list1 = new Node(10);
    list1.next = new Node(20);
    list1.next.next = new Node(30);
    list1.next.next.next = new Node(40);
    list1.next.next.next.next = new Node(50);
    Node list2 = new Node(30);
    list2.next = new Node(50);
    intersectioninLL obj = new intersectioninLL();
    Node result = obj.intersectioninLL(list1, list2);
    Node temp = result;
    while (temp != null) {
        System.out.print(temp.data + " -> ");
        temp = temp.next;
    }
    System.out.println("null");
}
}