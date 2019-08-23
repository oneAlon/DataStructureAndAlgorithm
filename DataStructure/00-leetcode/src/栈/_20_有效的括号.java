package 栈;

import java.util.Stack;

public class _20_有效的括号 {
    /**
     * 20. 有效的括号
     * https://leetcode-cn.com/problems/valid-parentheses/
     * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
     *
     * 有效字符串需满足：
     *
     * 左括号必须用相同类型的右括号闭合。
     * 左括号必须以正确的顺序闭合。
     * 注意空字符串可被认为是有效字符串。
     * @param s
     */
    public static boolean isValid(String s) {
        // 思考: 使用栈
        Stack<Character> stack = new Stack<>();

        int length = s.length();

        for (int i = 0; i < length; i++) {
            char c = s.charAt(i);
            // 遇到做符号就入栈
            if (c == '{' || c == '[' || c == '(') {
                stack.push(c);
            } else {
                // 右字符
                if (stack.isEmpty()) return false;
                // 取出左字符
                char left = stack.pop();
                if (left == '{' && c != '}') return false;
                if (left == '[' && c != ']') return false;
                if (left == '(' && c != ')') return false;
            }
        }

        // 如果栈为空=true, 不为空=false
        return stack.isEmpty();
    }

    public static void main(String[] args) {
        System.out.println(isValid("}"));
    }
}
