#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

/*编写一个算法来判断一个数 n 是不是快乐数。
「快乐数」 定义为：
对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
如果这个过程 结果为 1，那么这个数就是快乐数。
如果 n 是 快乐数 就返回 true ；不是，则返回 false 。*/

class Solution {
public:
	bool isHappy(int n) {
		unordered_set<int> set;
		while(n != 1) {
			if(set.count(n))
				return false;
			set.insert(n);
			int newn = 0;
			while(n > 0) {
				newn += (n % 10) * (n % 10);
				n /= 10;
			}
			n = newn;
		}
		return true;
	}
};