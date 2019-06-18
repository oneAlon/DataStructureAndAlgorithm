package com.onealon;

import com.onealon.DoubleLinkList.DoubleLinkList;
import com.onealon.LinkList.LinkList;

public class Main {

    /**
     * main入口
     * @param args
     */
    public static void main(String[] args) {
        // 单向链表
//        System.out.println("单向链表");
//        List<Integer> list = new LinkList<>();
//        testList(list);

        // 双向链表
        System.out.println("双向链表");
        List<Integer> doubleList = new DoubleLinkList<>();
        testList(doubleList);
    }

    static void testList(List<Integer> list) {
        list.add(11);
        list.add(22);
        list.add(33);
        list.add(44);

        list.add(0, 55); // [55, 11, 22, 33, 44]
        list.add(2, 66); // [55, 11, 66, 22, 33, 44]
        list.add(list.size(), 77); // [55, 11, 66, 22, 33, 44, 77]

        list.remove(0); // [11, 66, 22, 33, 44, 77]
        list.remove(2); // [11, 66, 33, 44, 77]
        list.remove(list.size() - 1); // [11, 66, 33, 44]

        AssertTool.test(list.indexOf(44) == 3);
        AssertTool.test(list.indexOf(22) == List.ELEMENT_NOT_FOUND);
        AssertTool.test(list.contains(33));
        AssertTool.test(list.get(0) == 11);
        AssertTool.test(list.get(1) == 66);
        AssertTool.test(list.get(list.size() - 1) == 44);

        System.out.println(list);
    }

}
