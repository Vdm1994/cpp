#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void printVector(vector<int> vec){
	for(int i=0; i<vec.size(); i++){
		cout << vec[i] << " ";
	}
	cout <<endl;
}

vector<int> BubbleSort(vector<int> vec){
	int max, idx; bool mod;
	for(int i=0; i<vec.size(); i++){
		max = INT_MIN;
		mod = false;
		idx = -1;
		for(int j=0;j<vec.size()-i;j++){
			if(max < vec[j]){
				idx = j;
				max = vec[j];
				mod = true;
			}
		}
		if(idx != -1){
			int temp = vec[vec.size()-i-1];
			vec[vec.size()-i-1] = vec[idx];
			vec[idx] = temp;
		}
		if(!mod)
			return vec;
	}
	return vec;
}

vector<int> SelectionSort(vector<int> vec){
	int min, idx; bool mod;
	for(int i=0; i<vec.size(); i++){
		min = INT_MAX;
		mod = false;
		idx = -1;
		for(int j=i; j<vec.size(); j++){
			if(min > vec[j]){
				min = vec[j];
				idx = j;
				mod = true;
			}
		}
		if (!mod)
			return vec;
		if(idx != -1){
			int temp = vec[i];
			vec[i] = vec[idx];
			vec[idx] = temp;
		}
	}
	return vec;
}

vector<int> InsertionSort(vector<int> vec){
	for(int i=1; i<vec.size(); i++){
		int val = vec[i];
		int idx = i;
		int j = i;
		while(j > 0 && val < vec[j-1]){
			vec[j] = vec[j-1];
			idx = j-1;
			j--;
		}	
		vec[idx] = val;
	}
	return vec;
}

vector<int> HeapSort(vector<int> vec){
	return vec;
}

void Merge(vector<int>& vec, int start, int mid, int end){
	int i,j,k;
	vector<int> left;
	vector<int> right;
	for(int i=start; i<=mid; i++)
		left.push_back(vec[i]);
	for(int i=mid+1; i<=end; i++)
		right.push_back(vec[i]);
	/*
	cout << "left: ";
	printVector(left);
	cout << "right: ";
	printVector(right);
	*/
	i = 0, j = 0;
	while(i < left.size() && j < right.size()){
		if(left[i] > right[j]){
			vec[start] = right[j];
			j++;
		}else{
			vec[start] = left[i];
			i++;
		}
		start++;
	}
	while(i < left.size()){
		vec[start] = left[i];
		i++;
		start++;
	}
	while(j < right.size()){
		vec[start] = right[j];
		j++;
		start++;
	}
	//cout << "sorted: ";
	//printVector(vec);
}

vector<int> Mergesort(vector<int>& vec, int start, int end){
	if(start < end){
		int mid = (start+end)/2;
		Mergesort(vec, start, mid);
		Mergesort(vec, mid+1, end);
		Merge(vec, start, mid, end);
	}
	return vec;
}

int pivot(vector<int> &vec,int start, int end){
	int p = vec[end];
        int i = start;
	int j = end-1;
	while(i <= j && j >=0 && i <= end){
		if(vec[i]<p)
			i++;
		else if(vec[j]>p)
			j--;
		else{
			int temp = vec[i];
			vec[i] = vec[j];
			vec[j] = temp;
		}
	}
	int temp = vec[i];
	vec[i] = vec[end];
	vec[end] = temp;
	return i;
}


vector<int> QuickSort(vector<int> &vec,int start, int end){
	if(start < end){
		int pivotIdx = pivot(vec, start, end);
		QuickSort(vec, start, pivotIdx-1);
		QuickSort(vec, pivotIdx+1, end);
	}
	return vec;
}

int main(){
	vector<int> v;
	cout << "Give -1 to terminate" << endl;
	cout << "Input Vector:" << endl;
	int i;
	cin >> i;
	while(i != -1){
		v.push_back(i);
		cin >> i;	
	}
		
	cout << "Input Vector: " <<endl;
	printVector(v);
	cout << "----" << endl;

 	cout <<"BubbleSort: " << endl;
	printVector(BubbleSort(v));
	cout << "----" << endl;

	cout <<"SelectionSort: "<< endl;
	printVector(SelectionSort(v));
	cout << "----" << endl;

	cout <<"InsertionSort: "<< endl;
	printVector(InsertionSort(v));
	cout << "----" << endl;

	cout <<"Mergesort: "<< endl;
	printVector(Mergesort(v, 0, v.size()-1)); // V.IMP step here -> size-1 to pass took 1 hr to resolve 
	cout << "----" << endl;

	cout <<"QuickSort: "<< endl;
	printVector(QuickSort(v, 0, v.size()-1));
	cout << "----" << endl;

	cout <<"HeapSort: "<< endl;
	printVector(HeapSort(v, 0, v.size()-1));
	cout << "----" << endl;


	return 0;
}
