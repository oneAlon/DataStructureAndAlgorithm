package 链表;

/**
 * 83. 删除排序链表中的重复元素
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 */
public class _83_删除排序链表中的重复元素 {
    public ListNode deleteDuplicates(ListNode head) {
        ListNode node = head;
        while (node != null && node.next != null) {
            ListNode nextNode = node.next;
            if (node.val == nextNode.val) {
                // 重复元素
                node.next = nextNode.next;
            }else {
                // 不重复, 执行下一个
                node = node.next;
            }
        }
        return head;
    }
}
