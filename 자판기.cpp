#include <iostream>
#include <string>
#include <Windows.h>
#include <conio.h>
#define NUMBER 10//자판기 처음 재고  10개 지정 
using namespace std;//STD::생략
void gotoxy(int x, int y);//커서이동 함수
class menu
{
private:
	char explain[9][20] = { "Q(q):50원 투입","W(w):100원 투입", "E(e):500원 투입","R(r):1000원 투입","B(b):동전 반환","S(s):매출 보기 ","F(f):자판기 초기화","P(p):수정 하기","X(x):프로그램 종료" };
	char array[9][5] = { "①","②","③","④","⑤","⑥","⑦","⑧","⑨" };
protected:
	char name[9][12] = { "콜라","사이다","환타","밀키스","코코팜","레쓰비","비타민음료","Null","Null" };
	int price[9] = { 900,800,600,400,700,500,1200,0,0 };
	int Stock[9] = { NUMBER ,NUMBER , NUMBER , NUMBER , NUMBER , NUMBER , NUMBER , 0,0 };
	void Start();
	void clean();
public:
	menu() { Start(); }//메뉴판을 상속받은 밴딩머신에서 호출당할떄 자동으로 불러오면서 메뉴판 구현한 함수를 호출하기 위함.
};
void gotoxy(int x, int y) {							// 커서이동을 하기위한 gotoxy()함수
	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);//  Pos.X가 x좌표고 Pos.Y가 y좌표 인곳으로 옮긴다.
}
void menu::Start()//사용자한테 보이는 메뉴판 인셈
{
	system("cls");//출력창 다 지움.
	for (int i = 0; i < 30; i++)//■로 윗부분 30개 채움
	{
		cout << "■";
	}
	cout << endl;
	for (int i = 1; i < 10; i++)//for문 9번 돌림 
	{
		cout << "■☞" << array[i - 1] << name[i - 1]; gotoxy(18, i); cout << "■[" << price[i - 1] << "]";//번호키,이름과가격
		gotoxy(28, i);
		cout << "■";
		if (Stock[i - 1] > 0)//재고가 있는지 없는지 미리 메뉴판에서 보여줌
			cout << "선택가능";
		else
			cout << "선택불가능";
		gotoxy(38, i);
		cout << "■" << explain[i - 1];//메뉴키 설명
		gotoxy(58, i);
		cout << "■" << endl;
	}
	for (int i = 0; i < 30; i++)//■로 아랫부분 30개 채움
	{
		cout << "■";
	}
	cout << endl;
	cout << "■";
	gotoxy(58, 11);
	cout << "■" << endl;
	for (int i = 0; i < 30; i++)
	{
		cout << "■";// ■로 아랫부분 30개 채움
	}
	gotoxy(0, 13);//(0,13)을 가르켜 메뉴판 밖에서 값 칠수 있게함.
}
void menu::clean()//메뉴판에서 system("cls")를 안쓰고 깔끔하게 보여주기위함
{
	gotoxy(2, 11);//(2,11)을 가르킨뒤
	cout << "                                                        ";//공백 출력하면 (2,11)뒤에 남아있던 문자들이 사라짐.
	gotoxy(2, 11);//다시 (2,11)가르킴
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
	vendingmachine() { keep(); }//자동으로 나오는 생성자하면서 투입된 돈과 매출량 0으로 초기화 Set 함수를 실행하는 keep함수 실행
};
void vendingmachine::set()
{
	gotoxy(0, 13);
	for (int i = 0; i < 10; i++)
		cout << "                                                                          ";
	gotoxy(0, 13);
	cin >> key;
	if (key == 81 || key == 113)//Q를 입력 받으면
	{
		clean();//동전만 입력받기에 clean()함수로 밑부분만 정리한다.
		if (money < 9950)//9950원 미만이면
		{
			cout << "50원이 투입 되었습니다.";
			gotoxy(34, 11);
			cout << "■";
			money = money + 50;
			cout << "현재 투입 금액:" << money;//50원을  투입하고 현재투입금액을 보여준다
		}
		else
		{
			cout << "미사용 금액이 10000원을 초과할수 없습니다.";//넘으면 10000원이상 불가능이라는것을 알려준다.
		}
		gotoxy(0, 13);
	}
	else if (key == 87 || key == 119)//아래와 위와 같다.
	{
		clean();
		if (money < 9900)
		{
			cout << "100원이 투입 되었습니다.";
			gotoxy(34, 11);
			cout << "■";
			money = money + 100;
			cout << "현재 투입 금액:" << money;
		}
		else
		{
			cout << "미사용 금액이 10000원을 초과할수 없습니다.";
		}
		gotoxy(0, 13);
	}
	else if (key == 69 || key == 101)
	{
		clean();
		if (money < 9500)
		{
			cout << "500원이 투입 되었습니다.";
			gotoxy(34, 11);
			cout << "■";
			money = money + 500;
			cout << "현재 투입 금액:" << money;
		}
		else
		{
			cout << "미사용 금액이 10000원을 초과할수 없습니다.";
		}
		gotoxy(0, 13);
	}
	else if (key == 82 || key == 114)
	{
		clean();
		if (money < 9000)
		{
			cout << "1000원이 투입 되었습니다.";
			gotoxy(34, 11);
			cout << "■";
			money = money + 1000;
			cout << "현재 투입 금액:" << money;
		}
		else
		{
			cout << "미사용 금액이 10000원을 초과할수 없습니다.";
		}
		gotoxy(0, 13);
	}
	else if (key == 66 || key == 98)//동전 반환 b키
	{
		clean();
		if (money > 0)
		{
			cout << "동전이 반환 됩니다.";
			money = 0;//money반환 됫기에 0으로 둔다.
		}
		else
			cout << "반환될 동전이 없습니다.";//0원인데 0원을 반환하는건 말이안되니깐
		gotoxy(34, 11);
		cout << "■";
	}
	else if (key >= 49 && key <= 57)//49~57이면 즉 1~9사이의 메뉴판을 보고 눌럿을시
	{
		put = key - 48;//put을 1~9사이로두고 배열에 입력해서 대응 가능하게 하기위해서임
		clean();
		if (Stock[put - 1] > 0)//재고가 0보다 크면
		{
			if (money >= price[put - 1])//투입금액이 price보다 같거나 크면 재고 1개 뺴고 사용가능금액도 금액에서 뺴고 판매량 증가 시켜준다.
			{
				cout << price[put - 1] << "원인 " << name[put - 1] << " 가 나왔습니다";
				sum = sum + price[put - 1];
				money = money - price[put - 1];
				Stock[put - 1] = Stock[put - 1] - 1;
				Sleep(1000);//1초 기다리기 내가 뭐사는지 봐야하니깐
				Start();
			}
			else
				cout << "금액이 부족합니다";
			gotoxy(34, 11);
			cout << "■";
			cout << "사용 가능한 금액:" << money;
			gotoxy(0, 13);
		}
		else
			cout << "재고 없음";//재고가 없기에 재고 없음을 알려줌...
		gotoxy(34, 11);
		cout << "■";
		cout << "사용 가능한 금액:" << money;
		gotoxy(0, 13);
	}
	else if (key == 83 || key == 115)//s 키를 누르면 sum 출력
	{
		clean();
		cout << "자판기 매출 금액:" << sum;
		gotoxy(0, 13);
	}
	else if (key == 70 || key == 102)//f키를 누르면 sum을 =0으로 만듬
	{
		clean();
		cout << "자판기 판매량이 초기화 되었습니다";
		sum = 0;
		gotoxy(0, 13);
	}
	else if (key == 80 || key == 112)//p키 입력받으면 그중에서도 1,2,3,의 선택지를주고 1~9번쨰 또 선택지를주고 그다음 수정을 하게해줌..
	{
		clean();
		cout << "이름 수정:1 가격 수정:2 재고 수정:3 수정x:그 외의 키";
		gotoxy(0, 13);
		char fix;
		cin >> fix;
		if (fix == 49)
		{
			int k;
			clean();
			cout << "몇번쨰 이름을 수정 하시겠습니까?[1~9]";
			gotoxy(0, 13);
			cin >> k;
			gotoxy(2, 11);
			cout << "                                                        ";
			gotoxy(2, 11);
			cout << k << "번째 바꿀 이름을 적으시오.";
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
			cout << "몇번쨰 가격을 수정 하시겠습니까?[1~9]";
			gotoxy(0, 13);
			cin >> k;
			gotoxy(2, 11);
			cout << "                                                        ";
			gotoxy(2, 11);
			cout << k << "번째 바꿀 가격을 적으시오.";
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
			cout << "몇번쨰 재고를 수정 하시겠습니까?[1~9]";
			gotoxy(0, 13);
			cin >> k;
			gotoxy(2, 11);
			cout << "                                                        ";
			gotoxy(2, 11);
			cout << k << "번째 바꿀 재고를 적으시오.";
			gotoxy(0, 13);
			cin >> Stock[k - 1];
			Start();
			gotoxy(2, 11);
			cout << "                                                        ";
		}
		else
		{
			clean();
			cout << "수정을 취소합니다.";
			gotoxy(0, 13);
		}
	}
	else if (key == 88 || key == 120)//굳이 표시는 안해도되지만 사용자가 프로그램 종료를 자기가 했음을 알려주기 위해
	{
		clean();
		cout << "프로그램을 종료합니다";
		gotoxy(0, 13);
	}
	else//지원외의 키를 눌럿을 경우
	{
		clean();
		cout << "지원하지 않는 키입니다.";
		gotoxy(34, 11);
		cout << "■";
	}
}
int main()
{
	vendingmachine();//밴딩머신 호출
	return 0;
}