// Created: 2025-06-24
#include "MyUtils.hpp"
// #ifdef MY_UTILS_H

/* LCR 148. 验证图书取出顺序
现在图书馆有一堆图书需要放入书架，并且图书馆的书架是一种特殊的数据结构，只能按照 一定 的顺序 放入 和 拿取 书籍。
给定一个表示图书放入顺序的整数序列 putIn，
请判断序列 takeOut 是否为按照正确的顺序拿取书籍的操作序列。你可以假设放入书架的所有书籍编号都不相同。
示例 1：
	输入：putIn = {6,7,8,9,10,11}, takeOut = {9,11,10,8,7,6}
	输出：true
	解释：我们可以按以下操作放入并拿取书籍：
	push(6), push(7), push(8), push(9), pop() -> 9,
	push(10), push(11),pop() -> 11,pop() -> 10, pop() -> 8, pop() -> 7, pop() -> 6
示例 2：
	输入：putIn = {6,7,8,9,10,11}, takeOut = {11,9,8,10,6,7}
	输出：false
	解释：6 不能在 7 之前取出。
提示：
	0 <= putIn.length == takeOut.length <= 1000
	0 <= putIn{i}, takeOut < 1000
	putIn 是 takeOut 的排列。*/

class Solution1 {
public:
	bool validateBookSequences(vector<int> &putIn, vector<int> &takeOut) {
		stack<int> st;
		int n = putIn.size(), i = 0, j = 0;
		while(i < n) {
			while(i < n && (st.empty() || st.top() != takeOut[j])) {
				st.push(putIn[i]);
				++i;
			}
			while(!st.empty() && st.top() == takeOut[j]) {
				++j;
				st.pop();
			}
		}
		return j == n;
	}
};

class Solution {
public:
	bool validateBookSequences(vector<int> &putIn, vector<int> &takeOut) {
		stack<int> st;
		int j = 0;
		for(int x : putIn) {
			st.push(x);
			while(!st.empty() && st.top() == takeOut[j]) {
				st.pop();
				++j;
			}
		}
		return st.empty();
	}
};

int main() {
	Solution sol;
	vector<int> putIn, takeOut;
	putIn = { 6, 7, 8, 9, 10, 11 }, takeOut = { 9, 11, 10, 8, 7, 6 };
	cout << sol.validateBookSequences(putIn, takeOut) << endl; // true
	putIn = { 6, 7, 8, 9, 10, 11 }, takeOut = { 11, 9, 8, 10, 6, 7 };
	cout << sol.validateBookSequences(putIn, takeOut) << endl; // false
}