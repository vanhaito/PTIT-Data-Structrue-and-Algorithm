#include<bits/stdc++.h>
using namespace std;
int arr[105], n;
void printArr(){
	for (int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void bubbleSort(){
	int k=1, flag=0;
	for(int i=0; i<n-1;i++){
		for(int j=0; j<n-i-1; j++){
			if (arr[j] > arr[j+1]){
				swap(arr[j], arr[j+1]);
				flag = 1;
			}
		}
		if (flag == 1){
			cout << "Buoc " << k++ <<": ";
			printArr();
			flag = 0;
		}
		
	}
}
int main(){
	cin >> n;
	for (int i=0; i<n; i++) cin >> arr[i];
	bubbleSort();
}
