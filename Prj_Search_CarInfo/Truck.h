#pragma once

#include "Car.h"

class Truck : public Car
{
public:

	Truck(void);

	~Truck() {}

	friend std::ostream& operator<<(std::ostream& stream, const Truck& truck);

private:

protected:
};

inline Truck::Truck(void)
{
	m_carInfos.push_back(CarInfo("포터", 2500., 180.));
	m_carInfos.push_back(CarInfo("GMC시에라", 9500., 230.));
	m_carInfos.push_back(CarInfo("레인저랩터", 8000., 200.));
}

inline std::ostream& operator<<(std::ostream& stream, const Truck& truck)
{
	using namespace std;

	stream << "[Truck 정보]" << endl;
	stream << "- 브랜드 개수 = " << truck.m_carInfos.size() << endl;
	stream << "----------------" << endl;
	for (const auto& carInfo : truck.m_carInfos)
	{
		stream << carInfo << endl;
		stream << "----------------" << endl;
	}
	return stream;
}