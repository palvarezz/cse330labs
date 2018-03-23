/*****************************************************************************
 * Paul Alvarez
 * CSE 330 section 2
 * Mtree.cpp
 * 3/19/2018
 * An implementation of a tree with traversals
 ***************************************************************************/
#include<iostream>
#include<cstdlib>
#include<vector>
#include<time.h>
using namespace std;

template <typename T>
class Tnode
{
  public :
  T data;
  Tnode *lptr;
  Tnode *rptr;
};

template <typename T>
class Mtree
{ public :
  Mtree();
  void add(T x);
  bool find(T x);
  vector<T> inorder();
  vector<T> preorder();
  vector<T> postorder();
  private :
  void add(Tnode<T> *ptr,T x);
  bool find(Tnode<T> *ptr,T x);
  void add(int i, T x);
  void inorder(Tnode<T> *ptr);
  void preorder(Tnode<T> *ptr);
  void postorder(Tnode<T> *ptr);
  vector<T> v;
  Tnode<T> *root;
  int tsize;
};

template<typename T>
Mtree<T>::Mtree()
{
 root=0;
 tsize=0;
}

template<typename T>
void Mtree<T>::add(T x)
{  if(tsize==0)
   {
   Tnode<T> *ptr=new Tnode<T>;
   ptr->lptr=0;
   ptr->rptr=0;
   ptr->data=x;
   root=ptr;
   }
   else
   {
	add(root,x);
   }
   tsize++;
}

template<typename T>
void Mtree<T>::add(Tnode<T> *ptr,T x)
{
  if(ptr->lptr==0 and x<=ptr->data)
  {
	Tnode<T> *nptr=new Tnode<T>;
	ptr->lptr=nptr;
	nptr->data=x;
	nptr->lptr=0;
	nptr->rptr=0;
  }
  else if(ptr->rptr==0 and x>ptr->data)
  {
	Tnode<T> *nptr=new Tnode<T>;
	ptr->rptr=nptr;
	nptr->data=x;
	nptr->lptr=0;
	nptr->rptr=0;
  }
  else  if(x<=ptr->data)
  {
	add(ptr->lptr,x);
  }
  else
  {
	add(ptr->rptr,x);
  }
}

template<typename T>
bool Mtree<T>::find(T x)
{
	Tnode<T> *ptr=root;
	bool tf;
	if(x==ptr->data)
	{
	  return true;
	}
	else
	{
	  if(x<=ptr->data and ptr->lptr!=0)
	  {
	    tf=find(ptr->lptr,x);
		
	  }
	  else if(x>=ptr->data and ptr->rptr!=0)
	  {
	   tf= find(ptr->rptr,x);
	  }
	  else
	  {
		return false;
	  }
	}
	return tf;
}

template<typename T>
bool Mtree<T>::find(Tnode<T> *ptr,T x)
{
	bool tf;
	if(x==ptr->data)
	{
	  return true;
	}
	
	else
	{
	  if(x<=ptr->data and ptr->lptr!=0 )
	  {
	    tf=find(ptr->lptr,x);
		return tf;
	  }
	  else if(x>=ptr->data and ptr->rptr!=0)
	  {
	   tf= find(ptr->rptr,x);
	   return tf;
	  }
	  else
	  {
		return false;
	  }
	}
	return tf;

}

template<typename T>
vector<T>  Mtree<T>::inorder()
{
	v.clear();
	if(tsize==0)
	{
	  return v;
	}
	else
	{
	  inorder(root);
	  return v;
	}
}

template<typename T>
vector<T>  Mtree<T>::preorder()
{
	v.clear();
	if(tsize==0)
	{
	  return v;
	}
	else
	{
	  preorder(root);
	  return v;
	}
}

template<typename T>
vector<T>  Mtree<T>::postorder()
{
	v.clear();
	if(tsize==0)
	{
	  return v;
	}
	else
	{
	  postorder(root);
	  return v;
	}
}

template<typename T>
void Mtree<T>::preorder(Tnode<T> *ptr)
{
	if(ptr==0)
	{
	  return;
	}
	else
	{
	  v.push_back(ptr->data);
	  preorder(ptr->lptr);
	  preorder(ptr->rptr);
	}
}

template<typename T>
void Mtree<T>::inorder(Tnode<T> *ptr)
{
	if(ptr==0)
	{
	  return;
	}
	else
	{
	  inorder(ptr->lptr);
	  v.push_back(ptr->data);
	  inorder(ptr->rptr);
	}
}

template<typename T>
void Mtree<T>::postorder(Tnode<T> *ptr)
{
	if(ptr==0)
	{
	  return;
	}
	else
	{
	  postorder(ptr->lptr);
	  postorder(ptr->rptr);
	  v.push_back(ptr->data);
	}
}

int main()
{       int n;
	vector<int> v;
	cout<<"Enter number of elements:";
       	cin>>n;

	srand (time(NULL));
	clock_t start,finish;
	start=clock();
	Mtree<int> tree;
	for(int i=0;i<n;i++)
	{
	  tree.add(rand());
	}
	v=tree.inorder();
	finish=clock();
	cout<<"cpu time= "<< finish-start<<endl;
	return 0;

}
