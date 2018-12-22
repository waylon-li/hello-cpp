#include <iostream>
#include <csignal>
#include <cstdlib>
#include <unistd.h>

/*
 * signal() 函数信号捕获
 * raise() 生成信号
 */

using namespace std;

void signalHandler(int signum)
{
	cout << "Interrupt signal (" << signum << ") recevied.\n";

	exit(signum);
}

int main()
{
	//注册信号 SIGINT 和信号处理程序
	signal(SIGINT, signalHandler);
	
	int i = 0;
	while(++i){
		cout << "Going to sleep..." << endl;
		
		if(i > 3){
			raise(SIGINT); 
		}	
		sleep(1);
	}

	return 0;
}
