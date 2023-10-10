#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;
int P;
int sol[11];
void afisare(int l)
{
    for(int i=1;i<=l;i++)
        cout<<sol[i];
    cout<<'\n';
}
void bkt(int k,long long prod)
{
    for(int i=2;i<=P;i++)
    {
        sol[k]=i;
        prod=prod*sol[k];
        if(prod<=P)
            if(prod==P)
        {
            afisare(k);
        }
        else
            bkt(k+1,prod);
        prod=prod/sol[k];
    }
}
int main()
{
    cin>>P;
    sol[0]=2;
    bkt(1,1);
    return 0;
}