#include <bits/stdc++.h>
using namespace std;

int main()
{
    int initialNode,seekTime;
    int n;
    cout<<"Enter the number of requests:"<<endl;
    cin>>n;
    cout<<"Enter initial node:";
    cin>>initialNode;
    int reqTime[n];
    cout<<"Enter the requests:"<<endl;
	for(int i=0;i<n;i++)
	{
    	cin>>reqTime[i];
	}
	seekTime = initialNode - reqTime[0];
	for(int i=1;i<n;i++)
	{
		seekTime += abs(reqTime[i] - reqTime[i-1]);
	}
    cout<<"Total Seek Time is "<<seekTime<<endl;
    cout<<"Average seek time is "<<seekTime/n;
    return 0;
}
