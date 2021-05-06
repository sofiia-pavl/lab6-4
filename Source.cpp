#include <iostream>
#include <math.h>
#include <string>
using namespace std; 
template <class T> 
class mas
{
	T* v; 
	int size; 
public:
	mas(int newsize);
	mas(mas&); 
	~mas(); 

	friend mas<T> operator < <>(mas<T>& x, mas<T>& y); 
	T& operator [] (int index); 
	mas& operator = (const mas&);
	friend ostream& operator << <>(ostream&, mas&); 
	friend istream& operator >> <>(istream&, mas&); 
};
template <class T>
mas<T>::mas(int newsize)
{
	v = new T[size = newsize];
	for (int i = 0; i < size; i++) 
		v[i] = T();
}
template <class T>
mas<T>::mas(mas<T>& x) 
{
	v = new T[size = x.size]; 
	for (int i = 0; i < size; i++) 
		v[i] = x.v[i];
}
template <class T>
mas<T>::~mas()
{
	delete[] v; 
}

template <class T>
mas<T> operator < (mas<T>& x, mas<T>& y) 
{
	if (x.size != y.size)
	{
		throw exception("The sizes should be the same!");
	}
	mas<T> z(x.size);
	for (int i = 0; i < x.size; i++)
	{
		z[i] = x[i] == y[i] ? 1 : 0;
	}
	return z;
}
template <class T>
T& mas<T>::operator [] (int index)
{
	if (index < 0 || index >= size)
	{
		throw exception("Index out of the range");
	}
		return v[index];
}
template <class T>
mas<T>& mas<T>::operator = (const mas<T>& x)
{
	if (this != &x)
	{
		delete[] v;
		v = new T[size = x.size];
		for (int i = 0; i < size; i++)
			v[i] = x.v[i];
	}
	return *this;
}
template <class T>
istream& operator >> (istream& is, mas<T>& x)
{
	cout << "Input " << x.size << " elements of vector" << endl;
	for (int i = 0; i < x.size; i++) {
		cout << "element[" << i << "] = ? ";
		is >> x.v[i];
	}
	return is;
}
template <class T>
ostream& operator << (ostream& os, mas<T>& x)
{
	for (int i = 0; i < x.size; i++)
		os << x.v[i] << ' ';
	os << endl;
	return os;
}
int main()
{
	try
	{
		mas<int> V(5), U(5), T(5);
		cin >> V;
		cout << "third element of array V(indexing):" << endl;
		cout << V[2] << endl << endl;
		cin >> U;
		cout << "comparison of two arrays:" << endl;
		T = U < V;
		bool q;
		for (int a = 0; a < 5; a++)
		{
			if (T[a] == 1)
				q = true;
			else
				q = false;
		}
		if (q)
			cout << "equal";
		else
			cout << "different";
	}
		catch (exception e)
	{
		cerr << e.what() << endl;
	}
	return 0;
}