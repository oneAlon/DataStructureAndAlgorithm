package 树;

/**
 * 938. 二叉搜索树的范围和
 * https://leetcode-cn.com/problems/range-sum-of-bst/
 * 给定二叉搜索树的根结点 root，返回 L 和 R（含）之间的所有结点的值的和。
 * 二叉搜索树保证具有唯一的值。
 */
public class _938_二叉搜索树的范围和 {
    int result = 0;
    public int rangeSumBST(TreeNode root, int L, int R) {
        if (root == null) return 0;
        if (root.val >= L && root.val <= R) {
            result += root.val;
        }
        if (root.val < L) {
            rangeSumBST(root.right, L, R);
        }
        if (root.val > R) {
            rangeSumBST(root.left, L, R);
        }
        return result;
    }

    //         int result = 0;
//         Stack s = new Stack();
//         TreeNode node = root;
//         // 中序遍历
//         while (node != null || !s.isEmpty()) {
//             if (node != null) {
//                 s.push(node);
//                 node = node.left;
//             } else {
//                 node = (TreeNode) s.pop();
//                 int value = node.val;
//                 if (value >= L && value <= R) result += value;
//                 node = node.right;
//             }
//         }

//         return result;
}
