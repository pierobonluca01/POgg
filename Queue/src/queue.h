/*
 * queue.h
 */

#ifndef QUEUE_H_
#define QUEUE_H_


#include <iostream>



template <typename T> class Queue; //Dichiarazione incompleta (alias forward declaration)
template <typename T> std::ostream& operator <<(std::ostream&, const Queue<T>&);
template <typename T> std::ostream& operator <<(std::ostream&, const typename Queue<T>::QueueItem&);

template <typename T>
class Queue {
private:
	friend std::ostream& operator <<<T>(std::ostream&, const Queue<T>&);

	class QueueItem {
	private:
		friend class Queue<T>;
		friend std::ostream& operator <<<T>(std::ostream&, const Queue<T>&);
		friend std::ostream& operator <<<T>(std::ostream&, const typename Queue<T>::QueueItem&);
	public:
		QueueItem(const T&, QueueItem* =0);
		T info;
		QueueItem* next;
		static QueueItem* copia(QueueItem*, QueueItem*&, QueueItem* =nullptr); //TODO
		QueueItem* scorri(QueueItem*) ;
	};

	Queue::QueueItem* primo;
	Queue::QueueItem* ultimo;

public:
	Queue();
	//Queue(const Queue& q): primo(copia(q->primo)), ultimo(scorri(this->primo)) { std::cout<<"Pisnelo costruttore"; }
	Queue(const Queue& q): ultimo(nullptr), primo(copia(q.primo, ultimo)) {}
	bool empty() const;
	void add(const T&);
	T remove();
	~Queue();
	Queue& operator =(const Queue&);
};



template <typename T> Queue<T>::QueueItem::QueueItem(const T& val, QueueItem* q): info(val), next(q) {}

template <typename T> std::ostream& operator <<(std::ostream& os, const Queue<T>& q) {
	//TODO
	return os;
}

template <typename T> std::ostream& operator <<(std::ostream& os, const typename Queue<T>::QueueItem& q) {
	//TODO
	return os;
}

template <typename T> typename Queue<T>::QueueItem* Queue<T>::QueueItem::copia(QueueItem* q, QueueItem*& ultimo, QueueItem* prec) { //TODO: Verificare la copia profonda.
	if(q==nullptr)
		return ultimo=nullptr;
	QueueItem* aux=new QueueItem(q->info, prec, nullptr);
	aux->next=copia(q->next, ultimo, aux);
	if(q->next==nullptr)
		ultimo=aux;
	return aux;

//	if(q==nullptr)
//		return nullptr;
//	else
//		return new QueueItem(q->info, copia(q->next));
}

template <typename T> typename Queue<T>::QueueItem* Queue<T>::QueueItem::scorri(QueueItem* q) {
	if(q->next==nullptr)
		return q;
	else
		return scorri(q->next);
}


template <typename T> Queue<T>::Queue(): primo(0), ultimo(0) {}

//template <typename T> Queue<T>::Queue(const Queue& q): primo(copia(q)), ultimo(scorri(this->primo)) { std::cout<<"pisenlo costruttore"; }

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
