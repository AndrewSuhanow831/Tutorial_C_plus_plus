#ifndef SUPP_H
#define SUPP_H

#include <string>
#include <vector>

class Item // Узел дерева. Может содержать указатели на несколько дочерних узлов
{
private:
    Item* leftChild;
    Item* rigthChild;
    int m_name;
public:
    Item(int index) 
    : m_name(index)
    {
        leftChild = nullptr;
        rigthChild = nullptr;
    };
    int childCount() const ; // возвращает количество дочерних элементов данного узла
    Item *&child(int index); // возвращает указатель на дочерний элемент
                                     // по индексу [0 <= index < childCount()]
    void printName() const {std::cout << m_name << std::endl;}; // выводит имя данного узла
    int getName() const {return m_name;}
};

class bTree
{
private:
    Item *root;

private:
    void add(Item*&, int);
    void printItems1(Item *&root);
    void printItems2(Item *root);

public:
    bTree()
    {
        root = nullptr;
    }

    void addItem(int);

    void printBTree();

};

#endif


