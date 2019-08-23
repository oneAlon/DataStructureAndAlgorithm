package 链表;

/**
 * 203. 移除链表元素
 * https://leetcode-cn.com/problems/remove-linked-list-elements/
 * 删除链表中等于给定值 val 的所有节点。
 */
public class _203_移除链表元素 {
    public ListNode removeElements(ListNode head, int val) {
        // 递归方式
//        if (head == null)
//            return head;
//        head.next = removeElements(head.next, val);
//        return head.val == val ? head.next : head;

        // 非递归 O(n)
//        while (head != null && head.val == val) {
//            head = head.next;
//        }
//        if (head == null) {
//            return null;
//        }
//        ListNode prevNode = head;
//        ListNode node = head.next;
//        while (node != null) {
//            if (node.val == val) {
//                prevNode.next = node.next;
//            }else {
//                prevNode = node;
//            }
//            node = node.next;
//        }
//        return head;

        // 非递归
        ListNode newHead = new ListNode(0);
        newHead.next = head;
        ListNode tempNode = newHead;
        while (tempNode.next != null) {
            if (tempNode.next.val == val) {
                tempNode.next = tempNode.next.next;
            } else {
                tempNode = tempNode.next;
            }
        }
        return newHead.next;
    }
}
