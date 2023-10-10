#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
int n,p;
int a[10];
int sol[10];
void afisare()
{
    for(int i=1;i<=p;i++)
        cout<<a[sol[i]]<<" ";
    cout<<'\n';
}
void bkt(int k)
{
    if(k==p+1)
    {
        afisare();
        return;
    }
    for(int i=sol[k-1]+1;i<=n;i++)
    {
        if(a[i]>a[sol[k-1]])
        {
            sol[k]=i;
            bkt(k+1);
        }
    }
}
int main()
{
    cin>>n>>p;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    bkt(1);
    return 0;
}