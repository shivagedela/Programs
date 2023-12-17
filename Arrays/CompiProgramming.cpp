#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	getline(cin, s);
	cout << "String is - " << s << "\n";
	
	int n;
	cin >> n;
	/*while (cin >> n) {
		printf("%d", n);
	}*/
	
	for (int b = 0; b < (1<<n); b++) {
		vector<int> subset;
		for (int i = 0; i < n; i++) {
			if (b&(1<<i)) subset.push_back(i);
		}
		
		for (int i = 0; i < subset.size(); i++)
			cout << i << " ";
		cout << endl;
	}
	
	return 0;
}
