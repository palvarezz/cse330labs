/*****************************************************************************
 * Paul Alvarez
 * CSE 330 section 2
 * Mtree.cpp
 * 3/12/2018
 * AAn implementation of a tree
 ***************************************************************************/
#include<iostream>
#include<time.h>
#include<vector>
using namespace std;

template <typename T>
class Tnode
{
  public :
  T data;
  Tnode *lptr;
  Tnode *rptr;
  vector<T> v;
};

template <typename T>
class Mtree
{ public :
  Mtree();
  void add(T x);
  bool find(T x);
  private:
  void add(Tnode<T> *ptr,T x);
   bool find(Tnode<T> *ptr,T x);
 Tnode<T> *root;
  int tsize;
};

template<typename T>
Mtree<T>::Mtree()
{
 root->lptr=0;
 root->rptr=0;
 root->data=0;
 
}

int main()
{
  Mtree<int> tree;
  return 0;
}
