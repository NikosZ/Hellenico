#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
struct rocks_t
{
	int m,v;
	public:bool operator<(const struct rocks_t &val)const{
	 return ((double)m/v <(double)val.m/val.v);
	}
};
typedef struct rocks_t rocks;
int main()
{
	FILE *in,*out;
	in=fopen("stones.in","r");
	out=fopen("stones.out","w");
	int n,z;
	fscanf(in,"%d %d ",&n,&z);
	vector<rocks> stones;
	int temp=n;
	while(temp--)
	{
	rocks tempval;
	fscanf(in,"%d %d",&tempval.v,&tempval.m);
	stones.push_back(tempval);
	}
	sort(stones.begin(),stones.end());
	for(int i=0;i<n;i++)
	printf("%d %d\n",stones[i].m,stones[i].v);
	double res=0;
	while(z>0)
	{
	if(stones.empty())
	break;
	if(stones.back().v<=z){
		z-=stones.back().v;
		res+=stones.back().m;
		stones.pop_back();}
	else
	{
		double r=(double)stones.back().m/stones.back().v;
		res+=r*z;
		break;
	}
	}
	fprintf(out,"%0.3f\n",res);
	return 0;
}
