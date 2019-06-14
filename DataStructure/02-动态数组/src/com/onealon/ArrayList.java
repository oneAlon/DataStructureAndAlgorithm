package com.onealon;

public class ArrayList<E> {

    /**
     * 元素的数量
     */
    private int size = 0;
    /**
     * 所有的元素
     */
    private Object[] elements;
    /**
     * 数组默认容量
     */
    private static final int DEFAULT_CAPACITY = 10;

    public ArrayList() {
        this(DEFAULT_CAPACITY);
    }

    public ArrayList(int capacity) {
        capacity = capacity > DEFAULT_CAPACITY ? capacity : DEFAULT_CAPACITY;
        elements = new Object[capacity];
    }

    /**
     * 添加元素
     * @param element
     */
    public void add(E element) {
        this.add(size, element);
    }

    /**
     * 在指定位置插入元素
     * @param index
     * @param element
     */
    public void add(int index, E element) {
        checkRangeForAdd(index);
        // 向后移动元素
        for (int i = size - 1; i >= index; i--) {
            elements[i + 1] = elements[i];
        }
        elements[index] = element;
        size++;
    }

    /**
     * 移除元素
     * @param index
     * @return
     */
    public E remove(int index) {
        checkRange(index);
        E oldElement = (E)elements[index];
        for (int i = index; i < size; i++) {
            elements[i] = elements[i + 1];
        }
        // 清空最后一个元素, 让对象释放内存
        elements[size] = null;
        size--;
        return oldElement;
    }

    /**
     * 清空所有元素
     */
    public void clear() {
        for (int i = 0; i < size; i++) {
            // 清空对象引用, 释放内存
            elements[i] = null;
        }
        size = 0;
    }

    /**
     * 设置index位置的元素
     * @param index
     * @param element
     * @return
     */
    public E set(int index, E element) {
        checkRange(index);
        E oldElement = (E)elements[index];
        elements[index] = element;
        return oldElement;
    }

    /**
     * 元素的数量
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
        return size == 0 ? true : false;
    }

    /**
     * 是否包含某个元素
     * @param element
     * @return
     */
    public boolean contains(E element) {
        if (element == null) {
            for (int i = 0; i < size; i++) {
                if (elements[i] == null) return true;
            }
        }else {
            for (int i = 0; i < size; i++) {
                if (element.equals(elements[i])) return true;
            }
        }
        return false;
    }

    /**
     * 获取某个位置的元素
     * @param index
     * @return
     */
    public E get(int index) {
        checkRange(index);
        return (E)elements[index];
    }

    /**
     * 获取某个元素的位置
     * @param element
     * @return
     */
    public int indexOf(E element) {
        if (element == null) {
            for (int i = 0; i < size; i++) {
                if (elements[i] == null) return i;
            }
        }else {
            for (int i = 0; i < size; i++) {
                if (element.equals(elements[i])) return i;
            }
        }
        return -1;
    }

    /**
     * 越界报错
     * @param index
     */
    private void outOfBounds(int index) {
        throw new IndexOutOfBoundsException("越界了, Index:" + index + ", Size:" + size);
    }

    private void checkRange(int index) {
        if (index < 0 || index >= size) {
            outOfBounds(index);
        }
    }

    private void checkRangeForAdd(int index) {
        if (index < 0 || index > size) {
            outOfBounds(index);
        }
    }

    @Override
    public String toString() {
        StringBuilder string = new StringBuilder();
        string.append("size=").append(size).append(", [");
        for (int i = 0; i < size; i++) {
            if (i != 0) string.append(", ");
            string.append(elements[i]);
        }
        string.append("]");
        return string.toString();
    }
}
