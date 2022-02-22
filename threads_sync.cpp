#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

static int i;
mutex m;
condition_variable cv;

void PrintEven(){
	while(i < 10){
		unique_lock<mutex> lock(m);
		cv.wait(lock, []{return i%2==0;});
		cout << this_thread::get_id() << " "  << i++ << endl;
		cv.notify_one();
	}
}

void PrintOdd(){
	while(i < 10){
		unique_lock<mutex> lock(m);
		cv.wait(lock, []{return i%2==1;});
		cout << this_thread::get_id() << " "  << i++ << endl;
		cv.notify_one();
	}
}

int main(){
	thread t1(PrintEven);
	thread t2(PrintOdd);
	t1.join();t2.join();
	return 0;
}
