/*
 * queue.h
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>

template <typename T>
class QueueItem {
public:
	QueueItem(const T&, QueueItem* =0);
	T info;
	QueueItem* next;
	QueueItem* copia(QueueItem* q) {
		std::cout<<"Zio treno copia";
		if(!q)
			return 0;
		else
			return new QueueItem(q->info, copia(q->next));
	}
};

template <typename T> QueueItem<T>::QueueItem(const T& val, QueueItem* q): info(val), next(q) {}


template <typename T> class Queue {
private:
	QueueItem<T>* primo;
	QueueItem<T>* ultimo;
public:
	Queue();
	bool empty() const;
	void add(const T&);
	T remove();
	~Queue();
	Queue(const Queue& q);
	Queue& operator =(const Queue&);
};

template <typename T> Queue<T>::Queue(): primo(0), ultimo(0) {}
template <typename T> bool Queue<T>::empty() const {
	return (primo==nullptr);
}
template <typename T> void Queue<T>::add(const T& val) {
	if(empty())
		primo=ultimo=new QueueItem<T>(val);
	else {
		ultimo->next=new QueueItem<T>(val);
		ultimo=ultimo->next;
	}
}
template <typename T> T Queue<T>::remove() {
	if(empty()) {
		std::cerr<<"\t[!] remove() su coda vuota. [!]\n";
		exit(1);
	}
	QueueItem<T>* p=primo;
	primo=primo->next;
	T aux=p->info;
	delete p;
	return aux;
}
template <typename T> Queue<T>::~Queue() {
	while(!empty())
		remove();
}


#endif /* QUEUE_H_ */
