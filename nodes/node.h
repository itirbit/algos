#pragma once

struct Node
{
	Node():val(0){}
	Node(int v):val(v){}
	Node* left{};
	Node* right{};
	int val{};
};

Node* getNode();
void cleanUp(Node* head);
