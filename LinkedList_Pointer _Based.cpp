#include <iostream>;
using namespace std;
typedef int ELementtype;
struct Node {
	ELementtype Data;
	Node* Next;
};
typedef Node* Position;
class LinkedList {
private: 
	Position head;
	Position tail;
	int Counter;
public:
	LinkedList() {
		MakeNull();
	}
	void MakeNull() {
		head = new Node();
		head->Next = NULL;
		tail = NULL;
		Counter = 0;
	}
	Position First() {
		return head;
	}
	bool IsEmpty() {
		return (head->Next = NULL);
	}
	Position End() {
		if (IsEmpty())
		{
			return head;
		}
		return tail;
	}
	Position Next(Position p) {
		if (p == NULL) {
			return NULL;
		}
		return p->Next;
	}
	Position Previos(Position p) {
		if (p = head) {
			return NULL;
		}
		Position q = head;
		while (q!=tail) {
			if (q = p) {
				return q;
			}
			q = q->Next;
		}
		return NULL;
	}
	Position Previos2(Position p) {
		if (p == head) {
			return NULL;
		}
		Position q = head;
		while (q != p && q!= NULL) {
			q = q->Next;
		}
		return q;
	}
	void Insert(ELementtype x, Position p) {
		if (p == NULL) {
			p = End();
		}
		Position NewNode = new Node();
		NewNode->Data = x;
		NewNode->Next = p->Next;
		p ->Next= NewNode;
		if (NewNode->Next == NULL) {
			NewNode = tail;
		}
		Counter++;
	}
	void Delete(Position p){
		if (p==NULL) {
			cout << "No Element to deleted";
		}
		if (p->Next ==tail) {
			tail = p;
		}
		p->Next = p->Next->Next;
		Counter--;
	}
	Position Locate(ELementtype x) {
		Position p = head;
		while (p->Next !=NULL) {
			if (p->Next->Data = x) {
				return p;
			}
			p = p->Next;
		}
	}
	ELementtype Retrive(Position p) {
		if (p == tail) {
			return tail->Data;
		}
		else if ( p == NULL || p -> Next = NULL)
		{
			cout << "this Element Not found";
		}
		else
		{
			return p->Next->Data;
		}
	}
	int Size() {
		return Counter;
	}
	void PrintList() {
		if (IsEmpty()) {
			cout << "the list is empty";
		}
		Position q = head;
		while (q->Next == NULL) {
			cout << "the Element is ";
			cout << endl;
			cout << q->Next->Data;
			q = q->Next;
		}
	}
	Position LocateRange(ELementtype x, Position start, Position End) {
		Position p = start;
		while (p->Next != NULL && p->Next != End) {
			if (p->Next->Data = x) {
				return p;
			}
			p = p->Next;
		}
		return p;
	}
	void prug(LinkedList &l) {
		Position i = l.First();
		Position j = l.First();
		while (i!= l.End()) {
			while (j != l.End() && j != i) {
				if (l.Retrive(i) == l.Retrive(j)) {
					l.Delete(j);
				}
				j = l.Next(j);
			}
			i= l.Next(i);
		}
	}
	LinkedList Reserve(LinkedList x) {
		LinkedList res;
		ELementtype curr;
		Position dir = x.First();
		while (dir!= End()) {
			curr = dir->Data;
			x.Insert(curr, x.First());
			dir = x.Next(dir);
		}
	}
	void Insert_x_After_y(ELementtype x, ELementtype y , LinkedList &l) {
		l.Insert( x ,  ( Next (Locate(y))  )  );
	}
	LinkedList Concatenet(LinkedList l1, LinkedList l2) {
		LinkedList l;
		Position p = l1.First();
		Position q = l2.First();
		while (p!=End())
		{
			l.Insert(p->Data, End());
			p = l1.Next(p);
		}
		while (q != End())
		{
			l.Insert(q->Data, l.End());
			q = l1.Next(q);
		}
		return l;
	}
	void split(LinkedList l, LinkedList &Evenl, LinkedList &oodl) {
		Position p = l.First();
		ELementtype x;
		while (p != End()) {
			ELementtype x = p->Data;
			if (x%2==0) {
				Evenl.Insert(x,End());
			}
			if (x % 2 != 0) {
				oodl.Insert(x, End());
			}
			p = l.Next(p);
		}
	}


};