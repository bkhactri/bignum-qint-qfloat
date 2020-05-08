﻿#include"UI.h"

// dịch vị trí con trỏ
void gotoxy(int column, int line)
{
	COORD coord = { column,line };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// text color
void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// ẩn con trỏ console
void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

// hàm di chuyển
int Move()
{
	int flag = 1;
	while (flag)
	{
		char c = _getch();
		if (int(c) == 80 || int(c) == 72 || int(c) == 13)
		{
			switch (int(c))
			{
			case 80:
				return 1;			// Xuong
			case 72:
				return 2;			// Len
			case 13:
				return 3;			// Enter
			default:
				break;
			}
			flag = 0;
		}
		else
		{
			flag = 1;
		}
	}
}

// tạo khung lớn
void BigFrame()
{
	// Khung lon
	for (int i = 20; i < 165; i++) // tao dong ngang
	{
		gotoxy(i, 5); cout << char(205); // dong ngang tren
		gotoxy(i, 27); cout << char(205);  // dong ngang duoi
	}

	for (int i = 49; i < 164; i++)		// dong ngang giua
	{
		gotoxy(i, 16); cout << char(205);
	}

	for (int i = 21; i < 49; i++)
	{
		gotoxy(i, 18); cout << char(205);
	}

	for (int i = 5; i <= 26; i++)  // dong ke thang dung
	{
		gotoxy(20, i); cout << char(186); // dong thang ben trai
		gotoxy(165, i); cout << char(186); // dong thang ben phai
	}

	for (int i = 6; i <= 26; i++)
	{
		gotoxy(48, i); cout << char(186); // dong thang o giua
	}

	for (int i = 17; i <= 26; i++)
	{
		gotoxy(88, i); cout << char(186);
		gotoxy(127, i); cout << char(186);
	}

	gotoxy(165, 5); cout << char(187); // cai moc cau ben phai ben tre^n
	gotoxy(165, 27); cout << char(188); // cai moc cau ben phai ben duoi
	gotoxy(20, 5); cout << char(201); // cai moc cau ben trai tren
	gotoxy(20, 27); cout << char(200); // moc cau ben trai duoi

	gotoxy(24, 20);	cout << "Huong dan su dung:";
	gotoxy(22, 22);	cout << "Mui ten xuong : Di xuong";
	gotoxy(22, 23);	cout << "Mui ten len : Di len";
	gotoxy(22, 24);	cout << "Enter : Chon";
	gotoxy(49, 18);	cout << " BIN : ";
	gotoxy(89, 18);	cout << " DEC : ";
	gotoxy(128, 18); cout << " HEX : ";
}

// tạo 2 khung nhỏ bên trong
void Frame_1()
{
	gotoxy(55, 9);	cout << "Nhap so X :";
	gotoxy(55, 13); cout << "Nhap so Y :";
	// Khung tren
	for (int i = 75; i < 155; i++) // tao dong ngang
	{
		gotoxy(i, 8); cout << char(205); // dong ngang tren
		gotoxy(i, 10); cout << char(205);  // dong ngang duoi
	}

	gotoxy(75, 9); cout << char(186); // dong thang ben trai
	gotoxy(155, 9); cout << char(186); // dong thang ben phai

	gotoxy(155, 8); cout << char(187); // cai moc cau ben phai ben tre^n
	gotoxy(155, 10); cout << char(188); // cai moc cau ben phai ben duoi
	gotoxy(75, 8); cout << char(201); // cai moc cau ben trai tren
	gotoxy(75, 10); cout << char(200); // moc cau ben trai duoi

	// Khung duoi
	for (int i = 75; i < 155; i++) // tao dong ngang
	{
		gotoxy(i, 12); cout << char(205); // dong ngang tren
		gotoxy(i, 14); cout << char(205);  // dong ngang duoi
	}

	gotoxy(75, 13); cout << char(186); // dong thang ben trai
	gotoxy(155, 13); cout << char(186); // dong thang ben phai

	gotoxy(155, 12); cout << char(187); // cai moc cau ben phai ben tre^n
	gotoxy(155, 14); cout << char(188); // cai moc cau ben phai ben duoi
	gotoxy(75, 12); cout << char(201); // cai moc cau ben trai tren
	gotoxy(75, 14); cout << char(200); // moc cau ben trai duoi
}

// tạo 1 khung nhỏ bên trong
void Frame_2()
{
	gotoxy(55, 11);	cout << "Nhap so X :";
	for (int i = 75; i < 155; i++)
	{
		gotoxy(i, 10); cout << char(205);
		gotoxy(i, 12); cout << char(205);
	}
	gotoxy(75, 11); cout << char(186); // dong thang ben trai
	gotoxy(155, 11); cout << char(186); // dong thang ben phai

	gotoxy(155, 10); cout << char(187); // cai moc cau ben phai ben tre^n
	gotoxy(155, 12); cout << char(188); // cai moc cau ben phai ben duoi
	gotoxy(75, 10); cout << char(201); // cai moc cau ben trai tren
	gotoxy(75, 12); cout << char(200); // moc cau ben trai duoi
}

// xóa vị trí nhập vào
void deleteInput()
{
	for (int i = 7; i <= 14; i++)
	{
		for (int j = 55; j <= 159; j++)
		{
			gotoxy(j, i); cout << " ";
		}
	}
}

// xóa vị trí xuất ra 
void deleteOutPut()
{
	// clear Bin
	for (int i = 20; i < 24; i++)
	{
		for (int j = 50; j < 88; j++)
		{
			gotoxy(j, i);
			cout << " ";
		}
	}

	// clear Dec
	for (int i = 20; i < 24; i++)
	{
		for (int j = 91; j < 126; j++)
		{
			gotoxy(j, i);
			cout << " ";
		}
	}

	//clear Hex
	for (int i = 20; i < 24; i++)
	{
		for (int j = 130; j < 163; j++)
		{
			gotoxy(j, i);
			cout << " ";
		}
	}
}

// xóa menu
void deleteMenu()
{

	for (int i = 7; i < 18; i++)
	{
		for (int j = 25; j < 48; j++)
		{
			gotoxy(j, i);
			cout << " ";
		}
	}
}

// xuất kết quả
void OutPut(string s, string q, string p)
{
	if (s.size() != 0)
	{
		int k = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (i < 32)
			{
				gotoxy(50 + k, 20);
				cout << s[i];
			}
			else if (i < 64)
			{
				gotoxy(50 + k, 21);
				cout << s[i];
			}
			else if (i < 96)
			{
				gotoxy(50 + k, 22);
				cout << s[i];
			}
			else {
				gotoxy(50 + k, 23);
				cout << s[i];
			}
			k++;
			if (k == 32)
			{
				k = 0;
			}
		}
	}

	if (q.size() != 0)
	{
		int l = 0;
		for (int i = 0; i < q.size(); i++)
		{
			if (i < 32)
			{
				gotoxy(91 + l, 20);
				cout << q[i];
			}
			else {
				gotoxy(91 + l, 21);
				cout << q[i];
			}
			l++;
			if (l == 32)
			{
				l = 0;
			}
		}
	}

	if (p.size() != 0)
	{
		int t = 0;
		for (int i = 0; i < p.size(); i++)
		{
			if (i < 32)
			{
				gotoxy(130 + t, 20);
				cout << p[i];
			}
			else {
				gotoxy(130 + t, 21);
				cout << p[i];
			}
			t++;
			if (t == 32)
			{
				t = 0;
			}
		}
	}
}

