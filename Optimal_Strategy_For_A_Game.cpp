#include<bits/stdc++.h>
using namespace std;
long long dp[101][101];
int find(int a[],int i,int j){
    if(i>j)
        return 0;
    
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    int op1=a[i]+min(find(a,i+2,j),find(a,i+1,j-1));
    int op2=a[j]+min(find(a,i+1,j-1),find(a,i,j-2));
    return dp[i][j]=max(op1,op2);
}
void fun(){
        int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   //int dp[n+1][n+1];
	   memset(dp,-1,sizeof(dp));
	   int p=find(a,0,n-1);
	   cout<<p<<endl;
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--){
	    fun();
	}
	return 0;
}
