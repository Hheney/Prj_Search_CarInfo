#pragma once

//메뉴 선택

#include "Sedan.h"
#include "Suv.h"
#include "Truck.h"
#include "Bus.h"

#define DEF_X_COORD (46)			//디폴트 X좌표 값
#define DEF_Y_COORD (13)			//디폴트 Y좌표 값

enum class WASDKeyOrSpace
{
	Up = 0, Down, Left, Right, SpaceBar
};

class MenuSelect : public Sedan, Suv, Truck, Bus
{
public:

	Sedan sedan;
	Suv suv;
	Truck truck;
	Bus bus;

	MenuSelect(void) {}

	MenuSelect(int nXPos, int nYPos)
	{
		setXPos(nXPos);
		setYPos(nYPos);
	}

	~MenuSelect() {}

	//setter
	void setXPos(int nXPos) //콘솔 X좌표값 설정 메소드
	{
		nXPosition = nXPos;
	}

	void setYPos(int nYPos) //콘솔 Y좌표값 설정 메소드
	{
		nYPosition = nYPos;
	}

	//getter
	int getXPos(void) const { return nXPosition; }
	int getYPos(void) const { return nYPosition; }

	void Menu(void); //메뉴 출력 및 선택 주기능 메소드

private:

	int nXPosition = DEF_X_COORD, nYPosition = DEF_Y_COORD;

	//메뉴 관련 메소드
	void MenuPrint(void);
	void InitXYPos(void);
	void TitlePrint(void);				
	void GotoXY(int nXPos, int nYPos);	//콘솔화면 커서 좌표이동 함수
	int InputKey(void);
	int MoveORSelect(void);

	//자동차 정보 검색 관련 메소드

protected:
};

inline void MenuSelect::Menu(void)
{
	using namespace std;

	while (1)
	{
		InitXYPos(); //XY좌표값 초기화
		MenuPrint(); //메뉴 출력

		switch (MoveORSelect())
		{
		case 0:
			system("cls");
			InitXYPos();
			GotoXY(nXPosition, nYPosition);
			cout << "Sedan 정보 보기 선택" << endl;
			Sleep(2000);
			system("cls");
			
			sedan.setGear(sedan.printInputGear());
			sedan.printMaxSpeed();
			sedan.printDistance();
			
			system("PAUSE");
			break;

		case 1:
			system("cls");
			InitXYPos();
			GotoXY(nXPosition, nYPosition);
			cout << "SUV 정보 보기 선택";
			Sleep(2000);
			system("cls");

			suv.setGear(suv.printInputGear());
			suv.printMaxSpeed();
			suv.printDistance();
			
			system("PAUSE");
			break;

		case 2:
			system("cls");
			InitXYPos();
			GotoXY(nXPosition, nYPosition);
			cout << "Truck 정보 보기";
			Sleep(2000);
			system("cls");

			truck.setGear(truck.printInputGear());
			truck.printMaxSpeed();
			truck.printDistance();

			system("PAUSE");
			break;

		case 3:
			system("cls");
			InitXYPos();
			GotoXY(nXPosition, nYPosition);
			cout << "Bus 정보 보기";
			Sleep(2000);
			system("cls");

			bus.setGear(bus.printInputGear());
			bus.printMaxSpeed();
			bus.printDistance();

			system("PAUSE");
			break;

		case 4:
			system("cls");
			InitXYPos();
			exit(0);

		default:
			break;
		}
		system("cls");
	}
}

inline void MenuSelect::MenuPrint(void)
{
	using namespace std;

	GotoXY(nXPosition - 2, nYPosition);
	cout << "▶";
	cout << " Sedan 정보 보기" << endl;

	GotoXY(nXPosition, nYPosition + 1);
	cout << "SUV 정보 보기" << endl;

	GotoXY(nXPosition, nYPosition + 2);
	cout << "Truck 정보 보기" << endl;

	GotoXY(nXPosition, nYPosition + 3);
	cout << "Bus 정보 보기" << endl;

	GotoXY(nXPosition, nYPosition + 4);
	cout << "프로그램 종료" << endl;

	GotoXY(nXPosition + 3, nYPosition + 8);

	cout << "■ 조작법 ■";

	GotoXY(nXPosition - 16, nYPosition + 10);
	cout << "[w] 위로 이동 [s] 아래로 이동 [spacebar] 메뉴 선택";
}

inline void MenuSelect::InitXYPos(void)
{
	setXPos(DEF_X_COORD);
	setYPos(DEF_Y_COORD);
}

inline void MenuSelect::TitlePrint(void)
{
	//fstream 파일처리 사용하여 출력하도록 메소드 구성
}

inline void MenuSelect::GotoXY(int nXPos, int nYPos)
{
	COORD Position; //Short X,Y typedef임, X, Y좌표로 커서 위치를 옮기는 동작을 수행예정

	Position.X = nXPos;
	Position.Y = nYPos;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position); //이 메소드를 통해 콘솔화면 좌표 이동
}

inline int MenuSelect::InputKey(void)
{
	char chInput = _getch();

	if (chInput == 'w' || chInput == 'W')
	{
		return (int)WASDKeyOrSpace::Up;
	}
	else if (chInput == 'a' || chInput == 'A')
	{
		return (int)WASDKeyOrSpace::Left;
	}
	else if (chInput == 's' || chInput == 'S')
	{
		return (int)WASDKeyOrSpace::Down;
	}
	else if (chInput == 'd' || chInput == 'D')
	{
		return (int)WASDKeyOrSpace::Right;
	}
	else if (chInput == ' ')
	{
		return (int)WASDKeyOrSpace::SpaceBar;
	}
	else return 0;
}

inline int MenuSelect::MoveORSelect(void)
{
	using namespace std;

	while (1)
	{
		switch (InputKey())
		{
		case (int)WASDKeyOrSpace::Up:

			if (nYPosition > DEF_Y_COORD)
			{
				GotoXY(nXPosition - 2, nYPosition);
				cout << " ";

				GotoXY(nXPosition - 2, --nYPosition);
				//settextcol(GREEN);
				cout << "▶";
			}
			break;

		case (int)WASDKeyOrSpace::Down:

			if (nYPosition < DEF_Y_COORD + 4) //시작좌표 + 4 : 5가지 메뉴가 존재하며, 커서 범위를 제한
			{
				GotoXY(nXPosition - 2, nYPosition);
				cout << " ";

				GotoXY(nXPosition - 2, ++nYPosition);
				//settextcol(GREEN);
				cout << "▶";
			}
			break;

		case (int)WASDKeyOrSpace::SpaceBar:

			return nYPosition - DEF_Y_COORD; //(변수) - (기본 y좌표)를 통해 switch문에 사용될 정수 반환 

		default:
			break;
		}
	}
}