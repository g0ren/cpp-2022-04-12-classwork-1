#include <iostream>
#include <iomanip>
#include <ctime>
#include <cassert>
using namespace std;

class Array {

	//const int const_int = 10;

	int* mas = nullptr;
	unsigned int size = 0;
	//unsigned int& link = size;
public:

	// Array a{45}, a1; Array (uint);
	//Array(unsigned int S = 10) :mas{ new int[S] }, size{ S }, const_int{ S }, link{size}{
	Array(unsigned int S = 10) :mas{ new int[S] }, size{ S }{
		cout << "Constructor  Array(unsigned int S = 10) for " << this << std::endl;
		for (int i = 0; i < size; ++i)
			mas[i] = rand() % 100;
	}

	Array(const Array& arr) :mas{ new int[arr.size] }, size{ arr.size } {
		cout << "Constructor  Array(const Array& arr) for " << this << std::endl;
		for (int i = 0; i < size; ++i)
			mas[i] = arr.mas[i];
	}

	Array(Array&& arr) :mas{ arr.mas }, size{ arr.size } {
		cout << "Constructor  Array(const Array&& arr) for " << this << std::endl;
		arr.mas = nullptr;
		arr.size = 0;
	}

	~Array() {
		cout << "destructor for " << this << std::endl;
		if (mas) // (mas!= nullprt)
			delete[]mas;
	}
	int get(unsigned int poz) const
	{
		return poz < size ? mas[poz] : 0;
	}

	Array& set(int ind, int value) {
		if (ind >= 0 && ind < size)
			mas[ind] = value;
		return *this;
	}

	//Array& set(int, double) = delete;

	int getSize() const {
		return size;
	}

	Array& operator=(const Array& arr);
	Array& operator=(int val);//изменяем все элементы массива на значение val
	Array& operator=(Array&& arr);

	int  operator[] (int poz) const { // get ()
		return poz < size ? mas[poz] : 0;
	}
	int& operator[](int poz) { //set()
		assert(poz >= 0 && poz < size && "Index is out of range!");
		return mas[poz];
	}

	void operator() (int ind, int value) { // get ()
		if (ind >= 0 && ind < size)
			mas[ind] = value;
	}
	operator int() const {
		int s = 0;
		for (int i{ 0 }; i < size; i++)
			s += mas[i];
		return s;
	}

	operator bool() const {
		return (size > 0);
	}

	/*template <class T>
	operator T() const {
		T s = 0;
		for (int i{ 0 }; i < size; i++)
			s += mas[i];
		return s;
	}*/

	friend void print2(const Array& arr);

};

ostream& operator<< (ostream& out_a, const Array& arr) {
	for (int i{ 0 }; i < arr.getSize(); i++)
		out_a << (i + 1) << "(" << arr.get(i) << ") ";
	return out_a;
}

istream& operator>> (istream& in, Array& arr) {
	for (int i{ 0 }; i < arr.getSize(); i++) {
		//cout << "Enter value " << (i + 1) << ":";
		in >> arr[i];
	}
	return in;
}


Array& Array::operator=(const Array& arr) {

	if (this == &arr)
		return *this;

	std::cout << "Operator= (const Array& arr) for " << this << std::endl;

	if (mas) delete[]mas;//выполняем освобождение памяти
	//выполняем действие конструктора копирования
	mas = new int[arr.size];
	size = arr.size;
	for (int i = 0; i < size; ++i)
		mas[i] = arr.mas[i];
	return *this;
}

//Array& Array::operator=(Array&& arr) {
//
//	if (this == &arr)
//		return *this;
//
//	std::cout << "Operator= (const Array&& arr) for " << this << std::endl;
//
//	this->size = arr.size;
//	this->mas = arr.mas;
//	arr.mas = nullptr;
//	arr.size = 0;
//	return *this;
//
//}

Array& Array::operator=(int val) {
	if (mas) {
		for (int i = 0; i < size; ++i)
			mas[i] = val;
	}
	return *this;
}

void print2(const Array& arr) {
	cout << "Print for " << &arr << " -> ";
	for (int i{ 0 }; i < arr.size; i++)
		cout << (i + 1) << ":" << arr.mas[i] << " ";

	cout << endl;
}

void print(const Array& arr) {
	cout << "Print for " << &arr << " -> ";
	for (int i{ 0 }; i < arr.getSize(); i++)
		//cout << (i + 1) << ":" << arr.get (i) << " ";
		cout << (i + 1) << ":" << arr[i] << " ";
	cout << endl;
}


Array create_array() {

	Array temp;

	return temp;
}



int main() {

	srand(time(NULL));

	//Array a(5);
	Array a1;
	print(a1);

	cout << a1[1];
	a1[2] = 33;
	a1[111] = 1;
	int x = (a1[111] + 2);
	cout << endl << x << endl;
	print(a1);

	//a1 = create_array();

	//Array a{ 5 };
	//print(a);
	//Array a1{7};
	//print(a1);
	//a1 = a;
	//print(a1);

	//a1 = ((double)10.99);
	////print(a1);

	//cout << a1 << endl;

	//Array a2(3);
	//cout << a2 << endl;
	//cin >> a2;
	//cout << a2 << endl;

	/*int a = 5;

	int& s{ a };

	int& s2{ s };

	const int& sd{ 45 };

	int&& sd2{ 45 };

	cout << a << endl;
	cout << s << endl;
	cout << s2 << endl;
	cout << sd << endl;*/




	return 0;
}
