#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>

using namespace std;

vector<int> vec1;	// 用于输出单层节点函数
vector<int> vec2; 	// for getTreeLevel1() function

/* 树的结构体 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* insert(TreeNode*, int);
TreeNode* createTree();
TreeNode* commonAncestor(TreeNode*, TreeNode*, TreeNode*);
TreeNode* commonAncestorHelper(TreeNode*, TreeNode*, TreeNode*);

/* 创建树 */
TreeNode* createTree() {
	TreeNode* root = NULL;
	int a[] = {4, 2, 6, 1, 3, 5, 7};
	int temp;
	//cout << "please input node value(end with 0):";
	//cin >> temp;
	int i = 0;
	while(i < (int)(sizeof(a)/sizeof(int))) {
		temp = a[i];
		root = insert(root, temp);
		i ++;
		//cout << "please input node value(end with 0):";
		//cin >> temp;
	}
	return root;
}

/* 插入节点，辅助建树 */
TreeNode* insert(TreeNode* root, int temp) {
	TreeNode* ptr = root;
	TreeNode* tempnode;
	TreeNode* newnode = new TreeNode(temp);

	if(ptr == NULL) {
		return newnode;
	} else {
		while(ptr != NULL) {
			tempnode = ptr;
			if(ptr->val >= temp)
				ptr = ptr->left;
			else
				ptr = ptr->right;
		}

		if(tempnode->val >= temp) 
			tempnode->left = newnode;
		else
			tempnode->right = newnode;
	}
	return root;
}

/* 递归前序遍历树 */
void PreOrderTree(TreeNode* root) {
	if(root == NULL)
		return;
	cout << root->val << " ";
	PreOrderTree(root->left);
	PreOrderTree(root->right);
}

/* 递归中序遍历树 */
void InOrderTree(TreeNode* root) {
	if(root == NULL)
		return;
	InOrderTree(root->left);
	cout << root->val << " ";
	InOrderTree(root->right);
}

/* 递归后序遍历树 */
void PostOrderTree(TreeNode* root) {
	if(root == NULL)
		return;
	PostOrderTree(root->left);
	PostOrderTree(root->right);
	cout << root->val << " ";
}

/* 层次遍历树 */
void HierachyOrderTree(TreeNode* root) {
	if(root == NULL)
		return ;
	queue<TreeNode*> que;
	que.push(root);
	TreeNode* b;
	while(!que.empty()) {
		b = que.front();
		cout << b->val << " ";
		que.pop();
		if(b->left)
			que.push(b->left);
		if(b->right)
			que.push(b->right);
	}
}

/* 循环前序遍历树 */
void whilePreOrderTree(TreeNode* root) {
	if(root == NULL)
		return;
	stack<TreeNode*> sta;
	TreeNode* temp = root;
	sta.push(temp);
	while(temp && !sta.empty()) {
		temp = sta.top();
		sta.pop();
		cout << temp->val << " ";
		if(temp->right)
			sta.push(temp->right);
		if(temp->left)
			sta.push(temp->left);
	}
}

/* 循环中序遍历树 */
void whileInOrderTree(TreeNode* root) {
	if(root == NULL)
		return;

	stack<TreeNode*> sta;
	TreeNode* temp = root;

	while(temp || !sta.empty()) {
		while(temp) {
			sta.push(temp);
			temp = temp->left;
		}
		if(!sta.empty()) {
			temp = sta.top();
			sta.pop();
			cout << temp->val << " ";
			temp = temp->right;
		}
		
	}
}

/* 循环后序遍历树 */
void whilePostOrderTree(TreeNode* root) {
	if(root == NULL)
		return ;

	stack<TreeNode*> s;
	TreeNode* cur;
	TreeNode* pre = NULL;
	s.push(root);
	while(!s.empty()) {
		cur = s.top();
		if((cur->left == NULL && cur->right == NULL) || (pre != NULL && (pre == cur->left || pre == cur->right))) {
			cout << cur->val << " ";
			s.pop();
			pre = cur;
		} else {
			if(cur->right != NULL)
				s.push(cur->right);
			if(cur->left != NULL)
				s.push(cur->left);
		}
	}
}

/* 树的高度 */
int getHighOfTree(TreeNode* root) {
	if(root == NULL)
		return 0;
	int left = getHighOfTree(root->left);
	int right = getHighOfTree(root->right);
	return left > right ? left + 1 : right + 1;
}

