 #include<iostream>
  #include<algorithm>
  #include<vector>
 using namespace std;
 int main()
 {
 	int i,s1,s2,n,t,s,c,p;
 
 	cin>>t;
 	
 	while(t--)
 	{   s=0;
 	    s1=0;
 	    s2=0;
 	    c=-1;
 	    	vector <int> a;
 	
 		cin>>n;
 		for(i=0;i<n;i++)
 		{
 			cin>>p;
 			a.push_back(p);
 		}
 		
 			for(i=0;i<n;i++)
 			{
 				s+=a[i];
 			}
 		
 		i=0;
 		do
 		{
 			s1+=a[i];
 			c++;
 			i++;
 		}
 		while(s1<=(s/2));
 	    s1=s1-a[c];
 		
 		for(i=c+1;i<n;i++)
 		{
 			s2+=a[i];
 		}
 	
 		if(s1==s2)
 		{
 			cout<<"YES\n";
 		
 		}
 		else
 		cout<<"NO\n";
 		
 	}
 	return 0;
 }
