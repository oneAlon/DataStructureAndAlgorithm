package com.onealon;

public class Main {

    public static void main(String[] args) {
        System.out.println("动态数组");
        ArrayList list = new ArrayList();
        list.add(11);
        list.add(22);
        list.add(33);
        list.add(44);
        list.remove(0);
        System.out.println("是否包含某个元素:" + list.contains(333));
        System.out.println(list);
    }
}
