#include<iostream>
#include<string>
using namespace std;

#define MAX 5

string queue[MAX];
int front = -1;
int rear = -1;

void enqueue(string request)
{
	if((rear + 1) % MAX == front)
	{
		cout << "Queue is Overflow\n";
	}
	else
	{
		if(front == -1)
			front = 0;
			
		rear = (rear + 1) % MAX;
		queue[rear] = request;
		
	}
}

void dequeue()
{
	if(front == -1)
	{
		cout << "Queue is Underflow\n";
	}
	else
	{
		cout << "Processed Request: " << queue[front] << endl;
		
		if (front == rear)
		{
			front = rear = -1;
		}
		else
		{
			front = (front +1) % MAX;
		}
	}
}

void display()
{
	if (front == -1)
	{
		cout << "Queue is Empty\n";
		return;
	}
	
	int i = front;
	
	while (true)
	{
		cout << queue[i] << endl;
		
		if(i == rear)
			break;
			
		i = (i + 1) % MAX;
	}
}

int main()
{
	enqueue("Customer 1");
	enqueue("Customer 2");
	enqueue("Customer 3");
	
	cout << "Queue Contents:\n";
	display();
	
	cout << "\n";
	dequeue;
	
	cout << "\nQueue After Dequeue\n";
	display();
	
	return 0;
}



