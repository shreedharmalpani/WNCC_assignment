#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include<bits/stdc++.h>
using namespace std;



int to_int(string s) // stoi  wasn't woring for this version 
{                    // so i created a function to extract the integer value out of the string
	int num=0;
	int len= s.length();
	for(int i=0;i<len;i++)
	{
		char ch= s.at(i);
		num=num*10+((int)ch-48);
		
	}
	return  num;
	
}
struct Groundwork{
	int st=0,d=0,et=0;
	
};

struct Available_Groundworks{

int n;
struct Groundwork gw[1000];
};

Available_Groundworks*  initialize(int start_time[ ], int duration[ ], int n)
{
	struct Available_Groundworks abc;
	abc.n=n;
	abc.gw[n];
		
	

	for(int i=0;i<n;i++)
	{
		abc.gw[i].st=start_time[i];
		abc.gw[i].d =duration[i];
		abc.gw[i].et=start_time[i]+ duration[i];
		
		
	}
	
	return (&abc) ;
}

int CalculateMaxGroundworks(Available_Groundworks* ptr)
{ 
    
    int n= ptr->n;
    
    vector<pair<int,int> > v;
	for(int i=0;i<n;i++){
		int x=ptr->gw[i].st;
		int y=ptr->gw[i].et;
		v.push_back(make_pair(y,x));
	}
	sort(v.begin(),v.end());
	
	
	
	int c=0,k=0;
	for(int i=0;i<n;i++){
		if(v[i].second>=k){
			c++;
			k=v[i].first;
		}
	}
	
	return c;
	
    
}

int main () {
  
  ifstream inFile;
  inFile.open("Schedule.txt");
  
  //cout<<"ENTER NO. OF ROWS"<<endl;   earlier it wasn't mentioned that all files will have same no. of row inputs as Schedule.txt
  int m;
  //cin>>m;   if file has different no. of row inputs
  m=22;
  
  string names[m];
  int start_times[m];
  int durations[m];
  
  string name;
  int count=0;
  while(inFile >> name)
  {
  	
  names[count]=(name);
  inFile >> name;
  start_times[count]=  to_int(name);
  inFile >> name;
  durations[count++]= to_int(name);
    
   }
 

int answer = CalculateMaxGroundworks(initialize(start_times,durations,m));
cout<<"MAX POSSIBLE MEETINGS HE CAN ATTEND - "<<answer;
	
return 0;
  
}
