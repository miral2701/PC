#include <iostream>
#include <string>
using namespace std;


class Transport abstract
{

public:
	virtual void deliver() = 0;
	
 };

 // ���������� ������� ��������� ��������� Product (� ����� ������, PC)
 class Truck : public Transport
 {
 public:
	 void deliver() {
		 cout << "Truck delivers";
	 }
 };

 // ���������� ������� ��������� ��������� Product (� ����� ������, PC)
 class Ship: public Transport
 {
 public:
	 void deliver() {
		 cout << "Ship delivers";
	 }
 };

 
 // ��������� ��������� ��������� �����, ������������ ������ ���� Product.
 class Logistics abstract
 {
 public:
	 virtual Transport* createTransport() = 0;
 };

 class RoadLogistics: public Logistics
 {
 public:
	 Transport* createTransport()override
	 {
		 Transport *t = new Truck();
		 return t;
	 }
 };


 class SeaLogistics : public Logistics
 {
 public:
	 Transport* createTransport()override
	 {
		 Transport* t = new Ship();
		 return t;
	 }
 };
 


 // ������� ��������� ������������ � ���������� ���� ��������� �� ������������� ������, � �������������� ������������ ��������� �� ����� ������� ������.
 void Factory(Logistics** creators, int size)
 {
	 // ��������� ������������ �� ���� ��������� � ����������� ���������� ������, ������� ����� ���������� ��������� ����������� ����������� ��������.
	 for(int i = 0; i < size; i++)
	 {
		 Transport *p = creators[i]->createTransport();
		 p->deliver();
	 }
 }

 void main()
 {
	 Logistics* log[2];
	 log[0] = new RoadLogistics();
	 log[1] = new SeaLogistics();
	 Factory(log, 2);

	 system("pause");
 }