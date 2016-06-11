#include <bits/stdc++.h>
using namespace std;
#define MOD 9999999

int n_cores;
int n_pins;
int n_partitions;
int power_data[]={0,660,602,823,275,690,354,530,753,641,1144};
#define n_generations 7
#define total_parent_population 1000
#define total_children_population 500

int sd=73,x,y,z,t,w;

int hash[100000000];

int parent_population [total_parent_population+1] [103];

int children_population [total_children_population+1] [103];

int parent_children [total_parent_population+total_children_population+1] [103];

vector < pair < double , int > > parent_fitness (total_parent_population+1);

vector < pair < double , int > > children_fitness (total_children_population+1);

vector < pair < double , int > > both_fitness (total_parent_population+total_children_population+1);

int parent_cummulative_fitness [total_parent_population+1];

int children_cummulative_fitness [total_children_population+1];

int core_data [1000] [103];

void read_problem (const char *filename)
{
	FILE *file;
	
	int i, j;
	
	char comma;
	
	file = fopen(filename, "r");
	
	for (i = 1; i <= n_pins; i++)
	{
		int tmp = 0;
		
		fscanf(file, "%d", &tmp);
		//printf("tmp = %d\n", tmp);
		
		for (j = 1; j <= n_cores; j++)
		{
			fscanf(file, "%c", &comma);
			fscanf(file, "%d", &(core_data[i][j]));	
		}
		tmp = getc(file);
		if (isdigit(tmp))
			ungetc(tmp, file);
	}
}

void random_seed(int s)
{
	x=s;
  y = x * s;
  z = y * s;
  w = z * s;
}

int random_number()
{	 
	t = x ^ (x << 11);
  x = y; y = z; z = w;                       
  return w = abs((w ^ (w >> 19)) ^ (t ^ (t >> 8))); 
}

long long int modular_exponentiation(long long int a,long long int b,long long int c)
{
	long long int x=1,y=a;
	while(b>0)
	{
		if(b%2==1)
		{
			x=(x*y)%c;      //  or call  mulmod(x,y,c);
		}
		y=(y*y)%c;          //  or call  mulmod(y,y,c);
		b=b/2;
	}
	return x%c;
}

int hash_value(int a[])
{
	long long int h=0;
	for(int j=n_cores+n_partitions;j>=1;j--)
	{
		long long int exp=modular_exponentiation(2,j-1,MOD);
		exp=(exp*a[j])%MOD;
		exp=(exp+a[j])%MOD;
		h=(h+exp)%MOD;
		//h+=((a[j]*(pow(2,j-1)))+a[j]);
	}
	
	return (int)h;
}

void make_population()
{
	int a1[103];
	int i=1;
	while(i<=total_parent_population)
	{//cout<<i<<endl;
		sd=sd+i;
		random_seed(sd);         int y=n_pins-n_partitions+1;        int x;        int counter=0;
		for(int j=1;j<=n_partitions-1;j++)
		{
			x=random_number()%y;
			x++;
			parent_population[i][j]=x;          a1[j]=x;          counter+=x;
			y=y-x+1;//cout<<"x="<<x<<"y="<<y<<endl;
		}
		parent_population[i][n_partitions]=n_pins-counter;//cout<<"x="<<n_pins-counter<<endl;
		for(int j=n_partitions+1;j<=n_cores+n_partitions;j++)
		{
			x=random_number()%n_partitions;
			x++;
			parent_population[i][j]=x;
			a1[j]=x;
		}
		int h=hash_value(a1);//cout<<h;
		if(hash[h]==0)
		{
			i++;
			hash[h]=1;
		}
	}
}

// addding power ////////////////////////////


list<int> ll[11];
int core_data_editable[1000][103];

