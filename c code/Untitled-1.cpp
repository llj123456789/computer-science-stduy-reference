#include<bits/stdc++.h>

using namespace std;
int n;

void fen(int s)
{
    for(int i=14;i>=0;i--)
    {
        if(pow(2,i)<=s)
        {
            if(i==0)
                cout<<"2(0)";
            else if(i==1)
                cout<<"2";
            else
            {
                cout<<"2(";
                fen(i);
                cout<<')';
            }
            s-=pow(2,i);
            if(s>0)
                cout<<'+';
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    fen(n);
    return 0;
}