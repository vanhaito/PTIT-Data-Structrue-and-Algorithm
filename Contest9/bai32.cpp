#include <bits/stdc++.h> 
using namespace std; 
int isSafe(int n, int m, int M[][505], int row, int col, bool visited[][505]){ 
    return (row >= 0) && (row < n) && (col >= 0) && (col < m) && (M[row][col] && !visited[row][col]); 
} 

void DFS(int n, int m, int M[][505], int row, int col, bool visited[][505]){ 
    static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
    static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 }; 
    visited[row][col] = true; 
    for (int k = 0; k < 8; ++k) 
        if (isSafe(n, m, M, row + rowNbr[k], col + colNbr[k], visited)) 
            DFS(n, m, M, row + rowNbr[k], col + colNbr[k], visited); 
} 
int countIslands(int n, int m, int M[][505]){ 
    bool visited[505][505]; 
    memset(visited, 0, sizeof(visited));  
    int count = 0; 
    for (int i = 0; i < n; ++i) 
        for (int j = 0; j < m; ++j) 
            if (M[i][j] && !visited[i][j]) { 
                DFS(n, m, M, i, j, visited);  
                ++count; 
            } 
  
    return count; 
}
int main(){ 
  int t; cin >> t;
  while (t--){
  	int n, m, matrix[505][505];
  	cin >> n >> m;
  	for (int i=0; i<n; i++)
  		for (int j=0; j<m; j++)
  			cin >> matrix[i][j];
  	cout << countIslands(n , m, matrix) << endl;
  }
} 