void make_list(int pp,int idx) 
{
	if(pp==1)
	{
		if(parent_population[idx][1]==0)
		return ;
	}
	else
	{
		if(parent_children[idx][1]==0)
		return ;
	}
	//cout<<"pp="<<pp<<endl;
	//cout<<"this chromosome\n";
	/*for(int i=1;i<=n_cores+n_partitions;i++)
	{
		if(pp==1)
		cout<<parent_population[idx][i]<<"  ";
		else
		cout<<parent_children[idx][i]<<"  ";
	}
	cout<<endl;*/
	
	int list_no;
	for(int j=n_partitions+1;j<=n_cores+n_partitions;j++) 
	{
		int core_no=j-n_partitions;
		if(pp==1)
		list_no=parent_population[idx][j];
		else
		list_no=parent_children[idx][j];
		
		//cout<<"list_no="<<list_no<<"  core_no="<<core_no<<endl;
		ll[list_no].push_back(core_no);
	}
	/*for(int i=1;i<=n_partitions;i++) 
	{
		for(int j=0;j<ll[i].size();j++)
		{
			cout<<ll[i][j]<<" ";
		}
		cout<<endl;
	}*/
}

int calc_power(int pp,int idx)
{
	memcpy(core_data_editable, core_data, sizeof(core_data));
	/*for(int i=1;i<=n_pins;i++)
	{
		for(int j=1;j<=n_cores;j++)
		{
			cout<<core_data_editable[i][j]<<"  ";
		}cout<<endl;
	}*/
	
	if(pp==1)
	{
		if(parent_population[idx][1]==0)
		return 6500;
	}
	else
	{
		if(parent_children[idx][1]==0)
		return 6500;
	}
	
	int max_power=0; int pin_no;
	bool islist_empty=false;
	while(!islist_empty) 
	{  
//		if(idx==2030||idx==2035)
//		cout<<"h";
		int total_power=0;
		for(int i=1;i<=n_partitions;i++) 
		{
			if(ll[i].size()>0)
			{
				int core_no=ll[i].front();
				total_power+=power_data[core_no];
			}
			//cout<<"core no. "<<core_no<<" "<<total_power<<endl;
		}
		//if(idx==2030||idx==2035)
		//cout<<"total_power="<<total_power;
		
		max_power=max(max_power, total_power);
		
		int min=200000, cnt=0;
		for(int i=1;i<=n_partitions;i++) 
		{
			if(ll[i].size()>0)
			{
				int core_no=ll[i].front();
				
				if(pp==1)
				pin_no=parent_population[idx][i];
				else
				pin_no=parent_children[idx][i];
				
				int test_time=core_data_editable[pin_no][core_no];
				if(min>test_time)
				min=test_time;	
			}
		}
//		if(idx==2030||idx==2035)
//		cout<<"min="<<min;
		for(int i=1;i<=n_partitions;i++) 
		{
			if(ll[i].size()>0) 
			{
				int core_no=ll[i].front();
				
				if(pp==1)
				pin_no=parent_population[idx][i];
				else
				pin_no=parent_children[idx][i];
				
				int test_time=core_data_editable[pin_no][core_no];
				int diff=test_time-min;
				
//				if(idx==2030||idx==2035)
//				cout<<"pin="<<pin_no<<"  core="<<core_no<<"  test="<<test_time<<"  diff="<<diff;
				
				if(diff==0)
				{
//					if(idx==2030||idx==2035)
//					{
//						cout<<"   deleting  ";
//						cout<<"   size = "<<ll[i].size();
//					}
					ll[i].pop_front();
					
//					if(idx==2030||idx==2035)
//					cout<<"   deleted  ";
				}
				else 
				core_data_editable[pin_no][core_no]=diff;
			}
			else cnt++;
		}
//		if(idx==2030||idx==2035)
//		cout<<"cnt="<<cnt<<endl;
		
		if(cnt==n_partitions) 
		islist_empty=true;
	}
	//cout<<"max_power="<<max_power<<endl;
	return max_power;
}

// ending power things  //////////////////////

void clear_fitness()
{
	for(int i=1;i<=total_parent_population;i++)
	{
		parent_fitness[i].first=0;
		parent_fitness[i].second=0;
	}
}

