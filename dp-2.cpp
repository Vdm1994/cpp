// kadane's algo
//
int kadane(vector<int> v){

	int max_so_far = INT_MIN;
	int max_here = 0;

	for(int i=0; i<v.size(); i++){
		max_here += v[i];
	        if(max_here < 0)
			max_here = 0;
		if(max_here > max_so_far)
			max_so_far = max_here;	
	}
	return max_so_far;
}
