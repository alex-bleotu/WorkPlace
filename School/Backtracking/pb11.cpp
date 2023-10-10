#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
int sol[41];
int cmmdc(int n,int m)
{
    while(m!=0)
    {
        int r=n%m;
        n=m;
        m=r;
    }
    return n;
}
void afisare(int l)
{
    for(int i=1;i<=l;i++)
        cout<<sol[i]<<" ";
    cout<<'\n';
}
void bkt(int k,int s)
{
    for(int i=sol[k-1]+1; i<=n-s; i++)
    {
        sol[k]=i;
        if(k==1 || sol[k]>=sol[k-1] && cmmdc(sol[k],sol[k-1])==1)
        {
            s=s+sol[k];
            if(s<=n)
                if(s==n)
                {
                    afisare(k);
                }
                else
                    bkt(k+1,s);
            s=s-sol[k];
        }

    }
}
int main()
{
    cin>>n;
    sol[0]=1;
    bkt(1,0);
    return 0;
}