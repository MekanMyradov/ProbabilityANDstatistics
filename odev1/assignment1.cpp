#include<bits/stdc++.h>
using namespace std;
vector< pair<int,int> >adjList[33];		// {node, cost}
bool visited[33];
vector<int> path;
#define d 29

void dfs(int s, int cost){
		path.push_back(s);
	static int cnt=0;
	if(s==d){ 				// if it is destination
		cnt++;
		int len = path.size();
		string tmp = "";
		for(int i=0; i<len; i++){
			if(path[i]>=0 && path[i]<=4) { tmp+="A"; tmp+= (path[i]+1 + '0');  tmp+="-"; } 
			if(path[i]>=5 && path[i]<=9) { tmp+='B'; tmp+= (path[i]-4 + '0');  tmp+='-'; } 
			if(path[i]>=10 && path[i]<=14) { tmp+='C'; tmp+= (path[i]-9 + '0');  tmp+='-'; } 
			if(path[i]>=15 && path[i]<=19) { tmp+='D'; tmp+= (path[i]-14 + '0');  tmp+='-'; } 
			if(path[i]>=20 && path[i]<=24) { tmp+='E'; tmp+= (path[i]-19 + '0');  tmp+='-'; } 
			if(path[i]>=25 && path[i]<=29) { tmp+='F'; tmp+= (path[i]-24 + '0');  tmp+='-'; } 
		}
		printf("%d. yol: ",cnt);
		tmp[tmp.length()-1] = '=';
		cout<<tmp<<cost<<"\n";
		
		path.pop_back();
		return;
	}
	visited[s] = true;
	for(int i=0; i<adjList[s].size(); i++){
		int u = adjList[s][i].first;			//node
		int c = adjList[s][i].second; 			//cost
		if(visited[u]==false) dfs(u, cost+c);
	}
	path.pop_back();
	visited[s] = false;
	return;
}


int main(){
string s="A1 B1 1,A1 A2 1,B1 B2 3,B1 C1 3,C1 C2 1,C1 D1 1,D1 E1 1,D1 D2 3,E1 F1 3,E1 E2 1,F1 F2 1,A2 A3 3,A2 B2 2,B2 B3 3,B2 C2 1,C2 C3 1,C2 D2 2,D2 D3 3,D2 E2 2,E2 E3 3,E2 F2 1,F2 F3 2,A3 A4 3,A3 B3 1,B3 B4 1,B3 C3 3,C3 C4 1,C3 D3 1,D3 D4 1,D3 E3 2,E3 E4 1,E3 F3 1,F3 F4 2,A4 A5 1,A4 B4 1,B4 B5 2,B4 C4 3,C4 C5 2,C4 D4 3,D4 D5 3,D4 E4 3,E4 E5 1,E4 F4 1,F4 F5 2,A5 B5 3,B5 C5 3,C5 D5 1,D5 E5 1,E5 F5 3,";

int len = s.length();
int a, b, c;

	for(int i=0; i<len; i++){
		if(s[i]==',') { adjList[a].push_back(make_pair(b,c)); continue; }
		int t;
		if(s[i]=='A') t=-1;	
		if(s[i]=='B') t=4;
		if(s[i]=='C') t=9;
		if(s[i]=='D') t=14;
		if(s[i]=='E') t=19;
		if(s[i]=='F') t=24;
		if(i%8==0) a=t;
		if(i%8==3) b=t;
		if(i%8==1) a += (s[i] - '0');
		if(i%8==4) b += (s[i] - '0');
		if(i%8==6) c = (s[i] - '0'); 
	}

memset(visited, false, sizeof visited);
	dfs(0, 0);

	return 0;
}
