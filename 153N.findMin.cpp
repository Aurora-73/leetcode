// Created: 2025-05-15
#include "MyUtils.hpp"

/*153. 寻找旋转排序数组中的最小值
已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,2,4,5,6,7] 在变化后可能得到：
若旋转 4 次，则可以得到 [4,5,6,7,0,1,2]
若旋转 7 次，则可以得到 [0,1,2,4,5,6,7]
注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。

给你一个元素值 互不相同 的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。

你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。*/

class Solution {
public:
	int findMin(vector<int> &nums) {
		int left = 0, right = nums.size() - 1;
		while(left < right) {
			int mid = left + (right - left) / 2; // mid不一定是最小值，有可能最后一轮被跳过了
			if(nums[mid] < nums[right]) {
				right = mid;
			} else {
				left = mid + 1;
			}
		}
		return nums[left];
	}
};

int main() {
	Solution sol;
}