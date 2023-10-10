#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
int n,p;
int pus[101];
int sol[101];
void afisare(int l)
{
    for(int i=1;i<=l;i++)
        cout<<sol[i]<<" ";
    cout<<'\n';
}
void bkt(int k,int s)
{
    for(int i=1;i<=n;i++)
    {
        if(pus[i]>0)
        {
            pus[i]--;
            sol[k]=i;
            s=s+sol[k];
            if(s<=n)
                if(s==n && k==p)
            afisare(k);
            else
            bkt(k+1,s);
            s=s-sol[k];
            pus[i]++;
        }
    }
}
int main()
{
    cin>>n>>p;
    for(int i=1;i<=n;i++)
        pus[i]=2;
    bkt(1,0);
    return 0;
}