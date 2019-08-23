package com.onealon;

public class Stack<E> {
    /**
     * 接口设计
     * 1. size()
     * 2. isEmpty()
     * 3. push()
     * 4. pop()
     * 5. top()
     */

    private ArrayList<E> list = new ArrayList<>();

    public int size() {
        return list.size();
    }

    public boolean isEmpty() {
        return list.size() == 0 ? true : false;
    }

    public void push() {

    }

    public E pop() {
        return null;
    }

    public void clear() {

    }

    public E top() {
        return null;
    }

}
