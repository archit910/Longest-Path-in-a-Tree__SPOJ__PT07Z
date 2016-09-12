/********   All Required Header Files ********/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
/***pre processors ***/
using namespace std;
#define gcd(a,b) __gcd(a,b)
#define TEST int t;cin>>t;while(t--)
const long long int mod = 1e9+7;
typedef long long int ll;
ll fexpo(ll a,ll b)
{
    if(b==0)
        return 1LL;
    if(b==1)
        return a;
    if(b==2)
     	return a*a;
 	if(b%2==0)
    	return fexpo(fexpo(a,b/2),2);
	else
    	return a*fexpo(fexpo(a,(b-1)/2),2);
}
char x[10101010];
void solve()
{
	
	cin >> x;
	int le = strlen(x);
	if(le%2!= 0 )
	{
			cout << -1 << endl;
	}
	else
	{
		//cout << -1 << endl;
		int u , r , d , l;
		u = r = d = l = 0 ;
		for (int i = 0 ;i < le ;i ++)
		{
			if(x[i] == 'U'){
				u++;

			}
			if(x[i] == 'R'){
				r++;
				
			}if(x[i] == 'D'){
				d++;
				
			}if(x[i] == 'L'){
				l++;
				
			}

		}
		int maxx = max(max(max(r,u),d),l);
		if(r == l && d == u )
		{
			cout << 0 << endl;

		}
		

		else	if(maxx == u)
		{
			if(maxx > le/2)
			{
				int ans = abs(u-le/2);
				ans += l+r;
				cout << ans << endl;

			}	
			else
			{
				int ans = (le - u) + r +l;
				cout << ans << endl;
			}
		}
		else if(maxx == r)
		{
			if(maxx > le/2)
			{
				int ans = abs(u-le/2);
				ans += u+d;
				cout << ans << endl;

			}	
			else
			{
				int ans = (le - r) + u +d;
				cout << ans << endl;
			}
		}
		else if(maxx == l)
		{if(maxx > le/2)
			{
				int ans = abs(l-le/2);
				ans += u+d;
				cout << ans << endl;

			}	
			else
			{
				int ans = (le - l) + u +d;
				cout << ans << endl;
			}//cout << l/2;
		}
		else if(maxx == d)
		{
			if(maxx > le/2)
			{
				int ans = abs(d-le/2);
				ans += l+r;
				cout << ans << endl;

			}	
			else
			{
				int ans = (le - d) + l +r;
				cout << ans << endl;
			}
		}
	}
}
int main()
{
	solve();
}