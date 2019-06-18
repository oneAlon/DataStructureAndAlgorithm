package com.onealon.LinkList;

import com.onealon.AbstractList;

/**
 * 单向链表
 * @param <E>
 */
public class LinkList<E> extends AbstractList<E> {

    private static class Node<E> {
        E element;
        Node<E> next;
        public Node(E element, Node<E> next) {
            this.element = element;
            this.next = next;
        }
    }

    /**
     * 指向第一个结点
     */
    Node<E> first;

    @Override
    public void add(int index, E element) {
        checkRangeForAdd(index);
        if (index == 0) {
            first = new Node<E>(element, first);
        }else {
            // 先获取要插入index的前一个结点
            Node<E> prev = node(index - 1);
            prev.next = new Node<E>(element, prev.next);
        }
        size++;
    }

    @Override
    public E remove(int index) {
        checkRange(index);
        Node<E> node = first;
        if (index == 0) {
            first = first.next;
        }else {
            // 获取前一个结点
            Node<E> prev = node(index - 1);
            node = prev.next;
            prev.next = node.next;
        }
        size--;
        return node.element;
    }

    @Override
    public void clear() {
        size = 0;
        first = null;
    }

    @Override
    public E get(int index) {
        return node(index).element;
    }

    @Override
    public E set(int index, E element) {
        Node<E> node = node(index);
        node.element = element;
        return node.element;
    }

    @Override
    public int indexOf(E element) {
        Node<E> node = first;
        for (int i = 0; i < size; i++) {
            if (node.element == element) {
                return i;
            }else {
                node = node.next;
            }
        }
        return ELEMENT_NOT_FOUND;
    }

    /**
     * 根据索引获取node结点
     * @param index
     * @return
     */
    private Node<E> node(int index) {
        checkRange(index);
        Node<E> node = first;
        for (int i = 0; i < index; i++) {
            node = node.next;
        }
        return node;
    }

    @Override
    public String toString() {
        StringBuilder string = new StringBuilder();
        Node<E> node = first;
        while (node != null) {
            if (node.next == null) {
                string.append(node.element).append("_").append("null");
            }else {
                string.append(node.element).append("_").append(node.next.element).append("--->");
            }
            node = node.next;
        }
        return string.toString();
    }
}
