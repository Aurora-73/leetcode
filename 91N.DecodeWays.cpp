// Created: 2025-06-10
#include "MyUtils.hpp"
// #ifdef MY_UTILS_H

/* 91. 解码方法
一条包含字母A-Z 的消息通过以下映射进行了 编码 ：
"1" -> "A"
"2" -> "B"
...
"25" -> "Y"
"26" -> "Z"
然而，在解码 已编码的消息时，你意识到有许多不同的方式来解码，因为有些编码被包含在其它编码当中（"2" 和 "5" 与 "25"）。
例如，"11106" 可以映射为：
	"AAJF"，将消息分组为 (1, 1, 10, 6)
	"KJF"，将消息分组为 (11, 10, 6)
	消息不能分组为 (1, 11, 06)，因为 "06"不是一个合法编码（只有 "6" 是合法的）。
注意，可能存在无法解码的字符串。
给你一个只含数字的 非空 字符串 s，请计算并返回 解码 方法的 总数。如果没有合法的方式解码整个字符串，返回 0。
题目数据保证答案肯定是一个 32 位 的整数。
示例 1：
	输入：s = "12"
	输出：2
	解释：它可以解码为 "AB"（1 2）或者 "L"（12）。
示例 2：
	输入：s = "226"
	输出：3
	解释：它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6)。
示例 3：
	输入：s = "06"
	输出：0
	解释："06" 无法映射到 "F"，因为存在前导零（"6" 和 "06" 并不等价）。
提示：
	1 <= s.length <= 100
	s 只包含数字，并且可能包含前导零。 */

class Solution1 {
public:
	int numDecodings(string &s) {
		if(s[0] == '0') {
			return 0;
		}
		int n = s.size();
		vector<int> dp(n + 2); // 最后一个元素可能用到 dp[i + 2]
		dp[n] = 1;
		for(int i = n - 1; i >= 0; --i) {
			if(s[i] != '0') {
				if(s[i] == '1' || (s[i] == '2' && i + 1 < n && s[i + 1] <= '6')) {
					dp[i] = dp[i + 1] + dp[i + 2];
				} else {
					dp[i] = dp[i + 1];
				}
			}
		}
		return dp[0];
	}
};

class Solution {
public:
	int numDecodings(string &s) {
		if(s[0] == '0') {
			return 0;
		}
		int n = s.size(), dp = 1, dp_1 = 0, dp_2;
		for(int i = n - 1; i >= 0; --i) {
			dp_2 = dp_1;
			dp_1 = dp;
			if(s[i] != '0') {
				if(s[i] == '1' || (s[i] == '2' && i + 1 < n && s[i + 1] <= '6')) {
					dp = dp_1 + dp_2;
				} else {
					dp = dp_1;
				}
			} else {
				dp = 0; // 不会再默认为 0 了
			}
		}
		return dp;
	}
};

int main() {
	Solution sol;
	string s;
	s = "12";
	cout << sol.numDecodings(s) << endl; // 2
	s = "226";
	cout << sol.numDecodings(s) << endl; // 3
	s = "06";
	cout << sol.numDecodings(s) << endl; // 0
}