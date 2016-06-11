//hashing with open addressing

#include<stdio.h>
int main()
{
	int i,index,x,d,item,d2,count=0;
	int size;
	static int a[100];
	printf("enter the size \n");
	scanf("%d",&size);
	printf("enter the numbers \n");
	for(i=0;i<size;i++)
	{
		scanf("%d",&d);
		index = (size*(d*997))%size;				//hashfunction
		count =0;
		while(a[index]!=0)							//linear probing
		{
			count++;
			index++;
			if(index==size)
				index=1;
		}
		if(count>size)
			printf("the array is full\n");		
		else
			a[index]= d;
	}
	
	for(i=0;i<size;i++)
	{
		printf("%d ",a[i]);
	}
	
	printf("\nenter the number to be searched\n");
	
	for(i=0;i<size;i++)												//searching the item
	{
		scanf("%d",&item);
		d2=	(size*(item*371))%size;

		if(a[d2]==item)
			printf("yes, the entered element exist and the index is = %d\n",d2);

		else if(a[d2]==0)
			printf("no, the entered element does notexist\n");		
	
		else
		{
			
			d2++;
			count=0;
			while(a[d2]!=item)
			{					
				d2++;
				count++;
				if(count>size)
					break;
			}
			if(a[d2]==item)
			printf("yes, the entered element exist and the index is = %d\n",d2);
			
			else
			printf("no, the entered element does notexist\n");
		}
	}
return 0;
}
