#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void stockSpan(int a[], int n)
{
    stack<pair<int,int>>s;
    vector<int>v(n,0);
    for(int i=0;i<n;i++)
    {
        if(s.size()==0)
            v[i]=-1;
        else if(s.size()>0 && s.top().first>a[i])
            v[i]=s.top().second;
        else if(s.size()>0 && s.top().first<=a[i])
        {
            while(s.size()>0 && s.top().first<=a[i])
                s.pop();
            if(s.size()==0)
                v[i]=-1;
            else
                v[i]=s.top().second;
        }
        
        
        s.push(make_pair(a[i],i));
    }
    for(int i=0;i<n;i++)
        cout<<i-v[i]<<" ";
    
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	    stockSpan(a,n);
	    cout<<endl;
	}
	return 0;
}
