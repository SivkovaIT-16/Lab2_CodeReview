#include <iostream>

// FIX_ME: using namespace std в глобальной области видимости
// using namespace std;

// FIX_ME: фигурная скобка должна быть на новой строке
//class Node {
class Node
{
    // FIX_ME: поля должны быть приватными, доступ через методы
    // FIX_ME: имена полей должны начинаться с большой буквы
    //public:
    //    int data;
    //    Node* next;
private:
    int Data;
    Node* Next;

public:
    //Node(int value) : data(value), next(nullptr) {}
    Node(int Value) : Data(Value), Next(nullptr) {}

    // FIX_ME: добавлены геттеры для доступа к полям
    int GetData() const { return Data; }
    Node* GetNext() const { return Next; }
    void SetNext(Node* NewNext) { Next = NewNext; }
};

// FIX_ME: фигурная скобка должна быть на новой строке
//class Stack {
class Stack
{
private:
    // FIX_ME: имя поля должно начинаться с большой буквы
    //Node* top;
    Node* Top;


public:

    //Stack() : top(nullptr) {}
    Stack() : Top(nullptr) {}

    // FIX_ME: добавлен деструктор для освобождения памяти
    ~Stack();

    // FIX_ME: комментарии должны начинаться с заглавной буквы и заканчиваться точкой
    // FIX_ME: методы должны быть названы с большой буквы
    // FIX_ME: к методам, которые не изменяют объект, добавлен const
    ////  для добавления элемента в стек
    //void push(int value)
    //// Метод для удаления элемента из стека
    //void pop()
    //void print()
    //Node* getTop() {
    //    return top;
    //}
    //void clearStack()

    //  Для добавления элемента в стек.
    void Push(int Value);

    // Метод для удаления элемента из стека.
    void Pop();

    void Print() const;

    Node* GetTop() const { return Top; }

    void ClearStack();

    // FIX_ME: добавлен метод проверки на пустоту
    bool IsEmpty() const { return Top == nullptr; }

    // FIX_ME: методы должны быть названы с большой буквы
    // FIX_ME: имена параметров должны начинаться с большой буквы и быть информативными
    //friend void addElementAndPrintAddress(Stack& stack, int D);
    friend void AddElementAndPrintAddress(Stack& StackRef, int D);
};

//void addElementAndPrintAddress(Stack& stack, int D);
void AddElementAndPrintAddress(Stack& StackRef, int D);