void calculate_fitness()
{
	int sum[103];
	for(int i=1;i<=total_parent_population;i++)
	{
		int x,y;
		parent_fitness[i].second=i;
		
		for(int k=1;k<=n_partitions;k++)
		sum[k]=0;
		
		for(int j=n_partitions+1;j<=n_cores+n_partitions;j++)
		{
			x=parent_population[i][j];
			y=parent_population[i][x];
			sum[x]+=core_data[y][j-n_partitions];
		}
		
		int max_sum=0;
		for(int k=1;k<=n_partitions;k++)
		{
			if(max_sum<sum[k])
			max_sum=sum[k];
		}
		
		make_list(1,i);
		int power=calc_power(1,i);
		double ff=sqrt(power);
		ff=sqrt(ff);
		ff=sqrt(ff);
		parent_fitness[i].first=ff;  // assinging fitness values
		parent_fitness[i].first*=max_sum;
	}
}

int find_individual_test_time(int idx)
{
	int sum[103];    int x,y;
	for(int k=1;k<=n_partitions;k++)
		sum[k]=0;
		
	for(int j=n_partitions+1;j<=n_cores+n_partitions;j++)
	{
		x=parent_population[idx][j];
		y=parent_population[idx][x];
		sum[x]+=core_data[y][j-n_partitions];
	}
		
	int max_sum=0;
	for(int k=1;k<=n_partitions;k++)
	{
		if(max_sum<sum[k])
		max_sum=sum[k];
	}
	return max_sum;
}

void arrange_parent_fitness()
{
	int temp[total_parent_population+1][n_cores+n_partitions+1];
	
	for(int i=1;i<=total_parent_population;i++)
	{
		int x=parent_fitness[i].second;
		
		for(int j=1;j<=n_cores+n_partitions;j++)
		{
			temp[i][j]=parent_population[x][j];
		}
	}
	
	for(int i=1;i<=total_parent_population;i++)
	{
		for(int j=1;j<=n_cores+n_partitions;j++)
		{
			parent_population[i][j] = temp[i][j];
		}
	}
	
}

void calculate_cummulative_fitness()
{
	int sum=0;
	for(int i=1;i<=total_parent_population;i++)
	{
		sum+=parent_fitness[i].first;
		parent_cummulative_fitness[i]=sum;
	}
}

int total_fitness()
{
	int sum=0; 
	for(int i=1;i<=total_parent_population;i++)
	{
		sum+=parent_fitness[i].first;//cout<<"sum="<<sum1;
	}
	return sum;
}

int select_chromosomes()
{
	//cout<<"total_fitness="<<total_fitness()<<endl;
	sd++;
	random_seed(sd);
	int x = random_number () % (2+total_fitness());  
	int y = lower_bound ( parent_cummulative_fitness+1 , parent_cummulative_fitness + total_parent_population , x ) - parent_cummulative_fitness;
	y=total_parent_population-y+1;
   	//cout<<"x="<<x<<"y="<<y<<endl;
	return y;
}
///////////////////////////////////////////////////////////////////////////
void crossover()
{
	int a1[103],a2[103];             //cout<<"h";
	int k1=1,k2=2,i=1;
	while(i<=total_children_population/2)
	{	//cout<<"h";
		int chromosome1=select_chromosomes();          int chromosome2=select_chromosomes();
		sd++;
		random_seed(sd);
		int position=random_number()%n_cores;
		position+=n_partitions+1;         //cout<<"position="<<position<<endl;     

		for(int j=1;j<position;j++)
		{
			children_population[k1][j] = parent_population[chromosome1][j];
			children_population[k2][j] = parent_population[chromosome2][j];
		}
		
		for(int j=position;j<=n_cores+n_partitions;j++)
		{
			children_population[k2][j] = parent_population[chromosome1][j];
			children_population[k1][j] = parent_population[chromosome2][j];
		}
		
		for(int j=1;j<=n_cores+n_partitions;j++)
		{
			a1[j]=children_population[k1][j];
			a2[j]=children_population[k2][j];
		}
		
		int h1=hash_value(a1);
		int h2=hash_value(a2);
		if(hash[h1]==0&&hash[h2]==0)
		{
			i++;
			k1+=2;
			k2+=2;
			hash[h1]=1;
			hash[h2]=1;
		}
	}	
	/*for(int i=1;i<=total_children_population;i++)
		{
			for(int j=1;j<=n_cores+2;j++)
			{
				cout<<children_population[i][j]<<"  ";
			}
			cout<<endl;
		}*/ 
}

