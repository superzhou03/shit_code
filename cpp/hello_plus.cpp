#include<iostream>
#include<thread>

int main(){
	// get all CPUcore nums
	int core_nums=std::thread::hardware_concurrency();
	std::cout<<"CPUcore usable nums"<<core_nums<<std::endl;

	// create thread sets
	std::thread thread_set[core_nums];

	for(int i=0;i<core_nums;i++){
		thread_set[i]=std::thread([i](){std::cout<<"hello world from thread"<<i<<std::endl;});
	}

	for(int i=0;i<core_nums;i++){
		thread_set[i].join();
	}

	return 0;
}
