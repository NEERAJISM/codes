 #include<iostream>
  #include<algorithm>
  #include<vector>
 using namespace std;
 
 
 
 int main()
 {
 	int i,j,n,t,s,c,p;
 
 	cin>>t;
 	
 	while(t--)
 	{
 		cin>>n;
 		vector <int> a;
 		for(i=0;i<n;i++)
 		{
 			cin>>p;
 			a.push_back(p);
 			
 		}
 		
 		sort(a.begin(),a.end());
 	
 		
 		s=0;
 		i=1;
 		int d=0;
 		while(i<n)
 		{
 			c=0;
 			    if(a[i]!=a[i-1])
 			 {
 			  
 				for(j=0;j<n;j++)
 				{
 					if(a[j]==a[i])
 					{
 						c++;
 					}
 				
 				}
 		    
 		        s+=(c*(c-1));
			 } 
 			i++;
 	       	
 		      
 		}
 		
 	
 				for(j=0;j<n;j++)
 				{
 					if(a[j]==a[0])
 					{
 						d++;
 					}
 				
 				}
 				   s+=(d*(d-1));
 		
 		
 		cout<<s<<endl;
 		
 		
 	}
 	
 return 0;	
 }
