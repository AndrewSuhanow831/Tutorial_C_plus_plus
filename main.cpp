#include <iostream>
#include <string>
#include <cstdint>
#include <Windows.h> //вывод кириллицы
#include <clocale> // вывод кириллицы
#include <bitset> //битовые флаги, маски
#include <typeinfo>
#include <string>
#include <cstdlib> // exit(), rand(), srand()
#include <ctime> // time()
#include <assert.h>
#include <array>
#include <algorithm>
#include <vector>
#include <functional>
#include <list>
#include <map>
#include "thread"
#include "mutex"
#include "chrono"

#include "supp.hpp"


int main()
{
    setlocale(LC_ALL, "ru");

    // int x = 10;
    // int y = 20;
    // std::cout << someFunction(x, y) << std::endl;
    
    // int a = 100'00'00;

    // std::cout << x << " " << y << std::endl;
    // auto foo = [&x, &y]()  { ++x; ++y; };
    // auto foo = [x, y]() mutable { ++x; ++y; };
    // auto foo = [&]() { ++x; ++y; };
    // auto foo = [=]() { ++x; ++y; };
    // foo();
    // std::cout << x << " " << y << std::endl;

    // std::cout << 1_KB << std::endl;

    // std::vector<double> A = {5,2,4,6,1,3,2,6};
    // for (int i = 0; i < A.size(); i++)
    // {
    //     std::cout << A[i] << " ";
    // }
    // std::cout << "\n";
    // merge(A, 0, 4, A.size());
    // for (int i = 0; i < A.size(); i++)
    // {
    //     std::cout << A[i] << " ";
    // }

    int a = 1;
    int b = 2;

    // std::thread someThread(doSmth, 2, 3);
    // std::thread someThread(doSmth, std::ref(a), std::ref(b));
    // int someVar = 0;
    // std::thread someThread([&someVar](){someVar = doSmth();});
    // someThread.detach();

    // MyClass myClass;
    // int someVar = 0;
    // std::thread someThread([&](){someVar = myClass.sum(2, 3);});
    // std::thread someThread(&MyClass::doSmth, myClass);
    // std::thread someThread(&MyClass::doSmth2, myClass, 5);

    // for (int i = 0; i < 10; i++)
    // {
        // std::cout << std::this_thread::get_id() << "\t" << "main(int argc ,*char argv[])"  << i << std::endl;
        // std::this_thread::sleep_for(std::chrono::milliseconds(500));
    // }

    // someThread.join();

    // std::cout << "someVar :\t" << someVar << std::endl;

    std::thread someThread1(print, '*');
    std::thread someThread2(print, '#');

    someThread1.join();
    someThread2.join();

    // print('*');
    // print('#');

	return 0;
}