#include <iostream>
#include <assert.h>
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
	assert(n>=0);
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
         assert(vsize>0);
	 vsize--;
}

template<typename T> void Mvector<T>::clear()
{
     vsize=0;
}

template<typename T> void Mvector<T>::insert(int i, T x)
{
	assert(i>=0 and i<=vsize);
     if(vsize==vcap)
     {
	reserve(vcap*2);
     }
     for(int j=vsize;j>i;j--)
     {
	v[j]=v[j-1];
     }
     v[i]=x;
     vsize++;
}

template<typename T>void Mvector<T>::erase(int i)
{
    assert(i>=0 and i<=vsize);
    for(int j=i;j<vsize;j++)
    {
	v[j]=v[j+1];
    }
   vsize--;
}

template<typename T> T Mvector<T>::operator[](unsigned int i)
{
   assert(i<vsize and vsize >0);
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
     assert(vcap>0);
     for(int i=0;i<vsize;i++)
     {
	rv[i]=v[i];
     }
     delete []v;
     v=rv;
}
int main()
{	int ind;
	Mvector<int> v;
	for(int i=0;i<4;i++)
	{
	   v.pushback(rand());
	}
	cout<<"random numbers added to vector:"<<endl;
	for(int i=0;i<v.size();i++)
	{
	cout<<v[i]<<endl;
	}
	cout<<"call popback:"<<endl;
	v.popback();

	for(int i=0;i<v.size();i++)
	{
	cout<<v[i]<<endl;
	}
	cout<<"insert element "<<endl;
	v.insert(1,rand());
	
	for(int i=0;i<v.size();i++)
	{
	cout<<v[i]<<endl;
	}
	cout<<"pushback 2  element which calls the private function reserve()"<<endl;
	v.pushback(rand());
	v.pushback(rand());
	for(int i=0;i<v.size();i++)
	{
	cout<<v[i]<<endl;
	}
	cout<<"erase from element 3"<<endl;
	v.erase(3);
	for(int i=0;i<v.size();i++)
	{
	cout<<v[i]<<endl;
	}

	cout<<"the size of vector is "<<v.size()<<endl;
	cout<<"Clear the vector with clear():"<<endl;
	v.clear();

	for(int i=0;i<v.size();i++)
	{
	cout<<v[i]<<endl;
	}
	Mvector<int> cv(5);
	cv.pushback(1234);
	cout<<"call copy constructor:"<<endl;
	for(int i=0;i<cv.size();i++)
	{
	cout<<cv[i]<<endl;
	}
	return 0;


}
