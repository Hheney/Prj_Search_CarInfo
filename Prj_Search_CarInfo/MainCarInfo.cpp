/* Car에서 상속 받아 Sedan, Suv, Truck, Bus 클래스 생성
-  Sedan, Suv, Truck, Bus별로 정보를 출력: 브랜드, 가격, 최대속도
- Car 클래스: 기어 단수에 따라 최대 속도 결정: 최대 속도를 Vm으로 설정 -> 1단 = Vm*0.25, 2단 = Vm*0.5, 3단 = Vm*0.75, 4단 = Vm
- Sedan, Suv, Truck, Bus도 기어 단수에 따라 최대 속도를 변경
- 각 이동체별로 이동한 거리를 계산: 시간 입력(time)을 받아 speed로 계산 = speed*time
*/
#include "MenuSelect.h"

int main()
{
	using namespace std;

	MenuSelect menu;

	menu.Menu();

	/*
	cout << "세단 1, SUV 2, Truck 3, Bus 4 : ";
	cin >> input;


	switch (input)
	{
	case 1:
		cout << sedan << endl;

		sedan.setGear(sedan.printInputGear());
		sedan.printMaxSpeed();

		break;

	case 2:
		cout << suv << endl;

		suv.setGear(suv.printInputGear());
		suv.printMaxSpeed();

		break;

	case 3:
		cout << truck << endl;

		truck.setGear(truck.printInputGear());
		truck.printMaxSpeed();

		break;

	case 4:
		cout << bus << endl;

		bus.setGear(bus.printInputGear());
		bus.printMaxSpeed();

	default:
		break;
	}
	*/



	
}