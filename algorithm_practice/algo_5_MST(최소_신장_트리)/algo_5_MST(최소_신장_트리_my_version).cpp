#include <iostream>
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void initialize(int id[],int n){
    for(int i = 1;i <= n; i++){
        id[i] = i;
    }
    return;
}

int root(int a,int id[]){
    while(id[a] != a){
        a = id[ id[a] ];
    }
    return a;
}

void join(int a, int b, int id[]){
    int root_a = root(a,id);
    int root_b = root(b,id);
    
    if(root_a != root_b){
        id[ root_a ] = id[ root_b ];
    }
    return;
}

ll kruskal(pair< ll , pair< int , int > > p[], int id[], int n){

ll min_weight = 0;
ll a,b,w,root_a,root_b;

for(int i = 1; i <= n ; i++){
    a = p[i].second.first;
    b = p[i].second.second;
    w = p[i].first;
    root_a = root(a,id);
    root_b = root(b,id);
    
    if( root_a != root_b ){
        min_weight += w;
        join(a,b,id);
    }
}
return min_weight;

}

int main(){

int n,m,a,b,w;
cin>>n>>m;

int *id = new int[n+1];
initialize(id,n);

pair< ll, pair< int, int > > p[m+1];

for(int i = 1;i <= m; i++){
    cin>>a>>b>>w;
    p[i].first = w;
    p[i].second.first = a;
    p[i].second.second = b;
}

sort( p , p+(m+1) );

/*for(int i = 1; i <= m ;i++){

cout<<"( "<<p[i].first <<" , "<<"<"<<p[i].second.first<<","<<p[i].second.second<<"> "<<") ";
}*/

ll mini = kruskal( p , id , m);
cout<<mini;
return 0;
}



