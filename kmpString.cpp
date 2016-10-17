#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

void generateLps(char *pat, int size, int *lps)
{
	int len=0, i=1;
	lps[0]=0;
	while(i<size)
	{
		if(pat[i]==pat[len])
		{
			len++;
			lps[i]=len;
			i++;
		}
		else
		{
			if(len!=0)
			{
				len=lps[len-1];
			}
			else
			{
				lps[i]=0;
				i++;
			}
		}
	}
}

int kmpSearch(char *text, char *pat)
{
	int n=strlen(text);
	int m=strlen(pat);
	
	int *lps = (int*)malloc(sizeof(int)*m);
	generateLps(pat, m, lps);
	
	int i=0, j=0;
	while(i<n)
	{
		if(text[i] == pat[j])
		{
			i++; j++;
		}
		if(j==m)
		{
			j=lps[j-1];
			return i-j;
		}
		else if(i<n && pat[j] != text[i])
		{
			if(j!=0)
			{
				j=lps[j-1];
			}
			else
			{
				i++;
			}
		}
	}
	free(lps);
	return 0;
}

int main() {
	// your code goes here
	char *txt = "ABABDABACDABABCABAB";
   	char *pat = "ABABCABAB";
   	cout<<kmpSearch(txt, pat);
	return 0;
}
