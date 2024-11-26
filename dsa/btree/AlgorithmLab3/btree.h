#pragma once
#include <iostream>
#include <iomanip>
#include <stack>
#include <queue>

template <typename Data, typename Key>
class Tree
{
	struct Node
	{
		Key key;
		Data data;
		Node* right;
		Node* left;
		Node* parent;
		int bal;

		Node(Key key, Data data = nullptr, int bal = 0, Node* right = nullptr,
			Node* left = nullptr, Node* parent = nullptr);
	};

	// �� ���������������� ������
	Node* getMinNode(Node* node);									// ����� ��-� � ����������� ������
	Node* getMaxNode(Node* node);									// ����� ��-� � ������������ ������
	// ������ ��� ����������
	void L_t_R(Node*& root, std::queue<Node*>& queue);				// ���� ������� ���������
	void L_t_R(Node*& root, std::stack<Node*>& stack);				// ���� ����� ���������
	// ������ ��� ����������������� ������
	void calculateTreeBalance();									// �������� ��������� ������������ ����� ������
	int calculateNodeBalance(Node*& node);							// ������ ������������ ��������
	Node* balance(Node* node);										// ������������ ���������
	Node* llRotate(Node* node);										// ����� ����� �������
	Node* rrRotate(Node* node);										// ������ ����� �������
	Node* lrRotate(Node* node);										// ������� ����� �������
	Node* rlRotate(Node* node);										// ������� ������ �������

public:
	Node* root = nullptr;
	int size = 0;
	int viewedNodes = 0;

	Tree();															// �����������
	~Tree();														// ����������
	int getTreeSize();												// ��������� �������
	void clearTree(Node*& root);									// �������
	bool isTreeEmpty();												// �������� �� �������
	// �������� ������
	Data readNodeData(Key key);										// ����� ��������
	void editNodeData(Key key, Data newData, Node*& root);			// ��������� ��������
	void addNode(Key key, Data data, Node*& root);					// ���������� �������� � �������������
	void deleteNode(Key key, Node*& root, bool isBalanced);			// �������� �������� � �������������
	// �������������� ������
	int getNodeHeight(Node*& node);									// ��������� ������ ��������
	void t_Lt_Rt(Node*& root);										// ����� ������������������ ������ �� ����� t_Lt_Rt
	// ���������� ������
	bool isTreeContains(Key key, Node*& root);						// �������� �� ������ ��������
	int getViewedNodes();											// �������� ���-�� ������������� ��-�� ��������� ���������
	void resetViewed();												// ����� ���-�� ������������� ��-��
	void printTreeH(Node*& root, int indent = 0);					// �������������� �����

	// ���������
	class Iterator
	{
	public:
		Node* nodePtr;
		Tree* treePtr;

		Iterator(Node* nodePtr = nullptr, Tree* treePtr = nullptr);
		Data& operator*();
		void operator++(int);
		void operator--(int);
		bool operator==(const Iterator& it);
		bool operator!=(const Iterator& it);
	};
public:
	Iterator begin();
	Iterator end();

	class ReverseIterator
	{
	public:
		Node* nodePtr;
		Tree* treePtr;

		ReverseIterator(Node* nodePtr = nullptr, Tree* treePtr = nullptr);
		Data& operator*();
		void operator++(int);
		void operator--(int);
		bool operator==(const ReverseIterator& it);
		bool operator!=(const ReverseIterator& it);
	};

	ReverseIterator rBegin();
	ReverseIterator rEnd();
};

template<typename Data, typename Key>
inline Tree<Data, Key>::Node::Node(Key key, Data data, int bal, Node* right, Node* left, Node* parent)
{
	this->key = key;
	this->data = data;
	this->right = right;
	this->left = left;
	this->parent = parent;
	this->bal = bal;
}

template<typename Data, typename Key>
inline Tree<Data, Key>::Node* Tree<Data, Key>::getMinNode(Node* node)
{
	while (node)
	{
		if (node->left)
			node = node->left;
		else
			return node;
	}
}

template<typename Data, typename Key>
inline Tree<Data, Key>::Node* Tree<Data, Key>::getMaxNode(Node* node)
{
	while (node)
	{
		if (node->right)
			node = node->right;
		else
			return node;
	}
}

template<typename Data, typename Key>
inline Tree<Data, Key>::Tree()
{

}

template<typename Data, typename Key>
inline Tree<Data, Key>::~Tree()
{
	clearTree(root);
}

template<typename Data, typename Key>
inline int Tree<Data, Key>::getTreeSize()
{
	return size;
}

template<typename Data, typename Key>
inline void Tree<Data, Key>::clearTree(Node*& root)
{
	if (!root)
		return;
	if (root->left)
		clearTree(root->left);
	if (root->right)
		clearTree(root->right);
	delete root;
	size--;
}

