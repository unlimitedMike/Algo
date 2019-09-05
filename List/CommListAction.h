#pragma once
#include "Node.h"

template<class T>
void deleteList()
{
	Node<T>* curDelNode = m_head;
	Node<T>* nextDelNode = nullptr;

	while (curDelNode != nullptr)
	{
		nextDelNode = curDelNode->next;
		delete curDelNode;
		curDelNode = nextDelNode;
	}

}

//反转链表
template<class T>
Node<T>* reverseList(Node<T>* pHead)
{
	if (pHead == nullptr) return nullptr;

	Node<T>* pTemp = nullptr, *pCur = pHead , *pNext = pHead->next ;

	pHead->next = nullptr;

	while (pNext != nullptr)
	{
		pTemp = pNext->next;
		pNext->next = pCur;
		pCur  = pNext;
		pNext = pTemp;
	}

	return pCur;
}

//判断是否有环
template<class T>
bool isCircularList(Node<T>* pHead)
{
	Node<T*> pQuick = pHead;
	Node<T*> pSlow = pHead;

	while (true)
	{
		for (int i = 0; i < 2; i++)
		{
			if (pQuick->next != nullptr)
			{
				pQuick = pQuick->next;
				if (pSlow == pQuick)
					return true;
		    }
			else return false;
		}
		
		pSlow = pSlow->next;
	}

	return false;
}

//获得第n个结点
template<class T>
Node<T>* getNode(Node<T>* pHead, int n)
{
	Node<T>* pCur = pHead;

	while (pCur != nullptr && --n)
		pCur = pCur->next;

	return pCur;
}

//获得倒数第N个结点
template<class T>
Node<T>* getbackwardsNode(Node<T>* pHead, int n)
{
	Node<T>* pFirst  = pHead;
	Node<T>* pAns    = nullptr;

	//assume that total list num is m , now get pos n
	while (--n)
	{
		pFirst = pFirst->next;
		if (pFirst == nullptr) return nullptr;
	}
	//getting backwards n equals to getting forwards m - n
	while (pFirst->next != nullptr)
	{
		pFirst = pFirst->next;
		pAns   = pAns->next;
	}
	
	return pAns;
}

//有序链表合并,要判断是否有序
template<class T>
Node<T>* mergeOrderedList(Node<T>* pHead1, Node<T>* pHead2)
{
	if (pHead1 == nullptr)
		return pHead2;

	if (pHead2 == nullptr)
		return pHead1;

	//assume that it is from least to most
	Node<T>* pCurNode1 = pHead1, *pCurNode2 = pHead2, *pMergeHead = nullptr;

	if (pHead1->val < pHead2->val) pMergeHead = pHead1;

	else pMergeHead = pHead2;

	int nCurListSNo = 0;
	Node<T>* pPreviousNode = nullptr;

	while (pCurNode1 != nullptr && pCurNode2 != nullptr)
	{
		if (pCurNode1->val < pCurNode2->val)
		{
			if (nCurListSNo == 2)
			{
				pPreviousNode->next = pCurNode1;
			}
			pPreviousNode = pCurNode1;
			pCurNode1     = pCurNode1->next;
			nCurListSNo   = 1;
		}
		else
		{
			if (nCurListSNo == 1)
			{
				pPreviousNode->next = pCurNode2;
			}
			pPreviousNode = pCurNode2;
			pCurNode2     = pCurNode2->next;
			nCurListSNo   = 2;
		}
	}

	if(pCurNode1 == nullptr) pPreviousNode->next = pCurNode2;
	else pPreviousNode->next = pCurNode1;

	return pMergeHead;
}