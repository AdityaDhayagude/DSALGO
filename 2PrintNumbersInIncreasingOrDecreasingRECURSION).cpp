#include <iostream>
#include <stdio.h>

using namespace std;

int inc(int n)
{
    if(n==0)
    {
        return 1;
    }
    inc(n-1);
    cout<<n;
}

int dcr(int n)
{
    if(n==0)
    {
        return 1;
    }
    cout<<n;
    dcr(n-1);
}

int main()
{
    int n;
    cin>>n;

    inc(n);
    cout<<endl;
    dcr(n);
}