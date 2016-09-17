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
	int mat[m+1][n+1];
	
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			if(i==0)
				mat[i][j]=j;
			else if(j==0)
				mat[i][j]=i;
			else if(str1[i-1]==str2[j-1])
				mat[i][j]=mat[i-1][j-1];
			else
				mat[i][j]=1+min(mat[i][j-1], mat[i-1][j], mat[i-1][j-1]);
		}
	}
	return mat[m][n];
}

int main()
{
    // your code goes here
    
    cout << editDist(str1.length(), str2.length());
 
    return 0;
}
