package 数组;

public class _1_两数之和 {

    /**
     * 1. 两数之和
     * https://leetcode-cn.com/problems/two-sum/
     * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
     *
     * 你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
     *
     * 给定 nums = [2, 7, 11, 15], target = 9
     *
     * 因为 nums[0] + nums[1] = 2 + 7 = 9
     * 所以返回 [0, 1]
     */


    /**
     * 第一种解法: 暴力循环
     * @param nums
     * @param target
     * @return
     */
    public static int[] twoSum(int[] nums, int target) {
        int[] results = new int[2];
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (target == nums[i] + nums[j]) {
                    results[0] = i;
                    results[1] = j;
                }
            }
        }
        return results;
    }

    /**
     * 空间换时间
     * @param nums
     * @param target
     * @return
     */
    public static int[] twoSum2(int[] nums, int target) {
        int maxSize = 2047;// 全是1
        int[] results = new int[maxSize + 1];
        for (int i = 0; i < nums.length; i++) {
            int num = target - nums[i];
            if (results[num] != 0) {
                return new int[] {results[num], i};
            }
            results[nums[i]] = i;
        }
        return new int[] {0, 0};
    }

    public static void main(String[] args) {
        int[] nums = {-1, 3, 5, 0, 2, 7, 11, 15};
        int[] results = twoSum2(nums, 9);
        System.out.println("运行结果: " + results[0] + " , " + results[1]);
    }

}
