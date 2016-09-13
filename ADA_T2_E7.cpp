//============================================================================
// Name        : ADA_T2_E7.cpp
// Author      : Juan Carlos González Tamayo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
using namespace std;

class RBTree_Node
{
public:
	bool color; // false para rojo, true para negro
	int key;
	RBTree_Node *left;
	RBTree_Node	*right;
	RBTree_Node	*p;
	RBTree_Node()
	{
		color = false;
		key = 0;
		left = nullptr;
		right = nullptr;
		p = nullptr;
	}
};

class RBTree
{
public:
	void insert(RBTree *T, RBTree_Node *z)
	{
		RBTree_Node * y = nullptr;
		RBTree_Node * x = T->root;
		while (x != nullptr)
		{
			y = x;
			if (z->key < x->key)
				x = x->left;
			else
				x = x->right;
		}
		z->p = y;
		if (y == nullptr)
			T->root = z;
		else if (z->key < y->key)
			y->left = z;
		else
			y->right = z;
		z->left = nullptr;
		z->right = nullptr;
		z->color = false;
		insertFixUp(T, z);
	}
	void insertFixUp(RBTree *T, RBTree_Node *z)
	{
		while (z->p->color == false)
		{
			if (z->p == z->p->p->left)
			{
				RBTree_Node *y = z->p->p->right;
				if (y->color == false)
				{
					z->p->color = true;
					y->color = true;
					z->p->p->color = false;
					z = z->p->p;
				}
				else if (z == z->p->right)
				{
					z = z->p;
					//left-rotate
				}

			}
		}
	}
private:
	RBTree_Node *root;
};

int main()
{
	int n, m;
	std::cin >> n >> m;

	list<int> cb;

	for (int i = 1; i <= n; ++i)
		cb.push_back(i);

	list<int>::iterator it = cb.begin();
	while (cb.size())
	{
		int t = m-1;
		while (t--)
		{
			it++;
			if (it == cb.end())
				it = cb.begin();
		}
		std::cout << (*it) << std::endl;
		it = cb.erase(it);
		if (it == cb.end())
			it = cb.begin();
	}

	return 0;
}
