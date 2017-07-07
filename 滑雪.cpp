#include <stdio.h>
#include <stdlib.h>
int MAX4(int a,int b,int c,int d,int compare)
{
	int line[4];
	line[0]=a;
	line[1]=b;
	line[2]=c;
	line[3]=d;
	for(int i=0;i<4;i++)
	{
		for(int j=0;i+j<3;j++)
		{
			if(line[j]>line[j+1])
			{
				int tmp=line[j];
				line[j]=line[j+1];
				line[j+1]=tmp;
			}
		}
	}
	int max4=line[0];
	int i=0;
	while((line[i]!=10000)&&line[i]<compare)
	{
		max4=line[i];
		i++;
	}
	return max4;
}
int main()
{
			int test=MAX4(1,2,10000,5,4);
			printf("%d\n",test);
			int row=0,column=0;
			int max=0;
			int min=10000;
			int startrow=0;
			int startcolumn=0;
			int endrow=0;
			int endcolumn=0;
			printf("intput the row and column\n");
			scanf("%d %d",&row,&column);
			int** matrix;
			matrix=(int **)calloc(column*row,sizeof(int));
			for(int i=0;i<row;i++)
			{
				matrix[i]=(int *)calloc(column,sizeof(int));
			}//初始化矩阵 
			for(int i=0;i<row;i++)
			{
				for(int j=0;j<column;j++)
				{
					printf("please input the element\n ");
					scanf("%d",&matrix[i][j]);
				}
			}//行列元素录入 
			for(int i=0;i<row;i++)	
			{
				for(int j=0;j<column;j++)
				{
					if(matrix[i][j]>max)
					{
						max=matrix[i][j];
						startrow=i;
						startcolumn=j;
					}
						if(matrix[i][j]<min)
					{
						min=matrix[i][j];
						endrow=i;
						endcolumn=j;
					}	
				}
			}//找到最大元素,并标记行和列 
			printf("row%d  column%d  row%d  column%d\n",startrow,startcolumn,endrow,endcolumn);
		 for(int i=0;i<row;i++)
			{
				for(int j=0;j<column;j++)
				{
					printf("%3d",matrix[i][j]);
				}
				printf("\n");
			}//行列元素打印 	
	printf("the biggest element is %d at row %d and column %d\n",max,startrow,startcolumn);		
	int answer[10000];
	//answer=(int *)calloc(row*column,sizeof(int));
	int up,down,left,right;
	int nowrow=startrow;
	int nowcolumn=startcolumn;
	int length=0;
	while(!((nowrow==endrow)&&(nowcolumn==endcolumn)))
	{
		answer[length]=matrix[nowrow][nowcolumn];
		if(nowrow>0)
		{
			up=matrix[nowrow-1][nowcolumn];
		}
		if(nowrow==0)
		{
			up=10000;
		}
		if(nowrow<row-1)
		{
			down=matrix[nowrow+1][nowcolumn];
		}
		if(nowrow==row-1)
		{
			down=10000;
		}
		if(nowcolumn>0)
		{
			left=matrix[nowrow][nowcolumn-1];
		}
		if(nowcolumn==0) 
		{
			left=10000;
		}
		if(nowcolumn<column-1)
		{
			right=matrix[nowrow][nowcolumn+1];
		}
		if(nowcolumn==column-1)
		{
			right=10000;
		}
		int nextrow,nextcolumn;
		//接下来找出四个元素中不等于10000且小于！！当前数值的最大值。 
		int temp=MAX4(left,right,up,down,matrix[nowrow][nowcolumn]);
		if(left==temp)
		{
			nextrow=nowrow;
			nextcolumn=nowcolumn-1;
		}
		if(right==temp)
		{
			nextrow=nowrow;
			nextcolumn=nowcolumn+1;
		}
		if(up==temp)
		{
			nextrow=nowrow-1;
			nextcolumn=nowcolumn;
		}
		if(down==temp)
		{
			nextrow=nowrow+1;
			nextcolumn=nowcolumn;
		}
		nowcolumn=nextcolumn;
		nowrow=nextrow;		
		length++;
	} 
	length++;
	printf("the longest length is %d",length);
	return 0; 
}
