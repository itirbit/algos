#include <fstream>
#include <queue>
#include <vector>
#include "node.h"

void cleanUp(Node* head)
{
	std::queue<Node*> q;
	q.push(head);
	while(!q.empty())
	{
		auto node = q.front();
		q.pop();
		if (node->left)
			q.push(node->left);
		if (node->right)
			q.push(node->right);
		delete node;
	}
}

Node* getNode()
{
	std::fstream fs("../randomInput/input.txt", std::fstream::in);
	if (!fs.is_open())
		return nullptr;
	
	std::queue<int> iq;
	std::string number;
	while(getline(fs, number, ' '))
	{
		iq.push(std::stoi(number));
	}
	
	auto head = new Node(iq.front());
	std::queue<Node*> q;
	q.push(head);
	iq.pop();
	while(!iq.empty())
	{		
		auto node = q.front();
		if (node->left && node->right)
			q.pop();
		else 
		{
			int i = iq.front();
			iq.pop();
			if (!node->left)
			{
				node->left = new Node(i);
				q.push(node->left);
			}
			else if (!node->right)
			{
				node->right = new Node(i);
				q.push(node->right);
			}
		}
	}

	fs.close();
	return head;	
}
