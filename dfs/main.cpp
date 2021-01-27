#include <stack>
#include <iostream>


struct Node
{
	Node():val(0){}
	Node(int v):val(v){}
	Node* left{};
	Node* right{};
	int val{};
};

void bfs(Node* node)
{
	std::stack<Node*> q;
	q.push(node);
	while(!q.empty())
	{
		auto node = q.top();
		q.pop();
		std::cout << node->val << " ";
		if (node->left)
			q.push(node->left);
		if (node->right)
			q.push(node->right);
	}
}

int main()
{
	Node* root = new Node(12);
	root->left = new Node(7);
	root->right = new Node(5);
	root->right->left = new Node(6);
	root->left->right = new Node(1);
	root->left->left = new Node(2);
	bfs(root);
	delete root->left->left;
	delete root->left->right;
	delete root->left;
	delete root->right->left;
	delete root->right;
	delete root;
}
