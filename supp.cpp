#include <iostream>
#include <math.h>
#include <cassert>
#include "thread"
#include "mutex"
#include "chrono"

#include "supp.hpp"

int Item::childCount() const
{
    int count = -1;
    if (leftChild)
        ++count;
    
    if (rigthChild)
        ++count;
    
    return count;
};

Item*& Item::child(int index)
{
    // assert(0 <= index && index <= childCount());
    switch (index)
    {
    case 0:
        return leftChild;
    default:
        return rigthChild;
    }
}

void bTree::add(Item *&root, int index)
{
    if (!root)
        root = new Item(index);
    else
    {
        if (index <= root->getName()) 
            add(root->child(0), index); 
        else
            add(root->child(1), index);
    }
}

void bTree::addItem(int index)
{
    add(root, index);
}

// Обход в глубину: рекурсивный алгоритм
void bTree::printItems1(Item *&root)
{
    if (root)
    {
        printItems1(root->child(0));
        std::cout << root->getName() << "\t";
        printItems1(root->child(1));
    }
}

// Обход в глубину: нерекурсивный алгоритм
void bTree::printItems2(Item *&root)
{
    stack.push(*root);
    Item *&ptr = root->child(0);
    while (ptr || !stack.empty())
    {
        if (!ptr)
        {
            std::cout << stack.top().getName() << "\t";
            ptr = stack.top().child(1);
            stack.pop();
        }
        else
        {
            stack.push(*ptr);
            ptr = ptr->child(0);
        }
    }
}

 void bTree::printBTree()
 {
    std::cout << "printItems1: " << std::endl;
    printItems1(root);
    std::cout << "\n";
    std::cout << "printItems2: " << std::endl;
    printItems2(root);
 }

 int Anything::s_value = 3;

 void func1(int &x)
{
    while (x & (4 | 8) || x > 6)
    {
        x /= 2;
        if (x == 1)
            x++;
    }
}

void func()
{
    int x = 0x10; // 0001 0000 ~ 16
    func1(x);
    std::cout << x++;
}

void merge(std::vector<double> &A, const int p, const int q, const int r)
{
    if ((p <= q) && (q <= r) && (A.size() <= r))
    {
        std::vector<double> result;
        std::queue<double> leftStack;
        std::queue<double> rightStack;
        for (int i = p; i < q; ++i)
        {
            leftStack.push(A[i]);
        }
        for (int i = q; i < r; ++i)
        {
            rightStack.push(A[i]);
        }
        int indexA = p;
        while (!(leftStack.empty() || rightStack.empty()))
        {
            double element = 0;
            if (leftStack.front() <= rightStack.front())
            {
                element = leftStack.front();
                leftStack.pop();
            }
            else
            {
                element = rightStack.front();
                rightStack.pop();
            }
            A[indexA++] = element;
        }
        if (indexA <= A.size())
        {
            while (!leftStack.empty())
            {
                A[indexA++] = leftStack.front();
                leftStack.pop();
            }
            while (!rightStack.empty())
            {
                A[indexA++] = rightStack.front();
                rightStack.pop();
            }
        }
    }
}

int MyClass::sum(int a, int b)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "\t" << std::this_thread::get_id() << "\t" << "START sum" << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout << "\t" << "END sum" << "\n";
    return a + b;
}

void MyClass::doSmth()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "\t" << std::this_thread::get_id() << "\t" << "START doSmth" << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout << "\t" << "END doSmth" << "\n";
}

void MyClass::doSmth2(int a)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "\t" << std::this_thread::get_id() << "\t" << "START doSmth2" << "\n";
    std::cout << "a :\t" << a << "\n"; 
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout << "\t" << "END doSmth2" << "\n";
}

std::mutex mtx;

void print(char ch)
{
    mtx.lock();

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            std::cout << ch;
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    mtx.unlock();
}

std::size_t find_range_m(const std::vector<int> &vec, int number)
{
    std::size_t result = 0;
    std::size_t intermediateResult = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec.at(i) == number)
        {
            ++intermediateResult;
        }
        else
        {
            intermediateResult = 0;
        }
            if (result < intermediateResult)
            {
                result = intermediateResult;
            }
    }
    return result;
}

void Func (char *s1, const char *s2)
{
   while (*s1++ = *s2++);
   {    
        std::cout << s1 << "\n";
        std::cout << *s1 << "\n";
        std::cout << s2 << "\n";
        std::cout << *s2 << "\n";
        return;
   }
}

int Test(void)
{
    int x, *p;
    x = 10;
    p = &x;
    return *p;
}

void sortTest (std::vector<int> vector)
{
    for (int i = 0; i < vector.size(); i++)
    {
        for (int j = i + 1; j < vector.size() - 1; j++)
        {
            if (vector[i] > vector[j])
            {
                vector[i] += vector[j];
                vector[j] = vector[i] - vector[j];
                vector[i] -= vector[j]; 
            }
        }
    }
    for (int i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << "\n";
    }
}

void otherStrcpy(std::string &newString, const std::string &source)
{
    int sourceSize = source.size();
    if (sourceSize > newString.size())
    {
        newString.resize(sourceSize);
    }
    for (int i = 0; i < sourceSize; ++i)
    {
        newString[i] = source.at(i);
    }
}

AbstractClass::AbstractClass(int someValue)
    : m_someVar(someValue)
{
}

HeirAbstractClass::HeirAbstractClass(int someValue)
    : AbstractClass(someValue) 
{
}
