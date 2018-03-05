/*****************************************************************************
 * Paul Alvarez
 * CSE 330 section 2
 * PList.cpp
 * 3/5/2018
 * Mvectoes withj iterators and a simple implementation of a List
 ***************************************************************************/
#include <time.h>
#include <iostream>
#include <assert.h>
using namespace std;
template <typename T>
class Mvector
{
  public:
	  typedef T* iterator;
	  Mvector();
	  Mvector(unsigned int n);
	  void pushback(T x);
	  void popback();
	  void clear();
	  void insert(int i,T x);
	  void erase(int i);
	  T operator[] (unsigned int i);
	  void operator--(int);
	  int size();
	  iterator begin(){return v;};
	  iterator end(){return v+vsize;}
	  void insert(iterator ix,T x);
	  void erase(iterator ix);
  private:
	  int vsize;
	  int vcap;
	  T *v;
	  void reserve(unsigned int n);

};

template <typename T>
class Lnode
{
  public :
  T data;
  Lnode *lptr;
  Lnode *rptr;
};

template <typename T>
class Plist
{ public :
  Plist();
  void add(T x);
  void del();
  T getfront();

  private :
  Lnode<T> *first;
  Lnode<T> *last;
  int lsize;
};
template<typename T> Mvector<T>::Mvector()
{
	T *newv=new T[20];
	vcap=20;
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

template<typename T>
void Mvector<T>::operator--(int)
{
     vsize--;
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
template <typename T> 
void Mvector<T>::insert(iterator ix,T x)
{
  typename Mvector<T>::iterator jx;
  if(vsize==vcap-1)
  {	
	reserve(2*vcap);
 	ix=v;
  }
  for(jx=v+vsize;jx>ix;jx--)
  {
	*jx=*(jx-1);	
	cout<<"jxin: "<<*jx<<endl;

  }
  *ix=x;
  vsize++;
}

template <typename T>
void Mvector<T>::erase(iterator ix)
{
   typename Mvector::iterator jx;
   for(jx=ix;jx<v+vsize;jx++)
   {
	*jx=*(jx+1);
   }
   vsize--;
}
template <typename T>
Plist<T>::Plist()
{
 first=0;
 last=0;
 lsize=0;
}
template <typename T>
void Plist<T>:: add(T x)
{
	Lnode<T> *ptr=new Lnode<T>;
	ptr->data=x;
	if(lsize==0)
	{
	  ptr->lptr=0;
	  ptr->rptr=0;
	  first=ptr;
	  last=ptr;
	}
	else
	{
	  ptr->lptr=last;
	  ptr->rptr=0;
	  last->rptr=ptr;
	  last=ptr;
	}
	lsize++;
}

template <typename T>
void Plist<T>::del()
{
	Lnode<T> *cur=first;
	first=first->rptr;
	delete cur;
	first->lptr=0;
	lsize--;
}
template <typename T>
T Plist<T>::getfront()
{
   return first->data;
}
int main()
{	typename Mvector<int>::iterator it;
	srand(time(NULL));
	Mvector<int> v;
	Plist<int> lis;
	cout<<"orignal vector elements: "<<endl;
       for(int i=0;i<5;i++)
	{
	   v.pushback(rand());
	}	
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<endl;
	}
       cout<<"Inserting values into different positions:"<<endl;
       
       for(int i=0;i<5;i++)
	{
	   v.insert(i,rand());
	}	
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<endl;
	}
	it=v.end();
	v.erase(it);
	cout<<"erase  at v.end(): "<<endl;
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<endl;
	}
	cout<<"front element in list of added elemtents: "<<endl;

	int t;
       for(int i=0;i<5;i++)
	{
	lis.add(rand());
	}	
	t=lis.getfront();
	cout<<t<<endl;

       cout<<"Delete front: "<<endl;
       lis.del();
	t=lis.getfront();
	cout<<t<<endl;

	return 0;
}
