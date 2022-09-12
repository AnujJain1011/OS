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
void findWT(int process[],int n,int bt[],int wt[])
{
	wt[0]=0;
	for(int i=1;i<n;i++)
	{
		wt[i]=bt[i-1]+wt[i-1];
	}
}
void findTAT(int process[],int n,int bt[],int wt[],int tat[])
{
	for(int i=0;i<n;i++)
	{
		tat[i]=wt[i]+bt[i];
	}
}
void findAT(int process[],int n,int bt[])
{
	int wt[n],tat[n],ct[n],total_wt=0,total_tat=0;
	findCT(process,n,bt,ct);
	findWT(process,n,bt,wt);
	findTAT(process,n,bt,wt,tat);
	cout<<"processId  burst_time  Completion_time  Waiting_time  TurnAroundTime "<<endl;
	for(int i=0;i<n;i++)
	{
		total_wt += wt[i];
		total_tat += tat[i];
		cout<<i+1<<"\t\t"<<bt[i]<<"\t\t"<<ct[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
	}
	
	cout<<"avg waiting time : "<<(float)total_wt/(float)n<<endl;
	cout<<"avg tat time(32) : "<<(float)total_tat/(float)n;
}

int main()
{
	int n;
	cout<<"Enter number of processes:"<<endl;
	cin>>n;
	cout<<"Enter the process id and burst time of the processes:"<<endl;
	int pro_id[n],bur_t[n];
	for(int i=0;i<n;i++)
	{
		cin>>pro_id[i]>>bur_t[i];
	}
	findAT(pro_id,n,bur_t);
	return 0;
}

