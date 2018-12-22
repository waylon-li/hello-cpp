#### linux 下c++ 多线程编程

##### 创建线程
创建一个 POSIX 线程：
```
#include <pthread.h>
pthread_create (thread, attr, start_routine, arg)
```
pthread_create 创建一个新的线程，并让它可执行。
参数的说明：

- thread	指向线程标识符指针。
- attr	一个不透明的属性对象，可以被用来设置线程属性。您可以指定线程属性对象，也可以使用默认值 NULL。
- start_routine	线程运行函数起始地址，一旦线程被创建就会执行。
- arg	运行函数的参数。它必须通过把引用作为指针强制转换为 void 类型进行传递。如果没有传递参数，则使用 NULL。

注：创建线程成功时，函数返回 0，若返回值不为 0 则说明创建线程失败。

##### 终止线程
终止一个 POSIX 线程：
```
#include <pthread.h>
pthread_exit (status)
```
注：pthread_exit 用于显式地退出一个线程。通常情况下，pthread_exit() 函数是在线程完成工作后无需继续存在时被调用。如果 main() 是在它所创建的线程结束之前结束，并通过 pthread_exit() 退出，那么主线程退出后其他线程将继续执行。否则，创建的线程将在 main() 结束时自动被终止。

##### 连接和分离线程
我们可以使用以下两个函数来连接或分离线程：
```
pthread_join (threadid, status) 
pthread_detach (threadid)
```
注：pthread_join() 子程序阻碍调用程序，直到指定的 threadid 线程终止为止。当创建一个线程时，它的某个属性会定义它是否是可连接的（joinable）或可分离的（detached）。只有创建时定义为可连接的线程才可以被连接。如果线程创建时被定义为可分离的，则它永远也不能被连接。
