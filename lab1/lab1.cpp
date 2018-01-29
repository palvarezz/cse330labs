/*******************************************************************************
 * Paul Alvarez
 * lab1.cpp
 * 1/22/18
 * Uses classs Time to keep trak of time ending at the specified time
 ********************************************************************************/
#include <iostream>
#include <unistd.h>

using namespace std;


class Time
{
   public:
   Time(int h, int m);
   int gethours() const;
   int getminutes() const;
   void addminute();
   void subtractminute();
   bool operator==(Time t);
   void operator++(); //prefix
   void operator++(int); //postfixi
   void operator--();//prefix
   void operator--(int);//postfix
   private :
   int hours;
   int minutes;
};
 
Time::Time(int h, int m)
{ hours=h;
  minutes=m;
}

int Time::gethours() const
{ return hours;
}


int Time::getminutes() const
{ return minutes;
}

bool Time::operator==(Time t)
{
  if (this->gethours() != t.gethours()) return false;
  if (this->getminutes() != t.getminutes()) return false;
  return true;
}

void Time::operator++()
{
  this -> addminute();
}

void Time::operator++(int)
{
  this -> addminute();
}

void Time::operator--()
{
  this -> subtractminute();
}

void Time::operator--(int)
{
  this -> subtractminute();
}

void Time::subtractminute()
{
   minutes--;
   if(minutes == -1)
   {
	 minutes=59;
	hours--;
   }
   if(hours==0)
   {
	hours=12;
   }
}

void Time::addminute()
{ minutes++;
  if (minutes == 60 )
    {
      minutes=0;
      hours++;
      }
   if (hours == 15)
      hours=1;
}

int main()
{
	Time start=Time(12,59);
	Time end=Time(2,10);
	cout<<"Start time: "<<start.gethours()<<":"<<start.getminutes()<<endl;
	for (int i=0; i<720; i++)
	{	sleep(1); //sleep 60 seconds
		++start; //add a minute to start
	
	if (start == end){
		
		cout<<"end time: "<<start.gethours()<<":"<<start.getminutes()<<endl;
		cout << "class dismissed"<<endl;
		break;
		}
	}
	cout<<endl;
	start=Time(1,1);
	end=Time(10,59);
	cout<<"prefix operator"<<endl;
	cout<<"Start time: "<<start.gethours()<<":"<<start.getminutes()<<endl;

	for(int i=0;i<720;i++)
	{
	  sleep(1);
	  --start;
	  if(start==end)
	  {
	cout<<"end: "<<start.gethours()<<":"<<start.getminutes()<<endl;

		cout<<"Timer finished"<<endl;
		break;
	  }
	}	
	
	start=Time(1,1);
        end=Time(10,59);
	cout<<endl;
	cout<<"Postfix"<<endl;
	cout<<"Start time: "<<start.gethours()<<":"<<start.getminutes()<<endl;


        for(int i=0;i<720;i++)
        {
          sleep(1);
          start--;
          if(start==end)
          {
        cout<<"end: "<<start.gethours()<<":"<<start.getminutes()<<endl;

                cout<<"Timer finished"<<endl;
                break;
          }
        }

}
