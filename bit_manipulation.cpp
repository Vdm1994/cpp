#include<iostream>

using namespace std;

int toggle(int num, int bit){
	int n = 1;
	n = n << bit-1;
	return num^n;
}

int set(int num, int bit){
	int n = 1;
	n = n << bit-1;
	return num|n;
}

int reset(int num, int bit){
	int n = 1;
	n = n << bit-1;
	n = ~n;
	return num&n;
}

int main(){
	cout << toggle(10, 3) << endl;
	cout << set(10, 3) << endl;
	cout << reset(10, 2) << endl;
	return 0;
}
