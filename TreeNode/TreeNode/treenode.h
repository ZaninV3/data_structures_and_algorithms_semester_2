#pragma once
#include <vector>
// ����� �������� ���-21

// ����� ���� ��������� ������
template <typename T>
class TreeNode {
private:
	// �������� ����
	T value;

	// ��������� �� ������ ������
	// ���� ��� �������� nullptr, �� ���� ��������� ������ ������
	TreeNode* parent_node;

	// ��������� �� ����� � ������ ����
	TreeNode* left_node;
	TreeNode* right_node;
public:
	// ������������������ �����������
	TreeNode() {
		this->parent_node = nullptr;
		this->left_node = nullptr;
		this->right_node = nullptr;
	}

	// ����������� � �����������
	TreeNode(T value, TreeNode* parent_node = nullptr, TreeNode* left_node = nullptr, TreeNode* right_node = nullptr) {
		this->value = value;
		this->parent_node = parent_node;
		this->left_node = left_node;
		this->right_node = right_node;
	}



	// ���������� �������� ����
	T getValue() const {
		return this->value;
	}

	// ���������� ��������� �� ������ ����
	// ���� ��������� �������, �� ���� ��������� ��������
	TreeNode* getParentNode() const {
		return this->parent_node;
	}

	// ���������� ��������� �� ����� ����-�������
	// ���� ��������� �������, �� ���� ��������� ����� ���������� ������
	TreeNode* getLeftNode() const {
		return this->left_node;
	}

	// ���������� ��������� �� ������ ����-�������
	// ���� ��������� �������, �� ���� ��������� ����� ���������� ������
	TreeNode* getRightNode() const {
		return this->right_node;
	}

	// ���� � ���������� ������ ������
	// ��� ����������� �� ����, � ������ ���� ���������� �����
	TreeNode* getRoot() {
		// ����� ���� ���� -- ������ ������
		TreeNode <T>* root = this;

		// ����� ���� ���� ���� �� ���������
		// �� ��������� � ��� �������� � ���������� ��������
		while (root->getParentNode() != nullptr) {
			root = root->getParentNode();
		}

		// ��� ������ ����� ������
		// ���������� ���
		return root;
	}



	// �������� �������� value
	void setValue(T value) {
		this->value = value;
	}

	// �������� ��������� �� ������.
	// ���� ������� ������� ��� ����������, �� ���� ���������� ��������
	void setParentNode(TreeNode* parent_node = nullptr) {
		this->parent_node = parent_node;
	}

	// �������� ��������� �� ������ �������.
	// ���� ������� ������� ��� ����������, �� ���� ����� ����� � ��������
	void setLeftNode(TreeNode* left_node = nullptr) {
		this->left_node = left_node;
		left_node->setParentNode(this);
	}

	// �������� ��������� �� ������� �������.
	// ���� ������� ������� ��� ����������, �� ���� ����� ����� � ��������
	void setRightNode(TreeNode* right_node = nullptr) {
		this->right_node = right_node;
		right_node->setParentNode(this);
	}

	// ����� � ������
	// ��� ����������� �� ����, � ������ ���� ����� �����
	// ����� ������ ����� ���������� � �����
	TreeNode* findBreadthFirstSearch(T value) {
		// �������� � �����
		TreeNode <T>* node = this->getRoot();

		// ��������� ������
		if (node->getValue() != value) {
			// �������
			std::vector <TreeNode <T>*> queue;

			// ��������� ������ � ������� ������� � �������
			queue.push_back(node->getLeftNode);
			queue.push_back(node->getRightNode);

			// ����������-������� ��� �������� �������
			unsigned int i = 0;

			while (true) {
				if (queue[i].getValue() != value) {

				}
			}
		}

		// ���� ���� ������ �� �������, ���������� ������ ������
		return node;
	}

	// ���������� ���� ������
	~TreeNode() {
	}
};


// ����� ��������� ������ ��� 5 �����
template <typename T1>
class BinTreeWithFiveNodes {
private:
	TreeNode <T1>* node_0;
	TreeNode <T1>* node_1;
	TreeNode <T1>* node_2;
	TreeNode <T1>* node_3;
	TreeNode <T1>* node_4;


	// ������� ����� ����� ����� ������, ��� ��������� ������
	void createRelations() {
		node_0->setLeftNode(node_1);
		node_0->setRightNode(node_2);
		node_1->setLeftNode(node_3);
		node_2->setRightNode(node_4);
	}
public:
	// ������������������ �����������
	BinTreeWithFiveNodes() {
		node_0 = new TreeNode <T1>();
		node_1 = new TreeNode <T1>();
		node_2 = new TreeNode <T1>();
		node_3 = new TreeNode <T1>();
		node_4 = new TreeNode <T1>();

		createRelations();
	}

	// ����������� � �����������
	BinTreeWithFiveNodes(T1 value_0, T1 value_1, T1 value_2, T1 value_3, T1 value_4) {
		node_0 = new TreeNode <T1>(value_0);
		node_1 = new TreeNode <T1>(value_1);
		node_2 = new TreeNode <T1>(value_2);
		node_3 = new TreeNode <T1>(value_3);
		node_4 = new TreeNode <T1>(value_4);

		createRelations();
	}

	// ���������� ���� ������
	TreeNode <T1>* getNode(unsigned int index_node) {
		switch (index_node) {
		case 0:
			return node_0;
		case 1:
			return node_1;
		case 2:
			return node_2;
		case 3:
			return node_3;
		case 4:
			return node_4;
		default:
			break;
		}
	}

	// ������� �� ����� �������� ����
	void printNodeValue(unsigned int index_node) {
		switch (index_node) {
		case 0:
			std::cout << node_0->getValue() << std::endl;
			break;
		case 1:
			std::cout << node_1->getValue() << std::endl;
			break;
		case 2:
			std::cout << node_2->getValue() << std::endl;
			break;
		case 3:
			std::cout << node_3->getValue() << std::endl;
			break;
		case 4:
			std::cout << node_4->getValue() << std::endl;
			break;
		default:
			break;
		}
	}

	// ���������� ������ �� 5 �����
	~BinTreeWithFiveNodes() {
		node_0->~TreeNode();
		node_1->~TreeNode();
		node_2->~TreeNode();
		node_3->~TreeNode();
		node_4->~TreeNode();
	}
};
