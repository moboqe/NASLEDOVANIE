#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

class STRING
{
	//protected:
public:
	char *str;
	int len;
public:
	STRING()
	{
		str = new char;    //constructor without parametrs
		str[0] = '\0';
		len = 0;
	}

	STRING(char *st)
	{
		int i = 0;
		while (st[i] != '\0')   //constructor with C string
			i++;
		len = i;
		str = new char[i];
		strcpy(str, st);
	}

	STRING(char st)         //construcnor for symbol
	{
		str = new char;
		str[0] = st;
		str[1] = '\0';
		len = 1;
	}

	STRING(const STRING & str1)  //copy constructor
	{
		str = new char;
		len = str1.len;
		strcpy(str, str1.str);
	}
	char *GetWord()
	{
		if (str) return str; else return nullptr;
	}
	void show()
	{
		std::cout << str << "   " << len << std::endl;
	}
	int dlina(char *st)
	{
		int i;
		while (st[i] != '\0')
			i++;
		len = i;
		return len;
	}
	char *clear(char *st)   //function clear
	{
		st[0] = '\0';
		strcpy(str, st);
		return str;
	}
	~STRING() { len = 0; }  //destructor
	//~STRING() { delete str; len=0;}  //destructor

};



class BITSTRING : public STRING    //child
{
public:
	BITSTRING()
	{                //constructor  without parametrs
		STRING();
	}

	BITSTRING(char *st) :STRING(st)
	{

		int i = 0;
		while (str[i] != '\0')
		{
			if ((str[i] != '0') && (str[i] != '1')) {
				str[0] = '\0';
				len = 0;
				break;
			}
			i++;
		}
	}

	BITSTRING(char st) :STRING(st)         //construcnor for symbol
	{
		//STRING(st)
		if ((str[0] != '0') && (str[0] != '1')) {
			str[0] = '\0';
			len = 0;
		}
	}
	BITSTRING(const BITSTRING & b) :STRING(b)  //copy constructor
	{
		str = new char;
		len = b.len;
		strcpy(str, b.str);
	}

	//~BITSTRING() { delete str; }; 
	~BITSTRING()
	{
		STRING::~STRING();
	}


	/*char *negative_number()
	{
		int *mas;
		mas = new int[10];                              //convert to negative number
		int i, j, smart;
		if (str[0] == '-')
		{
			i = 1;
			while (str[i] != '\0')
			{
				if (str[i] == '0') str[i] = '1';
				if (str[i] == '1') str[i] = '0';
				i++;
				j += i;
			}
			i = 0;
			j++;
			while (str[j] != '\0')
			{
				if (str[j] = '1') { str[j + 1] = 0; smart = 1; }

			}
			return str;
		}
		return nullptr;
	}*/

	/*	BITSTRING operator == (BITSTRING *str1, *str2;)
		{
			int l1, l2, i
				if (l1 == l2) {
					while l1 > 0 {if (str1[i] != str2[i]) return false; i++; }
				else return false;
				}
		};
		BITSTRING operator + (BITSTRING *str1, *str2; )
		{
			int mas1, mas2, a1, a2, b1, b2, s, sn = 0, l1, l2, i, j;
			int *mas;
			mas = new int[10];
			mas1 = int atoi(str.str1);
			mas2 = int atoi(str.str2);
			int l1 = strlen(str.str1);
			int l2 = strlen(str.str2);
			l = l1 + l2;
			sn = 0;
			for (i = l; l - 1 < i; i++)
			{
				a1 = mas1 % 10;       // mod
				a2 = mas2 % 10;
				b1 = mas1 / 10;       // div
				b2 = mas2 / 10;
				mas1 = b1;
				mas2 = b2
					s = a1 + a2 + sn;
				if s = 0{ mas[i] = 0 sn = 0 }
					if s = 1 {mas[i] = 1 sn = 0}
				if s = 2 {mas[i] = 0 sn = 1}
				if s = 3 {mas[i] = 1 sn = 1}
			}
			while (l > i) {
				char *itoa(int *mas[i], char *str[i], int 10);
				i++;
			}
			return str;
}*/
	const BITSTRING operator =(const BITSTRING & b)
	{
		if (str) free(str);
		if (b.str)
		{
			str = _strdup(b.str);
			len = b.len;
		}
		else
		{
			str = nullptr;
			len = 0;
		}
		return ' ';
	}
	const BITSTRING  operator +(const BITSTRING & b)
	{
		int m, p = 0, a1, a2;
		if (len > b.len) m = len; else m = b.len;
		char *bit = new char[m + 1];
		memset(bit, '0', m);
		bit[m] = 0;
		int n1 = len - 1, n2 = b.len - 1;
		for (int n = m - 1; n >= 0; n--)
		{
			if (n1 >= 0) a1 = str[n1] - '0';
			else a1 = 0;
			if (n2 >= 0) a2 = b.str[n2] - '0';
			else a2 = 0;
			switch (a1 + a2 + p)
			{
			case 3:
				bit[n] = 1;
				p = 2;
				break;
			case 2:
				bit[n] = '0';
				p = 1;
				break;
			case 1:
				bit[n] = '1';
				p = 0;
				break;
			case 0:
				bit[n] = '0';
				p = 0;
				break;
			}
			n1--;
			n2--;
		}
		return BITSTRING(bit);
	}
	int  operator ==(const BITSTRING & b)
	{
		int l;
		if (len > b.len) l = len; else l = b.len;
		int n1 = len - 1, n2 = b.len - 1, k;
		k = l - 1;
		while (k >= 0)
		{

			if ((n1 >= 0) && (n2 >= 0) && (str[n1] != b.str[n2])) return 0;
			if ((n1 < 0) && (b.str[n2] != '0')) return 0;
			if ((n2 < 0) && (str[n1] != '0')) return 0;
			k--; n1--; n2--;
		}
		return 1;
	}
};

int main()
{
	setlocale(LC_ALL, "RUS");
	char alfa1[] = "0101";
	char alfa2[] = "0011";
	char alfa3[] = "not a bitstring";
	char alfa4[] = "-1100";
	BITSTRING s1(alfa1);
	std::cout << "0101- "; s1.show();
	BITSTRING s2(s1);
	std::cout << "0101- ";  s2.show();
	BITSTRING s3('n');
	std::cout << "n- ";  s3.show();
	BITSTRING s4(alfa3);
	std::cout << "not a bitstring- ";  s4.show();
	/*BITSTRING s6(alfa4);
	s6.negative_number();
	s6.show();*/
	/*	char *slovo1 = alfa1;
		char *slovo2 = alfa2;*/
	BITSTRING *a = new BITSTRING(alfa1);
	BITSTRING *b = new BITSTRING(alfa2);
	BITSTRING c;
	printf("Тестирование функции GetWord(Объект a)- %s\n", a->GetWord());
	std::cout << "Тестирование функции show(Объект a)- "; a->show();
	printf("Тестирование функции GetWord(Объект b)- %s\n", b->GetWord());
	std::cout << "Тестирование функции show(Объект b)- "; b->show();
	if (*a == *b) printf("a==b\n");
	else printf("a!=b\n");
	c = (*a) + (*b);
	printf("%s\n", c.GetWord());
	system("pause");

	return 0;
}
