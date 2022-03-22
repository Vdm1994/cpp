#include <iostream>

#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(){


	vector<int> vec;
	vec.push_back(1);

	vector<int> v1(3, 100); // (size, value-at-each-idx)
	v1[0] = 1999;
	v1[1] = 345;
	v1[2] = 9;
	sort(v1.begin(), v1.end());
	sort(v1.begin(), v1.end(), greater<int>());

	for(int i: v1)
		cout << i << endl;

	// -----------------
	cout << endl;

	queue<int> q;
	q.push(10);
	q.push(20);
	
	while(!q.empty()){
		cout << q.front() << endl; // IMP < front in queue
		q.pop();
	}

	priority_queue<int, vector<int>, greater<int> > pq; // for min heap priority_queue<int, vector<int>, greater<int> >
	pq.push(100);
	pq.push(3);
	pq.push(10);

	cout << endl;

	while(!pq.empty()){
		cout << pq.top() << endl; // IMP < top in piority queue
		pq.pop();
	}
	// ----------------
	
	stack<int> stk;
	stk.push(10);stk.push(20);stk.push(30);
	while(!stk.empty()){
		cout << stk.top() << " ";
		stk.pop();
	}
	cout << endl << endl;

	// ------------
	// Sets 1
	//
	set<int> s; //- No duplicates allowed and stored in sequence (ascending by default)
	s.insert(2000);
	s.insert(3000);
	s.insert(1000);
	s.insert(1000);

	set<int>::iterator it;
	for(it = s.begin(); it != s.end(); it++){
		cout << *it << " ";
	}
	cout << endl << endl;

	// Sets 2
	//
	set<int, greater<int> > s1; // To store in descending 
	s1.insert(2000);
	s1.insert(3000);
	s1.insert(1000);
	s1.insert(1000);

	set<int, greater<int> >::iterator it1;
	for(it1 = s1.begin(); it1 != s1.end(); it1++){
		cout << *it1 << " ";
	}
	cout << endl << endl;


	/* -- pending
	// Unordered Sets 1
	//
	unordered_set<int> s2;
	s2.insert(2); s2.insert(4); s2.insert(-1); s2.insert(2);	
	unordered_set<int>::iterator it2;
	for(it2 = s2.begin(); it2 != s2.end(); it2++)
		cout << *it2 << " ";
	cout << endl << endl;

	// Unordered Sets 2
	//
	unordered_set<int, greater<int>> s3;
	s3.insert(3); s3.insert(5); s3.insert(7); s3.insert(9);
	unordered_set<int, greater<int>>::iterator it3;
	for(it3 = s3.begin(); it3 != s3.end(); it3++)
		cout << *it3 << " ";
	cout << endl << endl;	
	*/

	// -------------
	// Maps
	
	map<int, int> mp;
	mp[1] = 10;
	mp[2] = 100;
	if(mp.find(2) != mp.end()){
		cout << "Found 2:" << mp[2] << endl;
	}
	if(mp.find(3) != mp.end()){
		cout << "Found 3:" << mp[3] << endl;
	}
	cout << endl << endl;	

	unordered_map<int, int> mp1;
	mp1[1] = 10;
	mp1[2] = 100;
	if(mp1.find(2) != mp1.end()){
		cout << "Found 2:" << mp1[2] << endl;
	}
	if(mp1.find(3) != mp1.end()){
		cout << "Found 3:" << mp1[3] << endl;
	}
}
