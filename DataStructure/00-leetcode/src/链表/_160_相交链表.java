package 链表;

/**
 * 160. 相交链表
 * https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
 * 编写一个程序，找到两个单链表相交的起始节点。
 */
public class _160_相交链表 {

    public static void main(String[] args) {
        ListNode a = new ListNode(11);
        ListNode b = new ListNode(22);
        ListNode c = new ListNode(33);
        ListNode d = new ListNode(44);
        ListNode e = new ListNode(55);
        ListNode f = new ListNode(66);
        a.next = b;
        b.next = c;
        c.next = d;
        d.next = e;
        e.next = f;
        f.next = null;
        ListNode headA = a;
        ListNode headB= c;
    }

    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) {
            return null;
        }
        ListNode nodeA = headA;
        ListNode nodeB = headB;
        int lengthA = 0;
        int lengthB = 0;
        while (nodeA != null) {
            nodeA = nodeA.next;
            lengthA++;
        }
        while (nodeB != null) {
            nodeB = nodeB.next;
            lengthB++;
        }
        if (lengthA > lengthB) {
            for (int i = 0; i < lengthA - lengthB; i++) {
                headA = headA.next;
            }
        }
        if (lengthB > lengthA) {
            for (int i = 0; i < lengthB - lengthA; i++) {
                headB = headB.next;
            }
        }
        while (headA != headB) {
            headA = headA.next;
            headB = headB.next;
        }
        return headA;
    }
}
