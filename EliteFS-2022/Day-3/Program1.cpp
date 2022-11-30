/*
<------------- Question ------------------>
There are N computers in a network, all the computers are connected as tree 
structure. And one new connection is added in the Network. The computers in 
the network are identified with their IDs, the IDs are numbered between 1 to N.

The connections in the network is given as coonection[i] = [comp-A, comp-B], 
there is a connection between comp-A and comp-B.

Your task is to remove a connection in the network and print it, so that 
all the computers are connected as tree structure. If there are multiple 
options to remove, remove the connection that occurs last in the input.


Input Format:
-------------
Line-1: Two space separated integers N, number of computers.
Next N lines: Two space separated integers, comp-A & comp-B.

Output Format:
--------------
Print the connection which is removed.


Sample Input-1:
---------------
6
1 2
3 4
3 6
4 5
5 6
2 3

Sample Output-1:
---------------
5 6


Sample Input-2:
---------------
4
1 2
2 3
3 4
2 4

Sample Output-2:
---------------
2 4

<----------------------------------------->

*/

#include <bits/stdc++.h>
using namespace std;

int findPar(int u,vector<int> &parent){
    if(u == parent[u]) return u;
    return parent[u] = findPar(parent[u],parent);
}

void uunion(int u,int v,vector<int> &parent){
    parent[u] = v;
}


int main(){
    int n;cin>>n;
    vector<int> parent(n+1,0);
    for(int i=0;i<n+1;i++) parent[i] = i;
    int a,b;
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        int paru = findPar(u,parent);
        int parv = findPar(v,parent);
        
        if(paru == parv){
            a = u;
            b = v;
        }
        else{
            uunion(paru,parv,parent);
        }
    }
    cout<<a<<" "<<b<<endl;
}