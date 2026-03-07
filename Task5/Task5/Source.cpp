#include "Header.h"
#include <iostream>
#include <ctime>
#include <fstream>

// FIX_ME: добавлена функция для проверки корректности размера контейнера
bool IsValidSize(int Size)
{
    return (Size >= 2 && Size % 2 == 0);
}

// FIX_ME: выбор способа ввода вынесен в отдельную функцию
int ChooseInputMethod()
{
    int Method = 0;

    std::cout << "\nВыберете способ заполнения контейнера:" << std::endl;
    std::cout << "1) Ввод с клавиатуры." << std::endl;
    std::cout << "2) Ввод с помощью рандомайзера." << std::endl;
    std::cout << "3) Ввод данных из текстового файла." << std::endl;
    std::cout << "Ваш выбор: ";
    std::cin >> Method;

    // FIX_ME: добавлена проверка ввода
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 0;
    }

    return Method;
}
 
void Swap(int& A, int& B)
{
    // FIX_ME: имена переменных должны начинаться с заглавной буквы
    //int temp = a;
    //a = b;
    //b = temp;
    int Temp = A;
    A = B;
    B = Temp;
}