/* 树的高度 */
void getHighOfTree1(TreeNode* root, int& dep) {
	if(root == NULL)
		return;
	int leftdep = 0;
	int rightdep = 0;
	getHighOfTree1(root->left, leftdep);
	getHighOfTree1(root->right, rightdep);
	dep = leftdep > rightdep ? leftdep + 1 : rightdep + 1;
}

/* 判断是否是平衡二叉树 */
bool isBalance1(TreeNode* root, int& depth) {
	if(root == NULL) {
		depth = 0;
		return true;
	}

	int leftdep = 0;
	int rightdep = 0;
	if(!isBalance1(root->left, leftdep) || !isBalance1(root->right, rightdep)) 
		return false;
	if(leftdep - rightdep > 1 || leftdep - rightdep < -1)
		return false;
	depth = leftdep > rightdep ? leftdep + 1 : rightdep + 1;
	return true;
}

/* 判断是否是平衡二叉树 */
bool isBalance(TreeNode* root) {
	int depth = 0;
	return isBalance1(root, depth);
}

/* 输出单层的节点 */
void getTreeLevel(TreeNode* root, int depth, int& dep) {
	if(root == NULL) {
		return;
	}
	if(dep == depth)
		vec1.push_back(root->val);
	dep ++;
	getTreeLevel(root->left, depth, dep);
	getTreeLevel(root->right, depth, dep);
	dep --;
	//dep = (leftdep > rightdep ? leftdep : rightdep) + 1;
}

/* 输出单层的节点 */
/*
void getTreeLevel1(TreeNode* root, int depth, int dep) {
	if(root == NULL)
		return;

	if(dep == depth)
		vec2.push_back(root->val);

	getTreeLevel1(root->left, depth, dep+1);
	getTreeLevel1(root->left, depth, dep+1);
}
*/

/* 判断节点是否是树的节点 */
bool covers(TreeNode* root, TreeNode* node) {
	if(root == NULL)
		return false;
	if(root == node)
		return true;
	return covers(root->left, node) || covers(root->right, node);
}

/* 找出两个节点的公共祖先 */
TreeNode* commonAncestorHelper(TreeNode* root, TreeNode* p, TreeNode* q) {
	if(root == NULL)
		return NULL;
	if(root == p || root == q)
		return root;

	bool isPleft = covers(root->left, p);
	bool isQleft = covers(root->left, q);
	if(isPleft != isQleft)
		return root;

	TreeNode* child_size = isPleft ? root->left : root->right;
	return commonAncestor(child_size, p, q);
}

/* 找出两个节点的公共祖先 */
TreeNode* commonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if(!covers(root, p) || !covers(root, q))
		return NULL;
	return commonAncestorHelper(root, p, q);
}

/* 找到从根节点到叶子节点某一路径上的值为某一个数值 */
vector<vector<int> > res1;
void findPath(TreeNode* root, int num, vector<int>& result, int &sum) {
	sum += root->val;
	result.push_back(root->val);
	bool isLeaf = (root->left == NULL) && (root->right == NULL);
	if(isLeaf && num == sum)
		res1.push_back(result);
	if(root->left)
		findPath(root->left, num, result, sum);
	if(root->right)
		findPath(root->right, num, result, sum);
	result.pop_back();
	sum -= root->val;
}

void findPath(TreeNode* root, int num) {

	if(root == NULL)
		return;

	vector<int> result;
	int sum = 0;
	findPath(root, num, result, sum);
}

/* 找到从根节点到叶子节点某一路径上的值为某一个数值 */
vector<vector<int> > res2;
void findPath2(TreeNode* root, int num, vector<int>& result, int &sum) {
	sum += root->val;
	result.push_back(root->val);
	//bool isLeaf = (root->left == NULL) && (root->right == NULL);
	if(num == sum)
		res2.push_back(result);
	if(root->left)
		findPath2(root->left, num, result, sum);
	if(root->right)
		findPath2(root->right, num, result, sum);
	result.pop_back();
	sum -= root->val;
}

void findPath2(TreeNode* root, int num) {

	if(root == NULL)
		return;

	vector<int> result;
	int sum = 0;
	findPath2(root, num, result, sum);
}

/* 树中的某一路径的值得和为某一数值 */
vector<vector<int> > res3;

void putDataIntoResult(vector<int> result, int flag) {
	vector<int> temp;
	for(int i = result.size()-1; i >= flag; i--) {
		temp.push_back(result[i]);
	}
	res3.push_back(temp);
}

