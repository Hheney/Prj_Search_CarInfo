#pragma once

#include "Car.h"

class Bus : public Car
{
public:

	Bus(void);

	~Bus() {}

	friend std::ostream& operator<<(std::ostream& stream, const Bus& bus);

private:

protected:
};

inline Bus::Bus(void)
{
	m_carInfos.push_back(CarInfo("�׷�����", 9000., 180.));
	m_carInfos.push_back(CarInfo("���Ϲ���", 12000., 190.));
	m_carInfos.push_back(CarInfo("����Ƽ", 11000., 150.));
}

inline std::ostream& operator<<(std::ostream& stream, const Bus& bus)
{
	using namespace std;

	stream << "[Bus ����]" << endl;
	stream << "- �귣�� ���� = " << bus.m_carInfos.size() << endl;
	stream << "----------------" << endl;
	for (const auto& carInfo : bus.m_carInfos)
	{
		stream << carInfo << endl;
		stream << "----------------" << endl;
	}
	return stream;
}