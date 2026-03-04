#include "Header.h"
#include <iostream>

// FIX_ME: конструктор для инициализации
Queue::Queue()
{
    Head = nullptr;
    Tail = nullptr;
}

// FIX_ME: деструктор для освобождения памяти
Queue::~Queue()
{
    Clear();
}

// FIX_ME: фигурная скобка должна быть на новой строке
//void DobavitElement(int Chislo) {
// Добавить элемент в конец.
void Queue::Push(int Value)
{
    // FIX_ME: имя переменной не может быть написано транслитом
    //Uzel* Noviy = new Uzel;
    //Noviy->Znachenie = Chislo;
    //Noviy->Sleduyushiy = nullptr;
    Node* NewNode = new Node;
    NewNode->Data = Value;
    NewNode->Next = nullptr;

    // FIX_ME: фигурная скобка должна быть на новой строке
    //if (Nachalo == nullptr) {
    if (Head == nullptr)
    {
        //Nachalo = Noviy;
        //Konec = Noviy;
        Head = NewNode;
        Tail = NewNode;
    }
    // FIX_ME: фигурная скобка должна быть на новой строке
    //else {
    else
    {
        //Konec->Sleduyushiy = Noviy;
        //Konec = Noviy;
        Tail->Next = NewNode;
        Tail = NewNode;
    }

    // FIX_ME: добавлен вывод для удобства пользователя
    std::cout << "Элемент " << Value << " добавлен в очередь." << std::endl;
}

// FIX_ME: фигурная скобка должна быть на новой строке
//void UdalitElement() {
// Удалить первый элемент.
void Queue::Pop()
{
    // FIX_ME: фигурная скобка должна быть на новой строке
    //if (Nachalo == nullptr) {
    if (Head == nullptr)
    {
        // FIX_ME: добавлен std::
        // FIX_ME: добавлено уточнение ошибки для удобства пользователя
        //cout << "Очередь пуста!" << endl;
        std::cout << "Очередь пуста! Невозможно удалить элемент." << std::endl;
        return;
    }

    // FIX_ME: добавлено сохранение значения удаляемого элемента для вывода
    //Uzel* Vremenny = Nachalo;
    //Nachalo = Nachalo->Sleduyushiy;
    //delete Vremenny;
    Node* Temp = Head;
    int RemovedValue = Temp->Data;
    Head = Head->Next;
    delete Temp;

    // FIX_ME: добавлены фигурные скобки для условного оператора
    //if (Nachalo == nullptr) Konec = nullptr;
    if (Head == nullptr)
    {
        Tail = nullptr;
    }

    // FIX_ME: добавлен вывод для удобства пользователя
    std::cout << "Элемент " << RemovedValue << " удален из очереди." << std::endl;
}

// FIX_ME: фигурная скобка должна быть на новой строке
//void VivodElementov() {
// Вывести все элементы.
void Queue::Print() const
{
    // FIX_ME: добавлена проверка на пустую очередь
    if (Head == nullptr)
    {
        std::cout << "Очередь пуста!" << std::endl;
        return;
    }

    //Uzel* Tekushiy = Nachalo;
    Node* Current = Head;

    // FIX_ME: добавлен вывод для удобства пользователя
    std::cout << "Элементы очереди: ";

    // FIX_ME: фигурная скобка должна быть на новой строке
    //while (Tekushiy != nullptr) {
    while (Current != nullptr)
    {
        // FIX_ME: добавлен std::
        //cout << Tekushiy->Znachenie << " ";
        std::cout << Current->Data << " ";

        //Tekushiy = Tekushiy->Sleduyushiy;
        Current = Current->Next;
    }
    // FIX_ME: добавлен std::
    // cout << endl;
    std::cout << std::endl;
}

// FIX_ME: фигурная скобка должна быть на новой строке
//void VivodUkazatelei() {
// Вывести указатели начала и конца (ДОБАВЛЕН ВЫВОД ЗНАЧЕНИЙ).
void Queue::PrintPointers() const
{
    // FIX_ME: добавлены фигурные скобки для условных операторов
    // FIX_ME: добавлен std::
    //cout << "Адрес начала: " << Nachalo;
    //if (Nachalo != nullptr) cout << " (значение: " << Nachalo->Znachenie << ")";
    //cout << endl;

    //cout << "Адрес конца:  " << Konec;
    //if (Konec != nullptr) cout << " (значение: " << Konec->Znachenie << ")";
    //cout << endl;
    std::cout << "Адрес начала: " << Head;
    if (Head != nullptr)
    {
        std::cout << " (значение: " << Head->Data << ")";
    }
    std::cout << std::endl;

    std::cout << "Адрес конца:  " << Tail;
    if (Tail != nullptr)
    {
        std::cout << " (значение: " << Tail->Data << ")";
    }
    std::cout << std::endl;
}

// FIX_ME: метод очистки очереди
void Queue::Clear()
{
    while (Head != nullptr)
    {
        Node* Temp = Head;
        Head = Head->Next;
        delete Temp;
    }
    Tail = nullptr;
}