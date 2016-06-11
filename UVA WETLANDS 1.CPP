#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
vector<string> v;
int boolen[100][100];
int t,n,m,result,x,y,flag=-1;

void waterpool(int x,int y)
{
    if(v[x][y] == 'W')
    {
        result++;
        boolen[x][y] = 1;

        if(boolen[x+1][y] == 0 && x+1<n&& v[x+1][y] == 'W')
        {
            waterpool(x+1,y);
        }

        if(boolen[x][y+1] == 0 && y+1<m && v[x][y+1] == 'W')
        {
            waterpool(x,y+1);
        }

        if(boolen[x-1][y] == 0 && x-1>-1 && v[x-1][y] == 'W')
        {
            waterpool(x-1,y);
        }

        if(boolen[x][y-1] == 0 && y-1>-1&& v[x][y-1] == 'W')
        {
            waterpool(x,y-1);
        }

        if(boolen[x+1][y+1] == 0 && x+1<n && y+1 <m && v[x+1][y+1] == 'W')
        {
            waterpool(x+1,y+1);
        }

        if(boolen[x-1][y-1] == 0 && x-1 >-1 && y-1 >-1&& v[x-1][y-1] == 'W')
        {
            waterpool(x-1,y-1);
        }

        if(boolen[x+1][y-1] == 0 && x+1 <n && y-1 >-1 && v[x+1][y-1] == 'W')
        {
            waterpool(x+1,y-1);
        }

        if(boolen[x-1][y+1] == 0 && x-1 >-1 && y+1 <m && v[x-1][y+1] == 'W')
        {
            waterpool(x-1,y+1);
        }
    }
}

int main()
{
	string dummy;
	scanf("%d",&t);

	while(t--)
	{
	    //cout<<"firstblock"<<endl;
		n=0;
		m=-1;
		while(1)
		{
		    if(flag !=2)
                cin>>dummy;

            flag=0;
		    if(dummy[0]=='L' || dummy[0]=='W')
            {
                if(m==-1)
                    m=dummy.size();

                //cout<<dummy<<endl;
                v.push_back(dummy);
                n++;
            }
            else
                break;
		}
		flag=0;

		while(flag==1 && cin>>dummy || flag==0)
        {
            /*for(int i=0;i<v.size();i++)
                cout<<v[i]<<endl;
            cout<<"second block\n";*/
            if(flag==1)
            {
                if(dummy[0]=='L'|| dummy[0]=='W')
                {
                    flag = 2;
                    break;
                }
            }
            x=(int)dummy[0] - (int)'0';
            cin>>y;
            //cout<<n<<" ** "<<m<<endl;
            //cout<<x<<" ** "<<y<<endl;

            for(int i=0;i<=n;i++)
                for(int j=0;j<=m;j++)
                    boolen[i][j]=0;

            result = 0;
            waterpool(x-1,y-1);
            printf("%d\n",result);
            flag=1;
        }
        v.clear();
	}
return 0;
}
