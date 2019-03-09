/*************************************************************************
	> File Name: hello_cgi.cpp
	> Author: waylon
	> Mail: waylon_li@ghotmail.com 
	> Created Time: 2019年03月05日 星期二 16时20分36秒
 ************************************************************************/

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	if (argc == 2){
		cout << "Content-type:text/html\r\n\r\n";
		cout << "<html>\n";
		cout << "<head>\n";
		cout << "<meta charset=\"UTF-8\">\n"; 
		cout << "<title>Hello</title>\n"; 
		cout << "</head>\n"; 
		cout << "<body>\n"; 
		cout << "<meta charset=\"UTF-8\">\n"; 
		cout << "<h2>Welcome</h2>\n";
		cout << "</body>\n";
		cout << "</html>\n";
	}else{
		cout << "Content-type:text/html\r\n\r\n";
		cout << "<html>\n";
		cout << "<head>\n";
		cout << "<meta charset=\"UTF-8\">\n"; 
		cout << "<title>Hello World - 第一个 CGI 程序</title>\n";
		cout << "</head>\n";
		cout << "<body>\n";
		cout << "<meta charset=\"UTF-8\">\n"; 
		cout << "<h2>Hello Waylon! 这是你的第一个 CGI 程序</h2>\n";
		cout << "</body>\n";
		cout << "</html>\n";
	}
	return 0;
}