template<typename Data, typename Key>
inline bool Tree<Data, Key>::isTreeEmpty()
{
	if (size < 0)
		return true;
	else
		return false;
}

template<typename Data, typename Key>
inline Data Tree<Data, Key>::readNodeData(Key key)
{
	Node* current = root;
	while (current)
	{
		viewedNodes++;
		if (key == current->key)
			return current->data;
		else if (key < current->key)
			current = current->left;
		else if (key > current->key)
			current = current->right;
	}
	// �� ����� �������
	throw std::exception("����������");
}

template<typename Data, typename Key>
inline void Tree<Data, Key>::editNodeData(Key key, Data newData, Node*& root)
{
	viewedNodes++;
	if (!root)
		return;
	if (key < root->key)
		editNodeData(key, newData, root->left);
	if (key > root->key)
		editNodeData(key, newData, root->right);
	else if (key == root->key)
		root->data = newData;
}

template<typename Data, typename Key>
inline void Tree<Data, Key>::addNode(Key key, Data data, Node*& root)
{
	Node* current = root, * parent = nullptr;
	while (current) 
	{
		viewedNodes++;
		parent = current;
		if (key == current->key)
			return;
		if (key < current->key)
			current = current->left;
		else
			current = current->right;
	}
	if (!parent) 
	{
		root = new Node(key, data);
	}
	else 
	{
		if (key < parent->key) 
			parent->left = new Node(key, data, 0, nullptr, nullptr, parent);
		else 
			parent->right = new Node(key, data, 0, nullptr, nullptr, parent);
	}
	current = parent;
	while (current)
	{
		if (abs(calculateNodeBalance(current)) > 1)
			current = balance(current);
		current = current->parent;
	}
	size++;
}

template<typename Data, typename Key>
inline void Tree<Data, Key>::deleteNode(Key key, Node*& root, bool isNeedBalance)
{
	Node* current = root, * parent = nullptr;
	while (current && current->key != key) 
	{
		viewedNodes++;
		parent = current;
		if (key < current->key)
			current = current->left;
		else if (key > current->key)
			current = current->right;
	}
	// �������� ���
	if (!current)
		return;
	if (!current->left && !current->right) 
	{
		delete current;
		current = parent;
		if (key < parent->key)
			parent->left = nullptr;
		else
			parent->right = nullptr;
	}
	else 
	{
		Node* temp = nullptr;
		if (!current->left)
			temp = current->right;
		else if (!current->right)
			temp = current->left;
		if ((bool)current->left != (bool)current->right)
		{
			delete current;
			if (key < parent->key)
				parent->left = temp;
			else
				parent->right = temp;
			temp->parent = parent;
		}
		else
		{
			Node* min = getMinNode(current->right);
			parent = min->parent;
			Data tempData = min->data;
			Key tempKey = min->key;
			deleteNode(tempKey, root, false);
			current->data = tempData;
			current->key = tempKey;
			size++;
		}
		current = parent;
	}
	// ����������� ������� � ������������
	while (current && isNeedBalance)
	{
		if (abs(calculateNodeBalance(current)) > 1)
			current = balance(current);
		current = current->parent;
	}
	size--;
}

// ����������� �����
template<typename Data, typename Key>
inline void Tree<Data, Key>::printTreeH(Node*& root, int indent)
{
	if (!root)
	{
		std::cout << "������ ������" << std::endl;
		return;
	}
	calculateTreeBalance();
	if (root->right)
		printTreeH(root->right, indent + 4);
	if (indent)
		std::cout << std::setw(indent) << ' ';
	if (root->right)
		std::cout << " /\n" << std::setw(indent) << ' ';
	std::cout << root->key << ":" << root->bal << std::endl;
	if (root->left)
	{
		std::cout << std::setw(indent) << ' ' << " \\\n";
		printTreeH(root->left, indent + 4);
	}
}

template<typename Data, typename Key>
inline void Tree<Data, Key>::calculateTreeBalance()
{
	Node* current = nullptr;
	std::queue<Node*> queue;
	queue.push(root);
	while(!queue.empty())
	{
		current = queue.front();
		queue.pop();
		current->bal = calculateNodeBalance(current);
		if (current->left)
			queue.push(current->left);
		if (current->right)
			queue.push(current->right);
	}
}

template<typename Data, typename Key>
inline int Tree<Data, Key>::calculateNodeBalance(Node*& node)
{
	return getNodeHeight(node->right) - getNodeHeight(node->left);
}

