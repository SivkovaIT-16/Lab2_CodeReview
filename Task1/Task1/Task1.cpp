/*Дано число D и указатель P1 на вершину непустого стека.
Добавить элемент со значением D в стек и вывести адрес P2 новой вершины стека.

Для каждой динамической структуры должен быть предусмотрен стандартный набор методов -
добавления/удаления/вывода элементов.
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.

В заданиях подгруппы структура «стек» (stack) моделируется цепочкой связанных
узлов-записей типа TNode. Поле Next последнего элемента цепочки равно nullptr. Вершиной
стека (top) считается первый элемент цепочки. Для доступа к стеку используется указатель на
его вершину (для пустого стека данный указатель полагается равным nullptr). Значением
элемента стека считается значение его поля Data*/

// FIX_ME: программа разделена на модули
#include "Header.h"
#include <iostream>

// FIX_ME: using namespace std в глобальной области видимости
//using namespace std;

// FIX_ME: добавлена функция очистки ввода
void ClearInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// FIX_ME: добавлена функция проверки ввода
int GetValidNumber(const std::string& Prompt)
{
    int Value;
    while (true)
    {
        std::cout << Prompt;
        std::cin >> Value;

        if (std::cin.fail())
        {
            std::cout << "Ошибка: введите целое число!" << std::endl;
            std::cout << "Повторите ввод: " << std::endl;
            ClearInput();
        }
        else
        {
            ClearInput();
            return Value;
        }
    }
}

// FIX_ME: фигурная скобка должна быть на новой строке
//int main() {
int main()
{
    // FIX_ME: добавлена поддержка русского языка
    setlocale(LC_ALL, "Russian");

    // FIX_ME: имя переменной с большой буквы
    //Stack stack;
    Stack MainStack;

    // FIX_ME: переменная должна быть инициализирована
    //int choice, value;
    int Choice = 0;

    // FIX_ME: фигурная скобка должна быть на новой строке
    //while (true) {
    while (true)
    {
        // FIX_ME: добавлены std::
        //cout << "\nМеню:\n";
        //cout << "1. Добавить элемент в стек\n";
        //cout << "2. Удалить элемент из стека\n";
        //cout << "3. Вывести элементы стека\n";
        //cout << "4. Очистить стек\n";
        //cout << "5. Выйти\n";
        //cout << "Введите ваш выбор: ";
        //cin >> choice;

        std::cout << "\nМеню:\n";
        std::cout << "1. Добавить элемент в стек\n";
        std::cout << "2. Удалить элемент из стека\n";
        std::cout << "3. Вывести элементы стека\n";
        std::cout << "4. Очистить стек\n";
        std::cout << "5. Выйти\n";
        std::cout << "Введите ваш выбор: ";

        Choice = GetValidNumber("");

        // FIX_ME: фигурная скобка должна быть на новой строке
        // FIX_ME: добавлены фигурные скобки и табуляция для case
        //switch (choice) {
        switch (Choice)
        {
        case 1:
        {
            //cout << "Введите число для добавления в стек: ";
            //cin >> value;
            //addElementAndPrintAddress(stack, value);
            int Value = GetValidNumber("Введите число для добавления в стек: ");
            AddElementAndPrintAddress(MainStack, Value);
            break;
        }
        case 2:
        {
            //stack.pop();
            MainStack.Pop();
            break;
        }
        case 3:
        {
            //stack.print();
            MainStack.Print();
            break;
        }
        case 4:
        {
            //stack.clearStack();
            MainStack.ClearStack();
            break;
        }
        case 5:
        {
            // FIX_ME: добавлен std::
            //cout << "Выход из программы." << endl;
            std::cout << "Выход из программы." << std::endl;
            return 0;
        }
        default:
        {
            // FIX_ME: добавлен std::
            //cout << "Неверный выбор! Пожалуйста, попробуйте снова." << endl;
            std::cout << "Неверный выбор! Пожалуйста, попробуйте снова." << std::endl;
        }
        }
    }

    return 0;
}