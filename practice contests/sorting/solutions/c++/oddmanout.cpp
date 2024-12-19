#include <bits/stdc++.h>


using namespace std;

int main()
{
    int t;
    cin>>t;
    int k=0;
    while(k<t)
    {
        int g;cin>>g;
        vector<long long> v(g);
        for(int i=0;i<g;i++)
        {
            cin>>v[i];
        }
        
        for(int i=0;i<g;i++)
        {
            int ind=i;
            for(int j=i+1;j<g;j++)
            {
                if(v[j]<v[ind])
                {
                    ind=j;
                }
            }
            swap(v[ind],v[i]);
        }
        
        int i=0;
        while(i<g && v[i]==v[i+1])
        {
            i=i+2;
        }
        cout<<"Case #"<<k+1<<": "<<v[i]<<endl;
    k++;}
    return 0;
}