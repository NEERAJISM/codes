//hacker toys
#include<stdio.h>
int  main()
{
    int i,toy[100000],add=0,buy=0,current,num,flag=0,count=0;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&toy[i]);
    }

    for(i=0;i<num;i++)
    {
        for(j=0;j<i;j++)
        {
            if(toy[j]>toy[j+1])
            {
                temp = toy[j];
                toy[j] = toy[j+1];
                toy[j+1] = temp;
            }
        }
    }


    for(i=0;i<num;i++)
    {   tt=1;
        j=i+1;
        while(tt!=4&&)
        {




    printf("%d\n",buy);
return 0;
}
