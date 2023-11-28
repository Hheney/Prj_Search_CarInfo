#pragma once

//�޴� ����

#include "Sedan.h"
#include "Suv.h"
#include "Truck.h"
#include "Bus.h"

#define DEF_X_COORD (46)			//����Ʈ X��ǥ ��
#define DEF_Y_COORD (13)			//����Ʈ Y��ǥ ��

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

	MenuSelect(void) {

	}

	~MenuSelect() {

	}

	//setter
	void setXPos(int nXPos) //�ܼ� X��ǥ�� ���� �޼ҵ�
	{
		nXPosition = nXPos;
	}

	void setYPos(int nYPos) //�ܼ� Y��ǥ�� ���� �޼ҵ�
	{
		nYPosition = nYPos;
	}

	//getter
	int getXPos(void) const { return nXPosition; }
	int getYPos(void) const { return nYPosition; }

	void Menu(void); //�޴� ��� �� ���� �ֱ�� �޼ҵ�

private:

	int nXPosition = DEF_X_COORD, nYPosition = DEF_Y_COORD;

	void MenuPrint(void);
	void InitXYPos(void);
	void TitlePrint(void);				
	void GotoXY(int nXPos, int nYPos);	//�ܼ�ȭ�� Ŀ�� ��ǥ�̵� �Լ�
	int InputKey(void);
	int MoveORSelect(void);


protected:
};

inline void MenuSelect::Menu(void)
{
	using namespace std;

	while (1)
	{
		InitXYPos(); //XY��ǥ�� �ʱ�ȭ
		MenuPrint(); //�޴� ���

		switch (MoveORSelect())
		{
		case 0:
			system("cls");
			InitXYPos();
			GotoXY(nXPosition, nYPosition);
			cout << "Sedan ���� ���� ����" << endl;
			Sleep(2000);
			system("cls");
			
			sedan.setGear(sedan.printInputGear());
			sedan.printMaxSpeed();
			
			system("PAUSE");
			break;

		case 1:
			system("cls");
			InitXYPos();
			GotoXY(nXPosition, nYPosition);
			cout << "SUV ���� ���� ����";
			Sleep(2000);
			system("cls");

			suv.setGear(suv.printInputGear());
			suv.printMaxSpeed();
			
			system("PAUSE");
			break;

		case 2:
			system("cls");
			InitXYPos();
			GotoXY(nXPosition, nYPosition);
			cout << "Truck ���� ����";

			system("PAUSE");
			break;

		case 3:
			system("cls");
			InitXYPos();
			GotoXY(nXPosition, nYPosition);
			cout << "Bus ���� ����";

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
	cout << "��";
	cout << " Sedan ���� ����" << endl;

	GotoXY(nXPosition, nYPosition + 1);
	cout << "SUV ���� ����" << endl;

	GotoXY(nXPosition, nYPosition + 2);
	cout << "Truck ���� ����" << endl;

	GotoXY(nXPosition, nYPosition + 3);
	cout << "Bus ���� ����" << endl;

	GotoXY(nXPosition, nYPosition + 4);
	cout << "���α׷� ����" << endl;

	GotoXY(nXPosition + 3, nYPosition + 8);

	cout << "�� ���۹� ��";

	GotoXY(nXPosition - 16, nYPosition + 10);
	cout << "[w] ���� �̵� [s] �Ʒ��� �̵� [spacebar] �޴� ����";
}

inline void MenuSelect::InitXYPos(void)
{
	setXPos(DEF_X_COORD);
	setYPos(DEF_Y_COORD);
}

inline void MenuSelect::TitlePrint(void)
{

}

inline void MenuSelect::GotoXY(int nXPos, int nYPos)
{
	COORD Position; //Short X,Y typedef��, X, Y��ǥ�� Ŀ�� ��ġ�� �ű�� ������ ���࿹��

	Position.X = nXPos;
	Position.Y = nYPos;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position); //�� �޼ҵ带 ���� �ܼ�ȭ�� ��ǥ �̵�
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
				cout << "��";
			}
			break;

		case (int)WASDKeyOrSpace::Down:

			if (nYPosition < DEF_Y_COORD + 4) //������ǥ + 4 : 5���� �޴��� �����ϸ�, Ŀ�� ������ ����
			{
				GotoXY(nXPosition - 2, nYPosition);
				cout << " ";

				GotoXY(nXPosition - 2, ++nYPosition);
				//settextcol(GREEN);
				cout << "��";
			}
			break;

		case (int)WASDKeyOrSpace::SpaceBar:

			return nYPosition - DEF_Y_COORD; //(����) - (�⺻ y��ǥ)�� ���� switch���� ���� ���� ��ȯ 

		default:
			break;
		}
	}
}