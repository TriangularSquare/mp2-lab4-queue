#pragma once
#include <iostream>
using namespace std;

template <class T>
struct TNode {
	T value;
	TNode* pNext;
};

template <class T>
class TQueueL {
private:
	TNode<T>* pFirst;
	TNode<T>* pLast;
public:
	TQueueL();
	TQueueL(const TQueueL& tql);
	~TQueueL();
	TQueueL<T>& operator=(const TQueueL<T>& tql);

	bool operator==(const TQueueL<T>& tql) const;
	bool operator!=(const TQueueL<T>& tql) const;

	bool IsEmpty() const;

	void Push(T elem);
	T Pop();

	void Clear();

	friend ostream& operator<<(ostream& out, const TQueueL& tql) {
		TNode<T>* node = tql.pFirst;
		out << "[ ";
		while (node != nullptr)
		{
			out << node->value << ' ';
			node = node->pNext;
		}
		out << "]";
		return out;
	}
};

template<class T>
inline TQueueL<T>::TQueueL()
{
	pFirst = NULL;
	pLast = NULL;
}

template<class T>
inline TQueueL<T>::TQueueL(const TQueueL& tql)
{
	pFirst = NULL;
	if (!tql.IsEmpty()) {
		TNode<T>* node;
		node = new TNode<T>;
		node->value = tql.pFirst->value;
		node->pNext = NULL;
		pFirst = node;

		TNode<T>* prev = node;
		TNode<T>* other = tql.pFirst->pNext;

		while (other != NULL) {
			node = new TNode<T>;
			node->value = other->value;
			node->pNext = NULL;
			prev->pNext = node;
			prev = node;
			other = other->pNext;
		}
		pLast = prev;
	}
}

template<class T>
inline TQueueL<T>::~TQueueL()
{
	Clear();
}

template<class T>
inline TQueueL<T>& TQueueL<T>::operator=(const TQueueL<T>& tql)
{
	if (this == &tql) {
		return *this;
	}

	Clear();
	if (!tql.IsEmpty()) {
		TNode<T>* node = new TNode<T>;
		node->value = tql.pFirst->value;
		node->pNext = NULL;
		pFirst = node;
		TNode<T>* prev = node;
		TNode<T>* other = tql.pFirst->pNext;
		while (other != NULL) {
			node = new TNode<T>;
			node->value = other->value;
			node->pNext = NULL;
			prev->pNext = node;
			prev = node;
			other= other->pNext;
		}
		pLast = prev;
	}
}

template<class T>
inline bool TQueueL<T>::operator==(const TQueueL<T>& tql) const
{
	TNode<T>* node = pFirst;
	TNode<T>* other = tql.pFirst;

	while (node != NULL && other != NULL) {
		if (node->value != other->value) {
			return false;
		}
		node = node->pNext;
		other = other->pNext;
	}

	if (node != NULL || other != NULL) {
		return false;
	}

	return true;
}

template<class T>
inline bool TQueueL<T>::operator!=(const TQueueL<T>& tql) const
{
	return !(this == &tql);
}

template<class T>
inline bool TQueueL<T>::IsEmpty() const
{
	return pFirst == NULL;
}

template<class T>
inline void TQueueL<T>::Push(T elem)
{
	TNode<T>* node = new TNode<T>();
	node->value = elem;
	node->pNext = NULL;
	if (pLast != NULL) {
		pLast->pNext = node;
	}
	else {
		pFirst = node;
	}
	pLast = node;
}

template<class T>
inline T TQueueL<T>::Pop()
{
	if (IsEmpty()) {
		throw "ERROR!";
	}

	T value = pFirst->value;
	TNode<T>* prev = pFirst;
	pFirst = prev->pNext;
	delete prev;

	if (pFirst == NULL) {
		pLast = NULL;
	}

	return value;
}

template<class T>
inline void TQueueL<T>::Clear()
{
	TNode<T>* node;
	while (pFirst != NULL) {
		node = pFirst;
		pFirst = pFirst->pNext;
		delete node;
	}
	pLast = NULL;
}
