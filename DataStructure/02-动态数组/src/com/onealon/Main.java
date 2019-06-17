package com.onealon;

public class Main {

    public static void main(String[] args) {
        System.out.println("动态数组");
        ArrayList<Integer> list = new ArrayList();
        list.add(11);
        list.add(22);
        list.add(33);
        list.add(44);
        list.add(55);
        list.add(66);
        list.add(77);
        list.add(88);
        list.add(99);
        list.add(100);
        list.add(110);
        list.remove(2);
        System.out.println("33在list中的索引:" + list.indexOf(33));
        System.out.println("是否包含某个元素:" + list.contains(333));
        System.out.println(list);
    }
}
