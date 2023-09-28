#pragma once
#include <vector>
// Занин Вячеслав ВМК-21

// Класс узла бинарного дерева
template <typename T>
class TreeNode {
private:
	// Значение узла
	T value;

	// Указатель на предка дерева
	// Если его значение nullptr, то узел считается корнем дерева
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

	// Ищет и возвращает корень дерева
	// Вне зависимости от того, с какого узла начинается поиск
	TreeNode* getRoot() {
		// Пусть этот узел -- корень дерева
		TreeNode <T>* root = this;

		// Тогда если этот узел не указатель
		// то переходим к его родителю и продолжаем проверку
		while (root->getParentNode() != nullptr) {
			root = root->getParentNode();
		}

		// Как только нашли корень
		// возвращаем его
		return root;
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

	// Поиск в ширину
	// Вне зависимости от того, с какого узла начат поиск
	// Поиск всегда будет начинаться с корня
	TreeNode* findBreadthFirstSearch(T value) {
		// Начинаем с корня
		TreeNode <T>* node = this->getRoot();

		// Проверяем корень
		if (node->getValue() != value) {
			// Очередь
			std::vector <TreeNode <T>*> queue;

			// Добавляем левого и правого потомка в очередь
			queue.push_back(node->getLeftNode);
			queue.push_back(node->getRightNode);

			// Переменная-счетчик для перебора очереди
			unsigned int i = 0;

			while (true) {
				if (queue[i].getValue() != value) {

				}
			}
		}

		// Даже если ничего не найдено, возвращаем корень дерева
		return node;
	}

	// Деструктор узла дерева
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

	// Возвращает узел дерева
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

	// Деструктор дерева из 5 узлов
	~BinTreeWithFiveNodes() {
		node_0->~TreeNode();
		node_1->~TreeNode();
		node_2->~TreeNode();
		node_3->~TreeNode();
		node_4->~TreeNode();
	}
};
