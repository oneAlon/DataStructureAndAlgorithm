package 链表;

/**
 * 234. 回文链表
 * https://leetcode-cn.com/problems/palindrome-linked-list/
 * 请判断一个链表是否为回文链表。
 */
public class _234_回文链表 {

    public static void main(String[] args) {
        ListNode a1 = new ListNode(1);
        ListNode b1 = new ListNode(1);
        ListNode c1 = new ListNode(2);
        ListNode d1 = new ListNode(1);
        d1.next = null;
        c1.next = d1;
        b1.next = c1;
        a1.next = b1;
        ListNode headA = a1;

        ListNode a2 = new ListNode(1);
        ListNode b2 = new ListNode(2);
        ListNode c2 = new ListNode(1);
        ListNode d2 = new ListNode(1);
        a2.next = b2;
        b2.next = c2;
        c2.next = null;
        ListNode headB= c2;

        isPalindrome(a1);
    }

    public static boolean isPalindrome(ListNode head) {
        boolean isPalindrome = true;
        ListNode temp1 = head;
        ListNode temp2 = reverseList(head);
        while (temp1 != null) {
            if (temp1.val != temp2.val) {
                isPalindrome = false;
            }
            temp1 = temp1.next;
            temp2 = temp2.next;
        }

        return isPalindrome;
    }

    public static ListNode reverseList(ListNode head) {
        ListNode newNode = null;
        ListNode tempNode = head;
        while (tempNode != null) {
            ListNode nextNode = tempNode.next;
            tempNode.next = newNode;
            newNode = tempNode;
            tempNode = nextNode;
        }
        return newNode;
    }
}
