#include <bits/stdc++.h>
#include <algorithm>


using namespace std;



int main()
{
    int n=100;
    while(n)
    {
        cin>>n;
        vector<string> v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i];
        }
    
        for(int i=1;i<n;i++)
        {
            int j=i-1;
            string cur=v[i];
            while(j>=0 && (cur[0]<v[j][0] || (cur[0]==v[j][0] && cur[1]<v[j][1])))
            {
                v[j+1]=v[j];
                j--;
            }
            v[j+1]=cur;
        }
        
        for(int i=0;i<n;i++)
        {
            cout<<v[i]<<"\n";
        }
        cout<<'\n';
    }
    return 0;
}