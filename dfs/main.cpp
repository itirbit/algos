#include <stack>
#include <iostream>
#include "../nodes/node.h"

void bfs(Node* node)
{
	if(!node)
		return;
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
	auto node = getNode();
	bfs(node);
	cleanUp(node);
}
