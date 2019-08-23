package com.onealon;

import com.onealon.printer.BinaryTrees;

public class Main {
    /**
     * main入口
     * @param args
     */
    public static void main(String[] args) {
        System.out.println("二叉树");
        BinarySearchTree tree = new BinarySearchTree();
        for (int i = 0; i < 10; i++) {
            tree.add(((int)(Math.random() * 100)));
        }
        BinaryTrees.println(tree);
        // 层序遍历
        System.out.println("层序遍历");
//        tree.levelOrderTraversal();
        tree.levelOrderTraversal(new BinarySearchTree.Visitor() {
            @Override
            public void visit(Object element) {

            }
        });
    }
}
