#include <stdio.h>

int resMat[100][100];

int isSubsetSum(int arr[], int n, int sum)
{
	if(resMat[n][sum] != -1) 
		return resMat[n][sum];
	
	if(sum == 0)
		return 1;
	
	if(n==0 && sum != 0)
		return 0;
	
	if(arr[n-1]>sum)
		return resMat[n][sum] = isSubsetSum(arr, n-1, sum);
	
	else
		return resMat[n][sum] = isSubsetSum(arr, n-1, sum) || isSubsetSum(arr, n-1, sum-arr[n-1]);
}
int findPartition (int arr[], int n)
{
    // Calculate sum of the elements in array
    int sum = 0;
    for (int i = 0; i < n; i++)
       sum += arr[i];
 
    // If sum is odd, there cannot be two subsets 
    // with equal sum
    if (sum%2 != 0)
       return 0;
 
    // Find if there is subset with sum equal to
    // half of total sum
    return isSubsetSum (arr, n, sum/2);
}

int main()
{
  int arr[] = {2, 4, 8};
  int n = sizeof(arr)/sizeof(arr[0]);
  
  memset(resMat, -1, sizeof(resMat[0][0])*100*100);
  
  if (findPartition(arr, n))
     printf("Can be divided into two subsets "
            "of equal sum");
  else
     printf("Can not be divided into two subsets"
            " of equal sum");
  
  return 0;
}
