#include "Header.h"
#include <iostream>

// FIX_ME: конструктор Node
Node::Node(int Val) : Value(Val), Previous(nullptr), Next(nullptr) {}

// FIX_ME: геттеры и сеттеры Node
int Node::GetValue() const
{
    return Value;
}

Node* Node::GetPrevious() const
{
    return Previous;
}

Node* Node::GetNext() const
{
    return Next;
}

void Node::SetPrevious(Node* Prev)
{
    Previous = Prev;
}

void Node::SetNext(Node* Nxt)
{
    Next = Nxt;
}

// FIX_ME: конструктор DoubleList
DoubleList::DoubleList() : FirstElement(nullptr) {}

// FIX_ME: деструктор DoubleList
DoubleList::~DoubleList()
{
    Clear();
}

// FIX_ME: фигурные скобки на новой строке
//void Ochistka() {
void DoubleList::Clear()
{
    //Uzel* Tekushiy = PerviyElement;
    Node* Current = FirstElement;

    // FIX_ME: фигурные скобки на новой строке
    //while (Tekushiy != nullptr) {
    while (Current != nullptr)
    {
        //Uzel* Vremenniy = Tekushiy;
        Node* Temp = Current;

        // FIX_ME: использование геттеров
        //Tekushiy = Tekushiy->Sleduyushiy;
        Current = Current->GetNext();

        //delete Vremenniy;
        delete Temp;
    }
    //PerviyElement = nullptr;
    FirstElement = nullptr;
}

// FIX_ME: фигурные скобки на новой строке
//void DobavitElement(int Znachenie) {
void DoubleList::AddElement(int Val)
{
    // FIX_ME: используем конструктор при создании
    //Uzel* Noviy = new Uzel;
    //Noviy->Znachenie = Znachenie;
    //Noviy->Predydushiy = nullptr;
    //Noviy->Sleduyushiy = nullptr;
    Node* NewNode = new Node(Val);

    // FIX_ME: фигурные скобки на новой строке
    //if (PerviyElement == nullptr) {
    if (FirstElement == nullptr)
    {
        //PerviyElement = Noviy;
        FirstElement = NewNode;
    }
    // FIX_ME: фигурные скобки на новой строке
    //else {
    else
    {
        //Uzel* Tekushiy = PerviyElement;
        Node* Current = FirstElement;

        // FIX_ME: фигурные скобки на новой строке
        // FIX_ME: использование геттеров
        //while (Tekushiy->Sleduyushiy != nullptr) {
        //    Tekushiy = Tekushiy->Sleduyushiy;
        //}
        while (Current->GetNext() != nullptr)
        {
            Current = Current->GetNext();
        }
        // FIX_ME: использование сеттеров
        //Tekushiy->Sleduyushiy = Noviy;
        //Noviy->Predydushiy = Tekushiy;
        Current->SetNext(NewNode);
        NewNode->SetPrevious(Current);
    }
    // FIX_ME: добавлен вывод для удобства пользователя
    std::cout << "Элемент " << Val << " добавлен в список." << std::endl;
}
   
// FIX_ME: фигурные скобки на новой строке
//void VivodSpiska() {
void DoubleList::PrintList() const
{
    // FIX_ME: проверка на пустой список
    if (FirstElement == nullptr)
    {
        std::cout << "Список пуст!" << std::endl;
        return;
    }

    //Uzel* Tekushiy = PerviyElement;
    Node* Current = FirstElement;

    // FIX_ME: добавление пользовательского интерфейса
    std::cout << "Элементы списка: ";

    // FIX_ME: фигурная скобка должна быть на новой строке
    //while (Tekushiy != nullptr) {
    while (Current != nullptr)
    {
        // FIX_ME: добавлен std::
        // FIX_ME: использование геттеров
        //cout << Tekushiy->Znachenie << " ";
        //Tekushiy = Tekushiy->Sleduyushiy;
        std::cout << Current->GetValue() << " ";
        Current = Current->GetNext();
    }
    // FIX_ME: добавлен std::
    //cout << endl;
    std::cout << std::endl;
}
    
