package com.onealon;

/**
 * 抽象类, 实现了接口的默认方法
 */
public abstract class AbstractList<E> implements  List<E>{
    protected int size;

    @Override
    public void add(E element) {
        add(size, element);
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public boolean isEmpty() {
        return size == 0;
    }

    @Override
    public boolean contains(E element) {
        return indexOf(element) != ELEMENT_NOT_FOUND;
    }

    protected void outOfBounds(int index) {
        throw new IndexOutOfBoundsException("越界了, Index:" + index + ", Size:" + size);
    }

    protected void checkRange(int index) {
        if (index < 0 || index >= size) {
            outOfBounds(index);
        }
    }

    protected void checkRangeForAdd(int index) {
        if (index < 0 || index > size) {
            outOfBounds(index);
        }
    }
}
