#include<bits/stdc++.h>
using namespace std;
int arr[105], n;
void printArr(){
	for (int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void selectionSort(){
	int min, k=1;
	for (int i=0; i<n-1; i++){
		min = i;
		for(int j=i+1; j<n; j++){
			if (arr[j] < arr[min])
				min = j;
		}
		swap(arr[min], arr[i]);
		cout << "Buoc " << k++ <<": ";
		printArr();
	}
}
int main(){
	cin >> n;
	for (int i=0; i<n; i++) cin >> arr[i];
	selectionSort();
}
