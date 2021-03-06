// Created by Ziyi Tang
// Floyd Warshall Edge Length
#include <iostream>
using namespace std;
#define MAXN 100
#define REP(i,s,t) for(int i = s; i < t; i++)
const int INF = (int)1E9;
int grid[MAXN][MAXN];
int length[MAXN][MAXN];

int main(){
	// Initialize the grid
	int n,m,tmp;
	cin >> n >> m; // The number of vertices and edges
	REP(i,0,n) REP(j,0,n){
		if(i == j){
			grid[i][j] = 0;
			length[i][j] = 0;
		}
		else{
			grid[i][j] = INF;
			length[i][j] = INF;
		}
	}
	int sta, ter, cost; // Starting point and ending point
	REP(i,0,m){
		cin >> sta >> ter >> cost;
		grid[sta][ter] = cost;
		length[sta][ter] = 1; // There is a path
	}
	REP(k,0,n) REP(i,0,n) REP(j,0,n){
		if(grid[i][k] == INF || grid[k][j] == INF)
			continue;
		if(grid[i][k] + grid[k][j] < grid[i][j]){
			grid[i][j] = grid[i][k] + grid[k][j];
			length[i][j]=length[i][k]+length[k][j];
		}
	}
	REP(i,0,n) {
		REP(j,0,n){
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	REP(i,0,n) {
		REP(j,0,n){
			cout << length[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}