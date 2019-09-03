#pragma once
template<class T>
class Node
{
public:
	Node<T>* pre;
	Node<T>* next;
	T  val;
};