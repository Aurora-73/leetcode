// Created: 2025-05-02
#include "MyTreeNode.h"
#include "MyUtils.hpp"

/*173. 二叉搜索树迭代器
实现一个二叉搜索树迭代器类BSTIterator ，表示一个按中序遍历二叉搜索树（BST）的迭代器：
BSTIterator(TreeNode root) 初始化 BSTIterator 类的一个对象。BST 的根节点 root 会作为构造函数的一部分给出。指针应初始化为一个不存在于 BST 中的数字，且该数字小于 BST 中的任何元素。
boolean hasNext() 如果向指针右侧遍历存在数字，则返回 true ；否则返回 false 。
int next()将指针向右移动，然后返回指针处的数字。
注意，指针初始化为一个不存在于 BST 中的数字，所以对 next() 的首次调用将返回 BST 中的最小元素。
你可以假设 next() 调用总是有效的，也就是说，当调用 next() 时，BST 的中序遍历中至少存在一个下一个数字。*/

class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		InOrder(root);
		now = allval.begin() - 1;
	}

	void InOrder(TreeNode *root) {
		if(!root) return;
		InOrder(root->left);
		allval.push_back(root->val);
		InOrder(root->right);
	}

	int next() {
		now++;
		if(now != allval.end()) {
			return *now;
		}
		return -1;
	}

	bool hasNext() {
		return now + 1 != allval.end();
	}

private:
	vector<int> allval;
	vector<int>::iterator now;
};

class BSTIterator {
public:
	BSTIterator(TreeNode *root) : now(root) { }

	int next() {
		while(now) {
			s.push(now);
			now = now->left;
		}
		now = s.top();
		s.pop();
		int res = now->val;
		now = now->right;
		return res;
	}

	bool hasNext() {
		return now || !s.empty();
	}

private:
	stack<TreeNode *> s;
	TreeNode *now;
};

int main() { }