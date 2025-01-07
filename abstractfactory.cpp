#include <iostream>
using namespace std;
class Chair {
public:
	virtual void sitOn() const = 0;
	virtual ~Chair() = default;
};
class Sofa {
public:
	virtual void lieOn() const = 0;
	virtual ~Sofa() = default;
};
class VictorianChair :public Chair {
public:
	void sitOn() const override {
		cout << "sit on a victorian chair" << endl;
	}
};
class VictorianSofa:public Sofa {
public:
	void lieOn() const override {
		cout << "lie on a victorian sofa" << endl;
	}
};
class ModernChair : public Chair {
public:
	void sitOn() const override {
		cout << "sit on a modern chair" << endl;
	}
};
class ModernSofa : public Sofa {
public:
	void lieOn() const override {
		cout << "lie on a modern sofa" << endl;
	}
};
class FurnitureFactory {
public:
	virtual unique_ptr<Chair> createChair() const= 0;
	virtual unique_ptr<Sofa> createSofa() const= 0;
	virtual ~FurnitureFactory() = default;
};
class VictorianFurnitureFactory :public FurnitureFactory {
public:
	unique_ptr<Chair> createChair() const override {
		return make_unique<VictorianChair>();
	}
	unique_ptr<Sofa> createSofa() const override {
		return make_unique<VictorianSofa>();
	}
};
class ModernFurnitureFactory : public FurnitureFactory {
public:
	unique_ptr<Chair> createChair() const override {
		return make_unique<ModernChair>();
	}
	unique_ptr<Sofa> createSofa() const override {
		return make_unique<ModernSofa>();
	}
};
void ClientCode(const FurnitureFactory& factory) {
	auto chair = factory.createChair();
	auto sofa = factory.createSofa();
	chair->sitOn();
	sofa->lieOn();
}
int main() {
	VictorianFurnitureFactory victorianFactory;
	cout << "Victorian furniture" << endl;
	ClientCode(victorianFactory);

	ModernFurnitureFactory modernFactory;
	cout << "Modern furniture" << endl;
	ClientCode(modernFactory);
}