template<typename Data, typename Key>
inline Tree<Data, Key>::Node* Tree<Data, Key>::balance(Node* node)
{
	Node* temp = nullptr;
	int bal = calculateNodeBalance(node);
	// ����� ������� ���������������
	if (bal < -1) {
		// ���� ����� ��������� ������� ������ ��� ����� �������
		if (getNodeHeight(node->left) >= getNodeHeight(node->right))
			temp = rrRotate(node);
		else
			temp = rlRotate(node);
	}
	// ������ ������� ���������������
	else if (bal > 1) {
		// ���� ������ ��������� ������� ������ ��� ����� ������
		if (getNodeHeight(node->right) >= getNodeHeight(node->left))
			temp = llRotate(node);
		else
			temp = lrRotate(node);
	}
	return temp;
}

template<typename Data, typename Key>
inline Tree<Data, Key>::Node* Tree<Data, Key>::llRotate(Node* node)
{
	Node* temp = node->right;
	node->right = temp->left;
	temp->left = node;
	// ��������
	temp->parent = node->parent;
	if (temp->parent)
	{
		if (temp->key < temp->parent->key)
			temp->parent->left = temp;
		else if (temp->key > temp->parent->key)
			temp->parent->right = temp;
	}
	else
		root = temp;
	if (node->right)
		node->right->parent = node;
	if (temp->left)
		temp->left->parent = temp;
	node->parent = temp;
	return temp;
}

template<typename Data, typename Key>
inline Tree<Data, Key>::Node* Tree<Data, Key>::rrRotate(Node* node)
{
	Node* temp = node->left;
	node->left = temp->right;
	temp->right = node;
	// ��������
	temp->parent = node->parent;
	if (temp->parent)
	{
		if (temp->key < temp->parent->key)
			temp->parent->left = temp;
		else if (temp->key > temp->parent->key)
			temp->parent->right = temp;
	}
	else
		root = temp;
	if (node->left)
		node->left->parent = node;
	if (node->right)
		temp->right->parent = temp;
	node->parent = temp;
	return temp;
}

template<typename Data, typename Key>
inline Tree<Data, Key>::Node* Tree<Data, Key>::lrRotate(Node* node)
{
	Node* temp;
	temp = node->right;
	node->right = rrRotate(temp);
	return llRotate(node);
}

template<typename Data, typename Key>
inline Tree<Data, Key>::Node* Tree<Data, Key>::rlRotate(Node* node)
{
	Node* temp;
	temp = node->left;
	node->left = llRotate(temp);
	return rrRotate(node);
}

template<typename Data, typename Key>
inline void Tree<Data, Key>::t_Lt_Rt(Node*& root)
{
	if (!root)
		return;
	std::cout << root->key << " ";
	t_Lt_Rt(root->left);
	t_Lt_Rt(root->right);
}

template<typename Data, typename Key>
inline int Tree<Data, Key>::getNodeHeight(Node*& node)
{
	int h1 = 0, h2 = 0;
	if (!node)
		return 0;
	if (node->left)
		h2 = getNodeHeight(node->left);
	if (node->right)
		h1 = getNodeHeight(node->right);
	return (std::max(h1, h2) + 1);
}

template<typename Data, typename Key>
inline bool Tree<Data, Key>::isTreeContains(Key key, Node*& root)
{
	if (!root)
		return false;
	else if (key < root->key)
		return isTreeContains(key, root->left);
	else if (key > root->key)
		return isTreeContains(key, root->right);
	else
		return true;
}

template<typename Data, typename Key>
inline int Tree<Data, Key>::getViewedNodes()
{
	return viewedNodes;
}

template<typename Data, typename Key>
inline void Tree<Data, Key>::resetViewed()
{
	viewedNodes = 0;
}

template<typename Data, typename Key>
inline void Tree<Data, Key>::L_t_R(Node*& root, std::queue<Node*>& queue)
{
	if (!root)
		return;
	if (root->left)
		L_t_R(root->left, queue);
	// ���� ���������� ������� � �������� ��������� � ����������
	queue.push(root);
	if (root->right)
		L_t_R(root->right, queue);
}

template<typename Data, typename Key>
inline void Tree<Data, Key>::L_t_R(Node*& root, std::stack<Node*>& stack)
{
	if (!root)
		return;
	if (root->left)
		L_t_R(root->left, stack);
	// ���� ���������� ������� � �������� ��������� � ����������
	stack.push(root);
	if (root->right)
		L_t_R(root->right, stack);
}

template<typename Data, typename Key>
inline Tree<Data, Key>::Iterator Tree<Data, Key>::begin()
{
	Iterator it{};
	if (this->size)
		it.nodePtr = getMinNode(root);
	it.treePtr = this;
	return it;
}

template<typename Data, typename Key>
inline Tree<Data, Key>::Iterator Tree<Data, Key>::end()
{
	Iterator it{};
	if (this->size)
		it.nodePtr = getMaxNode(root);
	it.treePtr = this;
	return it;
}

