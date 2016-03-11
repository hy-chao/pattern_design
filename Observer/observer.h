#pragma once
#include<iostream>
#include<string>
#include<list>
using namespace std;

class  Subject;

class Observer
{
public:
	~Observer();
	virtual void Update(Subject*) = 0;
protected:
	Observer();
private:

};

class ConcreteObserverA : public  Observer
{
public:
	ConcreteObserverA();
	~ConcreteObserverA();
	virtual void Update(Subject*);

private:
	string m_state;
};

class ConcreteObserverB :public Observer
{
public:
	ConcreteObserverB();
	~ConcreteObserverB();
	virtual void Update(Subject*);

private:
	string m_state;
};

class Subject
{
public:
	~Subject();
	virtual void Notify();
	virtual void Attach(Observer*);
	virtual void Detach(Observer*);
	virtual string GetState();
	virtual void SetState(string state);
protected:
	Subject();
private:
	string m_state;
	list<Observer*> m_lst;
};

class ConcreteSubjectA : public Subject
{
public:
	ConcreteSubjectA();
	~ConcreteSubjectA();

protected:

private:

};

class ConcreteSubjectB : public Subject
{
public:
	ConcreteSubjectB();
	~ConcreteSubjectB();

protected:
private:

};

//й╣ож
Observer::Observer()
{
}

Observer::~Observer()
{
}
ConcreteObserverA::ConcreteObserverA()
{
}
ConcreteObserverA::~ConcreteObserverA()
{
}
void ConcreteObserverA::Update(Subject* pSubject)
{
	this->m_state = pSubject->GetState();
	cout << "This ConcreteObserverA is" << m_state << std::endl;
}

ConcreteObserverB::ConcreteObserverB()
{
}
ConcreteObserverB::~ConcreteObserverB()
{
}
void ConcreteObserverB::Update(Subject* pSubject)
{
	this->m_state = pSubject->GetState();
	cout << "This ConcreteObserverB is" << m_state << std::endl;
}

Subject::Subject()
{
}
Subject::~Subject()
{
}
void Subject::Attach(Observer* pObserver)
{
	this->m_lst.push_back(pObserver);
	cout << "Attach an Observer\n";
}
void Subject::Detach(Observer* pObserver)
{
	list<Observer*>::iterator iter;
	iter = find(m_lst.begin(), m_lst.end(), pObserver);
	if (iter != m_lst.end())
	{
		m_lst.erase(iter);
	}
	cout << "Detach an Observer\n";
}
void Subject::Notify()
{
	list<Observer*>::iterator iter = this->m_lst.begin();
	for (; iter != m_lst.end(); iter++)
	{
		(*iter)->Update(this);
	}
}
string Subject::GetState()
{
	return this->m_state;
}
void Subject::SetState(string state)
{
	this->m_state = state;
}

ConcreteSubjectA::ConcreteSubjectA()
{
}
ConcreteSubjectA::~ConcreteSubjectA()
{
}

ConcreteSubjectB::ConcreteSubjectB()
{
}
ConcreteSubjectB::~ConcreteSubjectB()
{
}