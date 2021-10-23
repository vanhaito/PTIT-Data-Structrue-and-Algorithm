#include<bits/stdc++.h>
using namespace std;
int n, m, s, e;
int matrix[1005][1005];
bool visited[1005];
int forward_point[1005];
void init(){
	cin >> n >> m >> s >> e;
	memset(matrix, 0, sizeof(matrix));
	memset(forward_point, 0, sizeof(forward_point));
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= m; i++){
			int x, y; cin >> x >> y;
			matrix[x][y] = 1;
			matrix[y][x] = 1;
	}
}
void DFS(int u)
{
    stack<int> st;
    st.push(u);
    visited[u] = true;
    while(!st.empty())
    {
        int s = st.top();
        st.pop();
        for(int t = 1; t <= n; t++)
        {
            if(visited[t] == false && matrix[s][t] == 1)
            {
                forward_point[t] = s;
                visited[t] = true;
                st.push(s);
                st.push(t);
                break;
            }
        }
    }
}

void PrintPath(int s, int e)
{
    if(forward_point[e] == 0)
        cout << "-1" ;
    else
    {
    	vector<int> res;
        res.push_back(e);
        int u = forward_point[e];
        while(u != s)
        {
            res.push_back(u);
            u = forward_point[u];
        }
        res.push_back(s);
        for (int i = res.size()-1; i >= 0; i--)
        	cout << res[i] << " ";
    }
}

int main(){
	int T; cin >> T;
	while (T--){
		init();
		DFS(s);
		PrintPath(s, e);
		cout << endl;
	}
}


