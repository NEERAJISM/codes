#include <bits/stdc++.h>




#define habalabadaba long long int



using namespace std;




char sghgsghgsdfhgsgkhsgfshdfgshgf[199900];



habalabadaba h[1001000],zero_hamama_ayay_hai[1000001],o[1000001],chinicumhai_panijyada[1000001];







int main()





{





	int testcasekalaudaloge;






	cin>>testcasekalaudaloge;








	while(testcasekalaudaloge--)







	{









		habalabadaba n,k,query_to_chutiyapa_hai_i_am_rock;







		cin>>n>>k>>query_to_chutiyapa_hai_i_am_rock;







		cin>>sghgsghgsdfhgsgkhsgfshdfgshgf;










		habalabadaba j=0;








		habalabadaba sifugyiusygisdfggdfigudfygiuyfwfygsfgskdgjsdgfjgfjhgsdhg=0,sacfsvnkbgkcfsnkvfbjksbnhcgfevwhfckgwwheiwhiethgvichwiugchevigicehgcieiughe=0;









		for(int i=0;i<n;i++)








		{









			if(sghgsghgsdfhgsgkhsgfshdfgshgf[i]=='1')








				sifugyiusygisdfggdfigudfygiuyfwfygsfgskdgjsdgfjgfjhgsdhg++;








			else










				sacfsvnkbgkcfsnkvfbjksbnhcgfevwhfckgwwheiwhiethgvichwiugchevigicehgcieiughe++;











			zero_hamama_ayay_hai[i+1]=sacfsvnkbgkcfsnkvfbjksbnhcgfevwhfckgwwheiwhiethgvichwiugchevigicehgcieiughe;








			o[i+1]=sifugyiusygisdfggdfigudfygiuyfwfygsfgskdgjsdgfjgfjhgsdhg;








		}







		for(int i=1;i<=n;i++)











		{










			int sifugyiusygisdfggdfigudfygiuyfwfygsfgskdgjsdgfjgfjhgsdhg=upper_bound(zero_hamama_ayay_hai,zero_hamama_ayay_hai+n+1,zero_hamama_ayay_hai[i-1]+k)-zero_hamama_ayay_hai;









			int sacfsvnkbgkcfsnkvfbjksbnhcgfevwhfckgwwheiwhiethgvichwiugchevigicehgcieiughe=upper_bound(o,o+n+1,o[i-1]+k)-o;










			h[i]=min(sifugyiusygisdfggdfigudfygiuyfwfygsfgskdgjsdgfjgfjhgsdhg,sacfsvnkbgkcfsnkvfbjksbnhcgfevwhfckgwwheiwhiethgvichwiugchevigicehgcieiughe);








			h[i]--;












		}








		habalabadaba chinicumhai_panijyadamation_rocks_babu=0;





		






		for(int i=1;i<=n;i++)







		{









			chinicumhai_panijyadamation_rocks_babu+=h[i]-i+1;

			chinicumhai_panijyada[i]=chinicumhai_panijyadamation_rocks_babu;





		}








		while(query_to_chutiyapa_hai_i_am_rock--)










		{









			habalabadaba l,r;






			scanf("%lld%lld",&l,&r);










			habalabadaba idsifugyiusygisdfggdfigudfygiuyfwfygsfgskdgjsdgfjgfjhgsdhg=upper_bound(h+l,h+r,r)-h;











				idsifugyiusygisdfggdfigudfygiuyfwfygsfgskdgjsdgfjgfjhgsdhg--;









			









				habalabadaba answer_is_the_thing_we_want=0;













				answer_is_the_thing_we_want=chinicumhai_panijyada[idsifugyiusygisdfggdfigudfygiuyfwfygsfgskdgjsdgfjgfjhgsdhg]-chinicumhai_panijyada[l-1];
















				answer_is_the_thing_we_want+=((r-idsifugyiusygisdfggdfigudfygiuyfwfygsfgskdgjsdgfjgfjhgsdhg)*(r-idsifugyiusygisdfggdfigudfygiuyfwfygsfgskdgjsdgfjgfjhgsdhg+1))/2;




















				printf("%lld\n",answer_is_the_thing_we_want);



















 

			
		}



	}






}
