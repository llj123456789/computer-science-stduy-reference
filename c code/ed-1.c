#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>


int min(int a,int b)
{
	return a>b?b:a;
}

int w[55]={0}, b[55]={0}, r[55]={0};

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);getchar();
	char tmp;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%c",&tmp);
			if (tmp == 'W') w[i]++; //统计每行有多少W
			if (tmp == 'B') b[i]++; //统计每行有多少B
			if (tmp == 'R') r[i]++; //统计每行有多少R
		}getchar();
	}
	int minn=500000;
	for (int i = 1; i <= n - 2; i++) {
		for (int j = i + 1; j <= n - 1; j++) {
			int cnt = 0;
			for (int k = 1; k <= n; k++) {
				if (k <= i) cnt += (m - w[k]);
				else if (k <= j) cnt += (m - b[k]);
				else cnt += (m - r[k]);
			}
			minn = min(minn, cnt);
		}
	}
	printf("%d\n",minn);
	return 0;	
}