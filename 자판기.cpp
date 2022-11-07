#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#define NUMBER 10//���Ǳ� ó�� ���  10�� ���� 
using namespace std;//STD::����
void gotoxy(int x, int y);//Ŀ���̵� �Լ�
class menu
{
private:
	char explain[9][20] = { "Q(q):50�� ����","W(w):100�� ����", "E(e):500�� ����","R(r):1000�� ����","B(b):���� ��ȯ","S(s):���� ���� ","F(f):���Ǳ� �ʱ�ȭ","P(p):���� �ϱ�","X(x):���α׷� ����" };
	char array[9][5] = { "��","��","��","��","��","��","��","��","��" };
protected:
	char name[9][12] = { "�ݶ�","���̴�","ȯŸ","��Ű��","������","������","��Ÿ������","Null","Null" };
	int price[9] = { 900,800,600,400,700,500,1200,0,0 };
	int Stock[9] = { NUMBER ,NUMBER , NUMBER , NUMBER , NUMBER , NUMBER , NUMBER , 0,0 };
	void Start();
	void clean();
public:
	menu() { Start(); }//�޴����� ��ӹ��� ����ӽſ��� ȣ����ҋ� �ڵ����� �ҷ����鼭 �޴��� ������ �Լ��� ȣ���ϱ� ����.
};
void gotoxy(int x, int y) {							// Ŀ���̵��� �ϱ����� gotoxy()�Լ�
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);//  Pos.X�� x��ǥ�� Pos.Y�� y��ǥ �ΰ����� �ű��.
}
void menu::Start()//��������� ���̴� �޴��� �μ�
{
	system("cls");//���â �� ����.
	for (int i = 0; i < 30; i++)//��� ���κ� 30�� ä��
	{
		cout << "��";
	}
	cout << endl;
	for (int i = 1; i < 10; i++)//for�� 9�� ���� 
	{
		cout << "���" << array[i - 1] << name[i - 1]; gotoxy(18, i); cout << "��[" << price[i - 1] << "]";//��ȣŰ,�̸�������
		gotoxy(28, i);
		cout << "��";
		if (Stock[i - 1] > 0)//��� �ִ��� ������ �̸� �޴��ǿ��� ������
			cout << "���ð���";
		else
			cout << "���úҰ���";
		gotoxy(38, i);
		cout << "��" << explain[i - 1];//�޴�Ű ����
		gotoxy(58, i);
		cout << "��" << endl;
	}
	for (int i = 0; i < 30; i++)//��� �Ʒ��κ� 30�� ä��
	{
		cout << "��";
	}
	cout << endl;
	cout << "��";
	gotoxy(58, 11);
	cout << "��" << endl;
	for (int i = 0; i < 30; i++)
	{
		cout << "��";// ��� �Ʒ��κ� 30�� ä��
	}
	gotoxy(0, 13);//(0,13)�� ������ �޴��� �ۿ��� �� ĥ�� �ְ���.
}
void menu::clean()//�޴��ǿ��� system("cls")�� �Ⱦ��� ����ϰ� �����ֱ�����
{
	gotoxy(2, 11);//(2,11)�� ����Ų��
	cout << "                                                        ";//���� ����ϸ� (2,11)�ڿ� �����ִ� ���ڵ��� �����.
	gotoxy(2, 11);//�ٽ� (2,11)����Ŵ
}
class vendingmachine :public menu
{
private:
	int sum;
	int money;
	char key;
	int go;
	int put;
protected:
	void set();
	void keep() { money = 0; sum = 0; while (key != 88 && key != 120) { set(); } }
public:
	vendingmachine() { keep(); }//�ڵ����� ������ �������ϸ鼭 ���Ե� ���� ���ⷮ 0���� �ʱ�ȭ Set �Լ��� �����ϴ� keep�Լ� ����
};
void vendingmachine::set()
{
	gotoxy(0, 13);
	for (int i = 0; i < 10; i++)
		cout << "                                                                          ";
	gotoxy(0, 13);
	cin >> key;
	if (key == 81 || key == 113)//Q�� �Է� ������
	{
		clean();//������ �Է¹ޱ⿡ clean()�Լ��� �غκи� �����Ѵ�.
		if (money < 9950)//9950�� �̸��̸�
		{
			cout << "50���� ���� �Ǿ����ϴ�.";
			gotoxy(34, 11);
			cout << "��";
			money = money + 50;
			cout << "���� ���� �ݾ�:" << money;//50����  �����ϰ� �������Աݾ��� �����ش�
		}
		else
		{
			cout << "�̻�� �ݾ��� 10000���� �ʰ��Ҽ� �����ϴ�.";//������ 10000���̻� �Ұ����̶�°��� �˷��ش�.
		}
		gotoxy(0, 13);
	}
	else if (key == 87 || key == 119)//�Ʒ��� ���� ����.
	{
		clean();
		if (money < 9900)
		{
			cout << "100���� ���� �Ǿ����ϴ�.";
			gotoxy(34, 11);
			cout << "��";
			money = money + 100;
			cout << "���� ���� �ݾ�:" << money;
		}
		else
		{
			cout << "�̻�� �ݾ��� 10000���� �ʰ��Ҽ� �����ϴ�.";
		}
		gotoxy(0, 13);
	}
	else if (key == 69 || key == 101)
	{
		clean();
		if (money < 9500)
		{
			cout << "500���� ���� �Ǿ����ϴ�.";
			gotoxy(34, 11);
			cout << "��";
			money = money + 500;
			cout << "���� ���� �ݾ�:" << money;
		}
		else
		{
			cout << "�̻�� �ݾ��� 10000���� �ʰ��Ҽ� �����ϴ�.";
		}
		gotoxy(0, 13);
	}
	else if (key == 82 || key == 114)
	{
		clean();
		if (money < 9000)
		{
			cout << "1000���� ���� �Ǿ����ϴ�.";
			gotoxy(34, 11);
			cout << "��";
			money = money + 1000;
			cout << "���� ���� �ݾ�:" << money;
		}
		else
		{
			cout << "�̻�� �ݾ��� 10000���� �ʰ��Ҽ� �����ϴ�.";
		}
		gotoxy(0, 13);
	}
	else if (key == 66 || key == 98)//���� ��ȯ bŰ
	{
		clean();
		if (money > 0)
		{
			cout << "������ ��ȯ �˴ϴ�.";
			money = 0;//money��ȯ �̱⿡ 0���� �д�.
		}
		else
			cout << "��ȯ�� ������ �����ϴ�.";//0���ε� 0���� ��ȯ�ϴ°� ���̾ȵǴϱ�
		gotoxy(34, 11);
		cout << "��";
	}
	else if (key >= 49 && key <= 57)//49~57�̸� �� 1~9������ �޴����� ���� ��������
	{
		put = key - 48;//put�� 1~9���̷εΰ� �迭�� �Է��ؼ� ���� �����ϰ� �ϱ����ؼ���
		clean();
		if (Stock[put - 1] > 0)//��� 0���� ũ��
		{
			if (money >= price[put - 1])//���Աݾ��� price���� ���ų� ũ�� ��� 1�� ���� ��밡�ɱݾ׵� �ݾ׿��� ���� �Ǹŷ� ���� �����ش�.
			{
				cout << price[put - 1] << "���� " << name[put - 1] << " �� ���Խ��ϴ�";
				sum = sum + price[put - 1];
				money = money - price[put - 1];
				Stock[put - 1] = Stock[put - 1] - 1;
				Sleep(1000);//1�� ��ٸ��� ���� ������� �����ϴϱ�
				Start();
			}
			else
				cout << "�ݾ��� �����մϴ�";
			gotoxy(34, 11);
			cout << "��";
			cout << "��� ������ �ݾ�:" << money;
			gotoxy(0, 13);
		}
		else
			cout << "��� ����";//��� ���⿡ ��� ������ �˷���...
		gotoxy(34, 11);
		cout << "��";
		cout << "��� ������ �ݾ�:" << money;
		gotoxy(0, 13);
	}
	else if (key == 83 || key == 115)//s Ű�� ������ sum ���
	{
		clean();
		cout << "���Ǳ� ���� �ݾ�:" << sum;
		gotoxy(0, 13);
	}
	else if (key == 70 || key == 102)//fŰ�� ������ sum�� =0���� ����
	{
		clean();
		cout << "���Ǳ� �Ǹŷ��� �ʱ�ȭ �Ǿ����ϴ�";
		sum = 0;
		gotoxy(0, 13);
	}
	else if (key == 80 || key == 112)//pŰ �Է¹����� ���߿����� 1,2,3,�� ���������ְ� 1~9���� �� ���������ְ� �״��� ������ �ϰ�����..
	{
		clean();
		cout << "�̸� ����:1 ���� ����:2 ��� ����:3 ����x:�� ���� Ű";
		gotoxy(0, 13);
		char fix;
		cin >> fix;
		if (fix == 49)
		{
			int k;
			clean();
			cout << "����� �̸��� ���� �Ͻðڽ��ϱ�?[1~9]";
			gotoxy(0, 13);
			cin >> k;
			gotoxy(2, 11);
			cout << "                                                        ";
			gotoxy(2, 11);
			cout << k << "��° �ٲ� �̸��� �����ÿ�.";
			gotoxy(0, 13);
			cin >> name[k - 1];
			Start();
			gotoxy(2, 11);
			cout << "                                                        ";
		}
		else if (fix == 50)
		{
			int k;
			clean();
			cout << "����� ������ ���� �Ͻðڽ��ϱ�?[1~9]";
			gotoxy(0, 13);
			cin >> k;
			gotoxy(2, 11);
			cout << "                                                        ";
			gotoxy(2, 11);
			cout << k << "��° �ٲ� ������ �����ÿ�.";
			gotoxy(0, 13);
			cin >> price[k - 1];
			Start();
			gotoxy(2, 11);
			cout << "                                                        ";
		}
		else if (fix == 51)
		{
			int k;
			clean();
			cout << "����� ��� ���� �Ͻðڽ��ϱ�?[1~9]";
			gotoxy(0, 13);
			cin >> k;
			gotoxy(2, 11);
			cout << "                                                        ";
			gotoxy(2, 11);
			cout << k << "��° �ٲ� ��� �����ÿ�.";
			gotoxy(0, 13);
			cin >> Stock[k - 1];
			Start();
			gotoxy(2, 11);
			cout << "                                                        ";
		}
		else
		{
			clean();
			cout << "������ ����մϴ�.";
			gotoxy(0, 13);
		}
	}
	else if (key == 88 || key == 120)//���� ǥ�ô� ���ص������� ����ڰ� ���α׷� ���Ḧ �ڱⰡ ������ �˷��ֱ� ����
	{
		clean();
		cout << "���α׷��� �����մϴ�";
		gotoxy(0, 13);
	}
	else//�������� Ű�� ������ ���
	{
		clean();
		cout << "�������� �ʴ� Ű�Դϴ�.";
		gotoxy(34, 11);
		cout << "��";
	}
}
int main()
{
	vendingmachine();//����ӽ� ȣ��
	return 0;
}