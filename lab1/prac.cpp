/********************************************************************************
 * Paul Alvarez
 * CSE 330 section 2
 * inpost.cpp
 * 1/22/2018
 * Takes a  an equation in infix and converts it to postfix
 ********************************************************************************/
#include <vector>
#include <string>
#include <iostream>

using namespace std;

template<typename T>
class Stack
{
 public:
 Stack();//creates the stack
 bool isempty(); // returns true if the stack is empty
 T gettop();//returns the front of the list 
 void push(T entry);//add entry to the top of the stack
 void pop();//remove the top of the stack
 private:
 vector<T> stack;
}; // Stack

template<typename T>
Stack<T>::Stack()
{
}

template<typename T>
bool Stack<T>::isempty()
{ if (stack.size() == 0)
	return true;
	else
	return false;
}

template<typename T>
T Stack<T>::gettop()
{ return stack[stack.size()-1];
}

template<typename T>
void Stack<T>::push(T entry)
{
   stack.push_back(entry);
}

template<typename T>
void Stack<T>::pop()
{
   stack.pop_back();
}

int main()
{
 	Stack<char>s;
	string x="(A+B)*C-(D/(J+D))";
	string y;
	char temp;
	int index=0;
	x.append("]");
	s.push('[');

	while(x[index]!=']')
	{
	 if(x[index]=='(')
	 {	
	    s.push(x[index]);
	 }
	 else if(x[index]=='*'||x[index]=='/')
	 {
		 while(s.gettop()=='*'||s.gettop()=='/')
		 {
			temp=s.gettop();
			y+=temp;
			s.pop();
		 }
		 s.push(x[index]);
	 }
	 else if(x[index]=='+'||x[index]=='-')
	 {
		while(s.gettop()=='*'||s.gettop()=='/'||s.gettop()=='+'||s.gettop()=='-')
		{
			temp=s.gettop();
			y+=temp;
			s.pop();
		}
		s.push(x[index]);
	 }
        else if(x[index]==')')
	{
		while(s.gettop()!='(')
		{
		   temp=s.gettop();
		   y+=temp;
		   s.pop();	
		}	
		s.pop();
	}
	 else
	 {
		temp=x[index];
		y+=temp;

	 }
	 index++;
	}
	if(x[index]==']')
	{
	    while(s.gettop()!='[')
	  {
		temp=s.gettop();
		y+=temp;
		s.pop();
	    }
	  s.pop();
	}
	x.pop_back();
	cout<<"Infix: "<<x<<endl;
	cout<<"Postfix: "<<y<<endl;
}
