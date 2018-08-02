
#include <bits/stdc++.h>
using namespace std;

void print(vector<char> results)
{
    for(int i=0;i<results.size();i++)
        cout<<results[i];
    cout<<endl;
}

void combine(int pos,vector<char> chars, vector<int> counts ,vector<char> results,int level)
{
	print(results);
    /*if(level == results.size()){
       // print(results);
        return;
    }*/

    for(int i=pos;i<chars.size();i++)
    {
    	
        if(counts[i]==0)
        {
        	continue;
        }
        results[level] = chars[i];
        counts[i]--;
        combine(i,chars,counts,results,level+1);
        counts[i]++;
    }
}

void sortedCombs(string str)
{
    map<char, int> count;
    vector<char> chars;
    vector<int> counts;
    map<char,int>::iterator it;
    for(int i=0;i<str.length();i++)
        count[str[i]]++;
    
    for(it=count.begin();it!=count.end();it++){
        chars.push_back(it->first);
        counts.push_back(it->second);
    }
    vector<char> results(str.length());
    //cout<<results.size()<<endl;
    combine(0,chars,counts,results,0);
}


int main()
{
	string str = "AABC";
	sortedCombs( str );
	return 0;
}
