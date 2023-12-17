#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

void GenerateMarks(int Mark, int n)
{
	int j = 1;
	bool plus = true;
	cout << Mark << ",";
	for(int i=1; i<n; i++)
	{
		if(plus)
		{
			cout << Mark+j;
			plus = false;
		}
		else
		{
			cout << Mark+(j*-1);
			j++;
			plus = true;
		}
		
		if(i!=n-1) cout << ",";
	}
}

int main()
{
	int n,m;
	cin >> n >> m;
	
	string id[m];
	float marks[m];
	string userline;
	for(int i=0; i<m; i++)
	{
		getline(cin, userline); 
		cout << userline << endl;
		int pos = 0;
		float grade = 0;
		bool after = true;
		string name;
		
		pos = userline.find_first_of(',');
		for(int j=pos; j<userline.length(); j++)
		{
			if(userline[j] != '.' && after)
				grade += (int)userline[j]*10;
			else if(userline[j] == '.')
				after = true;
			else
				grade += (int)userline[j]*0.1;
		}
		name = userline[0];
		for(int k=1; k<pos;k++)
			name += (userline[k]);
		id[i] = name;
		
		pos = userline.find(',',pos+1);
		cout << userline[pos+1]<< endl;
		for(int j=pos+1; j<userline.length(); j++)
		{
			if(userline[j] != '.' && after)
				grade += (int)userline[j]*1;
			else if(userline[j] == '.')
				after = false;
			else
				grade += (int)userline[j]*0.1;
		}
		marks[i] = grade;
		cout << grade<<endl;
	}
	
	for(int i=0; i<m; i++)
	{
		cout << i+1 << " " << id[i] << " ";
		int Mark = marks[i] * 20;
		GenerateMarks(Mark, n);
		cout << endl;
	}
}
