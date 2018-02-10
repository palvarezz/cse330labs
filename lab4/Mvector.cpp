#include <iostream>
using namespace std;
template <typename T>
class Mvector
{
  public:
	  Mvector();
	  Mvector(unsigned int n);
	  void pushback(T x);
	  void popback();
	  void clear();
	  void insert(int i,T x);
	  void erase(int i);
	  T operator[] (unsigned int i);
	  int size();
  private:
	  int vsize;
	  int vcap;
	  T *v;
	  void reserve(unsigned int n);

};

template<typename T> Mvector<T>::Mvector(){}
template<typename T> Mvector<T>::Mvector(unsigned int n)
{

}


template<typename T> void Mvector<T>::pushback(T x)
{

}

template<typename T> void Mvector<T>::popback()
{

}

template<typename T> void Mvector<T>::clear()
{

}

template<typename T> void Mvector<T>::insert(int i, T x)
{

}

template<typename T>void Mvector<T>::erase(int i)
{

}

template<typename T> T Mvector<T>::operator[](unsigned int i)
{

}

template<typename T> int Mvector<T>::size()
{
 
}

template <typename T> void Mvector<T>::reserve(unsigned int n)
{

}
int main()
{
  

}
