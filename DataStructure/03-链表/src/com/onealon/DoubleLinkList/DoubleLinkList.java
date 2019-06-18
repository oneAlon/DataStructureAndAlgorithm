package com.onealon.DoubleLinkList;

import com.onealon.AbstractList;

/**
 * 双向链表
 */
public class DoubleLinkList<E> extends AbstractList<E> {

    private static class Node<E> {
        E element;
        Node<E> prev;
        Node<E> next;
        public Node(Node<E> prev, E element, Node<E> next) {
            this.prev = prev;
            this.element = element;
            this.next = next;
        }
    }

    private Node<E> first;
    private Node<E> last;

    @Override
    public E set(int index, E element) {
        checkRange(index);
        Node<E> node = node(index);
        node.element = element;
        return node.element;
    }

    @Override
    public void add(int index, E element) {
        checkRangeForAdd(index);
        if (index == size) {
            Node<E> node = new Node<>(last, element, null);
            if (last == null) {// 空表, 这是添加的第一个元素
                first = node;
                last = node;
            }else {// 添加到链表的最后一个位置
                last.next = node;
                last = node;
            }
        }else {
            Node<E> nextNode = node(index);
            Node<E> prevNode = nextNode.prev;
            Node<E> node = new Node<>(prevNode, element, nextNode);
            nextNode.prev = node;
            if (prevNode == null) {// 第一个结点
                first = node;
            }else {
                prevNode.next = node;
            }
        }
        size++;
    }

    @Override
    public E remove(int index) {
        checkRange(index);
        Node<E> node = node(index);
        Node<E> prevNode = node.prev;
        Node<E> nextNode = node.next;

        if (prevNode == null) {// 删除的第一个结点
            first = nextNode;
        }else {
            prevNode.next = nextNode;
        }
        if (nextNode == null) {// 删除的最后一个结点
            last = prevNode;
        }else {
            nextNode.prev = prevNode;
        }

        size--;
        return node.element;
    }

    @Override
    public void clear() {
        size = 0;
        first = null;
        last = null;
    }

    @Override
    public E get(int index) {
        return node(index).element;
    }

    @Override
    public int indexOf(E element) {
        if (element == null) {
            Node<E> node = first;
            for (int i = 0; i < size; i++) {
                if (node.element == null) return i;
                node = node.next;
            }
        }else {
            Node<E> node = first;
            for (int i = 0; i < size; i++) {
                if (element.equals(node.element)) return i;
                node = node.next;
            }
        }
        return ELEMENT_NOT_FOUND;
    }

    /**
     * 获取index位置对应的结点
     * @param index
     * @return
     */
    private Node<E> node(int index) {
        if (index <= (size >> 1)) {
            Node<E> node = first;
            for (int i = 0; i < index; i++) {
                node = node.next;
            }
            return node;
        }else {
            Node<E> node = last;
            for (int i = size - 1; i > index; i--) {
                node = node.prev;
            }
            return node;
        }
    }

    @Override
    public String toString() {
        StringBuilder string = new StringBuilder();
        Node<E> node = first;
        while (node != null) {
            String prevElement = (node.prev != null) ? String.valueOf(node.prev.element) : "null";
            String nextElement = (node.next != null) ? String.valueOf(node.next.element) : "null";
            string.append(prevElement).append("_").append(node.element).append("_").append(nextElement);
            if (!nextElement.equals("null")) string.append("--->");
            node = node.next;
        }
        return string.toString();
    }
}
