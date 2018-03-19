/*****************************************************************************
 * Paul Alvarez
 * CSE 330 section 2
 * Mtree.cpp
 * 3/19/2018
 * An implementation of a tree with traversals
 ***************************************************************************/
#include<iostream>
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
{
	Mtree<int> tree;
	 srand (time(NULL));
	 cout<<"add 6(25,12,89,3,50,18) numbers into tree"<<endl;
	 tree.add(25);
	 tree.add(12);
	 tree.add(89);
	 tree.add(3);
	 tree.add(50);
	 tree.add(18);
	cout<<"check to see if numbers 3,6,25,50,51 art in tree"<<endl;
	if(tree.find(3)!=false)
	{cout<<"Number 3 is in tree"<<endl;
	}
	if(tree.find(6)!=false)
	{cout<<"Number 6 is in tree"<<endl;
	}
	if(tree.find(25)!=false)
	{cout<<"Number 25 is in tree"<<endl;
	}
	if(tree.find(50)!=false)
	{cout<<"Number 50 is in tree"<<endl;
	}
	if(tree.find(51)!=false)
	{cout<<"Number 51 is in tree"<<endl;
	}
	cout<<"Inorder:"<<endl;
	vector<int> t=tree.inorder();
	for(int i=0;i<t.size();i++)
	{ 
	   cout<<t[i]<<endl;	
	}
	t.clear();
	cout<<"preorder:"<<endl;
	vector<int> x=tree.preorder();
	for(int i=0;i<x.size();i++)
	{ 
	   cout<<x[i]<<endl;	
	}
	t.clear();
	t=tree.postorder();
	cout<<"postorder: "<<endl;
	for(int i=0;i<t.size();i++)
	{ 
	   cout<<t[i]<<endl;	
	}
	return 0;
}
