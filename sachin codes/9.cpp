 #include<iostream>
  #include<vector>
 using namespace std;
 int main()
 {
 	int n,k,q;
 	cin>>n>>k>>q;
 	

 		vector <int> a;
 		int i,j,t,p,x;
 		for(i=0;i<n;i++)
 		{
 			cin>>p;
 			a.push_back(p);
 			
 		}
 		
 		for(j=0;j<k;j++)
 		{
 		
 		t=a[n-1];
 		for(i=n-1;i>0;i--)
 		{
 			a[i]=a[i-1];
 		}
 		a[0]=t;
 	    }
 	
 	for(j=0;j<q;j++)
 		{
 			cin>>x;
 			cout<<a[x]<<endl;
 		
     }
 	return 0;
 }
