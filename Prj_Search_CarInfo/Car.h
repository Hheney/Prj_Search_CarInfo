#pragma once

#include <vector>
#include "Vehicle.h"
#include "CarInfo.h"

// public ���: ���� ������ �������
// protected ���: public  ��� -> protected ����� ����; �������� �״��
// private ���: public, protected ��� -> private ���; �������� �״��
// : �ǹ�: ��� �޴´ٴ� ��
class Car : public Vehicle
{
public:
	Car(void) {}
	~Car() {}

	int getGear(void) const { return m_nGear; }
	void setGear(int nGear) { m_nGear = nGear; }

	void printMaxSpeed(void) const;
	void printDistance(void);
	double InputTime(void); //�̵� �ð��� �Է¹޴� �޼ҵ�
	int printInputGear(void); //��� �Է��� �޾� ���ܼ� ���� �޼ҵ�


	// friend: ��� X, ���� ������Ƽ�� ���� ������ �޼ҵ�; � �޼ҵ���� friend ���� ���������� operator �ߺ����� �ַ� ���
	friend std::ostream& operator<<(std::ostream& stream, const Car& vehicle);

private:
	int m_nGear = 0;
	bool m_bBrake = true;

protected:
	// �귣��, ����, �ִ�ӵ�
	//std::vector<std::string> m_brand; // ���� �귣�带 �����ϴ� ���� �ڷ� ����; ���Ҵ� ���ڿ��� ����
	//std::vector<double> m_price;
	//std::vector<double> m_maxSpeed;
	std::vector<CarInfo> m_carInfos;
};

inline void Car::printMaxSpeed(void) const
{
	using namespace std;
	cout << "[���� �ְ� �ӵ�]" << endl;
	cout << "���� ��� = " << m_nGear << "��" << endl;
	cout << "---------------" << endl;
	for (const auto& carInfo : m_carInfos)
	{
		cout << carInfo.getBrand() << "�� �ְ� �ӵ� = " << carInfo.getSpeed(m_nGear) << "km/h" << endl;
	}
	cout << "---------------" << endl;
}

inline void Car::printDistance(void)
{
	using namespace std;

	double dbTravelTime = InputTime();
	cout << "---------------" << endl;
	for (const auto& carInfo : m_carInfos)
	{
		cout << carInfo.getBrand() << "�� �̵� �Ÿ� = " << carInfo.getSpeed(m_nGear) * dbTravelTime << "km" << endl;
	}
	cout << "---------------" << endl;
}

inline double Car::InputTime(void)
{
	using namespace std;
	double dbTime = 0.0;

	cout << "�̵��� �ð��� �Է����ּ���. ����) 10.2" << endl << endl;
	cin >> dbTime;

	return dbTime;
}


inline int Car::printInputGear(void)
{
	using namespace std;
	int nGear = 0;

	cout << "���(1~4)�� �����ϼ���: ";
	cin >> nGear;
	while (!cin || nGear < 1 || nGear > 4)
	{
		if (!cin)
		{
			cin.clear();
			cin.ignore(1, '\n');
		}
		cout << "�� �ٽ� �����ϼ���: ";
		cin >> nGear;	
	}

	return nGear;
}

inline std::ostream& operator<<(std::ostream& stream, const Car& car)
{
	using namespace std;
	stream << "[Car: " << car.getName() << "]" << endl;
	stream << "�ӵ� = " << car.getSpeed() << " km/h" << endl;
	stream << "���� ��ġ = (" << car.getPosX() << ", " << car.getPosY() << ")" << endl;
	stream << "��� = " << car.m_nGear << "��" << endl;
	stream << "�극��ũ = " << ((car.m_bBrake) ? "�ɸ�" : "�Ȱɸ�");
	return stream;
}
