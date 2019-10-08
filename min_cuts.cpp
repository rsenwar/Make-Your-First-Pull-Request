#include <iostream>
#include <climits>
using namespace std;
 
bool isPalindrome(string X, int i, int j)
{
	while (i <= j) 
	{
		if (X[i++] != X[j--])
			return false;
	}
	return true;
}
 
int partitionsRequired(string X, int i, int j)
{
 
	if (i == j || isPalindrome(X, i, j))
		return 0;
 
	int min = INT_MAX;
 
	for (int k = i; k <= j - 1; k++) 
	{
		int count = 1 + partitionsRequired(X, i, k) + 
					partitionsRequired(X, k + 1, j);
 
		if (count < min)
			min = count;
	}
 
	return min;
}
 
int main()
{
    int t;
    cin>>t;
    while(t--){
    	string X;
    	cin>>X;
    	int n = X.length();
    
    	cout << partitionsRequired(X, 0, n - 1)<<endl;
    }
 
	return 0;
}
