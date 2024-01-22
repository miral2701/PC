#include <iostream>
#include <string>
using namespace std;


class Transport abstract
{

public:
	virtual void deliver() = 0;
	
 };

 // Конкретный продукт реализует интерфейс Product (в нашем случае, PC)
 class Truck : public Transport
 {
 public:
	 void deliver() {
		 cout << "Truck delivers";
	 }
 };

 // Конкретный продукт реализует интерфейс Product (в нашем случае, PC)
 class Ship: public Transport
 {
 public:
	 void deliver() {
		 cout << "Ship delivers";
	 }
 };

 
 // создатель объявляет фабричный метод, возвращающий объект типа Product.
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
 


 // Паттерн позволяет использовать в клиентском коде программы не специфические классы, а манипулировать абстрактными объектами на более высоком уровне.
 void Factory(Logistics** creators, int size)
 {
	 // Создатель «полагается» на свои подклассы в определении фабричного метода, который будет возвращать экземпляр подходящего конкретного продукта.
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