#include "AccountHandler.h"
#include "NormalAccount.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

void AccountHandler::PrintMenu()const
{
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌계설" << endl;
	cout << "2. 입  금" << endl;
	cout << "3. 출  금 " << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택 : ";
}

void AccountHandler::PrintAll()const
{
	cout << "[전체출력]" << endl;

	for (int i = 0; i < peopleNum; ++i)
	{
		account[i]->ShowInfo();
		cout << endl;
		cout << endl;
	}
}

void AccountHandler::MakeAccount()
{
	int choice;
	cout << "[계좌종류선택]" << endl;
	cout << "1.보통예금계좌" << ' ' << "2.신용신뢰계좌" << endl;
	cout << "선택: ";
	cin >> choice;

	if (choice == 1)
		MakeNormalAccount();
	else if (choice == 2)
		MakeHighCreditAccount();
}

void AccountHandler::MakeNormalAccount()
{
	int id, money, ratio;
	char name[20];

	cout << "[보통 예금 계좌 개설]" << endl;
	cout << "계좌ID : ";
	cin >> id;
	cout << "이름 : ";
	cin >> name;
	cout << "입금액 : ";
	cin >> money;
	cout << "이자율: ";
	cin >> ratio;

	account[peopleNum++] = new NormalAccount(id, name, money, ratio);

	cout << endl;
}
void AccountHandler::MakeHighCreditAccount()
{
	int id, money, ratio, rate;
	char name[20];

	cout << "[신용 신뢰 계좌 개설]" << endl;
	cout << "계좌ID : ";
	cin >> id;
	cout << "이름 : ";
	cin >> name;
	cout << "입금액 : ";
	cin >> money;
	cout << "이자율: ";
	cin >> ratio;
	cout << "신용등급 : ";
	cin >> rate;

	switch (rate)
	{
	case 1:
		account[peopleNum++] = new HighCreditAccount(id, name, money, ratio, LEVEL_A);
		break;
	case 2:
		account[peopleNum++] = new HighCreditAccount(id, name, money, ratio, LEVEL_B);
		break;
	case 3:
		account[peopleNum++] = new HighCreditAccount(id, name, money, ratio, LEVEL_C);
		break;
	}
	cout << endl;
}
void AccountHandler::MoneyIn()
{
	int id, money;
	cout << "[입  금]" << endl;
	cout << "계좌ID : ";
	cin >> id;

	//계좌 ID로
	for (int i = 0; i < peopleNum; ++i)
	{
		if (account[i]->GetID() == id)
		{
			cout << "입금액 :";
			cin >> money;
			account[i]->PlusMoney(money);
			cout << "입금완료" << endl;
			return;
		}
	}
	cout << "없는 ID 입니다" << endl;
	cout << endl;
}

void AccountHandler::MoneyOut()
{
	int id, money;
	cout << "[출  금]" << endl;
	cout << "계좌ID : ";
	cin >> id;

	//계좌 ID로
	for (int i = 0; i < peopleNum; ++i)
	{
		if (id == account[i]->GetID())
		{
			cout << "출금액 :";
			cin >> money;
			account[i]->MinusMoney(money);
			cout << "출금완료" << endl;
		}

		else
		{
			cout << "없는 ID 입니다" << endl;
			return;
		}
	}
	cout << endl;
}