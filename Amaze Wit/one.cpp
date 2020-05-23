/*
 * This is my solution to today's AmazeWit question
 * The question states to create a function with the funtion signature
 * vector<string> retrieveMostFrequentlyUsedWords(string& helpText,vector<string> wordsToExclude)
 * {
 * //your code here
 * }
 * which takes 2 inputs (helpText and wordsToExclude). helpText is an email per say and the company wants to
 * see the most frequently used words in the email except the common words which are stored in wordsToExclude.
 * */
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
inline bool sortByVal(const pair<string, int> &a,const pair<string, int> &b){
    return (a.second < b.second);}
vector<string> retrieveMostFrequentlyUsedWords(string& helpText,vector<string> wordsToExclude){
    string s="";
    string w="";
    for(char c : helpText)
    {
        if(c!=' '){
            w+=c;
        } else{
            if(find(wordsToExclude.begin(),wordsToExclude.end(),w)==wordsToExclude.end())
            {
                s+=w+" ";
            }
            w="";
        }
    }
    map<string, int> wordFreq;
    stringstream ss(s);
    string word;
    while (ss >> word)
        wordFreq[word]++;
    map<string, int>:: iterator p;
    map< string ,int> mymap;
    for (p = wordFreq.begin(); p != wordFreq.end(); p++) {
        mymap.insert({p->first, p->second});
    }
    map<string,int> :: iterator it;
    vector<pair<string,int>> str;
    for (it=mymap.begin() ; it!=mymap.end() ; it++)
        str.emplace_back((*it).first,(*it).second);
    sort(str.begin(),str.end(),sortByVal);
    vector<string> val;
    int c=str[str.size()-1].second;
    val.emplace_back(str[str.size()-1].first);
    for(int i=str.size()-2;i>=0;i--)
    {
        if(c==(str[i].second))
            val.emplace_back(str[i].first);
        else
            break;
    }
    return val;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s = "Hello this is just a text this this to me is me is to to to show that this program works fine and is being addressed by me in full";
    vector<string>a(2);
    a.emplace_back("is");
    a.emplace_back("me");
    vector<string> ans =retrieveMostFrequentlyUsedWords(s,a);
    for(auto  s:ans )
        cout << s << endl ;

}

