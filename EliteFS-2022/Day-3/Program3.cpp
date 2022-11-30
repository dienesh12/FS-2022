/*
<------------- Question ------------------>
Prabhath is working on words.  He used to take out every letter that was repeated 
in the word. 
A word W is given to Prabhath. His objective is to eliminate every duplicate 
letter from W such that the resultant word R contains every unique letter from W
and did not contain any duplicate letters. 
And R should be at the top of the dictionary order.

NOTE:
-----
He is not allowed to shuffle the relative order of the letters of the word W to
form the word R.

Input Format:
-------------
A String, the word W.

Output Format:
--------------
Print a String, resultant word R.


Sample Input-1:
---------------
cbadccb

Sample Output-1:
----------------
adcb


Sample Input-2:
---------------
silicosis

Sample Output-2:
----------------
ilcos

<----------------------------------------->

*/

#include <bits/stdc++.h>
using namespace std;

string StackToString(stack<char> st){
    string ans = "";

    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    
    return ans;
}

string solve(int n,string s,map<char,int> mp){
    stack<char> st;
    st.push(s[0]);
    vector<int> cnt(26,0);
    cnt[s[0]-'a']++;

    for(int i=1;i<n;i++){
        if(cnt[s[i]-'a']) continue;

        if(s[i] < st.top() &&  mp[st.top()] >= i){
            while(!st.empty() && s[i] < st.top() && mp[st.top()] > i){
                cnt[st.top()-'a']--;
                st.pop();
            }
        }

        st.push(s[i]);
        cnt[st.top()-'a']++;
    }

    return StackToString(st);
}


int main(){
    string s;cin>>s;
    int n = s.length();
    map<char,int> mp;

    for(int i=0;i<s.length();i++){
        mp[s[i]] = i;
    }

    string ans = solve(n,s,mp);

    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}