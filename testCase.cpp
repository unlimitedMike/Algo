#include<vcruntime_new.h>
#include<list>
#include<stdlib.h>
#include<iostream>
#include<time.h>

#include"LRUList.h"
#include "CommListAction.h"

using namespace std;
#define random(x) (rand()%x)

//this test provide that rand() is not truly random
//Is it a wrong test? I can't understand the result

//Test lruList
int main()
{
	clock_t start, end;
	double cost;

	LRUList<int> lruList;
	list<int> normalList;

	int testNum = 10;
	printf("enter operation times to compare lrulist to normal list speed:\n");

	while (cin >> testNum && testNum > 0)
	{
		lruList.clear();
		normalList.clear();

		int curNum = 0;
		Node<int>* pNode = nullptr;
		srand((int)time(0));
		start = clock();

		for (int i = 0; i < testNum; i++)
		{
			curNum = random(1000000);
			
			pNode = lruList.Get(curNum);
			if (pNode != nullptr)
			{
				pNode->val++;
				pNode->val--;
			}
			else lruList.Cache(curNum);
		}

		end = clock();
		cost = end-start;
		printf("LRUList cost: %.2f ms\n", cost);

		bool bFindcurNum = false;
		start = clock();

		for (int i = 0; i < testNum; i++)
		{
			curNum = random(1000000);
			
			for (auto iter = normalList.begin(); iter != normalList.end(); iter++)
			{
				if (curNum == *iter)
				{
					bFindcurNum = true;
					break;
				}
			}
			if (bFindcurNum == false)
				normalList.push_back(curNum);

			bFindcurNum = false;
		}

		end = clock();
		cost = end - start;
		printf("\nnormalList cost: %.2f ms\n", cost);
	}

	return 0;
}