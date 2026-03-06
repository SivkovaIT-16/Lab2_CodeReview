/* Дан набор из 10 чисел. Создать две очереди: первая должна содержать числа из
исходного набора с нечетными номерами (1, 3, …, 9), а вторая — с четными (2, 4, …, 10);
порядок чисел в каждой очереди должен совпадать с порядком чисел в исходном наборе.
Вывести указатели на начало и конец первой, а затем второй очереди.


Для каждой динамической структуры должен быть предусмотрен стандартный набор методов -
добавления/удаления/вывода элементов.
Во всех задачах обязательно наличие дружественного интерфейса. Ввод данных с клавиатуры.



В заданиях данной подгруппы структура «очередь» (queue) моделируется цепочкой связанных
узлов-записей типа TNode. Поле Next последнего элемента цепочки равно nullptr. Началом
очереди («головой», head) считается первый элемент цепочки, концом («хвостом», tail) — ее
последний элемент. Для возможности быстрого добавления в конец очереди нового элемента
удобно хранить, помимо указателя на начало очереди, также и указатель на ее конец. В случае
пустой очереди указатели на ее начало и конец полагаются равными nullptr. Как и для стека,
значением элемента очереди считается значение его поля Data.


*/

// FIX_ME: программа разделена на модули
#include "Header.h"
#include <iostream>
#include <windows.h>

// FIX_ME: using namespace std в глобальной области видимости
//using namespace std;

// FIX_ME: добавлена функция очистки ввода
void ClearInput()
{
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}

// FIX_ME: добавлена функция проверки ввода
int GetValidNumber(const std::string& Prompt, int Index)
{
    int Value;
    while (true)
    {
        std::cout << Prompt << Index << ": ";
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

    // FIX_ME: имена переменных не могут быть написаны транслитом
    // FIX_ME: конструктор вызывается автоматически при создании объекта
    //Ochered Ochered1, Ochered2;
    //Ochered1.Inicializaciya();
    //Ochered2.Inicializaciya();
    Queue OddQueue;
    Queue EvenQueue;
   
    // FIX_ME: добавлен std::
    //cout << "Введите 10 чисел:\n";
    std::cout << "Введите 10 чисел:" << std::endl;

    // FIX_ME: фигурная скобка должна быть на новой строке
    // FIX_ME: использовать префиксный инкремент
    //for (int i = 1; i <= 10; i++) {
    for (int i = 1; i <= 10; ++i)
    {
        // FIX_ME: имя переменной не может быть написано транслитом
        // FIX_ME: используется функция ввода с проверкой
        //int Chislo;
        //cout << "Число " << i << ": ";
        //cin >> Chislo;
        
        //// Примитивная проверка на ввод
        //if (cin.fail()) {
        //    cout << "Ошибка! Введите число!\n";
        //    return 0;
        //}
        int Value = GetValidNumber("Число ", i);

        // FIX_ME: добавлены фигурные скобки для условных операторов
        // FIX_ME: комментарии должны заканчиваться точкой
        //if (i % 2 != 0) Ochered1.DobavitElement(Chislo);
        //else Ochered2.DobavitElement(Chislo);
        // Распределение по очередям
        if (i % 2 != 0)
        {
            OddQueue.Push(Value);
        }
        else
        {
            EvenQueue.Push(Value);
        }
    }

    // FIX_ME: добавлен std::
    // FIX_ME: комментарии должны заканчиваться точкой
    //cout << "\nНечетная очередь:\n";
    //Ochered1.VivodElementov();
    //Ochered1.VivodUkazatelei();

    //cout << "\nЧетная очередь:\n";
    //Ochered2.VivodElementov();
    //Ochered2.VivodUkazatelei();

    // Вывод результатов.
    std::cout << "\nНечетная очередь (номера 1, 3, 5, 7, 9):" << std::endl;
    OddQueue.Print();
    OddQueue.PrintPointers();

    std::cout << "\nЧетная очередь (номера 2, 4, 6, 8, 10):" << std::endl;
    EvenQueue.Print();
    EvenQueue.PrintPointers();

    return 0;
}