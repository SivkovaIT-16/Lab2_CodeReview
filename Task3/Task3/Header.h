#include <iostream>
#include <fstream>

// FIX_ME: фигурная скобка должна быть на новой строке
// FIX_ME: поля должны быть приватными
// FIX_ME: имена полей должны начинаться с заглавной буквы
//class Node {
//public:
//    int data;
//    Node* next;
class Node
{
private:
    int Data;
    Node* Next;

public:
    Node(int value) : Data(value), Next(nullptr) {}

    // FIX_ME: добавлены геттеры  и сеттеры для доступа к полям
    int GetData() const { return Data; }
    Node* GetNext() const { return Next; }
    void SetNext(Node* NewNext) { Next = NewNext; }
};

// FIX_ME: фигурная скобка должна быть на новой строке
//class LinkedList {
class LinkedList
{
private:
    // FIX_ME: имя поля должно начинаться с большой буквы
    //Node* head;
    Node* Head;

public:

    LinkedList() : Head(nullptr) {}

    // FIX_ME: добавлен деструктор для освобождения памяти
    ~LinkedList();

    // FIX_ME: к методам, которые не изменяют объект, добавлен const
    // FIX_ME: методы и парметры должны быть названы с большой буквы
    //FIX_ME: к методам добавлены комментарии
    //void insertSorted(int value);
    // Mетод вставки элемента с сохранением упорядоченности по убыванию.
    void InsertSorted(int Value);


    //void print();
    // Метод вывода элементов списка.
    void Print() const;


    //void readFromFile(const std::string& filename);
    // Метод чтения из файла.
    void ReadFromFile(const std::string& FileName);

    // FIX_ME: добавлен метод очистки списка
    void Clear();

    // FIX_ME: добавлен метод проверки на пустоту
    bool IsEmpty() const;

    // Дружественная функция для чтения данных из файла и заполнения списка.
    //friend void readFromFile(LinkedList& list, const string& filename);
    friend void ReadFromFile(LinkedList& List, const std::string& FileName);
};

// FIX_ME: прототип дружественной функции с большой буквы
// FIX_ME: комментарии должны заканчиваться точкой
//void readFromFile(LinkedList& list, const string& filename);
// Дружественная функция для чтения данных из файла и заполнения списка.
void ReadFromFile(LinkedList& List, const std::string& FileName);

