package 链表;

/**
 * 206. 反转链表
 * https://leetcode-cn.com/problems/reverse-linked-list/
 * 反转一个单链表。
 */
public class _206_反转链表 {
    /**
     * 递归方式
     * @param head
     * @return
     */
    public ListNode reverseList(ListNode head) {
        if (head.next == null || head == null) return head;
        ListNode newNode = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return newNode;
    }

    /**
     * 非递归方式
     * @param head
     * @return
     */
    public ListNode reverseList2(ListNode head) {
        ListNode newNode = null;
        while (head != null) {
            ListNode nextNode = head.next;
            head.next = newNode;
            newNode = head;
            head = nextNode;
        }
        return newNode;
    }

}
