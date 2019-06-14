package com.onealon;

import java.sql.Time;

import static com.onealon.TimeTool.*;

public class Main {

    private static final int n = 45;

    /*
    * 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233，377，610，...
    * 这个数列从第3项开始，每一项都等于前两项之和。
    * */

    public static void main(String[] args) {
        check("fib1", new Task() {
            @Override
            public void execute() {
                System.out.println(fib1(n));
            }
        });
        TimeTool.check("fib2", new Task() {
            @Override
            public void execute() {
                System.out.println(fib2(n));
            }
        });
    }

    /**
     * 计算斐波那契数列
     * fib1(1) 1
     * fib1(2) 2
     * fib1(3) 4
     * fib1(4) 8
     * 2^0 + 2^1 + 2^2 + 2^3 = 2^4 - 1 = 2^(n - 1) - 1
     * 时间复杂度O(2^n)
     * */
    public static int fib1(int n) {
        if (n <= 1) return n;
        return fib1(n - 1) + fib1(n - 2);
    }

    /**
     * 计算斐波那契数列
     * 1 + 1 + 1 + 1 + n + n + n + n = 4 + 4n
     * 时间复杂度O(n)
     * */
    public static int fib2(int n) {
        if (n <= 1) return n;
        int first = 0;
        int second = 1;
        for (int i = 0; i < n - 1; i++) {
            second = first + second;
            first = second - first;
        }
        return second;
    }

    /**
     * 分析算法的时间复杂度
     * */
//    public static void
}
