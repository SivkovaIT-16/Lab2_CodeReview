/* Элементами контейнеров являются целые числа. Для
заполнения контейнера использовать итератор и конструктор соответствующего контейнера,
для вывода элементов использовать итератор (для вывода элементов в обратном порядке
использовать обратные итераторы, возвращаемые функциями-членами rbegin и rend)
Обязательно наличие дружественного интерфейса. Ввод данных организовать
разными способами (с клавиатуры, рандом, из файла)

Даны вектор V, дек D и список L. Каждый исходный контейнер содержит не менее
двух элементов, количество элементов является четным. Поменять значения двух средних
элементов каждого из исходных контейнеров. Использовать алгоритм swap (не путать его с
одноименной функцией-членом контейнера).


*/

// FIX_ME: программа разделена на модули
#include "Header.h"
#include <vector>
#include <ctime>
#include <deque>
#include <list>
#include <fstream>
#include <iostream>

// FIX_ME: using namespace std в глобальной области видимости
//using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    // FIX_ME: имена переменных должны начинаться с заглавной буквы и быть информативными
    // FIX_ME: переменные должны быть инициализированы при создании
    //int n1, n2, n3;
    int Size1 = 0, Size2 = 0, Size3 = 0;

    // FIX_ME: добавлен std::
    // FIX_ME: имена переменных должны быть информативными
    //vector <int> V;
    //deque <int> D;
    //list <int> L;
    std::vector<int> Vector;
    std::deque<int> Deque;
    std::list<int> List;

    // FIX_ME: добавлен std::
    //cout << "Введите размерность вектора n1 (n1 >= 2, n1-чётное): ";
    //cin >> n1;
    std::cout << "Введите размерность вектора (>= 2, четное): ";
    std::cin >> Size1;
    //Input(V, n1);
    InputContainer(Vector, Size1);

    // FIX_ME: добавлен std::
    //cout << "Введите размерность дека n2 (n2 >= 2, n2-чётное): ";
    //cin >> n2;
    std::cout << "\nВведите размерность дека (>= 2, четное): ";
    std::cin >> Size2;
    //Input(D, n2);
    InputContainer(Deque, Size2);

    // FIX_ME: добавлен std::
    //cout << "Введите размерность списка n3 (n3 >= 2, n3-чётное): ";
    //cin >> n3;
    std::cout << "\nВведите размерность списка (>= 2, четное): ";
    std::cin >> Size3;
    //Input(L, n3);
    InputContainer(List, Size3);

    // FIX_ME: добавлен std::
    //cout << "Изначальное содержимое контейнеров." << endl;
    //cout << "Вектор: ";
    std::cout << "\nИзначальное содержимое контейнеров:" << std::endl;
    std::cout << "Вектор: ";

    //Print(V);
    PrintContainer(Vector);

    // FIX_ME: добавлен std::
    //cout << "Дек: ";
    std::cout << "Дек: ";

    //Print(D);
    PrintContainer(Deque);

    // FIX_ME: добавлен std::
    //cout << "Список: ";
    std::cout << "Список: ";

    //Print(L);
    PrintContainer(List);

    //MiddleElement(V);
    //MiddleElement(D);
    //MiddleElement(L);
    SwapMiddleElements(Vector);
    SwapMiddleElements(Deque);
    SwapMiddleElements(List);

    // FIX_ME: добавлен std::
    //cout << "Изменённое содержание контейнеров." << endl;
    //cout << "Вектор: ";
    std::cout << "\nИзменённое содержание контейнеров:" << std::endl;
    std::cout << "Вектор: ";

    //Print(V);
    PrintContainer(Vector);

    // FIX_ME: добавлен std::
    //cout << "Дек: ";
    std::cout << "Дек: ";

    //Print(D);
    PrintContainer(Deque);

    // FIX_ME: добавлен std::
    //cout << "Список: ";
    std::cout << "Список: ";

    //Print(L);
    PrintContainer(List);

    // FIX_ME: добавлен std::
    //cout << "      /\\     /\\  " << endl;
    //cout << "     {  `---'  } " << endl;
    //cout << "     {  O   O  } " << endl;
    //cout << "     ~~>  V  <~~ " << endl;
    std::cout << "\n      /\\     /\\  " << std::endl;
    std::cout << "     {  `---'  } " << std::endl;
    std::cout << "     {  O   O  } " << std::endl;
    std::cout << "     ~~>  V  <~~ " << std::endl;
    return 0;
}