package 链表;

/**
 * 21. 合并两个有序链表
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
 */
public class _21_合并两个有序链表 {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode newNode = new ListNode(-1);
        ListNode tempNode = newNode;
        while ((l1 != null) && (l2 != null)) {
            if (l1.val <= l2.val) {
                tempNode.next = l1;
                l1 = l1.next;
            }else  {
                tempNode.next = l2;
                l2 = l2.next;
            }
            tempNode = tempNode.next;
        }
        if (l1 != null) {
            tempNode.next = l1;
        }
        if (l2 != null) {
            tempNode.next = l2;
        }

        return newNode.next;
    }
}
