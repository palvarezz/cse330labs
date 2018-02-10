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

template<typename T> Mvector<T>::Mvector()
{
	T *newv=new T[5];
	vcap=5;
	vsize=0;
	v=newv;
}
template<typename T> Mvector<T>::Mvector(unsigned int n)
{

	T *newv=new T[n];
	vcap=n;
	vsize=0;
	v=newv;
}


template<typename T> void Mvector<T>::pushback(T x)
{
       if(vcap==vsize)
       {
 	 reserve(vcap*2);
       }  
       	v[vsize]=x;
	  vsize++;
}

template<typename T> void Mvector<T>::popback()
{
         v[vsize]=0;
	 vsize--;
}

template<typename T> void Mvector<T>::clear()
{
     for(int i=0;i<vsize;i++)
     {
	v[i]=0;
     }
     vsize=0;
}

template<typename T> void Mvector<T>::insert(int i, T x)
{
     if(vsize==vcap)
     {
	reserve(vcap*2);
     }
}

template<typename T>void Mvector<T>::erase(int i)
{
    for(int j=i;j<vsize;i++)
    {
	v[j]=v[j+1];
    }
   
}

template<typename T> T Mvector<T>::operator[](unsigned int i)
{
   return v[i]; 
}

template<typename T> int Mvector<T>::size()
{
   return vsize; 
}

template <typename T> void Mvector<T>::reserve(unsigned int n)
{
     T* rv=new T[n];
     vcap=n;
    // vsize=0;
     for(int i=0;i<vsize;i++)
     {
	rv[i]=v[i];
     }
     delete v;
     v=rv;
}
int main()
{	int ind;
	Mvector<int> v;
	v.pushback(3);
	v.pushback(2);
	v.pushback(5);
	v.pushback(7);
	v.pushback(8);
	v.pushback(19);
	v.pushback(20);
	//v.clear();
	for(int i=0;i<v.size();i++)
	{
	ind=v[i];
	cout<<ind<<endl;
	}
}
