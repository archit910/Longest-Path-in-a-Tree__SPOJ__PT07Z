#include <bits/stdc++.h>
using namespace  std;
#define ll long long int
#define pb push_back
#define mp make_pair
int main() {
//this is a test comment just to check the git features out :)
	int n;
	cin>>n;
	ll arr[100010],i;
	for(i=0;i<n;i++)
		cin>>arr[i];
	ll dp[100010],sum1=0,sum2=0;
	dp[n-1]=arr[n-1];
	int flag=0;
	for(i=n-2;i>=0;i--)
	{
		if(!flag)
		{
			sum2+=dp[i+1];
			sum1-=dp[i+1];
			dp[i]=arr[i]-sum1;
			flag=1;
		}
		else{
			sum1+=dp[i+1];
			sum2-=dp[i+1];
			dp[i]=arr[i]-sum2;
			flag=0;
		}
	}
	for(i=0;i<n;i++)
		cout<<dp[i]<<" ";
    return 0;
}
