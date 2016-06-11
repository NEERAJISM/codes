								#include<bits/stdc++.h>
								using namespace std;
								 
								typedef long long LL;
								 
								 #define Init(c,x) c=getchar_unlocked();x=0;
								#define Blah(c) while(c>'9' || c<'0')c=getchar_unlocked();
								#define Xyz(c,x) while(c<='9' && c>='0')(x=(x<<3)+(x<<1)+c-'0')+(c=getchar_unlocked());
								#define Int(c,x) Init(c,x);Blah(c);Xyz(c,x);
								#define skipws(c) while(c=='\n' || c==' ')c=getchar_unlocked();
								#define skipnan(c) while(c>'9' || c<'0')c=getchar_unlocked();
								const int N=5003;
								const int mod=1000000007;
								#define foreach(it, c) for(typeof(c.begin()) it=c.begin();it!=c.end();it++)
								
								
								
								//Chef is impressed by mathematical logic and linear algebra. He wants to combine his favorite subjects, so he introduced the concept of logical operations on boolean matrices.
								struct trie
								{
								    int ch[26],fail,len,v;
								    void init()
								    {
								        memset(ch,0,sizeof(ch));
								        fail=-1;
								        len=0;
								        v=1;
								    }
								} sachin[N*10];
								LL dynap[N][N];//
								//The first line of the input contains an integer T denoting the number of test cases. The description of T test cases follows.
