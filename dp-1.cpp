#include <iostream>

using namespace std;

// Using recursion without DP
int f(int i){
	int sum = 0;
	if(i < 0)
		return 1;
	if(i == 1 || i == 0)
		return 2;
	for(int k=0; k< i; k++) 
		sum += 2*f(k)*(k-1);
	return sum
}

// With recursion using DP
int f_DP(int i){
	int arr[i];
	int sum = 0;
	arr[0] = 2; arr[1] = 2;
	for(int k=2; k<i; k++){
		T[k] = 0;
		for(int j=1; j<k; j++){
			T[k] += 2*T[j]*T[j-1];
		}
	}
	return T[i];

	//--
	//
	T[0] = T[1] = 2;
	T[2] = 2 * T[1] * T[0];
	for(int k=3; k<i; k++)
		T[k] = T[k-1] + 2 * T[k-1] * T[k-2];
	return T[i];
}

int main(){

}
