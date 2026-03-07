#include <vector>
#include <ctime>
#include <deque>
#include <list>
#include <fstream>
#include <iostream>

// Проверка корректности размера контейнера.
bool IsValidSize(int Size);

// Выбор способа ввода.
int ChooseInputMethod();

// FIX_ME: имена параметров должны начинаться с заглавной буквы
// FIX_ME: добавлен комментарий к функции
//void Swap(int& a, int& b)
// Алгоритм swap (не метод контейнера).
void Swap(int& A, int& B);

// FIX_ME: все шаблонные функции с реализацией

// FIX_ME: заполнение контейнера с клавиатуры вынесено в отдельную функцию
template <typename Container>
// Заполнение контейнера с клавиатуры.
void InputFromKeyboard(Container& Cont, int Size)
{
    int Value = 0;

    for (int i = 0; i < Size; ++i)
    {
        std::cout << "Введите " << i + 1 << " элемент: ";
        std::cin >> Value;

        // FIX_ME: добавлена проверка ввода
        if (std::cin.fail())
        {
            std::cout << "Ошибка ввода! Используется значение 0." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            Value = 0;
        }

        // FIX_ME: использование итератора для вставки
        Cont.insert(Cont.end(), Value);
    }
}

// FIX_ME: заполнение контейнера случайными числами вынесено в отдельную функцию
template <typename Container>
// Заполнение контейнера случайными числами.
void InputFromRandom(Container& Cont, int Size)
{
    // FIX_ME: инициализация генератора случайных чисел
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    for (int i = 0; i < Size; ++i)
    {
        // FIX_ME: числа от -50 до 50
        int Value = std::rand() % 101 - 50;
        Cont.insert(Cont.end(), Value);
    }

    std::cout << "Сгенерировано " << Size << " случайных чисел." << std::endl;
}

// FIX_ME: заполнение контейнера из файла вынесено в отдельную функцию
template <typename Container>
// Заполнение контейнера из файла.
bool InputFromFile(Container& Cont, int Size, const std::string& FileName = "a.txt")
{
    std::ifstream File(FileName);

    if (!File.is_open())
    {
        std::cout << "Ошибка. Файл " << FileName << " не был открыт." << std::endl;
        return false;
    }

    int Value = 0;

    for (int i = 0; i < Size; ++i)
    {
        File >> Value;

        // FIX_ME: добавлена проверка на конец файла
        if (File.eof())
        {
            std::cout << "Ошибка. В файле недостаточно элементов." << std::endl;
            File.close();
            return false;
        }

        Cont.insert(Cont.end(), Value);
    }

    File.close();
    std::cout << "Данные успешно загружены из файла." << std::endl;
    return true;
}

// FIX_ME: название функции и имена параметров должны быть информативными и начиснаться с заглавной буквы
// FIX_ME: комментарии должны содержать пробел после '//' и заканчиваться точкой
//void Input(Container& N, int n)//Заполнение контейнеров
template <typename Container>
// Заполнение контейнеров.
void InputContainer(Container& Cont, int Size)
{
    // FIX_ME: используется функция
    //int m, x;
    //cout << "Выберете способ заполнения контейнера: " << endl;
    //cout << "1)Ввод с клавиатуры." << endl;
    //cout << "2)Ввод с помощью рандомайзера." << endl;
    //cout << "3)Ввод данных из текстового файла." << endl;
    //cin >> m;
    int Method = ChooseInputMethod();

    // FIX_ME: используется функция
    //if (n < 2 || n % 2 != 0)
    //{
    //    cout << "Ошибка. Недопустимый размер." << endl;
    //    return;
    //}
    if (!IsValidSize(Size))
    {
        std::cout << "Ошибка. Недопустимый размер. Размер должен быть >= 2 и четным." << std::endl;
        return;
    }

    //switch (m)
    switch (Method)
    {
    case 1:
    {
        // FIX_ME: используется функция
        //for (int i = 0; i < n; i++)
        //{
        //    cout << "Введите " << i + 1 << " элемент: ";
        //    cin >> x;
        //    N.insert(N.end(), x);
        //}
        InputFromKeyboard(Cont, Size);
        break;
    }
    case 2:
    {
        // FIX_ME: используется функция
        //srand(time(0));
        //for (int i = 0; i < n; i++)
        //    N.insert(N.end(), rand() % 101 - 50);
        InputFromRandom(Cont, Size);
        break;
    }
    case 3:
    {
        // FIX_ME: используется функция
        //ifstream file("a.txt", ios::in); // a.txt {2 4 98 6 39 0 -2 3 7 -38 24 100 27 -8 -11 -25 33 47 -30 -41 -8 3 -13 -29 -21 10 -33 -38 -18}
        //if (!file)
        //{
        //    cout << "Ошибка. Файл не был открыт.";
        //    return;
        //}
        //for (int i = 0; i < n; i++)
        //{
        //    file >> x;
        //    N.insert(N.end(), x);
        //}
        //file.close();
        if (!InputFromFile(Cont, Size))
        {
            std::cout << "Заполнение отменено." << std::endl;
        }
        break;
    }
    default:
    {
        // FIX_ME: добавлен std::
        // FIX_ME: улучшено сообщение для пользователя
        //cout << "Ошибка ввода." << endl;
        std::cout << "Ошибка ввода. Выберите 1, 2 или 3." << std::endl;
        break;
    }
    }
}

// FIX_ME: название функции и имя параметра должны быть информативными
// FIX_ME: комментарии должны содержать пробел после '//' и заканчиваться точкой
//void Print(const Container& N)//Вывод содержимого контейнеров
template <typename Container>
// Вывод содержимого контейнеров.
void PrintContainer(const Container& Cont)
{
    // FIX_ME: имя итератора с большой буквы
    // FIX_ME: используем префиксный инкремент
    // FIX_ME: добавлены фигурные скобки для однострочного for
    //for (auto it = N.begin(); it != N.end(); it++)
    for (auto It = Cont.begin(); It != Cont.end(); ++It)
    {
        // FIX_ME: добавлен std::
        //cout << *it << " ";
        std::cout << *It << " ";
    }
    // FIX_ME: добавлен std::
    //cout << endl;
    std::cout << std::endl;
}

// FIX_ME: имя параметра должно быть информативным
// FIX_ME: комментарии должны содержать пробел после '//' и заканчиваться точкой
//void MiddleElement(Container& N)//Меняет значения двух средних элементов контейнера
template <typename Container>
// Меняет значения двух средних элементов контейнера.
void SwapMiddleElements(Container& Cont)
{
    // FIX_ME: проверка на пустой контейнер
    if (Cont.empty())
    {
        std::cout << "Ошибка. Контейнер пуст." << std::endl;
        return;
    }

    // FIX_ME: имена переменных должны начинаться с заглавной буквы
    //auto it = N.begin();
    //auto size = N.size();
    auto Size = Cont.size();
    auto It = Cont.begin();

    // FIX_ME: используем префиксный инкремент
    // FIX_ME: добавлены фигурные скобки для однострочного for
    //for (int i = 0; i < size / 2 - 1; i++)
    //    ++it;
    for (int i = 0; i < Size / 2 - 1; ++i)
    {
        ++It;
    }

    // FIX_ME: имена переменных должны начинаться с заглавной буквы и быть информативными
    //auto average1 = it;
    //++it;
    //auto average2 = it;
    //Swap(*average1, *average2);
    auto FirstMiddle = It;
    ++It;
    auto SecondMiddle = It;
    Swap(*FirstMiddle, *SecondMiddle);
}

