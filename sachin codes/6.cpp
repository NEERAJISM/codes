 #include<iostream>
 #include<vector>
 #include<algorithm>
 using namespace std;
 int main()
 {
 	 long long int n,c=0,i,p;
 	 long long int k,s=0;
 	vector <int> a;
 	cin>>n>>k;
 	
 	for(i=0;i<n;i++)
 	{
 		cin>>p;
 		a.push_back(p);
 		
 	}
    sort(a.begin(),a.end());

 	i=0;
 	do
 	{
 		s+=a[i];
 		c++;
 		i++;
 	}
 	while(s<k);
 	cout<<c-1<<endl;
 	return 0;
 	
 }
