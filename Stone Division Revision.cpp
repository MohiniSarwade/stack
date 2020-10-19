long fun(long n,vector<long>s,unordered_map<long,long>&mp)
{
    if(mp.find(n)!=mp.end())
        return mp[n];
    long ans=0;
    for(long i=0;i<s.size();i++)
    {
        if((n%s[i]==0)&&(n/s[i])>1)
            ans=max(ans,1+((n/s[i])*fun(s[i],s,mp)));
    }

    return mp[n]=ans;
}
long stoneDivision(long n, vector<long> s) {
    unordered_map<long,long>mp;
    return fun(n,s,mp);
}
