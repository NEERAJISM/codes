#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int a[10][10]={{0,1,0,0,1,1,0,0,0,0},
			   {1,0,1,0,0,0,1,0,0,0},
			   {0,1,0,1,0,0,0,1,0,0},
			   {0,0,1,0,1,0,0,0,1,0},
			   {1,0,0,1,0,0,0,0,0,1},
			   {1,0,0,0,0,0,0,1,1,0},
			   {0,1,0,0,0,0,0,0,1,1},
			   {0,0,1,0,0,1,0,0,0,1},
			   {0,0,0,1,0,1,1,0,0,0},
			   {0,0,0,0,1,0,1,1,0,0}};
int main()
{
	int alphbet[5][2] =  {{0,5},
					{1,6},
					{2,7},
					{3,8},
					{4,9}};

	char vertex[10] = {'A','B','C','D','E','A','B','C','D','E'};


	int t,row1,flag,source1,source2,i,j,current;

    /*for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            if(a[i][j] == 1)
                cout<<j<<" ";
        }
        cout<<endl;
    }*/
 	string s;
	scanf("%d",&t);

	while(t--)
	{
		flag = 0;
		cin>>s;


		int length= s.size();
        vector<int> result(length);
        row1 = (int)s[0]-65;
		if(length == 1)
		{
			printf("%d\n",row1);
		}
		else
		{
			source1 = alphbet[row1][0];
			source2 = alphbet[row1][1];

			int k=0;
			i=source1;
			result[k] = source1;
			k++;

			while(length>k)
			{
				i= result[k-1];
				flag = 0;

				for(j=0;j<=9;j++)
				{
					if(a[i][j]!=0 && s[k] == vertex[j])
					{
						result[k] = j;
						k++;
						flag=1;
						break;
					}
				}
				if(flag != 1)
				{
					flag=2;
					break;
				}
			}

			if(flag==2)
            {
                k=0;
                i=source2;
                result[k] = source2;
                k++;

                while(length>k)
                {
                    i= result[k-1];
                    flag = 3;
                    for(j=0;j<=9;j++)
                    {
                        if(a[i][j]!=0 && s[k] == vertex[j])
                        {
                            result[k] = j;
                            k++;
                            flag=4;
                            break;
                        }
                    }
                    if(flag != 4)
                    {
                        flag=5;
                        break;
                    }
                }

                if(flag==5)
                    printf("-1\n");
                else
                {
                    for(i=0;i<k;i++)
                        printf("%d",result[i]);
                    printf("\n");
                }
            }
            else
            {
                for(i=0;i<k;i++)
                    printf("%d",result[i]);
                printf("\n");
            }
		}
	}
return 0;
}
