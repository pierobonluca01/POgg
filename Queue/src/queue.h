/*
 * queue.h
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>

template <typename T> class Queue {
private:
	class QueueItem {
	private:
		friend class Queue<T>;
	public:
		QueueItem(const T& val, QueueItem* q =0): info(val), next(q) {}
		T info;
		QueueItem* next;
		QueueItem* copia(QueueItem* q) {
			if(!q)
				return 0;
			else
				return new QueueItem(q->info, copia(q->next));
		}
	};
	Queue::QueueItem* primo;
	Queue::QueueItem* ultimo;
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
		primo=ultimo=new Queue<T>::QueueItem(val);
	else {
		ultimo->next=new Queue<T>::QueueItem(val);
		ultimo=ultimo->next;
	}
}
template <typename T> T Queue<T>::remove() {
	if(empty()) {
		std::cerr<<"\t[!] remove() su coda vuota. [!]\n";
		exit(1);
	}
	Queue<T>::QueueItem* p=primo;
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
