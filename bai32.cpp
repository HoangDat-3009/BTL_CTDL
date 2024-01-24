#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
	int data;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int value)
	{
		data = value;
		left = NULL;
		right = NULL;
	}
};
class BinaryTree
{
public:
	TreeNode *root;

	BinaryTree()
	{
		root = NULL;
	}


	TreeNode *insert(int arr[], TreeNode *root, int i, int n)
	{
		if (i < n)
		{
			TreeNode *temp = new TreeNode(arr[i]);
			root = temp;
			root->left = insert(arr, root->left, 2 * i + 1, n);
			root->right = insert(arr, root->right, 2 * i + 2, n);
		}
		return root;
	}
	void preorderTraversal(TreeNode *currentNode)
	{
		if (currentNode != NULL)
		{
			cout << currentNode->data << " ";
			preorderTraversal(currentNode->left);
			preorderTraversal(currentNode->right);
		}
	}
	int count(TreeNode *root)
	{
		if (root == NULL)
			return 0;
		return 1 + count(root->left) + count(root->right);
	}
	int max0(int a, int b, int c)
	{
		int max = a;
		if (b > max)
			max = b;
		if (c > max)
			max = c;
		return max;
	}

	bool canWin(TreeNode *root, int n, int x)
	{
		if (root == NULL)
			return false;
		if (x == 1)
			return false;
		if (root->data == x)
		{
			int left = count(root->left);
			int right = count(root->right);
			int parent = n - left - right - 1;
			if (max0(left, right, parent) > n / 2)
				return true;
			else
				return false;
		}
		return canWin(root->left, n, x) || canWin(root->right, n, x);
	}
};

int main()
{
	BinaryTree tree;
	int n;
	cout << "Nhap n(1<=n<=100, n le): ";
	cin >> n;
	while (n < 1 || n > 100 || n % 2 == 0)
	{
		cout << "nhap lai n(1<=x<=100,n le): ";
		cin >> n;
	}
	int arr[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}
	tree.root = tree.insert(arr, tree.root, 0, n);
	//	for(int i=1;i<=n;i++){
	//		tree.insert(i);
	//	}
	cout << "Duyet cay theo tien tu:\n ";
	tree.preorderTraversal(tree.root);
	int x;
	cout << "\nNhap buoc di cua nguoi thu nhat(nhap x):";
	cin >> x;
	while (x < 1 || x > n)
	{
		cout << "nhap lai x(1<=x<=n): ";
		cin >> x;
	}
	if (tree.canWin(tree.root, n, x))
	{
		cout << "true";
	}
	else
	{
		cout << "false";
	}
	return 0;
}