template<typename Data, typename Key>
inline Tree<Data, Key>::Iterator::Iterator(Node* nodePtr, Tree* treePtr)
{
	this->nodePtr = nodePtr;
	this->treePtr = treePtr;
}

template<typename Data, typename Key>
inline Data& Tree<Data, Key>::Iterator::operator*()
{
	return this->nodePtr->data;
}

template<typename Data, typename Key>
inline void Tree<Data, Key>::Iterator::operator++(int)
{
	std::queue<Node*> queue;
	this->treePtr->L_t_R(this->treePtr->root, queue);
	Node* current;
	while (!queue.empty())
	{
		current = queue.front();
		queue.pop();

		// ���� ����� �� ������ ������
		if (queue.empty())
		{
			// ���� ����� �� ������ ������
			throw std::exception("����������");
		}
		// ���� ������� ��������� � ����������
		// �� ��������� ������� ��������� � ���������
		else if (current == this->nodePtr)
		{
			this->nodePtr = queue.front();
			return;
		}
	}
}

template<typename Data, typename Key>
inline void Tree<Data, Key>::Iterator::operator--(int)
{
	std::stack<Node*> stack;
	this->treePtr->L_t_R(this->treePtr->root, stack);
	Node* current;
	while (!stack.empty())
	{
		current = stack.top();
		stack.pop();
		// ���� ����� �� ������ ������
		if (stack.empty())
		{
			// ���� ����� �� ������ ������
			throw std::exception("����������");
		}
		// ���� ������� ��������� � ����������
		// �� ��������� ������� ��������� � ���������
		else if (current == this->nodePtr)
		{
			this->nodePtr = stack.top();
			return;
		}
	}
}

template<typename Data, typename Key>
inline bool Tree<Data, Key>::Iterator::operator==(const Iterator& it)
{
	if (nodePtr == it.nodePtr)
		return true;
	else
		return false;
}

template<typename Data, typename Key>
inline bool Tree<Data, Key>::Iterator::operator!=(const Iterator& it)
{
	if (nodePtr != it.nodePtr)
		return true;
	else
		return false;
}

template<typename Data, typename Key>
inline Tree<Data, Key>::ReverseIterator Tree<Data, Key>::rBegin()
{
	ReverseIterator it{};
	if (this->size)
		it.nodePtr = getMaxNode(root);
	it.treePtr = this;
	return it;
}

template<typename Data, typename Key>
inline Tree<Data, Key>::ReverseIterator Tree<Data, Key>::rEnd()
{
	ReverseIterator it{};
	if (this->size)
		it.nodePtr = getMinNode(root);
	it.treePtr = this;
	return it;
}

template<typename Data, typename Key>
inline Tree<Data, Key>::ReverseIterator::ReverseIterator(Node* nodePtr, Tree* treePtr)
{
	this->nodePtr = nodePtr;
	this->treePtr = treePtr;
}

template<typename Data, typename Key>
inline Data& Tree<Data, Key>::ReverseIterator::operator*()
{
	return this->nodePtr->data;
}


template<typename Data, typename Key>
inline void Tree<Data, Key>::ReverseIterator::operator++(int)
{
	std::stack<Node*> stack;
	this->treePtr->L_t_R(this->treePtr->root, stack);
	Node* current;
	while (!stack.empty())
	{
		current = stack.top();
		stack.pop();
		// ���� ����� �� ������ ������
		if (stack.empty())
		{
			// ���� ����� �� ������ ������
			throw std::exception("����������");
		}
		// ���� ������� ��������� � ����������
		// �� ��������� ������� ��������� � ���������
		else if (current == this->nodePtr)
		{
			this->nodePtr = stack.top();
			return;
		}
	}
}

template<typename Data, typename Key>
inline void Tree<Data, Key>::ReverseIterator::operator--(int)
{
	std::queue<Node*> queue;
	this->treePtr->L_t_R(this->treePtr->root, queue);
	Node* current;
	while (!queue.empty())
	{
		current = queue.front();
		queue.pop();

		// ���� ����� �� ������ ������
		if (queue.empty())
		{
			// ���� ����� �� ������ ������
			throw std::exception("����������");
		}
		// ���� ������� ��������� � ����������
		// �� ��������� ������� ��������� � ���������
		else if (current == this->nodePtr)
		{
			this->nodePtr = queue.front();
			return;
		}
	}
}

template<typename Data, typename Key>
inline bool Tree<Data, Key>::ReverseIterator::operator==(const ReverseIterator& it)
{
	if (nodePtr == it.nodePtr)
		return true;
	else
		return false;
}

template<typename Data, typename Key>
inline bool Tree<Data, Key>::ReverseIterator::operator!=(const ReverseIterator& it)
{
	if (nodePtr != it.nodePtr)
		return true;
	else
		return false;
}