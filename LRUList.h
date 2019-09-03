#pragma once
#include<vcruntime_new.h>
#include "Node.h"

template<class T>
class LRUList 
{
public:
	LRUList() 
	{
		pHead = nullptr;
	}
	
	~LRUList()
	{
		clear();
	}

	void clear()
	{
		Node<T>* pNext = nullptr;

		while (pHead != nullptr)
		{
			pNext = pHead->next;
			delete(pHead);
			pHead = pNext;
		}
	}

	Node<T>* Get(T object)
	{
		Node<T>* pCur = pHead;

		while (pCur != nullptr)
		{
			if (pCur->val == object)
				return pCur;
			pCur = pCur->next;
		}
		
		return nullptr;
	}

	bool Cache(T object)
	{
		Node<T>* pTarget = Get(object);
		
		if (pTarget == nullptr)
		{
			//use data pool to optimize this
			pTarget = new(std::nothrow) Node<T>();
			if (pTarget == nullptr) return false;

			pTarget->val  = object;
			pTarget->next = pHead;
			pHead = pTarget;
		}
		else
		{
			if (pHead == pTarget) return true;
            //let object be head val
			T temp;
			temp = pHead->val;
			pHead->val = object;
			pTarget->val = temp;
		}

		return true;
	}

private:
	Node<T>* pHead;
};