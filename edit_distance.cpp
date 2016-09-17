#include <iostream>
#include <string>
using namespace std;

string str1 = "sunday";
string str2 = "saturday";

int min(int x, int y, int z)
{
	return min(min(x, y), z);
}
int editDist(int m, int n)
{
	if(m==0)
		return n;
	if(n==0)
		return m;
	if(str1[m-1] == str2[n-1])
		return editDist(m-1, n-1);
	else
		return 1+min(editDist(m, n-1), editDist(m-1, n), editDist(m-1, n-1));
}

int main()
{
    // your code goes here
    
    cout << editDist(str1.length(), str2.length());
 
    return 0;
}
