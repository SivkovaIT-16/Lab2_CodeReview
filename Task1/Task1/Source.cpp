#include "Header.h"
#include <iostream>

// FIX_ME: деструктор для освобождения памяти
Stack::~Stack()
{
    ClearStack();
}

// FIX_ME: фигурная скобка должна быть на новой строке
// FIX_ME: имена параметров должны начинаться с большой буквы
// FIX_ME: имена переменных должны начинаться с большой буквы
// FIX_ME: комментарии должны заканчиваться точкой
//void push(int value) {
void Stack::Push(int Value)
{
    //Node* newNode = new Node(value); // Создаем новый узел
    Node* NewNode = new Node(Value); // Создаем новый узел.

    // FIX_ME: использование геттеров/сеттеров вместо прямого доступа
    //newNode->next = top;             // Новый узел указывает на текущую вершину
    //top = newNode;                   // Обновляем вершину стека
    NewNode->SetNext(Top);            // Новый узел указывает на текущую вершину.
    Top = NewNode;                    // Обновляем вершину стека.

    // FIX_ME: добавлен std::
    //cout << "Элемент " << value << " добавлен в стек." << endl;
    std::cout << "Элемент " << Value << " добавлен в стек." << std::endl;
}

// FIX_ME: фигурная скобка должна быть на новой строке
//void pop() {
void Stack::Pop()
{
    // FIX_ME: фигурная скобка должна быть на новой строке
    //if (top == nullptr) {
    if (Top == nullptr)
    {
        // FIX_ME: добавлен std::
        //cout << "Стек пуст! Невозможно удалить элемент." << endl;
        std::cout << "Стек пуст! Невозможно удалить элемент." << std::endl;
        return;
    }

    //Node* temp = top;
    Node* Temp = Top;

    // FIX_ME: использование геттеров/сеттеров вместо прямого доступа
    // FIX_ME: добавлен std::
    //top = top->next;
    //cout << "Элемент " << temp->data << " удален из стека." << endl;
    Top = Top->GetNext();
    std::cout << "Элемент " << Temp->GetData() << " удален из стека." << std::endl;

    //delete temp;
    delete Temp;
}

// FIX_ME: фигурная скобка должна быть на новой строке
//void print() {
void Stack::Print() const
{
    // FIX_ME: фигурная скобка должна быть на новой строке
    //if (top == nullptr) {
    if (Top == nullptr)
    {
        // FIX_ME: добавлен std::
        //cout << "Стек пуст!" << endl;
        std::cout << "Стек пуст!" << std::endl;
        return;
    }

    //Node* current = top;
    Node* Current = Top;

    // FIX_ME: добавлен std::
    //cout << "Элементы стека: ";
    std::cout << "Элементы стека: ";

    // FIX_ME: фигурная скобка должна быть на новой строке
    //while (current != nullptr) {
    while (Current != nullptr)
    {
        // FIX_ME: использование геттеров/сеттеров вместо прямого доступа
        // FIX_ME: добавлен std::
        //cout << current->data << " ";
        //current = current->next;
        std::cout << Current->GetData() << " ";
        Current = Current->GetNext();
    }
    // FIX_ME: добавлен std::
    //cout << endl;
    std::cout << std::endl;
}

// FIX_ME: фигурная скобка должна быть на новой строке
//void clearStack() {
void Stack::ClearStack()
{
    // FIX_ME: фигурная скобка должна быть на новой строке
    //while (top != nullptr) {
    while (Top != nullptr)
    {
        //Node* temp = top;
        Node* Temp = Top;

        // FIX_ME: использование геттеров/сеттеров вместо прямого доступа
        //top = top->next;
        Top = Top->GetNext();

        // FIX_ME: комментарии должны заканчиваться точкой
        //delete temp;                 // Удаляем узел
        delete Temp;                 // Удаляем узел.
    }
    // FIX_ME: добавлен std::
    //cout << "Стек очищен." << endl;
    std::cout << "Стек очищен." << std::endl;
}

// FIX_ME: фигурная скобка должна быть на новой строке
//void addElementAndPrintAddress(Stack& stack, int D) {
void AddElementAndPrintAddress(Stack& StackRef, int D)
{
    //stack.push(D);
    StackRef.Push(D);

    // FIX_ME: добавлен std::
    //cout << "Адрес новой вершины стека: " << stack.getTop() << endl;
    std::cout << "Адрес новой вершины стека: " << StackRef.GetTop() << std::endl;
}