void combine_both_generations()
{
	for(int i=1;i<=total_parent_population;i++)
	{
		for(int j=1;j<=n_cores+n_partitions;j++)
		{
			parent_children[i][j]=parent_population[i][j];
		}
	}
	for(int i=1;i<=total_children_population;i++)
	{
		for(int j=1;j<=n_cores+n_partitions;j++)
		{
			parent_children[total_parent_population+i][j]=children_population[i][j];
		}
	}
/*	for(int i=1;i<=total_children_population;i++)
		{
			for(int j=1;j<=n_cores+2;j++)
			{
				cout<<children_population[i][j]<<"  ";
			}
			cout<<endl;
		}*/
/*	cout<<"combined population\n";
	for(int i=1;i<=total_parent_population+total_children_population;i++)
		{
			for(int j=1;j<=n_cores+2;j++)
			{
				cout<<parent_children[i][j]<<"  ";
			}
			cout<<endl;
		}*/
}

void clear_both_fitness()
{
	for(int i=1;i<=total_parent_population+total_children_population;i++)
	{
		both_fitness[i].first=0;
		both_fitness[i].second=0;
	}
}

void calculate_both_fitness()
{
	int sum[103];
	for(int i=1;i<=total_parent_population + total_children_population;i++)
	{
//		if(i==2030||i==2035)
//		{
//			cout<<"i="<<i<<endl;
//			for(int j=1;j<=n_cores+n_partitions;j++)
//			cout<<parent_children[i][j]<<"  ";
//			cout<<endl;
//		}
				int x,y;
		both_fitness[i].second=i;
		
		for(int k=1;k<=n_partitions;k++)
		sum[k]=0;
		
		for(int j=n_partitions+1;j<=n_cores+n_partitions;j++)
		{
			x=parent_children[i][j];
			y=parent_children[i][x];
			sum[x]+=core_data[y][j-n_partitions];
		}
		
		int max_sum=0;
		for(int k=1;k<=n_partitions;k++)
		{
			if(max_sum<sum[k])
			max_sum=sum[k];
		}
		
		make_list(2,i);
		
		int power=calc_power(2,i);
//		if(i==2030||i==2035)
//		cout<<"power="<<power;
		double ff=sqrt(power);
		ff=sqrt(ff);
		ff=sqrt(ff);
		both_fitness[i].first=ff;  // assinging fitness values
		both_fitness[i].first*=max_sum;
	}
}

void arrange_both_fitness()
{
	int temp[total_parent_population+total_children_population+1][n_cores+n_partitions+1];
	
	for(int i=1;i<=total_parent_population+total_children_population;i++)
	{
		int x=both_fitness[i].second;
		
		for(int j=1;j<=n_cores+n_partitions;j++)
		{
			temp[i][j]=parent_children[x][j];
		}
	}
	
	for(int i=1;i<=total_parent_population+total_children_population;i++)
	{
		for(int j=1;j<=n_cores+n_partitions;j++)
		{
			parent_children[i][j] = temp[i][j];
		}
	}
	
	/*for(int i=1;i<=total_parent_population+total_children_population;i++)
		{
			for(int j=1;j<=n_cores+2;j++)
			{
				cout<<parent_children[i][j]<<"  ";
			}
			cout<<endl;
		}*/
}

