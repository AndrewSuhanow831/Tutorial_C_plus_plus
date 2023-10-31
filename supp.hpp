#ifndef SUPP_H
#define SUPP_H

#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>

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
    std::stack<Item> stack;
    
private:
    void add(Item*&, int);
    void printItems1(Item *&root);
    void printItems2(Item *&root);

public:
    bTree()
    {
        root = nullptr;
    }

    void addItem(int);

    void printBTree();

};

template<class T>
class Queue
{
private:
    std::vector<T> vect;
    // T *pointer;

public:
    Queue()
    {
    }

    int size()
    {
        return vect.size();
    }

    void push(T value)
    {
        vect.resize(vect.size()+1);
        vect[vect.size() - 1] = value;
    }

    T first()
    {
        assert("Queue is empty!" && vect.size() != 0);
        return vect[0];
    }

    void pop()
    {
        for (int i = 0; i < vect.size() - 1; i++)
        {
            vect[i] = vect[i + 1];
        }
        vect.resize(vect.size()-1);
    }

    void print()
    {
        for (int i = 0; i < vect.size(); ++i)
            std::cout << vect[i] << "\t";
    }
};

class Anything
{
public:
// private:
    static int s_value;
};

void func();

class SomeParent
{
private:
    int m_private;
protected:    
    int m_protected;
public:
    int m_public;
SomeParent()
{
}
};

class SomeChild : public SomeParent
{
    public:
    SomeChild()
    : SomeParent()
    {
        // m_public = 2;
    }
};
#endif

template<class T>
T max(const T &x, const T &y)
{
    unsigned long long fs;
    size_t fs1;
    return ((x > y) ?  x : y);
}

using ull = unsigned long long;
const ull degree = 1024;

constexpr ull operator"" _KB(ull number)
{
    return number * degree;
}

constexpr int someFunction(const int &x, const int &y)
{
    return x + y;
}

void merge(std::vector<double> &A, const int p, const int q, const int r);

int doSmth();

class MyClass
{
public:
    void doSmth();
    void doSmth2(int a);
    int sum(int a, int b);

};

void print(char ch);

std::size_t find_range_m(const std::vector<int> &vec, int number);

void Func (char *s1, const char *s2);

int Test(void);

class Base 
{
    virtual void method1 () {std::cout << 100 << "\n";}
 };
class Derived: public Base 
{
    virtual void method1 () {std::cout << 200 << "\n";}
};

void otherStrcpy(std::string &newString, const std::string &source);
// void otherStrcpy(char *str1, const char *str2);

void sortTest (std::vector<int> vector);

class AbstractClass
{
    
private:
    int m_someVar = 0;

public:
    AbstractClass() = default;
    AbstractClass(int someValue);
    virtual double getP() = 0;
    virtual double getS() = 0;
};

class HeirAbstractClass : public AbstractClass
{
public:
    HeirAbstractClass() = default;
    HeirAbstractClass(int someValue);
    virtual double getP(){return 0;};
    virtual double getS(){return 0;};
};

enum class enumClass
{
    a,
    b,
    c
};