#include "Header.h"
#include <iostream>
#include <fstream>

// FIX_ME: деструктор LinkedList
LinkedList::~LinkedList()
{
    Clear();
}

// FIX_ME: фигурная скобка должна быть на новой строке
//void insertSorted(int value) {
void LinkedList::InsertSorted(int Value)
{
    // FIX_ME: имя переменной с большой буквы
    //Node* newNode = new Node(value);
    Node* NewNode = new Node(Value);

    // FIX_ME: фигурные скобки на новой строке
    // FIX_ME: использование геттеров/сеттеров
    //if (head == nullptr || head->data < value) {
    //    newNode->next = head;
    //    head = newNode;
    //}
    if (Head == nullptr || Head->GetData() < Value)
    {
        NewNode->SetNext(Head);
        Head = NewNode;
    }
    // FIX_ME: фигурные скобки на новой строке
    //else {
    else
    {
        //Node* current = head;
        Node* Current = Head;

        // FIX_ME: фигурные скобки на новой строке
        //while (current->next != nullptr && current->next->data > value) {
        while (Current->GetNext() != nullptr && Current->GetNext()->GetData() > Value)
        {
            // FIX_ME: использование геттеров
            //current = current->next;
            Current = Current->GetNext();
        }

        // FIX_ME: использование сеттеров
        //newNode->next = current->next;
        //current->next = newNode;
        NewNode->SetNext(Current->GetNext());
        Current->SetNext(NewNode);
    }
    // FIX_ME: добавление пользовательского интерфейса
    std::cout << "Элемент " << Value << " добавлен в список." << std::endl;
}

// FIX_ME: фигурная скобка должна быть на новой строке
//void print() {
void LinkedList::Print() const
{
    // FIX_ME: проверка на пустой список
    if (Head == nullptr)
    {
        std::cout << "Список пуст!" << std::endl;
        return;
    }

    //Node* current = head;
    Node* Current = Head;
    
    // FIX_ME: добавление пользовательского интерфейса
    std::cout << "Элементы списка: ";

    // FIX_ME: фигурная скобка должна быть на новой строке
    //while (current != nullptr) {
    while (Current != nullptr)
    {
        // FIX_ME: добавлен std::
        // FIX_ME: использование геттеров
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
//void readFromFile(const std::string& filename) {
void LinkedList::ReadFromFile(const std::string& FileName)
{
    // FIX_ME: добавить std::
    // FIX_ME: комментарии должны заканчиваться точкой
    //ifstream file(filename);
    std::ifstream File(FileName);   // Открываем файл для чтения.

    // FIX_ME: фигурная скобка должна быть на новой строке
    // FIX_ME: комментарии должны заканчиваться точкой
    //if (!file.is_open()) {  
    if (!File.is_open())           // Проверяем, удалось ли открыть файл.
    {      
        // FIX_ME: добавить std::
        //cerr << "Ошибка открытия файла!" << endl;
        std::cerr << "Ошибка: не удалось открыть файл " << FileName << std::endl;
        return;
    }

    // FIX_ME: переменная инициализирована при объявлении
    //int N;
    int N = 0;

    // FIX_ME: комментарии должны заканчиваться точкой
    //file >> N;
    File >> N;                      // Читаем количество элементов.

    // FIX_ME: проверка на корректность N
    if (File.fail() || N <= 0)
    {
        std::cerr << "Ошибка: некорректное количество элементов в файле." << std::endl;
        File.close();
        return;
    }

    // FIX_ME: переменная инициализирована при объявлении
    // FIX_ME: имена переменных должны начинаться с большой буквы
    //int value;
    int Value;

    // FIX_ME: комментарии должны заканчиваться точкой
    // FIX_ME: фигурная скобка должна быть на новой строке
    //for (int i = 0; i < N; ++i) {   
    for (int i = 0; i < N; ++i)       // Читаем элементы и добавляем их в список.
    {
        //file >> value;
        File >> Value;

        // FIX_ME: проверка на корректность значения
        if (File.fail())
        {
            std::cerr << "Ошибка: некорректное значение в файле на позиции " << i + 1 << std::endl;
            File.close();
            return;
        }

        // FIX_ME: комментарии должны заканчиваться точкой
        //insertSorted(value);
        InsertSorted(Value);         // Вставляем элемент с сохранением упорядоченности.
    }

    // FIX_ME: комментарии должны заканчиваться точкой
    //file.close();
    File.close();                   // Закрываем файл.

    // FIX_ME: добавление пользовательского интерфейса
    std::cout << "Данные успешно загружены из файла." << std::endl;
}

// FIX_ME: метод очистки списка
void LinkedList::Clear()
{
    while (Head != nullptr)
    {
        Node* Temp = Head;
        Head = Head->GetNext();
        delete Temp;
    }
}

// FIX_ME: метод проверки на пустоту
bool LinkedList::IsEmpty() const
{
    return Head == nullptr;
}

// FIX_ME: фигурная скобка должна быть на новой строке
//void readFromFile(LinkedList& list, const string& filename) {
void ReadFromFile(LinkedList& List, const std::string& FileName)
{
    //list.readFromFile(filename);
    List.ReadFromFile(FileName);
}
