#include <mpi.h>
#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
int main(int argc, char** argv) {
	MPI_Init(NULL, NULL);
	int world_rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
	int world_size;
	MPI_Comm_size(MPI_COMM_WORLD, &world_size);
	int number;
	if(world_rank==0){
		srand(time(NULL));
		number=rand();
		cout<<"process "<<world_rank<<" send a random number "<<number<<" to process 0"<<endl;
		MPI_Send(&number,1,MPI_INT,1,0,MPI_COMM_WORLD);
	}else{
		MPI_Recv(&number,1,MPI_INT,world_rank-1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		cout<<"process "<<world_rank<<" recieved "<<number<<" from process "<< world_rank-1 <<endl;
		number+=1;
		if(world_rank<world_size-1){
			MPI_Send(&number,1,MPI_INT,world_rank+1,0,MPI_COMM_WORLD);
		}else{
			MPI_Send(&number,1,MPI_INT,0,0,MPI_COMM_WORLD);
		}
	}
	if(world_rank==0){
		MPI_Recv(&number,1,MPI_INT,world_size-1,0,MPI_COMM_WORLD,MPI_STATUS_IGNORE);
		cout<<"process "<<world_rank<<" reciever number "<<number<<" from process "<<world_size-1<<endl;
	}
	MPI_Bcast(&number,1,MPI_INT,0,MPI_COMM_WORLD);
	if(world_rank!=0){
		cout<<"process "<<world_rank<<" recieved number "<<number<<" the broacast from process 0"<<endl;
	}

	MPI_Finalize();
}
