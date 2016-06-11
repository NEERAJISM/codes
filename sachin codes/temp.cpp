
deque<int> ll[n_partitions];
int core_data_editable[1000][103];

void make_list(int n_partitions, int idx) 
{
	for(int j=n_partitions+1;j<=n_cores+n_partitions;j++) 
	{
		int core_no=j-n_partitions;
		int list_no=parent_population[idx][j];
		ll[list_no].push_back(core_no);
	}
}

int calc_power(int n_partitions,int idx)
{
	memcpy(core_data_editable, core_data, sizeof(core_data));
	
	int max_power=0;
	bool islist_empty=false;
	while(!islist_empty) 
	{
		int total_power=0;
		for(int i=1;i<=n_partitions;i++) 
		{
			int core_no=ll[i][0];
			total_power+=power[core_no];
		}
		
		max_power=max(max_power, total_power);
		
		int min=200000, cnt=0;
		for(int i=1;i<=n_partitions;i++) 
		{
			if(ll[i].size()>0)
			{
				int core_no=ll[i][0];
				int pin_no=parent_population[idx][i];
				int test_time=core_data_editable[pin_no][core_no];
				if(min<test_time)
				min=test_time;	
			}
		}
		for(int i=1;i<=n_partitions;i++) 
		{
			if(ll[i].size()>0) 
			{
				int core_no=ll[i][0];
				int pin_no=parent_population[idx][i];
				int test_time=core_data_editable[pin_no][core_no];
				int diff=test_time-min;
				if(diff==0)
				ll[i].pop_front();
				else 
				core_data_editable[pin_no][core_no]=diff;
			}
			if(ll[i].size()==0) cnt++;
		}
		if(cnt==n_partitions) 
		islist_empty=true;
	}
	return max_power;
}
