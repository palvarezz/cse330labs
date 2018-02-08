/*****************************************************************************
 * Paul Alvarez
 * CSE 330 section 2
 * lab3.cpp
 * 2/6/2018
 * AAn implementation of a priority queue
 ***************************************************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <time.h>
using namespace std;

template <typename T>
class PQueue
{
	public:
	PQueue();
	int  qsize();
	T   front();
	void print();
	void add(T x);
        void remove();

	private:
	PQueue(vector<T> &v);
	vector<T> vec;
};

template <typename T> PQueue<T>::PQueue(){}

template <typename T> PQueue<T>::PQueue(vector<T> &v)
{
	for (int i = v.size()-1; i > 0; i--)
    		for (int j = 0; j < i; j++)
        		if (v[j] > v[j+1])
            		swap(v[j], v[j+1]);
}

template<typename T> int PQueue<T>::qsize()
{  	int size;
   	size=vec.size();
  	return size;   
}

template<typename T> T PQueue<T>::front()
{       T value;
 	value= vec.front();
	return value;
}

template<typename T> void PQueue<T>::print()
{
  for (int i = 0; i < vec.size(); i++)
        cout<<vec[i]<<endl;
}

template<typename T> void PQueue<T>::add(T x)
{  
   vec.push_back(x);
   PQueue<T> srt(vec);
}

template<typename T> void PQueue<T>::remove()
{
       	vec.erase(vec.begin());
}

int main()
{
   PQueue<int> q;
   srand (time(NULL));
  for(int i=0;i<10;i++)
  { 
   q.add(rand());
  }
   q.print();
   cout<<endl;
   q.remove();
   q.print();
}
