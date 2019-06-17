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
    /**
     * 数据未找到
     */
    public static final int ELEMENT_NOT_FOUND = -1;

    /**
     * 构造方法
     */
    public ArrayList() {
        this(DEFAULT_CAPACITY);
    }

    public ArrayList(int capacity) {
        // 设置初始化数组的空间大小
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
        // 确认当前容量是否可以再添加元素
        ensureCapacity();
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
        return size == 0;
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
        return ELEMENT_NOT_FOUND;
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
        // 为添加元素 做范围判断
        if (index < 0 || index > size) {
            outOfBounds(index);
        }
    }

    /**
     * 数组扩容
     */
    private void ensureCapacity() {
        // oldCapacity: 初始化的容量
        int oldCapacity = elements.length;
        if (oldCapacity > size) return;
        int newCapacity = oldCapacity + (oldCapacity >> 1);
        Object[] newElements = new Object[newCapacity];
        for (int i = 0; i < size; i++) {
            newElements[i] = elements[i];
        }
        elements = newElements;
        System.out.println(oldCapacity + "扩容为" + newCapacity);
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
