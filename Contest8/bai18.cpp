#include<bits/stdc++.h>
using namespace std;
int n, m;
int matrix[505][505];
bool isvalid(int i, int j){ 
    return (i >= 0 && j >= 0 && i < n && j < m); 
} 
struct ele{ 
    int x, y; 
}; 
bool isdelim(ele temp) { 
    return (temp.x == -1 && temp.y == -1); 
} 
bool checkall() { 
    for (int i = 0; i < n; i++) 
       for (int j = 0; j < m; j++) 
          if (matrix[i][j] == 1) 
             return true; 
    return false; 
} 

long long solve() { 
    queue<ele> Q; 
    ele temp; 
    long long ans = 0; 
    for (int i = 0; i < n; i++) { 
       for (int j = 0; j < m; j++) 
       { 
            if (matrix[i][j] == 2) 
            { 
                temp.x = i; 
                temp.y = j; 
                Q.push(temp); 
            } 
        } 
    } 
    temp.x = -1; 
    temp.y = -1; 
    Q.push(temp); 
    while (!Q.empty()){ 
        bool flag = false; 
        while (!isdelim(Q.front())){ 
            temp = Q.front(); 
            if (isvalid(temp.x+1, temp.y) && matrix[temp.x+1][temp.y] == 1){ 
                if (!flag) ans++, flag = true;
                matrix[temp.x+1][temp.y] = 2; 
                temp.x++; 
                Q.push(temp); 
                temp.x--;
            } 
            if (isvalid(temp.x-1, temp.y) && matrix[temp.x-1][temp.y] == 1){ 
                if (!flag) ans++, flag = true; 
                matrix[temp.x-1][temp.y] = 2; 
                temp.x--; 
                Q.push(temp);
                temp.x++; 
            } 
            if (isvalid(temp.x, temp.y+1) && matrix[temp.x][temp.y+1] == 1){ 
                if (!flag) ans++, flag = true; 
                matrix[temp.x][temp.y+1] = 2; 
                temp.y++; 
                Q.push(temp);
                temp.y--; 
            } 
            if (isvalid(temp.x, temp.y-1) && matrix[temp.x][temp.y-1] == 1){ 
                if (!flag) ans++, flag = true; 
                matrix[temp.x][temp.y-1] = 2; 
                temp.y--; 
                Q.push(temp);
            } 
  
            Q.pop(); 
        } 
        Q.pop(); 
        if (!Q.empty()){ 
            temp.x = -1; 
            temp.y = -1; 
            Q.push(temp); 
        } 
    } 
    return (checkall())? -1: ans; 
} 
int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> matrix[i][j];
	cout << solve() << endl;
}