// FIX_ME: фигурная скобка должна быть на новой строке
//void PoiskMinMax(Uzel*& Min, Uzel*& Max) {
void DoubleList::FindMinMax(Node*& Min, Node*& Max) const
{
    // FIX_ME: добавлены фигурные скобки для однострочного if
    // FIX_ME: добавлена инициализация указателей
    //if (PerviyElement == nullptr) return;
    if (FirstElement == nullptr)
    {
        Min = nullptr;
        Max = nullptr;
        return;
    }

    //Min = Max = PerviyElement;
    Min = FirstElement;
    Max = FirstElement;

    // FIX_ME: использование геттеров
    //Uzel* Tekushiy = PerviyElement->Sleduyushiy;
    Node* Current = FirstElement->GetNext();

    // FIX_ME: фигурная скобка должна быть на новой строке
    //while (Tekushiy != nullptr) {
    while (Current != nullptr)
    {
        // FIX_ME: добавлены фигурные скобки для однострочных if
        //if (Tekushiy->Znachenie < Min->Znachenie) Min = Tekushiy;
        //if (Tekushiy->Znachenie > Max->Znachenie) Max = Tekushiy;
        if (Current->GetValue() < Min->GetValue())
        {
            Min = Current;
        }
        if (Current->GetValue() > Max->GetValue())
        {
            Max = Current;
        }
        // FIX_ME: использование геттеров
        //Tekushiy = Tekushiy->Sleduyushiy;
        Current = Current->GetNext();
    }
}

// FIX_ME: фигурная скобка должна быть на новой строке
//bool ProverkaPoryadka(Uzel* A, Uzel* B) {
bool DoubleList::CheckOrder(Node* First, Node* Second) const
{
    //Uzel* Tekushiy = PerviyElement;
    Node* Current = FirstElement;

    // FIX_ME: фигурная скобка должна быть на новой строке
    //while (Tekushiy != nullptr) {
    while (Current != nullptr)
    {
        // FIX_ME: добавлены фигурные скобки для однострочных if
        //if (Tekushiy == A) return true;
        //if (Tekushiy == B) return false;
        if (Current == First)
        {
            return true;
        }
        if (Current == Second)
        {
            return false;
        }
        // FIX_ME: использование геттеров
        //Tekushiy = Tekushiy->Sleduyushiy;
        Current = Current->GetNext();
    }
    return false;
}

// FIX_ME: фигурная скобка должна быть на новой строке
//void VivodMezhduMinMax() {
void DoubleList::PrintBetweenMinMax() const
{
    //Uzel* Min = nullptr;
    //Uzel* Max = nullptr;
    //PoiskMinMax(Min, Max);
    Node* Min = nullptr;
    Node* Max = nullptr;
    FindMinMax(Min, Max);

    // FIX_ME: фигурная скобка должна быть на новой строке
    //if (Min == nullptr || Max == nullptr || Min == Max) {
    if (Min == nullptr || Max == nullptr || Min == Max)
    {
        // FIX_ME: добавлен std::
        //cout << "Нет элементов для вывода!" << endl;
        std::cout << "Нет элементов для вывода!" << std::endl;
        return;
    }

    //bool MinPerviy = ProverkaPoryadka(Min, Max);
    //Uzel* Start = MinPerviy ? Min : Max;
    //Uzel* End = MinPerviy ? Max : Min;
    bool IsMinFirst = CheckOrder(Min, Max);
    Node* Start = IsMinFirst ? Min : Max;
    Node* End = IsMinFirst ? Max : Min;

    // FIX_ME: добавлен std::
    //cout << "Элементы между " << Min->Znachenie << " и " << Max->Znachenie << ": ";
    std::cout << "Элементы между " << Min->GetValue() << " и " << Max->GetValue() << ": ";

    // FIX_ME: использование геттеров
    //Uzel* Tekushiy = Start->Sleduyushiy;
    Node* Current = Start->GetNext();

    //bool EstElementy = false;
    bool HasElements = false;

    // FIX_ME: фигурная скобка должна быть на новой строке
    // while (Tekushiy != nullptr && Tekushiy != End) {
    while (Current != nullptr && Current != End)
    {
        // FIX_ME: использование геттеров
        // FIX_ME: добавлен std::
        //cout << Tekushiy->Znachenie << " ";
        std::cout << Current->GetValue() << " ";

        //EstElementy = true;
        HasElements = true;

        // FIX_ME: использование геттеров
        //Tekushiy = Tekushiy->Sleduyushiy;
        Current = Current->GetNext();
    }

    // FIX_ME: добавлены фигурные скобки для однострочного if
    // FIX_ME: добавлен std::
    //if (!EstElementy) cout << "Отсутствуют";
    if (!HasElements)
    {
        std::cout << "Отсутствуют";
    }
    // FIX_ME: добавлен std::
    //cout << endl;
    std::cout << std::endl;
}

// FIX_ME: метод проверки на пустоту
bool DoubleList::IsEmpty() const
{
    return FirstElement == nullptr;
}