void find_next_generation_parent_population()
{
	for(int i=1;i<=total_parent_population;i++)
	{
		for(int j=1;j<=n_cores+n_partitions;j++)
		{
			parent_population[i][j]=parent_children[i][j];
		}
	}
}

void select_next_generation()
{
	combine_both_generations();cout<<"a";
	clear_both_fitness();cout<<"b";
	calculate_both_fitness();cout<<"c";
	sort(both_fitness.begin(),both_fitness.end());cout<<"d";
	/*for(int i=1;i<=total_parent_population+total_children_population;i++)
		{
			cout<<both_fitness[i].first<<"  "<<both_fitness[i].second<<endl;
		}*/
	arrange_both_fitness();cout<<"e";
	find_next_generation_parent_population();cout<<"f";
}

int main()
{
	cout<<"enter the number of pins and number of cores and number of partitions\n";
	cin>>n_pins>>n_cores>>n_partitions;
	
	read_problem("d695.csv");
	/*for(int i=1;i<=n_pins;i++)
	{
		for(int j=1;j<=n_cores;j++)
		{
			cout<<core_data[i][j]<<"\t";
		}
		cout<<endl;
	}*/
	cout<<"1";
	make_population();cout<<"2";
	/*for(int i=1;i<=total_parent_population;i++)
	{
		for(int j=1;j<=n_cores+n_partitions;j++)
		{
				cout<<parent_population[i][j]<<"  ";
		}
		cout<<endl;
	}*/
	
	for(int i=0;i<n_generations;i++)
	{
		cout<<"generation no="<<i<<endl;
		
		clear_fitness();cout<<"3";
		
	
		calculate_fitness();cout<<"4";

		
		sort(parent_fitness.begin()+1,parent_fitness.end());cout<<"5";
		/*for(i=1;i<=total_parent_population;i++)
		{
			cout<<parent_fitness[i].first<<"  "<<parent_fitness[i].second<<endl;
		}  */                                                            
		
		arrange_parent_fitness();cout<<"6";
		/*for(int i=1;i<=total_parent_population;i++)
		{
			for(int j=1;j<=n_cores+n_partitions;j++)
			{
				cout<<parent_population[i][j]<<"  ";
			}
			cout<<endl;
		}*/
		if(i==n_generations)
		break;
		
		calculate_cummulative_fitness();cout<<"7";
		/*for(i=1;i<=total_parent_population;i++)
		{
			cout<<parent_cummulative_fitness[i]<<endl;
		}*/
		
		crossover();cout<<"8";
		
		select_next_generation();cout<<"9";
		/*for(int i=1;i<=total_parent_population;i++)
		{
			for(int j=1;j<=n_cores+n_partitions;j++)
			{
				cout<<parent_population[i][j]<<"  ";
			}
			cout<<endl;
		}*/
	}
	ofstream output("output.csv");
	for(int i=1;i<=total_parent_population;i++)
	{
		make_list(1,i);
		int power=calc_power(1,i);
		int tt=find_individual_test_time(i);
		
		output << parent_fitness[i].first << ","<< tt << "," << power << "," ;
		for(int j=1;j<=n_cores+n_partitions;j++)
		{
				output<<parent_population[i][j]<<",";
		}
		output<<endl;
	}
	output.close();
	
	
	
	make_list(1,1);
	int power=calc_power(1,1);
	cout<<" final optimized power = "<< power<<endl;
	
	int tt=find_individual_test_time(1);
	cout<<" final optimized test time = "<< tt<<endl;
	
	cout<<" pins used in the partition are    "<<endl;
	
	for(int j=1;j<=n_partitions;j++)
	cout<<parent_population[1][j]<<"   ";
	cout<<endl;
	
	cout<<" arrangement of pins = "<<endl;
	
	for(int j=n_partitions+1;j<=n_cores+n_partitions;j++)
	{
		cout<<parent_population[1][j]<<"   ";
	}
	
	cout<<"\nits over man \n";
	return 0;
}
