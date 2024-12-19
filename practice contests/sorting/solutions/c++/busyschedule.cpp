#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main()
{
    int n=100;
    while(n>0)
    {
        cin>>n;
        vector<vector<string>> v(n);
        for(int i=0;i<n;i++)
        {
            string time,period;
            cin>>time>>period;
            int del=0;
            while(time[del]!=':')
            {
                del++;
            }
            string hour(time.begin(),time.begin()+del);
            string minute(time.begin()+del+1,time.end());
            
            v[i]={hour,minute,period};
        }
        for(int i=0;i<n;i++)
        {
            int ind=i;
            for(int j=i+1;j<n;j++)
            {
                bool isLess=false;
                if (v[j][2] != v[ind][2]) {
                    isLess = (v[j][2] == "a.m."); 
                } else {
                    
                    int hour1 = (v[ind][0] == "12") ? 0 : stoi(v[ind][0]);
                    int hour2 = (v[j][0] == "12") ? 0 : stoi(v[j][0]);

                    if (hour1 != hour2) {
                        isLess = hour2 < hour1;
                    } else {
                        
                        isLess = stoi(v[j][1]) < stoi(v[ind][1]);
                    }
                }
                if (isLess) {
                    ind = j;
                }
            }
            
            swap(v[i],v[ind]);
        }
        
        for(int i=0;i<n;i++)
        {
            cout<<v[i][0]<<":"<<v[i][1]<<" "<<v[i][2]<<"\n";
        }
        cout<<'\n';
    }
    return 0;
}