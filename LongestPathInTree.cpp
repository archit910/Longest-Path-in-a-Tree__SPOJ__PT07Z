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
#define setbits(x) __builtin_popcount(x)
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
vector <int > graph[101010];
int visited[1010110];
int dis[1010101];
int n , e;
int u , v;
void bfs(int startNode) // iterative
{
    memset(visited , 0 , sizeof visited);
    memset(dis , 0 , sizeof dis);
    dis[startNode] = 0 ;
    visited[startNode ] = 1;
    queue<int> q;
    q.push(startNode);
    while(!q.empty())
    {
        int top = q.front();
       // cout << top << " ";
        q.pop();
        for(int i = 0 ;i < graph[top].size(); i ++)
        {
            if(visited[graph[top][i]] == 0)
            {
                dis[graph[top][i]] = dis[top]+1;
                visited[graph[top][i]] = 1;
                q.push(graph[top][i]);
            }
        }
    }
 
 
}
void solve()
{
  
    cin >> n ;
    e = n-1;
    for(int i = 0 ; i < e ;i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bfs(1);
    int farYet = -1;
    int NStartNode;
    for(int i = 2 ;i <=n;i++)
    {
        farYet = max(farYet , dis[i]);
        if(farYet == dis[i])
            NStartNode = i;
 
        
    }
    //cout <<"n is  " << NStartNode << endl;
    bfs(NStartNode);
    farYet = -1;
    for(int i = 1 ;i <=n;i++)
    {
        if( i != NStartNode)
        farYet = max(farYet , dis[i]);
      
 
        
    }
    cout << farYet << endl;
 
 
}
int main()
{
	//TEST
	solve();
} 