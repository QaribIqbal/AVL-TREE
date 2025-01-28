#include<iostream>
using namespace std;
struct node {
	int height;
	node* left;
	node* right;
	int data;
	node()
	{
		left = nullptr;
		right = nullptr;
		height = 1;
		data = 0;
	}
	node(int val) {
		data = val;
	}
};
class AVL {
private:
	node* root;
public:
	int getHeight(node* ptr) {
		if (ptr->height == 0)
		{
			return 0;
		}
		return ptr->height;
	}
	node* insert(node* leafnode, int val)
	{
		if (leafnode == nullptr) {
			return new node(val);
		}
		else if (leafnode->data < val)
		{
			insert(leafnode->right, val);
		}
		else if (leafnode->data > val)
		{
			insert(leafnode->left, val);
		}
		else {
			return leafnode;
		}
		leafnode->height = max(this->getHeight(leafnode->left), this->getHeight(leafnode->right)) + 1;
		
		//NOW CHECK FOR BALANCE IN THE TREE
	}
	};
	int main()
	{
		return 0;
	}