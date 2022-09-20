#include<iostream>
using namespace std;

void findCT(int process[],int n,int bt[],int ct[])
{
	ct[0]=bt[0];
	for(int i=1;i<n;i++)
	{
		ct[i]=ct[i-1] + bt[i];
	}
}

void findTAT(int process[],int n,int ct[],int at[],int tat[])
{
	for(int i=0;i<n;i++)
	{
		tat[i]=ct[i] - at[i];
	}
}

void findWT(int process[],int n,int bt[],int tat[],int wt[])
{
	wt[0]=0;
	for(int i=1;i<n;i++)
	{
		wt[i]=tat[i] - bt[i];
	}
}

void findAT(int process[],int n,int at[],int bt[])
{
	int wt[n],tat[n],ct[n],total_wt=0,total_tat=0;
	findCT(process,n,bt,ct);
	findTAT(process,n,ct,at,tat);
	findWT(process,n,bt,tat,wt);
	cout<<"process    arr_time      burst_time      completionTime    waitingTime  turnAroundTime "<<endl;
	for(int i=0;i<n;i++)
	{
		total_wt += wt[i];
		total_tat += tat[i];
		cout<<i+1<<"\t\t"<<at[i]<<"\t\t"<<bt[i]<<"\t\t"<<ct[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
	}
	cout<<"avg waiting time : "<<(float)total_wt/(float)n<<endl;
	cout<<"avg turnAroundTime time : "<<(float)total_tat/(float)n;
}

int main()
{
	int n;
	cout<<"Enter number of processes:"<<endl;
	cin>>n;
	int pro_id[n],arr_t[n],bur_t[n];
	cout<<"Enter the process id,arrival time and burst time for the processes:"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>pro_id[i]>>arr_t[i]>>bur_t[i];
	}
	findAT(pro_id,n,arr_t,bur_t);
	return 0;
}

