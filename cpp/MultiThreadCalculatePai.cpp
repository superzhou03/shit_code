// Author: superzhou03
// Created time: 2023-12-07
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>

void* calculate_pi(void* arg)
{
   int circle_points=0;
   int i;
   double pi;
   int intervals=*((int*)arg);  //线程函数参数用于控制循环次数
   unsigned seed=time(NULL);

   for(i=0;i<intervals*intervals;i++)
   {
      double rand_x=(double)rand_r(&seed)/RAND_MAX;     // rand()函数不适用于并行计算
      double rand_y=(double)rand_r(&seed)/RAND_MAX;
      
      if((rand_x*rand_x+rand_y*rand_y)<=1)
      {
           circle_points++;
      }
   }
   
   pi= (4.0*circle_points)/ i;
   
   printf("Cirlce points:%d, total_points:%d, the estimated PI is %lf\n",circle_points, i, pi);
   
   pthread_exit(0);
}

int main()
{
   clock_t start,delta;
   double time_used;   
   start=clock();
   
   pthread_t calculate_pi_threads[10]; //用于存放10个线程函数的id
   int args[10];  //用于存放10个线程函数的参数
   
   for(int i=0; i<10;i++)
   {
      args[i]=1000*(i+1);
      pthread_create(calculate_pi_threads+i, NULL, calculate_pi, args+i);
   }
   
   for(int i=0;i<10;i++)
   {
      pthread_join(calculate_pi_threads[i],NULL);
   }
  
   delta=clock()-start;
   printf("The time taken: %lf seconds\n",(double)delta/CLOCKS_PER_SEC);
   return 0;
}

