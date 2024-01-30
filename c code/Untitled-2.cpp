//#include<bits/stdc++.h>
#include<iostream>
using namespace std;
char a[1024][2048];
int main()
{
	ios::sync_with_stdio(false);
	int n,length=4,k=1;
	cin>>n;
	for(int i=0;i<1024;i++)
    for(int j=0;j<2048;j++)
	a[i][j]=' ';
	a[0][1]=a[1][0]='/',a[0][2]=a[1][3]='\\',a[1][1]=a[1][2]='_';
	while(k<n)
	{
		for(int i=0;i<length/2;i++)
		for(int j=0;j<length;j++)
		a[i+(length/2)][j+(length/2)]=a[i][j+length]=a[i][j];
		length*=2,k++;
	} 
	for(int i=0;i<length/2;i++) 
	{	
	    for(int j=0;j<length;j++)
	    cout<<a[i][j]; 
		cout<<endl;
	}
	return 0;
}