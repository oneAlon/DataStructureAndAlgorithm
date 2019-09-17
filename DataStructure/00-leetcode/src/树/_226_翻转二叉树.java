package 树;

/**
 * 226. 翻转二叉树
 * https://leetcode-cn.com/problems/invert-binary-tree/
 */
public class _226_翻转二叉树 {
    public TreeNode invertTree(TreeNode root) {
//        if (root == null) return root;
//        TreeNode tmpNode = root.left;
//        root.left = root.right;
//        root.right = tmpNode;
//        invertTree(root.left);
//        invertTree(root.right);
//        return root;
        if (root == null) return root;
        root.right = invertTree(root.left);

        return root;
    }
}
