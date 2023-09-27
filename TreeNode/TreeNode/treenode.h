#pragma once
// Занин Вячеслав ВМК-21

// Класс узла бинарного дерева
template <typename T>
class TreeNode {
private:
	// Значение узла
	T value;

	// Указатель на предка дерева
	TreeNode* parent_node;

	// Указатели на левый и правый узлы
	TreeNode* left_node;
	TreeNode* right_node;
public:
	// Безпараметрический конструктор
	TreeNode() {
		this->parent_node = nullptr;
		this->left_node = nullptr;
		this->right_node = nullptr;
	}

	// Конструктор с параметрами
	TreeNode(T value, TreeNode* parent_node = nullptr, TreeNode* left_node = nullptr, TreeNode* right_node = nullptr) {
		this->value = value;
		this->parent_node = parent_node;
		this->left_node = left_node;
		this->right_node = right_node;
	}


	// Возвращает значение узла
	T getValue() const {
		return this->value;
	}

	// Возвращает указатель на предка узла
	// Если указатель нулевой, то узел считается вершиной
	TreeNode* getParentNode() const {
		return this->parent_node;
	}

	// Возвращает указатель на левый узел-потомок
	// Если указатель нулевой, то узел считается узлом последнего уровня
	TreeNode* getLeftNode() const {
		return this->left_node;
	}

	// Возвращает указатель на правый узел-потомок
	// Если указатель нулевой, то узел считается узлом последнего уровня
	TreeNode* getRightNode() const {
		return this->right_node;
	}


	// Изменяет значение value
	void setValue(T value) {
		this->value = value;
	}

	// Изменяет указатель на предка.
	// Если функция указана без параметров, то узел становится вершиной
	void setParentNode(TreeNode* parent_node = nullptr) {
		this->parent_node = parent_node;
	}

	// Изменяет указатель на левого потомка.
	// Если функция указана без параметров, то узел рушит связь с потомком
	void setLeftNode(TreeNode* left_node = nullptr) {
		this->left_node = left_node;
		left_node->setParentNode(this);
	}

	// Изменяет указатель на правого потомка.
	// Если функция указана без параметров, то узел рушит связь с потомком
	void setRightNode(TreeNode* right_node = nullptr) {
		this->right_node = right_node;
		right_node->setParentNode(this);
	}


	// Деструктор класса
	~TreeNode() {
	}
};


// Класс бинарного дерева для 5 узлов
template <typename T1>
class BinTreeWithFiveNodes {
private:
	TreeNode <T1>* node_0;
	TreeNode <T1>* node_1;
	TreeNode <T1>* node_2;
	TreeNode <T1>* node_3;
	TreeNode <T1>* node_4;


	// Создает связи между всеми узлами, чем формирует дерево
	void createRelations() {
		node_0->setLeftNode(node_1);
		node_0->setRightNode(node_2);
		node_1->setLeftNode(node_3);
		node_2->setRightNode(node_4);
	}
public:
	// Беспараметрический конструктор
	BinTreeWithFiveNodes() {
		node_0 = new TreeNode <T1>();
		node_1 = new TreeNode <T1>();
		node_2 = new TreeNode <T1>();
		node_3 = new TreeNode <T1>();
		node_4 = new TreeNode <T1>();

		createRelations();
	}

	// Конструктор с параметрами
	BinTreeWithFiveNodes(T1 value_0, T1 value_1, T1 value_2, T1 value_3, T1 value_4) {
		node_0 = new TreeNode <T1>(value_0);
		node_1 = new TreeNode <T1>(value_1);
		node_2 = new TreeNode <T1>(value_2);
		node_3 = new TreeNode <T1>(value_3);
		node_4 = new TreeNode <T1>(value_4);

		createRelations();
	}

	// Выводит на экран значение узла
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

	// Деструктор класса
	~BinTreeWithFiveNodes() {
		node_0->~TreeNode();
		node_1->~TreeNode();
		node_2->~TreeNode();
		node_3->~TreeNode();
		node_4->~TreeNode();
	}
};
