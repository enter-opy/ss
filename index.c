#include<stdio.h>
int main()
{
	int n,in,l,c,i,count,j;
	printf("Enter total number of blocks in the disk:");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{
		a[i]=0;
	}
	do{
		count=0,j=0;
		printf("Enter index of file:");
		scanf("%d",&in);
		if (a[in]==0)
		{
			printf("Enter number of blocks for %d:",in);
			scanf("%d",&l);
			int index[l];
			printf("Enter index of  each blocks for %d:",in);
			for(i=0;i<l;i++)
			{
				scanf("%d",&index[i]);
				if(a[index[i]]==0)
				{
					count++;
				}
			}
			if(count==l)
			{
				printf("File Allocated\n");
				for(i=0;i<l;i++)
				{
					a[index[j]]=1;
					printf("%d----->%d",in,index[j]);
					j++;
				}
			}
			else
			{
				printf("File Not Allocated\n");
			}	
		}
		else
		{
			printf("%d is already allocated\n",in);
		}
		printf("Do you want to continue?(1.yes/0.No):");
		scanf("%d",&c);
	}while(c!=0);
	return 0;
}
