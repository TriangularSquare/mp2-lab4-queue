#pragma once

template<class T>
class TQueue {
private:
	T* Arr;
	int MaxSize;
	int Head, Tail;
	int Counter;
public:
	TQueue(int _MaxSize = 10);
	TQueue(const TQueue& tq);
	~TQueue();
	TQueue<T>& operator=(const TQueue<T>& tq);

	bool operator==(const TQueue<T>& tq) const;
	bool operator!=(const TQueue<T>& tq) const;

	bool IsEmpty();
	bool IsFull();

	int GetSize();
	int GetMaxSize();

	int GetHead();
	int GetTail();

	void Push(T elem);
	T Pop();

	void Clear();
	friend std::ostream& operator<<(std::ostream& out, const TQueue& tq)
	{

		for (int tCounter = tq.Counter, i = tq.Head; tCounter > 0; tCounter--)
		{
			out << tq.Arr[i] << ' ';
			i = (i + 1) % tq.MaxSize;
		}

		return out;
	}
};

template<class T>
inline TQueue<T>::TQueue(int _MaxSize)
{
	if (_MaxSize <= 0) {
		throw "Not correct size";
	}
	MaxSize = _MaxSize;
	Arr = new T[_MaxSize];

	Counter = 0;
	Tail = -1;
	Head = 0;
}

template<class T>
inline TQueue<T>::TQueue(const TQueue& tq)
{
	MaxSize = tq.MaxSize;
	Arr = new T[MaxSize];

	Counter = tq.Counter;
	Head = tq.Head, Tail = tq.Tail;

	for (int tCounter = Counter, i = Head; tCounter > 0; tCounter--)
	{
		Arr[i] = tq.Arr[i];
		i = (i + 1) % MaxSize;
	}
}

template<class T>
inline TQueue<T>::~TQueue()
{
	delete[] Arr;
}

template<class T>
inline TQueue<T>& TQueue<T>::operator=(const TQueue<T>& tq)
{
	if (this == &tq)
		return *this;

	if (MaxSize != tq.MaxSize) {
		MaxSize = tq.MaxSize;
		delete[] Arr;
		Arr = new T[MaxSize];
	}
	Counter = tq.Counter;
	Head = tq.Head, Tail = tq.Tail;

	for (int tCounter = Counter, i = Head; tCounter > 0; tCounter--)
	{
		Arr[i] = tq.Arr[i];
		i = (i + 1) % MaxSize;
	}

	return *this;
}

template<class T>
inline bool TQueue<T>::operator==(const TQueue<T>& tq) const
{
	if (MaxSize != tq.MaxSize || Head != tq.Head ||
		Tail != tq.Tail || Counter != tq.Counter) {
		return false;
	}

	for (int tCounter = Counter, i = Head; tCounter > 0; tCounter--) {
		if (Arr[i] != tq.Arr[i])
			return false;
		i = (i + 1) % MaxSize;
	}

	return true;
}

template<class T>
inline bool TQueue<T>::operator!=(const TQueue<T>& tq) const
{
	return !(this == &tq);
}

template<class T>
inline bool TQueue<T>::IsEmpty()
{
	return Counter == 0;
}

template<class T>
inline bool TQueue<T>::IsFull()
{
	return Counter == MaxSize;
}


template<class T>
inline int TQueue<T>::GetSize()
{
	return Counter;
}

template<class T>
inline int TQueue<T>::GetMaxSize()
{
	return MaxSize;
}

template<class T>
inline int TQueue<T>::GetHead()
{
	return Head;
}

template<class T>
inline int TQueue<T>::GetTail()
{
	return Tail;
}

template<class T>
inline void TQueue<T>::Push(T elem)
{
	if (IsFull()) {
		throw "Queue is full!";
	}
	Tail = (Tail + 1) % MaxSize;
	Arr[Tail] = elem;
	Counter++;
}

template<class T>
inline T TQueue<T>::Pop()
{
	if (IsEmpty()) {
		throw "Queue is empty!";
	}
	T elem = Arr[Head];
	Head = (Head + 1) % MaxSize;
	Counter--;
	return elem;
}

template<class T>
inline void TQueue<T>::Clear()
{
	Counter = 0;
	Head = 0; Tail = -1;
}