// kiểm tra enter, esc
void checkEnter()
{
	int flag = 1;
	while (flag)
	{
		char c = _getch();
		if (int(c) == 13 || int(c) == 27)
		{
			flag = 0;
			deleteInput();
			deleteOutPut();
		}
		else flag = 1;
	}
}

// kiểm tra nhập thập phân
int checkDec(string s)
{
	int flag = 1;
	if (s.size() == 1 && s == "-")
	{
		return 0;
	}
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9' && (s[0] = '-' || (s[0] >= '0' && s[0] <= '9')))
		{
			flag = 1;
		}
		else {
			flag = 0;
			break;
		}
	}
	return flag;
}

// kiểm tra nhập nhị phân
int checkBin(string s)
{
	int flag = 1;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '0' || s[i] == '1')
		{
			flag = 1;
		}
		else {
			flag = 0;
			break;
		}
	}
	return flag;
}

// kiểm tra nhập thập lục phân
int checkHex(string s)
{
	int flag = 1;
	for (int i = 0; i < s.size(); i++)
	{
		if ((s[i] >= 'a' && s[i] <= 'f' || (s[i] >= '0' && s[i] <= '9')) || (s[i] >= 'A' && s[i] <= 'F') || (s[i] >= '0' && s[i] <= '9'))
		{
			flag = 1;
		}
		else {
			flag = 0;
			break;
		}
	}
	return flag;
}

// kiểm tra chia
int checkDiv(string s)
{
	int flag = 1;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '0')
		{
			flag = 1;
		}
		else {
			flag = 0;
			break;
		}
	}
	return flag;
}