#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> minmemo;
vector<int> maxmemo,maxchoice;

int minmaxwithpruning(int n,int maxnode)
{
	if(n==1)
		if(maxnode==1)
		{   
			return 0;
		}else{ 

			return 1;
		}
	if(maxnode)
	{
		if(maxmemo[n]>-1)
			return maxmemo[n];
		for(int i=1;i<=3 && n-i>0;i++){

			if(minmaxwithpruning(n-i,1-maxnode)==1)
			{   maxchoice[n]=i;
				maxmemo[n]=1;
				return 1;
			}
		}
		maxmemo[n]=0;
		return 0;
	}else{
		if(minmemo[n]>-1)
			return minmemo[n];
		for(int i=1;i<=3 && n-i >0;i++){
			if(minmaxwithpruning(n-i,1-maxnode)==0)
			{    
				minmemo[n]=0;
				return 0;
			}
		}
		minmemo[n]=1;
		return 1;
	}

}

int main(){


	cout<<"\nThe Game Of Sticks\n\n";
	cout<<"CHOOSE GAME\n1. AI vs Human\n2. AI vs AI\nSelect = \n";
	int option=0;
	cin>>option;
	if(option==1){
		cout<<"# AI vs Human\n";
		cout<<"Number of sticks in starting: ";
		cin>>n;
		maxmemo.resize(n+1,-1);
		minmemo.resize(n+1,-1);
		maxchoice.resize(n+1,-1);

		int toss=rand()%2,input,i=0;
		if(toss ==0)
		{
			cout<<"\nYou Are Player1\n---AI is Player2\n";
		}else{
			cout<<"\n---AI is Player1\n---You Are Player2\n\n";
		}
		cout<<"\nPLayer1 will draw stick(s) first\n\n";
		while(n>0)
		{
			if((i==0&&toss==0)or(i%2==1&&toss==1))
			{   cout<<"Take 1 to 3 No. Of sticks from "<<n<<" sticks: ";
				cin>>input;
				if(input<0&&input>3&&input<=n)
				{   cout<<"No. of sticks not in range\n"; 
					return 0;
				}
				n-=input;
				if(n<=0)
				{
					cout<<"You Loose\n";
				}

			}else{
				int win = minmaxwithpruning(n,1);
				int choice;
				if(maxchoice[n]==-1)
				{
					choice=1;
				}else{
					choice=maxchoice[n];
				}
				cout<<"AI Took "<<choice<<" Sticks. Now "<<n-choice<<" Sticks Remain\n";
				n-=choice;
				if(n<=0)
				{
					cout<<"You win\n";
				}
			}

			i++;
		}
	}else if(option==2){
		cout<<"Starting AI1 vs AI2 ...\n";
		cout<<"Number of sticks in starting: ";
		cin>>n;
		maxmemo.resize(n+1,-1);
		minmemo.resize(n+1,-1);
		maxchoice.resize(n+1,-1);
		int i=0;
		int win=minmaxwithpruning(n,1);
		if(win==0)
		{
			cout<<"--For n="<<n<<" First AI To Take sticks will always lose\n";
		}
		while(n>0)
		{   
			minmaxwithpruning(n,1);
			int choice;
			if(maxchoice[n]==-1)
			{
				choice=1;
			}else{
				choice=maxchoice[n];
			}
			cout<<"AI"<<(i%2)+1<<" Took "<<choice<<" Sticks. Now "<<n-choice<<" Sticks Remain\n";
			n-=choice;
			i++;
		}
		if(win==1)
			cout<<"AI1 Wins\n";
		else{
			cout<<"AI1 Loses\n";
		}
	}else{
		cout<<"Invalid Option\n";
	}


	return 0;
}
