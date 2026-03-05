#include <iostream>

// FIX_ME: имена классов и полей не могут быть написаны транслитом
// FIX_ME: комментарии должны заканчиваться точкой
// FIX_ME: фигурная скобка должна быть на новой строке
//struct Uzel {
//    int Znachenie;
//    Uzel* Sleduyushiy;
//};
// Структура для узла очереди.
struct Node
{
    int Data;
    Node* Next;
};

// FIX_ME: имена классов и полей не могут быть написаны транслитом
// FIX_ME: комментарии должны заканчиваться точкой
// FIX_ME: фигурная скобка должна быть на новой строке
//class Ochered {
//private:
//    Uzel* Nachalo; // Указатель на начало
//    Uzel* Konec;   // Указатель на конец
// Класс для работы с очередью.
class Queue
{
private:
    Node* Head;
    Node* Tail;
public:
    // FIX_ME: вместо отдельного метода инициализации должен быть конструктор
    // FIX_ME: имена не могут быть написаны транслитом
    // Инициализация очереди
    //void Inicializaciya(). 
    Queue();

    // FIX_ME: добавлен деструктор для освобождения памяти
    ~Queue();

    // FIX_ME: имена функций и параметров не могут быть написаны транслитом
    // FIX_ME: комментарии должны заканчиваться точкой
    // FIX_ME: к методам, которые не изменяют объект, добавлен const
    //void DobavitElement(int Chislo);
    //void UdalitElement();
    //void VivodElementov();
    //void VivodUkazatelei();
    
    // Добавить элемент в конец.
    void Push(int Value);

    // Удалить первый элемент.
    void Pop();

    // Вывести все элементы.
    void Print() const;

    // Вывести указатели начала и конца (ДОБАВЛЕН ВЫВОД ЗНАЧЕНИЙ).
    void PrintPointers() const;

    // FIX_ME: добавлены геттеры для получения указателей
    Node* GetHead() const { return Head; }
    Node* GetTail() const { return Tail; }

    // FIX_ME: добавлен метод проверки на пустоту
    bool IsEmpty() const { return Head == nullptr; }

    // FIX_ME: добавлен метод очистки очереди
    void Clear();
};
