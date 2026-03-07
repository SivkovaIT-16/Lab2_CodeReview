#include <iostream>

// FIX_ME: имена классов и полей не могут быть написаны транслитом
// FIX_ME: структура должна быть классом для инкапсуляции
// FIX_ME: фигурная скобка должна быть на новой строке
// FIX_ME: комментарии должны заканчиваться точкой
//struct Uzel {
//    int Znachenie;
//    Uzel* Predydushiy;
//    Uzel* Sleduyushiy;
//};
// Структура узла двусвязного списка.
class Node
{
private:
    int Value;        // Значение узла.
    Node* Previous;      // Указатель на предыдущий узел.
    Node* Next;      // Указатель на следующий узел.
public:
    // FIX_ME: конструктор с списком инициализации
    Node(int Val);

    // FIX_ME: добавлены геттеры и сеттеры
    int GetValue() const;
    Node* GetPrevious() const;
    Node* GetNext() const;
    void SetPrevious(Node* Prev);
    void SetNext(Node* Nxt);
};

// FIX_ME: имена классов и полей не могут быть написаны транслитом
// FIX_ME: фигурная скобка должна быть на новой строке
// FIX_ME: комментарии должны заканчиваться точкой
//class Spisok {
//private:
    //Uzel* PerviyElement;
// Класс для работы с двусвязным списком.
class DoubleList
{
private:
    Node* FirstElement;    // Указатель на первый элемент списка.
public:
    // FIX_ME: конструктор вместо отдельного метода инициализации
    //// Инициализация списка
    //void Initsializatsiya() {
    //    PerviyElement = nullptr;
    //}
    DoubleList();

    // FIX_ME: добавлен деструктор для освобождения памяти
    ~DoubleList();

    // FIX_ME: имена методов и параметров не могут быть написаны транслитом
    // FIX_ME: к методам, которые не изменяют объект, добавлен const
    // FIX_ME: комментарии должны заканчиваться точкой
    //void Ochistka();
    //void DobavitElement(int Znachenie);
    //void VivodSpiska();
    //void PoiskMinMax(Uzel*& Min, Uzel*& Max);
    //bool ProverkaPoryadka(Uzel* A, Uzel* B);
    //void VivodMezhduMinMax()
    
    // Очистка списка.
    void Clear();

    // Добавление элемента в конец списка.
    void AddElement(int Val);

    // Вывод всех элементов списка
    void PrintList() const;

    // Поиск минимального и максимального элементов.
    void FindMinMax(Node*& Min, Node*& Max) const;

    // Проверка, какой элемент встречается раньше.
    bool CheckOrder(Node* First, Node* Second) const;

    // Вывод элементов между минимальным и максимальным.
    void PrintBetweenMinMax() const;

    // FIX_ME: добавлен метод проверки на пустоту
    bool IsEmpty() const;
};
