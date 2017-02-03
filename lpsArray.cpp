#include <iostream>
#include <string>
using namespace std;

int *calculateLps(string pattern) {
	int length = pattern.size();
	int *lps = (int *)malloc(sizeof(int)*pattern.size());
	lps[0]=0;
	int j=0;
	for(int i=1;i<length;) {
		if(pattern[j]==pattern[i]) {
			j++;
			lps[i]=j;
			i++;
		}
		else {
			if(j!=0)
				j = lps[j-1];
			else {
				lps[i]=0;
				i++;
			}
		}
	}
	return lps;
}
int main() {
	// your code goes here
	string pattern = "AAABAAA";
	int *lps;
	lps = calculateLps(pattern);
	int i=0;
	while(i<pattern.size()) {
		cout<<lps[i]<<endl;
		i++;
	}
	free(lps);
	return 0;
}
