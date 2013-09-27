#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct crocodiles_t {
	bool birth;
	int year;
	bool operator<(const struct crocodiles_t &k)const{
	if (year!=k.year)
	return year<k.year;
	else
		if(birth==true && k.birth==false)
			return false;
		else return true;
	}
};
typedef struct crocodiles_t crocodiles;
int findmax(vector<crocodiles> target)
{
	int max=0;
	int temp=0;
	for(vector<crocodiles>::iterator it=target.begin();it!=target.end();++it)
	{
		if((*it).birth==true)
			temp++;
		else
			temp--;
		if(temp>max)
		max=temp;
	}

	return max;
}	
int main()
{
	FILE *in,*out;
	in=fopen("crocodiles.in","r");
	out=fopen("crocodiles.out","w");
	int N;
	fscanf(in,"%d",&N);
	vector<crocodiles> alig;
	while(N--)
	{
		crocodiles temp1,temp2;
		fscanf(in,"%d %d",&temp1.year,&temp2.year);
		temp1.birth=true;
		temp2.birth=false;
		alig.push_back(temp1);
		alig.push_back(temp2);
	}
	sort(alig.begin(),alig.end());
	fprintf(out,"%d\n",findmax(alig));
	return 0;
}
