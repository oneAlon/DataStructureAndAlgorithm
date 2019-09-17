package com.onealon;

import com.onealon.printer.BinaryTrees;

public class Main {
    /**
     * main入口
     * @param args
     */
    public static void main(String[] args) {
        System.out.println("二叉树");

        // 构建二叉搜索树
        BinarySearchTree tree = new BinarySearchTree();
        int treeNode[] = {10, 5, 15, 3, 7, 18};
        for (int i = 0; i < treeNode.length; i++) {
//            tree.add(((int)(Math.random() * 100)));
            tree.add(treeNode[i]);
        }
        BinaryTrees.println(tree);

        // 前序遍历
        System.out.println("前序遍历");
        tree.preorderTraversal();
        System.out.println();

        // 前序遍历非递归
        System.out.println("前序遍历非递归");
        tree.preorderNoTraversal();
        System.out.println();

        // 层序遍历
        System.out.println("层序遍历");
        tree.levelOrderTraversal();
        System.out.println("");
//        tree.levelOrderTraversal(new BinarySearchTree.Visitor() {
//            @Override
//            public void visit(Object element) {
//                System.out.println(element + "-");
//            }
//        });

        // 树的深度
        System.out.print("树的深度: ");
        System.out.println(tree.treeHeight());
    }
}
