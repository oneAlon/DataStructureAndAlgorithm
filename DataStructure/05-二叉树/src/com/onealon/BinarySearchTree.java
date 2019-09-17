package com.onealon;

import com.onealon.printer.BinaryTreeInfo;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

/**
 * 二叉排序树
 * 0. 概念
 * 1. 二叉排序树的打印 MJ提供的工具
 * 2. 二叉树遍历, 前中后层序遍历
 *    前序: 跟左右
 *    中序: 左跟右
 *    后续: 左右跟
 *    层序: 从上到下 从左到右
 * 3. 二叉树的应用
 */
public class BinarySearchTree<E> implements BinaryTreeInfo {

    private int size = 0;
    // 根结点
    private Node<E> root;

    /**
     * 元素数量
     * @return
     */
    public int size() {
        return size;
    }

    /**
     * 是否为空
     * @return
     */
    public boolean isEmpty() {
        return size == 0;
    }

    /**
     * 是否包含元素
     * @param element
     * @return
     */
    public boolean contains(E element) {
        return true;
    }

    /**
     * 添加
     */
    public void add(E element) {
        if (element == null) return;

        // 添加的是根结点
        if (root == null) {
            Node<E> node = new Node<>(element, null);
            root = node;
            size++;
            return;
        }

        // 查找需要添加的父结点
        Node<E> parent = root;
        Node<E> node = root;
        int cmp = 0;
        while (node != null) {
            cmp = compare(node.element, element);
            parent = node;
            if (cmp > 0) {
                // 添加到左边
                node = node.left;
            } else if (cmp < 0) {
                // 添加到右边
                node = node.right;
            } else {
                node.element = element;
                return;
            }
        }

        // parent就是要添加结点的父结点
        node = new Node<>(element, parent);
        if (cmp > 0) {
            parent.left = node;
        } else if (cmp < 0) {
            parent.right = node;
        }
        size++;
    }

    /**
     * 前序遍历
     */
    public void preorderTraversal() {
        preorderTraversal(root);
    }

    private void preorderTraversal(Node<E> node) {
        if (node == null) return;
        System.out.print(node.element);
        System.out.print(" ");
        preorderTraversal(node.left);
        preorderTraversal(node.right);
    }

    /**
     * 前序遍历非递归
     */
    public void preorderNoTraversal() {
        Stack s = new Stack();
        Node node = root;
        while (node != null || !s.isEmpty()) {
            if (node != null) {
                s.push(node);
                System.out.print(node.element);
                System.out.print(" ");
                node = node.left;
            } else {
                node = (Node)s.pop();
                node = node.right;
            }
        }
    }

    /**
     * 中序遍历: 左跟右, 二叉搜索树的中序遍历结果
     */
    public void inoderTraversal() {
        inoderTraversal(root);
    }

    private void inoderTraversal(Node<E> node) {
        if (node == null) return;
        inoderTraversal(node.left);
        System.out.print(node.element);
        System.out.print("  ");
        inoderTraversal(node.right);
    }

    /**
     * 中序遍历 非递归
     */
    public void inorderNoTraversal() {
        Stack s = new Stack();
        Node node = root;
        while (node != null || !s.isEmpty()) {
            if (node != null) {
                s.push(node);
                node = node.left;
            } else {
                node = (Node)s.pop();
                System.out.print(node.element);
                System.out.print(" ");
                node = node.right;
            }
        }
    }

    /**
     * 层序遍历: 一层一层, 使用队列
     */
    public void levelOrderTraversal() {
        levelOrderTraversal(root);
    }

    private void levelOrderTraversal(Node<E> node) {
        if (node == null) return;
        // 使用队列
        Queue<Node<E>> queue = new LinkedList<>();

        while (node != null) {
            // 先访问node
            System.out.print(node.element);
            System.out.print(" ");
            if (node.left != null) {
                queue.offer(node.left);
            }
            if (node.right != null) {
                queue.offer(node.right);
            }
            node = queue.poll();
        }
    }

//    public void levelOrderTraversal(Visitor<E> visitor) {
//        if (root == null || visitor == null) return;
//        // 使用队列
//        Queue<Node<E>> queue = new LinkedList<>();
//        Node<E> node = root;
//        while (node != null) {
//            // 先访问node
//            visitor.visit(node.element);
//            if (node.left != null) {
//                queue.offer(node.left);
//            }
//            if (node.right != null) {
//                queue.offer(node.right);
//            }
//            node = queue.poll();
//        }
//    }

    /**
     * 删除元素
     * @param element
     */
    public void remove(E element) {

    }

    private int compare(E e1, E e2) {
        return ((Comparable<E>)e1).compareTo(e2);
    }

    public Object root() {
        return root;
    }

    public Object left(Object node) {
        Node<E> myNode = (Node<E>)node;
        return  myNode.left;
    }

    public Object right(Object node) {
        Node<E> myNode = (Node<E>)node;
        return  myNode.right;
    }

    public Object string(Object node) {
        Node<E> myNode = (Node<E>)node;
        return  myNode.element + "";
    }

    public int treeHeight() {
        return treeHeight(root);
    }

    private int treeHeight(Node node) {
        if (node == null) return 0;
        int leftHeight = treeHeight(node.left);
        int rightHeight = treeHeight(node.left);
        return Math.max(leftHeight, rightHeight) + 1;
    }

    private static class Node<E> {
        E element;
        Node<E> left;
        Node<E> right;
        Node<E> parent;

        public Node(E element, Node<E> parent) {
            this.element = element;
            this.parent = parent;
        }

        // 是否是叶子节点
        public boolean isLeaf() {
            return this.left != null && this.right != null;
        }

        // 是否有两个节点
        public boolean hasTwoChildren() {
            return this.left != null && this.right != null;
        }
    }

    public static interface Visitor<E> {
        void visit(E element);
    }
}