void findPath3(TreeNode* root, int num, vector<int>& result) {
	//sum += root->val;
	result.push_back(root->val);
	int sum = 0;
	for(int i  = result.size()-1; i >= 0; i--) {
		sum += result[i];
		if(sum == num) {
			//res3.push_back(result);
			putDataIntoResult(result, i);
		}
	}
	if(root->left)
		findPath3(root->left, num, result);
	if(root->right)
		findPath3(root->right, num, result);
	result.pop_back();
}

void findPath3(TreeNode* root, int num) {

	if(root == NULL)
		return;

	vector<int> result;
	findPath3(root, num, result);
}


int main(void) {
	// 测试用例1
	TreeNode* head = NULL;
	head = createTree();
	//int depth = 0;

	// 递归前序遍历树
	cout << "PreOrderTree: ";
	PreOrderTree(head);
	cout << endl;

	// 递归中序遍历树
	cout << "InOrderTrr: ";
	InOrderTree(head);
	cout << endl;

	// 递归后序遍历树
	cout << "PostOrderTree: ";
	PostOrderTree(head);
	cout << endl;

	// 层序遍历树
	cout << "HierachyOrderTree: ";
	HierachyOrderTree(head);
	cout << endl;

	// 循环前序遍历树
	cout << "whilePreOrderTree: ";
	whilePreOrderTree(head);
	cout << endl;

	// 循环中序遍历树
	cout << "whileInOrderTree: ";
	whileInOrderTree(head);
	cout << endl;

	// 循环后序遍历树
	cout << "whilePostOrderTree: ";
	whilePostOrderTree(head);
	cout << endl;

	/*
	// 树的高度
	cout << getHighOfTree(head) << endl;

	// 树的高度
	getHighOfTree1(head, depth);
	cout << depth << endl;

	// 判断是否为平衡二叉树
	cout << isBalance(head) << endl;

	// 输出单层节点
	int high = 9;
	depth = 1;
	getTreeLevel(head, high, depth);
	for(int i = 0; i < vec1.size(); ++i) {
		cout << vec1[i] << " ";
	}
	cout << endl;
	*/
	// getTreeLevel1 输出单层节点	
	/*
	high = 4;
	depth = 1;
	getTreeLevel1(head, high, depth);
	for(int i = 0; i < vec2.size(); ++i) {
		cout << vec2[i] << " ";
	}
	cout << endl;
	*/

	// 判断节点是否是树的节点
	TreeNode* node = head->left->left;
	cout << "covers(head, head): ";
	cout << covers(head, head) << endl;
	cout << "covers(head, head-left-left): ";
	cout << covers(head, node) << endl;
	cout << "covers(head-left, head): ";
	cout << covers(head->left, head) << endl;

	// 找出两个节点的公共祖先
	TreeNode* node1 = head;
	TreeNode* node2 = head->left;
	TreeNode* node3 = head->right;
	TreeNode* node4 = head->left->left;
	TreeNode* node5 = head->left->right;
	TreeNode* node6 = head->right->left;
	TreeNode* node7 = head->right->right;
	TreeNode* node8 = NULL;

	cout << "commonAncestorHelper(head, head-left, head-right): ";
	cout << commonAncestor(node1, node2, node3)->val << endl;
	cout << "commonAncestor(head, head-left-left, head-left-right): ";
	cout << commonAncestor(node1, node4, node5)->val << endl;
	cout << "commonAncestor(head, head-right-left, head-right-right): ";
	cout << commonAncestor(node1, node6, node7)->val << endl;
	cout << "commonAncestor(head, head-left-left, head-right-right): ";
	cout << commonAncestor(node1, node4, node7)->val << endl;
	cout << "commonAncestor(NULL, head-left, head-right-right): ";
	cout << commonAncestor(node8, node2, node7) << endl;

	// 查找路径和为某值的路径，根到叶子节点
	findPath(head, 9);
	cout << "path is: ";
	for(unsigned int i = 0; i < res1.size(); ++i)
		for(unsigned int j = 0; j < res1[i].size(); ++j)
			cout << res1[i][j] << " ";
		cout << endl;

	// 查找路径和为某值的路径,从根出发，
	findPath2(head, 15);
	cout << "path2 is: ";
	for(unsigned int i = 0; i < res2.size(); ++i)
		for(unsigned int j = 0; j < res2[i].size(); ++j)
			cout << res2[i][j] << " ";
		cout << endl;

	// 查找路径和为某值的路径，
	findPath3(head, 5);
	cout << "path3 is: ";
	for(unsigned int i = 0; i < res3.size(); ++i)
		for(unsigned int j = 0; j < res3[i].size(); ++j)
			cout << res3[i][j] << " ";
		cout << endl;


	return 0;
}