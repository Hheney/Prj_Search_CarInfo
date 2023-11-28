#pragma once

#include "Car.h"

class Suv : public Car
{
public:

	Suv(void);

	~Suv() {}

	friend std::ostream& operator<<(std::ostream& stream, const Suv& suv);

private:

protected:
};

inline Suv::Suv(void)
{
	m_carInfos.push_back(CarInfo("��Ÿ��", 4000., 200.));
	m_carInfos.push_back(CarInfo("GV80", 8000., 250.));
	m_carInfos.push_back(CarInfo("�����÷��̵�", 15000., 260));
}

inline std::ostream& operator<<(std::ostream& stream, const Suv& suv)
{
	using namespace std;

	stream << "[Suv ����]" << endl;
	stream << "- �귣�� ���� = " << suv.m_carInfos.size() << endl;
	stream << "----------------" << endl;
	for (const auto& carInfo : suv.m_carInfos)
	{
		stream << carInfo << endl;
		stream << "----------------" << endl;
	}
	return stream;
}
