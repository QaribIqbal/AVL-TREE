//#include<iostream>
//using namespace std;
//struct node {
//	int height;
//	node* left;
//	node* right;
//	int data;
//	node()
//	{
//		left = nullptr;
//		right = nullptr;
//		height = 1;
//		data = 0;
//	}
//	node(int val) {
//		data = val;
//		height = 1;
//		left = nullptr;
//		right = nullptr;
//	}
//};
//class AVL {
//private:
//	node* root;
//
//	//level related functions
//	int getHeight(node* ptr) {
//		if (ptr == nullptr)
//		{
//			return 0;
//		}
//
//		return ptr->height;
//	}
//	int checkBalance(node* nodeleaf)
//	{
//		int sum = (this->getHeight(nodeleaf->left) - this->getHeight(nodeleaf->right));
//		return sum;
//	}
//	//Rotations 
//
//	node* rotateLeft(node* parentNode, node* nodeleaf)
//	{
//		node* temp = nodeleaf->right;
//		node* temp2 = nodeleaf->right->left;
//		nodeleaf->right->left = nodeleaf;
//		nodeleaf->right = temp2;
//		parentNode->right = temp;
//		return temp;
//		// Update heights
//		nodeleaf->height = max(getHeight(nodeleaf->left), getHeight(nodeleaf->right)) + 1;
//		temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
//
//	}
//	node* rotateRight(node* parentNode, node* nodeleaf)
//	{
//		node* temp = nodeleaf->left;
//		node* temp2 = nodeleaf->left->right;
//		nodeleaf->left->right = nodeleaf;
//		nodeleaf->left = temp2;
//		parentNode->left = temp;
//		return temp;
//		// Update heights
//		nodeleaf->height = max(getHeight(nodeleaf->left), getHeight(nodeleaf->right)) + 1;
//		temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
//
//
//	}
//	//Insertions and reassignments of height when returning in recursion
//	node* insert(node* prev_node, node* leafnode, int val)
//	{
//		//prev_node = leafnode;
//		if (leafnode == nullptr) {
//			return new node(val);
//		}
//		else if (leafnode->data < val)
//		{
//			leafnode->left=insert(leafnode, leafnode->right, val);
//		}
//		else if (leafnode->data > val)
//		{
//			leafnode->right=insert(leafnode, leafnode->left, val);
//		}
//		else {
//			return leafnode;
//		}
//		leafnode->height = max(this->getHeight(leafnode->left), this->getHeight(leafnode->right)) + 1;
//
//		//NOW CHECK FOR BALANCE IN THE TREE
//		int balance = checkBalance(leafnode);
//		if (balance > 1 && val < leafnode->left->data)
//		{
//			//LL
//
//			rotateRight(prev_node, leafnode);
//		}
//		else if (balance > 1 && val > leafnode->left->data)
//		{
//			//LR
//			rotateLeft(leafnode, leafnode->left);
//		}
//		else if (balance<0 && val>leafnode->right->data)
//		{
//			//RR
//			rotateLeft(prev_node, leafnode);
//		}
//		else if (balance < 0 && val < leafnode->right->data)
//		{
//			rotateRight(prev_node, leafnode);
//		}
//		else {
//			//same val node
//			return leafnode;
//		}
//
//	}
//	//Taversal IN-ORDER
//	void print(node* leafnode)
//	{
//		if (leafnode == nullptr)
//		{
//			return;
//		}
//		print(leafnode->left);
//		cout << leafnode->data << endl;
//		print(leafnode->right);
//	}
//public:
//	AVL()
//	{
//		this->root = nullptr;
//	}
//	void insertNode(node* root, int val)
//	{
//		if (root == nullptr)
//		{
//			this->root = new node(val);
//		}
//		else if (val < root->data)
//		{
//			this->root = insert(this->root, this->root->left, val);
//		}
//		else if (val > root->data)
//		{
//			this->root = insert(this->root, this->root->right, val);
//		}
//		else {
//			cout << "\nSame values are not allowed and won't be added!\n";
//		}
//	}
//	node* getRoot()
//	{
//		return this->root;
//	}
//	void printTree(node* root)
//	{
//		print(root);
//	}
//};
//int main()
//{
//	AVL tree;
//	tree.insertNode(tree.getRoot(),1);
//	tree.insertNode(tree.getRoot(), 2);
//	tree.insertNode(tree.getRoot(), 3);
//	tree.printTree(tree.getRoot());
//	return 0;
//}
#include<iostream>
using namespace std;

struct node {
    int height;
    node* left;
    node* right;
    int data;

    node(int val) {
        data = val;
        height = 1;
        left = nullptr;
        right = nullptr;
    }
};

class AVL {
private:
    node* root;

    int getHeight(node* ptr) {
        if (ptr == nullptr) return 0;
        return ptr->height;
    }

    int getBalanceFactor(node* nodeleaf) {
        if (nodeleaf == nullptr) return 0;
        return getHeight(nodeleaf->left) - getHeight(nodeleaf->right);
    }

    node* rotateLeft(node* nodeleaf) {
        node* temp = nodeleaf->right;
        nodeleaf->right = temp->left;
        temp->left = nodeleaf;

        nodeleaf->height = max(getHeight(nodeleaf->left), getHeight(nodeleaf->right)) + 1;
        temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;

        return temp;
    }

    node* rotateRight(node* nodeleaf) {
        node* temp = nodeleaf->left;
        nodeleaf->left = temp->right;
        temp->right = nodeleaf;

        nodeleaf->height = max(getHeight(nodeleaf->left), getHeight(nodeleaf->right)) + 1;
        temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;

        return temp;
    }

    node* insert(node* leafnode, int val) {
        if (leafnode == nullptr)
            return new node(val);

        if (val < leafnode->data)
            leafnode->left = insert(leafnode->left, val);
        else if (val > leafnode->data)
            leafnode->right = insert(leafnode->right, val);
        else
            return leafnode;  // No duplicate values allowed

        // Update height of this node
        leafnode->height = 1 + max(getHeight(leafnode->left), getHeight(leafnode->right));

        // Check balance
        int balance = getBalanceFactor(leafnode);

        // Left-Left Case (Right Rotate)
        if (balance > 1 && val < leafnode->left->data)
            return rotateRight(leafnode);

        // Right-Right Case (Left Rotate)
        if (balance < -1 && val > leafnode->right->data)
            return rotateLeft(leafnode);

        // Left-Right Case (Left Rotate + Right Rotate)
        if (balance > 1 && val > leafnode->left->data) {
            leafnode->left = rotateLeft(leafnode->left);
            return rotateRight(leafnode);
        }

        // Right-Left Case (Right Rotate + Left Rotate)
        if (balance < -1 && val < leafnode->right->data) {
            leafnode->right = rotateRight(leafnode->right);
            return rotateLeft(leafnode);
        }

        return leafnode; // No rotation needed
    }

    void print(node* leafnode) {
        if (leafnode == nullptr) return;
        print(leafnode->left);
        cout << leafnode->data << " ";
        print(leafnode->right);
    }

public:
    AVL() { root = nullptr; }

    void insertNode(int val) {
        root = insert(root, val);
    }

    void printTree() {
        print(root);
        cout << endl;
    }
};

int main() {
    AVL tree;
    tree.insertNode(1);
    tree.insertNode(2);
    tree.insertNode(3);
    tree.insertNode(4);
    tree.insertNode(5);
    tree.printTree();  // Expected Output: 1 2 3 4 5 (balanced)

    return 0;
}
