#include<stdio.h>
int main()
{
	int SA,SB;
	int x,y,m,n,l;
	int times;
	printf("input x y m n l\n");
	scanf("%d%d%d%d%d",&x,&y,&m,&n,&l);
	SA=x;SB=y;
	if(x==y)
	{ 
		printf("they met at home\n");
		return 0;
	}
	if(m==n)
	{ 
		printf("impossible\n");
		return 0;
	}
	else
	{
	times=1;
	while(SA!=SB)
	{
		SA=(x+times*m)%l;
		SB=(y+times*n)%l;
		times++;
	}
	printf("经过%d次跳跃相遇",times-1);		
	}
}
