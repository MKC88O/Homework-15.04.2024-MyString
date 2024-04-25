// Homework-15.04.2024-MyString.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

class String
{
	char* text = nullptr;
	unsigned int length = 0;
	unsigned int capacity = 80;

public:
	String() : String("", 80) {}

	String(const char* text) : String(text, 80) {}

	String(unsigned int capacity) : String("", capacity) {}

	String(const String& original) : String(original.text, original.capacity) {}

	String(const char* text, unsigned int capacity)
	{
		SetString(text, capacity);
	}

	~String()
	{
		if (text != nullptr)
		{
			delete[] text;
			text = nullptr;
		}
	}

	String GetString() const
	{
		String copy = text;
		return copy;
	}

	void SetString(const char* text, unsigned int capacity = 80)
	{
		length = strlen(text);

		if (capacity <= length)
			capacity = length + 1;
		this->capacity = capacity;

		delete[] this->text;
		this->text = new char[capacity];
		strcpy_s(this->text, length + 1, text);
	}

	int GetLength() const
	{
		return length;
	}

	// метода SetLength не должно быть!

	int GetCapacity() const
	{
		return capacity;
	}

	void Clear()
	{
		text[0] = 0;
		length = 0;
	}

	void ShrinkToFit()
	{
		if (length + 1 <= capacity)
		{
			return;
		}

		capacity = length + 1;
		char* temp = new char[capacity];
		strcpy_s(temp, capacity, text);
		delete[] text;
		text = temp;
	}

	void ShowInfo() const
	{
		cout << "Text: " << text << "\n";
		cout << "Length: " << length << "\n";
		cout << "Capacity: " << capacity << "\n";
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	char GetCharAt(unsigned int index) const {
		if (index >= length) {
			cout << "ERROR!\n";
		}
		return text[index];
	}

	void Print() const {
		cout << text;
	}

	void PrintLn() const {
		Print();
		cout << "\n";
	}

	void GetLine() const{
		const int Size = 100;
		cin.getline(text, Size);
	}


	void RandomFill() const {
		srand(time(0));
		char str[80]{};
		for (int i = 0; i < capacity; i++) {
			char randomFill = 'a' + rand() % 26;
			str[i] = randomFill;
			cout << randomFill;
		}
		cout << "\n";
	}

	
	String ToUpper() const {
		for (int i = 0; i < length; i++) {
			char Char = text[i];
			if ((Char >= 'a' && Char <= 'z') || (Char >= 'а' && Char <= 'я')) {
				char upper = Char - 32;
				text[i] = upper;
			}
			else {
				text[i] = Char;
			}
		}

		return text;
	}

	String ToLower()  {
		for (int i = 0; i < length; i++) {
			char Char = text[i];
			if ((Char >= 'A' && Char <= 'Z') || (Char >= 'А' && Char <= 'Я')) {
				char lower = Char + 32;
				text[i] = lower;
			}
			else {
				text[i] = Char;
			}
		}
		return text;
	}
};


int main()
{
	String a;
	a.ShowInfo();

	String b("Alex");
	b.ShowInfo();

	// String c(75);
	// c.ShowInfo();

	// String d("Alex", 20);
	// d.ShowInfo();

	// String e = d;
	// e.ShowInfo();
	 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	cout << "At index 2: " << b.GetCharAt(2) << "\n";

	b.PrintLn();

	b.Print();
	cout << "\n";

	a.GetLine();
	a.PrintLn();

	
	b.RandomFill();
	
	String c("max");
	c.ToUpper();
	c.PrintLn();
	
	String d("MAX");
	d.ToLower();
	d.PrintLn();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
