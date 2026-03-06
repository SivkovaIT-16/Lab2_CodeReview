/*Дан текстовый файл, в первой строке которого хранится число N, а во второй
строке N целых чисел. Необходимо создать упорядоченный по убыванию список, в который
поместить все эти элементы, при этом очередной элемент вставлять в список так, чтобы не
нарушалась его упорядоченность.

Для каждой динамической структуры должен быть предусмотрен стандартный набор методов -
добавления/удаления/вывода элементов.
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.

*/

// FIX_ME: программа разделена на модули

#include "Header.h"
#include <iostream>
#include <fstream>

// FIX_ME: using namespace std в глобальной области видимости
//using namespace std;

// FIX_ME: добавлена функция очистки ввода
void ClearInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// FIX_ME: добавлена функция проверки ввода
std::string GetValidFileName()
{
    std::string Filename;
    while (true)
    {
        std::cout << "Введите имя файла: ";
        std::cin >> Filename;

        // Проверка на пустое имя файла
        if (Filename.empty())
        {
            std::cout << "Ошибка: имя файла не может быть пустым!" << std::endl;
            continue;
        }

        return Filename;
    }
}

// FIX_ME: комментарии должны заканчиваться точкой
// FIX_ME: фигурная скобка должна быть на новой строке
//int main() {
int main()
{
    // FIX_ME: добавлена поддержка русского языка
    setlocale(LC_ALL, "Russian");

    // FIX_ME: имена переменных с большой буквы
    //LinkedList list;
    LinkedList List;                     // Создаем список.

    // FIX_ME: имена переменных с большой буквы
    // FIX_ME: переменная инициализирована при объявлении
    // FIX_ME: добавлен std::
    //string filename;
    std::string FileName = "";

    //cout << "Введите имя файла: ";
    //cin >> filename;
    // Ввод имени файла.
    FileName = GetValidFileName();

    //readFromFile(list, filename);
    // Чтение данных из файла и заполнение списка.
    ReadFromFile(List, FileName);

    // FIX_ME: добавлен std::
    //cout << "Упорядоченный список: ";
    //list.print();
    // Вывод элементов списка.
    std::cout << "Упорядоченный по убыванию список: ";
    List.Print();

    return 0;
}