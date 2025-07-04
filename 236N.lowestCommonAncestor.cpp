// Created: 2025-05-01
#include "MyTreeNode.h"
#include "MyUtils.hpp"

/* 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，
满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先） */

class Solution1 {
public:
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
		vector<TreeNode *> path, path2;
		TreeNode *curr = root;
		TreeNode *lastVisited = nullptr;

		while(curr || !path.empty()) {
			while(curr) {
				path.push_back(curr);
				curr = curr->left;
			}
			TreeNode *node = path.back();
			// 如果右子树存在且没访问过，转向右子树
			if(node->right && node->right != lastVisited) {
				curr = node->right;
			} else {
				// 否则访问当前节点，并记录为“最近访问”
				if(node == p || node == q) {
					if(path2.empty()) {
						path2 = path;
					} else {
						break;
					}
				}
				lastVisited = node;
				path.pop_back();
			}
		} // 非递归后序遍历

		int min_size = min(path.size(), path2.size()), i = 0;
		while(i < min_size && path[i] == path2[i]) ++i;
		return path[i - 1];
	}
}; // 非递归后序遍历遍历到p q节点时的最后一个公共节点

class Solution2 {
public:
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
		vector<TreeNode *> pathP, pathQ;

		// 找到从根到p和q的路径
		findPath(root, p, pathP);
		findPath(root, q, pathQ);

		// 找到最后一个公共节点
		int min_size = min(pathP.size(), pathQ.size()), i = 0;
		while(i < min_size && pathP[i] == pathQ[i]) ++i;
		return pathP[i - 1];
	}

private:
	bool findPath(TreeNode *root, TreeNode *target, vector<TreeNode *> &path) {
		if(!root) return false;

		path.push_back(root);

		if(root == target) return true;

		if(findPath(root->left, target, path) || findPath(root->right, target, path)) {
			return true;
		}

		path.pop_back(); // 回溯
		return false;
	}
}; // 递归遍历，保存路径

class Solution {
public:
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
		// 边界条件：空节点或找到目标节点
		if(!root || root == p || root == q) {
			return root;
		}

		// 在左右子树中递归查找
		TreeNode *left = lowestCommonAncestor(root->left, p, q);
		TreeNode *right = lowestCommonAncestor(root->right, p, q);

		// 判断结果
		if(left && right) return root; // p和q分别在左右子树，当前节点就是LCA
		return left ? left : right;    // p和q都在同一子树，返回非空的那个
	}
};

int main() { }