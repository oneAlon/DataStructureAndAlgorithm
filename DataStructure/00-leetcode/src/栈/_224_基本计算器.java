package 栈;

import java.util.Stack;

/**
 * 224. 基本计算器
 * https://leetcode-cn.com/problems/basic-calculator/
 * 实现一个基本的计算器来计算一个简单的字符串表达式的值。
 *
 * 字符串表达式可以包含左括号 ( ，右括号 )，加号 + ，减号 -，非负整数和空格  。
 */
public class _224_基本计算器 {

    public static void main(String[] args) {
        System.out.println(calculate("9+(3-1)*3+10/2"));;
    }

    public static int calculate(String s) {
        // 先将中缀表达式转为后缀表达式
        String newS = new String();
        char[] charArray = s.toCharArray();
        int length = charArray.length;
        // 初始化一个栈 用于存放操作符
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < length; i++) {
            char c = charArray[i];
            if (c >= 48 && c <= 57/*是数字*/) {
                newS = newS + Character.toString(c);
            } else {
                if (stack.isEmpty()) {
                    stack.push(c);
                } else {
                    // 取出栈顶的操作符 和当前操作符的优先级作对
                    char topChar = stack.pop();
                    if (topChar == ')') {
                        // 一直出栈知道遇到(
                        char popChar = stack.pop();
                        while (popChar != '(') {
                            newS = newS + Character.toString(popChar);
                            popChar = stack.pop();
                        }
                    }
                    // c 不高于栈顶操作符的优先级, 就将栈顶出栈
                    if ((c == '+' || c == '-') && (topChar == '*' || topChar == '/')) {
                        newS = newS + Character.toString(topChar);
                        stack.push(c);
                    } else {
                        stack.push(topChar);
                        stack.push(c);
                    }
                }
            }
        }
        while (!stack.isEmpty()) {
            newS = newS + Character.toString(stack.pop());
        }
        return 0;

        // 后缀表示法: 遇到数字就进栈, 遇到符号就将处于栈顶的两个数字出栈进行运算, 运算结果进栈, 一直到获取到结果

        /*
        for (int i = 0; i < length; i++) {
            char c = charArray[i];
            // 遇到符号, 取出栈顶的两个元素
            if (c == ' ') {
                continue;
            } else if (c == '+' || c == '-' || c == '*' || c == '/') {
                int num2 = stack.pop();
                int num1 = stack.pop();
                if (c == '+') {
                    int num = num1 + num2;
                    stack.push(num);
                }
                if (c == '-') {
                    int num = num1 - num2;
                    stack.push(num);
                }
                if (c == '*') {
                    int num = num1 * num2;
                    stack.push(num);
                }
                if (c == '/') {
                    int num = num1 * num2;
                    stack.push(num);
                }
            } else {
                // 遇到数字, 进栈
                int num = Integer.valueOf(Character.toString(c));
                stack.push(Integer.valueOf(num));
            }
        }
        */
//        return stack.pop();
//        return 0;
    }
}
