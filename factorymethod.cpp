#include <iostream>
using namespace std;
class Transport {
public:
	virtual void deliver() const =0;
	virtual ~Transport() = default;
};
class Truck: public Transport {
public:
	void deliver() const override {
		cout << "deliver by truck" << endl;
	}
};
class Ship : public Transport {
public:
	void deliver() const override {
		cout << "deliver by ship" << endl;
	}
};
class Logistics {
public:
	virtual unique_ptr<Transport> createTransport() const = 0;
	virtual ~Logistics() = default;
};
class RoadLogistics:public Logistics {
public:
	unique_ptr<Transport> createTransport() const override{
		return make_unique<Truck>();
	}
};
class SeaLogistics :public Logistics {
public:
	unique_ptr<Transport> createTransport() const override {
		return make_unique<Ship>();
	}
};
void ClientCode(const Logistics& logistics) {
	auto transport = logistics.createTransport();
	transport->deliver();
}
int main() {
	RoadLogistics roadLogistics;
	SeaLogistics seaLogistics;
	cout << "road logistics" << endl;
	ClientCode(roadLogistics);
	cout << endl;
	cout << "sea logistics" << endl;
	ClientCode(seaLogistics);
}
