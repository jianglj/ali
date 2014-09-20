/*
给定一个query和text，均由小写字母组成。
要求在text中找出以同样的顺序连续出现在query中的最长连续字母序列的长度。
例如，query为“acbac”，text为“acaccbabb”，那么text中的“cba”为最长的连续出现在query中的字母序列，
因此，返回结果应该为其长度3.请注意程序效率。
*/

#include <stdio.h>
#include <string.h>
using namespace std;

#define N 10002

int c[N][N];

int STRICT_LCS_LENGTH(char *X, char *Y,int m,int n)
{
	int i,j,max=0;;
	for ( i = 0;i < m;i++)
		c[i][0] = 0;

	for ( j = 0;j < n;j++)
		c[0][j] = 0;

	for( i = 1;i <= m;i++){
		for ( j = 1;j <= n;j++){
			if (X[i-1] == Y[j-1])
			{
				c[i][j] = c[i-1][j-1]+1;
				if (max<c[i][j])
					max = c[i][j];
			}
			else
				c[i][j] = 0;
		}
	}
	return max;
}

int main(){

	char a[N] = "acbac";
	char b[N] = "accbacbabb";
	int m = strlen(a);
	int n = strlen(b);
	int len = STRICT_LCS_LENGTH(a,b,m,n);

	printf("%d\n",len);
	return 0;
}
