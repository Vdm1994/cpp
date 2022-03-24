#include <iostream>
#include <fstream>

using namespace std;

int main(){

	ofstream fout;
	string hello;

	fout.open("test.txt");

	while(fout){
		//getline(cin, hello);
		cin >> hello;
		if(hello == "-1")
			break;
		fout << hello << endl;
	}
	fout.close();

	fstream fin;
	fin.open("test.txt");

	while(fin){
		//getline(fin, hello);
		fin >> hello;
		cout << hello << endl;
	}
	fin.close();
	return 0;
}
