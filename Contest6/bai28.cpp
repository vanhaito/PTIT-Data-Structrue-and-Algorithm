#include<bits/stdc++.h>
using namespace std;
int arr[105], n;
void printArr(int k){
	for (int i=0; i<k; i++)
		cout << arr[i] << " ";
	cout << endl;
}
void insertionSort(){
	int i, j, key;
	int k=0, t=0;
	cout << "Buoc " << t++ <<": ";
	cout << arr[0] << endl;
	for (i=1; i<n; i++){
		key = arr[i];
		j = i-1;
		while (j>=0 && arr[j]>key){
			swap(arr[j], arr[j+1]);
			j -= 1;
		}
		k++;
		arr[j+1] = key;
		cout << "Buoc " << t++ <<": ";
		printArr(k+1);
	}
}
int main(){
	cin >> n;
	for (int i=0; i<n; i++) cin >> arr[i];
	insertionSort();
}
