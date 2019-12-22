#
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct proccess
{
	int bt,ct,wt,btt;
	string pro_id;


}Schedule;


int main()
{
	Schedule pro[10];
	int n,i,j,pcom,q;

	cout<<"Enter the number of Process::";
	cin>>n;

	cout<<"Enter the value of quantum time::";
	cin>>q;



	for(i=0;i<n;i++)
	{
	    cout<<"Enter the Process id's  burst time "<<i+1<<" :";
		cin>>pro[i].bt;
		pro[i].btt=pro[i].bt;
	}

	int ctime=0;
	pcom=0;
	while(pcom<n)
	{
		for(j=0;j<n;j++)
		{
			if(pro[j].bt>q){
                pro[j].bt-=q;
                ctime+=q;
			}
			else if(pro[j].bt>0){

                ctime+=pro[j].bt;
                pro[j].ct=ctime;
                pcom=pcom+1;
                pro[j].bt=0;
			}
		}
	}
     double AverageWaiting=0;
	cout<<"ProID\tBurst time\tComplete time\tWaiting time\n";

	for(i=0;i<n;i++)
	{

		pro[i].wt=pro[i].ct-pro[i].btt;
		AverageWaiting+=pro[i].wt;

		cout<<i+1<<"\t\t"<<pro[i].btt<<"\t\t"<<pro[i].ct<<"\t\t"<<pro[i].wt<<endl;

	}
	cout<<"Average waiting time :"<<AverageWaiting/n<<endl;

	return 0;
}

