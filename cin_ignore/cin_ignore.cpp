/*************************************************************************
	> File Name: cin_ignore.cpp
	> Author: waylon
	> Mail: waylon_li@ghotmail.com 
	> Created Time: 2018年12月23日 星期日 12时39分12秒
 ************************************************************************/
/*
 * cin.ignore(a,ch)方法是从输入流（cin）中提取字符，提取的字符被忽略（ignore），不被使用。每抛弃一个字符，它都要计数和比较字符：如果计数值达到a或者被抛弃的字符是ch，则cin.ignore()函数执行终止；否则，它继续等待。它的一个常用功能就是用来清除以回车结束的输入缓冲区的内容，消除上一次输入对下一次输入的影响。
 *
 * 如果cin.ignore()不给参数，则默认参数为cin.ignore(1,EOF)，即把EOF前的1个字符清掉，没有遇到EOF就清掉一个字符然后结束，会导致不正确的结果.如果在地址那里输入bcdabcd那么此时流里面剩的是bcd\n,此时cin.ignore();吃掉的就是b了，这是流里还剩下cd\n直接交给cin.getline(str3,30);应为有个\n所以这里getline就直接返回 
 */

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
	char str1[30],str2[30],str3[30];  
	cout << "请输入你的姓名：";  
	cin >> str1;  
	cout << "请输入你的住址：";  
	cin.ignore();
	//cin.getline 函数会一次读取多个字符(包括空白字符）。它以指定的地址为存放第一个读取的字符的位置，依次向后存放读取的字符，直到读满N-1个，或者遇到指定的结束符为止。若不指定结束符，则默认结束符为'\0'
	cin.getline(str2,30,'a');  
	cout << "请输入你的籍贯：";  
	cin.ignore();  
	cin.getline(str3,30);  
	cout << str3;

	return 0;
}


