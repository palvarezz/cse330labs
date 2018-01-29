#include <vector>
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void selsort(vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
          for (int j = i+1; j < v.size(); j++)
              if (v[i] > v[j])
	      { int t =v[i];
		v[i]=v[j];
                v[j]=t;
	      }
}

void bubsort(vector<int>& v)
{
for (int i = v.size()-1; i > 0; i--)
    for (int j = 0; j < i; j++)
        if (v[j] > v[j+1])
            swap(v[j], v[j+1]);
}
int main()
{
	clock_t start, finish;
	srand (time(NULL));
	vector<int> v;
	int n=0;
	cout << "Enter size of input :" ;
	cin >> n;
	for (int i=0; i<n; i++)
		v.push_back(rand());
	start=clock();
	bubsort(v);
	finish=clock();
	cout << "time= " << finish-start<<endl;
	//  sel  sort
	v.clear();
	for (int i=0; i<n; i++)
		v.push_back(rand());
	start=clock();
	selsort(v);
	finish=clock();
	cout << "time= " << finish-start;
}
