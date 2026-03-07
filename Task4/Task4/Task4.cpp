/* Дан двусвязный линейный список и указатель первый элемент этого
списка. Все элементы списка хранят различные между собой значения. Необходимо
вывести значения элементов списка, которые находятся между наименьшим и
наибольшим элементами списка, в том порядке, в каком они находятся в исходном
списке. Использовать процедуры.

Все динамические структуры данных реализовывать через классы. Не использовать STL.
Для каждой динамической структуры должен быть предусмотрен
стандартный набор методов - добавления/удаления/вывода элементов.
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.*/

// FIX_ME: программа разделена на модули
#include "Header.h"
#include <iostream>

// FIX_ME: using namespace std в глобальной области видимости
using namespace std;

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
    setlocale(LC_ALL, "Russian");

    // FIX_ME: имя переменной не должно быть написано транслитом
    // FIX_ME: инициализируем через конструктор
    //Spisok Spisok;
    //Spisok.Initsializatsiya();
    DoubleList List;

    // FIX_ME: переменная инициализирована при создании
    // FIX_ME: добавлена проверка ввода через функцию
    //cout << "Введите количество элементов: ";
    //int N;
    //cin >> N;
    int N = GetValidNumber("Введите количество элементов: ");

    // FIX_ME: фигурные скобки на новой строке
    //if (N <= 0) {
    if (N <= 0)
    {
        // FIX_ME: улучшен пользовательский интерфейс
        // FIX_ME: добавлен std::
        //cout << "Некорректное число!" << endl;
        std::cout << "Ошибка: количество элементов должно быть положительным!" << std::endl;
        return 0;
    }

    // FIX_ME: добавлен std::
    //cout << "Вводите элементы:" << endl;
    std::cout << "Вводите элементы:" << std::endl;

    // FIX_ME: фигурные скобки на новой строке
    // FIX_ME: использовать префиксный инкремент
    //for (int i = 0; i < N; i++) {
    for (int i = 0; i < N; ++i)
    {
        // FIX_ME: имя переменной не должно быть написано транслитом
        // FIX_ME: используем функцию для провверки ввода
        //int Chislo;
        //if (!(cin >> Chislo)) {
        //    cout << "Ошибка ввода!" << endl;
        //    return 0;
        //}
        int Value = GetValidNumber("Число: ");

        //Spisok.DobavitElement(Chislo);
        List.AddElement(Value);
    }
    // FIX_ME: добавлен std::
    //cout << "Список: ";
    std::cout << "Список: ";

    //Spisok.VivodSpiska();
    //Spisok.VivodMezhduMinMax();
    List.PrintList();
    List.PrintBetweenMinMax();

    // FIX_ME: деструктор вызывается автоматически
    //Spisok.Ochistka();

    return 0;
}