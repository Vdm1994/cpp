#include <bits/stdc++.h>
using namespace std;

void IdentifyEndianess(){
	unsigned int i = 1;
	 char *c = (char*)&i;
	 if (*c)
		 cout<<"Little endian"<<endl;
	 else
		 cout<<"Big endian"<<endl;
}

/*
 * To arrange in below way
 * i = xxxx xxxx   xxxx xxxx   xxxx xxxx    xxxx xxxx
 *	leftmost   leftmiddle  rightmiddle  rightmost
 *
 */
int SwapEndianess(int i){
	int leftmost;
	int leftmiddle;
	int rightmiddle;
	int rightmost;

	/*
	 *putting righmost from input in leftmost and so on
	 *
	 */
	leftmost = (i & 0x000000FF) >> 0;
	leftmiddle = (i & 0x0000FF00) >> 8;
	rightmiddle = (i & 0x00FF0000) >> 16;
	rightmost = (i & 0xFF000000) >> 24;

	leftmost <<= 24; // this will be at end start now
	leftmiddle <<= 16;
	rightmiddle <<= 8;
	rightmost <<= 0;

	return leftmost | leftmiddle | rightmiddle | rightmost;
}

int main() 
{
       /* Other logic that i gave 	
    if(i&0x0f){
	cout<<"Little endian"<<endl;
    }else{
	cout<<"Big endian"<<endl;
    }
    */

	IdentifyEndianess();
	cout << SwapEndianess(1) << endl;
	cout << SwapEndianess(16777216) << endl;
	 return 0;
} 
