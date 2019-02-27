/*************************************************************************
	> File Name: array_k_th.cpp
	> Author: waylon
	> Mail: waylon_li@ghotmail.com 
	> Created Time: 2019年02月27日 星期三 20时22分01秒
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <ctime>
//#define DEBUG
 
#define MINV(a, b) ((a) <= (b) ? (a) : (b))
#define MAXV(a, b) ((a) >= (b) ? (a) : (b))
#define MAX_N 10000000
#define MAX_VAL 10000
using namespace std;
 
int array_1[MAX_N] = {0, 12, 17, 19, 44, 47, 52, 52, 57, 90};
int array_2[MAX_N] = {14, 20, 38, 47, 76, 77, 77, 82, 89, 89};
int n, m, k;
 
int getKth(int s1, int e1, int s2, int e2, int k)
{
	int mid_1 = (s1 + e1) / 2;
	int mid_2 = (s2 + e2) / 2;
	
	int pLen_1 = mid_1 - s1 + 1;
	int pLen_2 = mid_2 - s2 + 1;
 
	if(s1 > e1) pLen_1 = 0;
	if(s2 > e2) pLen_2 = 0;
	int pSum = pLen_1 + pLen_2;
 
	if(k < pSum)
	{
		
		if(pLen_2 != 0 && (pLen_1 == 0 || array_1[mid_1] <= array_2[mid_2]))
			return getKth(s1, e1, s2, mid_2 - 1, k);
		else
			return getKth(s1, mid_1 - 1, s2, e2, k);
	}
	else
	{
		if(k == pSum)
		{
			if(pLen_1 == 0) return array_2[mid_2];
			else if(pLen_2 == 0) return array_1[mid_1];
		}
 
		if(pLen_1 != 0 && (pLen_2 == 0 || array_1[mid_1] <= array_2[mid_2]))
			return getKth(mid_1 + 1, e1, s2, e2, k - pLen_1);
		else 
			return getKth(s1, e1, mid_2 + 1, e2, k - pLen_2);
	}
}
 
int main()
{
	int i, j;
	
	// testing cases num: 1000
	int caseNum = 1;
	
	while(caseNum--)
	{
		//getchar();
		// create m, n, k
		srand(time(NULL));
		m = rand() % MAX_N + 1;
		n = rand() % MAX_N + 1;
		k = rand() % (m + n) + 1;
		
		// create array_1 and sort it
		for(i = 0; i < m; i++)
			array_1[i] = rand() % MAX_VAL;
		sort(array_1, array_1 + m);
		
		// output array_1
#ifdef DEBUG
		cout<<"k:"<<k<<endl;
		cout<<"array_1:"<<endl;
		for(i = 0; i < m; i++)
			cout<<array_1[i]<<" ";
		cout<<endl;
#endif		
		// create array_2 and sort it
		for(i = 0; i < n; i++)
			array_2[i] = rand() % MAX_VAL;
		sort(array_2, array_2 + n);
		
		// output array_2
#ifdef DEBUG
		cout<<"array_2:"<<endl;
		for(i = 0; i < n; i++)
			cout<<array_2[i]<<" ";
		cout<<endl;
#endif
		// get the kth num
		int kthValue = getKth(0, m - 1, 0, n - 1, k);
#ifdef DEBUG
		cout<<"The kth value by my algorithm: "<<kthValue<<endl;
#endif
		// verify the result
		int idex = 0;
		int realValue;
		i = j = 0;
		while(i < m || j < n)
		{
			if(j == n || (i != m && array_1[i] <= array_2[j]))
			{
				idex++;
				if(idex == k)
				{
					realValue = array_1[i];
					break;
				}
				i++;
				continue;
			}
			if(i == m || (j != n && array_2[j] <= array_1[i]))
			{
				idex++;
				if(idex == k)
				{
					realValue = array_2[j];
					break;
				}
				j++;
			}
		}
#ifdef DEBUG
		cout<<"The real kth value is: "<<realValue<<endl;
#endif
		if(realValue == kthValue) cout<<"Result: Correct"<<endl;
		else
		{
			cout<<"k:"<<k<<endl;
			cout<<"array_1:"<<endl;
			for(i = 0; i < m; i++)
				cout<<array_1[i]<<" ";
			cout<<endl;
			cout<<"array_2:"<<endl;
			for(i = 0; i < n; i++)
				cout<<array_2[i]<<" ";
			cout<<endl;
			cout<<"The kth value by my algorithm: "<<kthValue<<endl;
			cout<<"The real kth value is: "<<realValue<<endl;
			cout<<"Resutl: Wrong"<<endl;
 
			break;
		}
		
#ifdef DEBUG
		cout<<endl<<endl;
#endif
		
		k++;	
	}
	return 0;	
}
 

