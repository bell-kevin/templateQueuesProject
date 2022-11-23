// ch19queues.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

//template, so that the queue can work with integers, doubles, strings
template <class T>
class MyQueue
{
private:
	queue<T> q;
public:
	void push(T data)
	{
		q.push(data);
	}
	void pop()
	{
		q.pop();
	}
	void display()
	{
		while (!q.empty())
		{
			cout << q.front() << endl;
			q.pop();
		}
	}
};



int main()
{
    cout << "Ch 19 Queues by Kevin Bell\n\n";
	cout << "Queue with Doubles...\n";
	MyQueue<double> qd;
	qd.push(5.0);
	//display decimal point for double with one decimal place
	cout << "Enqueuing " << fixed << setprecision(1) << 5.0 << endl;
	qd.push(10.3);
	cout << "Enqueuing " << fixed << setprecision(1) << 10.3 << endl;
	qd.push(15.2);
	cout << "Enqueuing " << fixed << setprecision(1) << 15.2 << endl;
	qd.push(55.7);
	cout << "Enqueuing " << fixed << setprecision(1) << 55.7 << endl;
	qd.push(123.4);
	cout << "Enqueuing " << fixed << setprecision(1) << 123.4 << endl;
	cout << endl;
	cout << "The values in the queue:\n";
	qd.display();
	cout << endl;
	cout << "Queue with Strings...\n";
	MyQueue<string> qs;
	qs.push("technology is everywhere");
	cout << "Enqueuing technology phrase" << endl;
	qs.push("prgramming is an exciting career");
	cout << "Enqueuing programming phrase" << endl;
	qs.push("computers run the universe");
	cout << "Enqueuing computers phrase" << endl;
	cout << endl;
	cout << "The values in the queue:\n";
	qs.display();
	system("pause");
	return 0;
} //end main