//The first line of each test case contains a single integer N denoting the size of A. The next N lines contain N space-separated 
								LL res[N];
								int counter[1234567];
								LL cnt_str[N];
								int sz;
								 
								LL combination(int n, int r)
								{
								    if(n<r)
								        return 0ll;
								    r=min(r, n-r);
								    if(n==r)
								        return dynap[n][r]=1;
								    if(r==0)
								        return dynap[n][r]=1;
								    if(r==1)
								        return dynap[n][r]=(LL)n;
								    if(dynap[n][r])
								        return dynap[n][r];
								    return dynap[n][r]=(combination(n-1, r)+combination(n-1, r-1))%mod;
								}
								
								/*CodeChef Long Challenge is a 10 day monthly coding cont
								est where you can show off your computer programming skills
								. The significance being- it gives you enough time to think ab
								out a problem, try different ways of attacking the problem, read 
								the concepts etc. If you're usually slow at solving problems and 
								have ample time in hand, this is ideal for you. There would a trem
								endous amount of learning while competing. We also put in a lot of 
								efforts in getting quality problems, which would in turn foster your l
								earning while solving them.*/
								 
								 void calculate();
								 void subtract(char *sss);
						
								int id[N*10];
								LL cnt[N*10],ans[N];
								char s[N];
								bool cmp(int i,int j)
								{
								    return sachin[i].len>sachin[j].len;
								}
						/*
						mputer programming and programming contests. 
						At CodeChef, we work hard to revive the geek in you
						 by hosting a programming contest at the start of the
						  month and another smaller programming challenge in the middle of the month.*/
								int main()
								{
								    int i,j,test,ca=0,k,q,n;
								    scanf("%d",&test);
								    while(test--)
								    {
								        scanf("%d %d", &n, &q);
								        if(n<=5){
								 	/*
						mputer programming and programming contests. 
						At CodeChef, we work hard to revive the geek in you
						 by hosting a programming contest at the start of the
						  month and another smaller programming challenge in the middle of the month.*/
								            string str, temp;
								            map<string, int> my_map;
								            cin>>str;
								            int len=n;
								            for(int l=1;l<=len;l++)
								            {
								                for(int i=0;i<=len-l;i++)
								                {
								                    temp=str.substr(i, l);
								                    my_map[temp]++;
								                }
								            }
								            while(q--)
								            {
								                int k, ans=0;
								                scanf("%d", &k);
								                foreach(it, my_map)
								                {
								                    //cout<<it->first<<" "<<it->second<<endl;
								                    	/*
						mputer programming and programming contests. 
						At CodeChef, we work hard to revive the geek in you
						 by hosting a programming contest at the start of the
						  month and another smaller programming challenge in the middle of the month.*/
								                    if(it->second>=k)
								                        ans+=combination(it->second, k);
								                }
								                printf("%d\n", ans);
								            }
								            my_map.clear();
								            continue;
								        }
								        scanf("%s",s);
								        n=strlen(s);
								        sachin[0].init();
								        	/*
						mputer programming and programming contests. 
						At CodeChef, we work hard to revive the geek in you
						 by hosting a programming contest at the start of the
						  month and another smaller programming challenge in the middle of the month.*/
																		        sz=0;
								        subtract(s);
								        calculate();
								        for(int i=1;i<N;i++){
								 
								            cnt_str[i]=(ans[i]-ans[i+1])/i;
								        }
								        int idx=-1;
								        for(int i=1;i<=5000;i++){
								 
								            if(cnt_str[i]){
								 
								                idx++;
								                counter[idx]=i;
								            }
								        }
								        	/*
						mputer programming and programming contests. 
						At CodeChef, we work hard to revive the geek in you
						 by hosting a programming contest at the start of the
						  month and another smaller programming challenge in the middle of the month.*/
								 
								        int max_ctr=counter[idx];
								        for(int ctr=1;ctr<=max_ctr;ctr++){
								 
								            int start=lower_bound(counter, counter+idx+1, ctr)-counter;
								            ans[ctr]=0;
								            for(int j=start;j<=idx;j++){
								 
								                res[ctr]=(res[ctr]+(cnt_str[counter[j]]*combination(counter[j], ctr)))%mod;
								            }
								        }
								        	/*
						mputer programming and programming contests. 
						At CodeChef, we work hard to revive the geek in you
						 by hosting a programming contest at the start of the
						  month and another smaller programming challenge in the middle of the month.*/
								 
								        while(q--)
								        {
								            scanf("%d",&k);
								            if(k>n)
								                printf("0\n");
								            else
								                printf("%lld\n", res[k]);
								        }
								    }
								    return 0;
								}
									/*
						mputer programming and programming contests. 
						At CodeChef, we work hard to revive the geek in you
						 by hosting a programming contest at the start of the
						  month and another smaller programming challenge in the middle of the month.*/
								
								void calculate()
								{
								    int i,j,k,n;
								    n=strlen(s);
								    for(i=0; i<=sz; i++)id[i]=i,cnt[i]=0;
								    for(i=0; i<=n; i++)ans[i]=0;
								    sort(id,id+sz+1,cmp);
								    for(k=0; k<=sz; k++)
								    {
								        i=id[k];
								        	/*
						mputer programming and programming contests. 
						At CodeChef, we work hard to revive the geek in you
						 by hosting a programming contest at the start of the
						  month and another smaller programming challenge in the middle of the month.*/
								        if(sachin[i].v)cnt[i]++;
								        //cerr<<t[i].c<<" "<<t[i].len<<" "<<cnt[i]<<"\n";
								        j=sachin[i].fail;
								        LL v=(LL)(sachin[i].len-sachin[j].len)*cnt[i];
								        ans[1]+=v;
								        if(cnt[i]+1<=n)ans[cnt[i]+1]-=v;
								        //DBG(v)DBG(ans[1])
								        cnt[j]+=cnt[i];
								    }
								    for(i=1; i<=n; i++)ans[i]+=ans[i-1];
								}
								
								
								void subtract(char *s)
								{	/*
						mputer programming and programming contests. 
						At CodeChef, we work hard to revive the geek in you
						 by hosting a programming contest at the start of the
						  month and another smaller programming challenge in the middle of the month.*/
								    int ed=0,i,j;
								    for(i=0; s[i]; i++)
								    {
								        j=s[i]-'a';
								        int p=++sz;
								        sachin[p].init();
								        sachin[p].len=sachin[ed].len+1;
								        while(ed>=0&&!sachin[ed].ch[j])sachin[ed].ch[j]=p,ed=sachin[ed].fail;
								        if(ed==-1)
								        {
								            sachin[p].fail=0;
								            ed=p;
								            continue;
								        }
								        int q=sachin[ed].ch[j];
								        if(sachin[q].len==sachin[ed].len+1)
										sachin[p].fail=q;
								        else
								        {
								        		/*
						mputer programming and programming contests. 
						At CodeChef, we work hard to revive the geek in you
						 by hosting a programming contest at the start of the
						  month and another smaller programming challenge in the middle of the month.*/
								            int r=++sz;
								            sachin[r]=sachin[q];
								            sachin[r].len=sachin[ed].len+1;
								            sachin[p].fail=sachin[q].fail=r;
								            sachin[r].v=0;
								            while(ed>=0&&sachin[ed].ch[j]==q)sachin[ed].ch[j]=r,ed=sachin[ed].fail;
								        }
								        ed=p;
								    }
								    	/*
						mputer programming and programming contests. 
						At CodeChef, we work hard to revive the geek in you
						 by hosting a programming contest at the start of the
						  month and another smaller programming challenge in the middle of the month.*/
								}
