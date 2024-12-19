#include <iostream>
#include <queue>
#include <bits/stdc++.h>



using namespace std;

int main()
{
    int n;cin>>n;cin.ignore();
    queue<char> q;
    
    while(n--)
    {
        string str;
        getline(cin,str);
        transform(str.begin(), str.end(), str.begin(),::tolower);
        for(int i='a';i<='z';i++)
        {
            if(find(str.begin(),str.end(),i)==str.end())
            {
                q.push(i);
            }
        }
        if(q.empty())
        {
            cout<<"pangram"<<endl;
        }
        else
        {
           cout<<"missing ";
           while(!q.empty())
           {
               cout<<q.front();
               q.pop();
           }
           cout<<'\n';
        }
    }
    
}