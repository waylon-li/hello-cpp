#include <iostream>
#include <cstdlib>
#include <pthread.h>
#include <unistd.h>

using namespace std;

#define NUM_THREADS     2
void *PrintHello(void *threadid)
{  
	// 对传入的参数进行强制类型转换，由无类型指针变为整形数指针，然后再读取
	int tid = *((int*)threadid);
	cout << "Hello Runoob! 线程 ID, " << tid << endl;
	int i = 0;
	for(;;){
		cout << "loop 线程 ID, " << tid << endl;
		if(i > 3)
			break;
		sleep(1);
		i++;
	}
	pthread_exit(NULL);
}

int main ()
{
	pthread_t threads[NUM_THREADS];
	pthread_attr_t attr;
	int indexes[NUM_THREADS];// 用数组来保存i的值
	int rc;
	int i;
	void *status;

	// 初始化并设置线程为可连接的（joinable）
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

	for( i=0; i < NUM_THREADS; i++ ){      
		cout << "main() : 创建线程, " << i << endl;
		indexes[i] = i; //先保存i的值
		// 传入的时候必须强制转换为void* 类型，即无类型指针        
		rc = pthread_create(&threads[i], &attr, 
		PrintHello, (void *)&(indexes[i]));
		if (rc){
			cout << "Error:无法创建线程," << rc << endl;
			exit(-1);
		}
	}

	// 删除属性，并等待其他线程
	pthread_attr_destroy(&attr);
	for( i=0; i < NUM_THREADS; i++ ){
		rc = pthread_join(threads[i], &status);
		if (rc){
			cout << "Error:unable to join," << rc << endl;
			exit(-1);
		}
		cout << "Main: completed thread id :" << i ;
		cout << "  exiting with status :" << status << endl;
	}

	cout << "Main: program exiting." << endl;
	pthread_exit(NULL);
}
