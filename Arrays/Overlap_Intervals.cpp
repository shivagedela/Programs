#include<bits/stdc++.h>
using namespace std;

/*** Problem - Given group of intervals, merge overlapping intervals and show output ***/

// Efficient Approach - Sort based on start of intervals and then merge intervals 
vector<vector<int>> bestWay(vector<vector<int>> vec2D, int n)
{
    sort(vec2D.begin(), vec2D.end());   //sort intervals based on start
    vector<vector<int>> solVector;
    vector<int> interval;

    int i = 0, start = vec2D[0][0], end = vec2D[0][1];
    for (i = 0; i < n-1; i++)
    {
        if (end >= vec2D[i+1][0]) //if end of curr interval >= start of next interval
            end = max(end, vec2D[i+1][1]);  //then Merge intervals i.e., update end interval of curr
        else
        {
            interval.push_back(start);
            interval.push_back(end);
            solVector.push_back(interval); //add the new interval into solution
            interval.clear();
            start = vec2D[i+1][0];
            end = vec2D[i+1][1];
        }
    }
    
    //add the last interval
    interval.push_back(start);
    interval.push_back(end);
    solVector.push_back(interval);
    return solVector;
//Time Complexity: O(NlogN) - sorting of N elements
//Space Complexity: O(1) - No extra space used
}

int main()
{
    vector<vector<int>> vec2D = {{2,4},{1,3},{7,9},{11,13},{6,10}};
    int vec2D_size = vec2D.size();

    vector<vector<int>> sol_BF = bestWay(vec2D, vec2D_size);
    for (int i = 0; i < sol_BF.size(); i++)
    {
        cout << "{ ";
        for (int j = 0; j < sol_BF[i].size(); j++)
            cout << sol_BF[i][j] << " ";
        cout << "}\n";
    }

    return 0;
}