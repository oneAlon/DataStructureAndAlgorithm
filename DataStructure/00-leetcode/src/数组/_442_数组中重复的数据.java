package 数组;

import java.util.ArrayList;
import java.util.List;

/**
 * 442. 数组中重复的数据
 * https://leetcode-cn.com/problems/find-all-duplicates-in-an-array/
 * 给定一个整数数组 a，其中1 ≤ a[i] ≤ n （n为数组长度）, 其中有些元素出现两次而其他元素出现一次。
 *
 * 找到所有出现两次的元素。
 *
 * 你可以不用到任何额外空间并在O(n)时间复杂度内解决这个问题吗？
 */
public class _442_数组中重复的数据 {

    public static List<Integer> findDuplicates(int[] nums) {
        List<Integer> resultList = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            int number = Math.abs(nums[i]);
            if (nums[number - 1] < 0) {
                resultList.add(number);
            } else {
                nums[number - 1] *= -1;
            }
        }
        return resultList;
    }

    public static void main(String[] args) {
        int nums[] = {4,3,2,7,8,2,3,1};
        List<Integer> result = findDuplicates(nums);
        for (Integer i :
                result) {
            System.out.println(i);
        }
    }

}
