#pragma once

#include "iostream"
#include "cstring"

using namespace std;
class Port
{
private:
	char * brand;
	char style[20];
	int bottles;
public:
	Port(const char *br = "none", const char * st = "none", int b = 0);
	Port(const Port & p);
	virtual ~Port();
	Port & operator=(const Port &p);
	Port & operator+=(int b);
	Port & operator-=(int b);
	int BottleCount()const;
	virtual void Show()const;
	friend ostream& operator<<(ostream & os, const Port & p);
};

class VintagePort :public Port
{
private:
	char *nickname;
	int year;
public:
	VintagePort();
	VintagePort(const char *br, int b, const char * nn, int y);
	VintagePort(const VintagePort &vp);
	~VintagePort()
	{
		delete[] nickname;
	}
	VintagePort & operator=(const VintagePort & vp);
	void Show()const;
	friend ostream & operator<<(ostream & os, const VintagePort & vp);
};


Port::Port(const char *br, const char * st, int b)
{
	int len = strlen(br) + 1;
	brand = new char[len];
	strcpy(brand, br);
	strcpy(style, st);
	bottles = b;
}
Port::Port(const Port & p)
{
	int len = strlen(p.brand) + 1;
	brand = new char[len];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;
}
Port::~Port()
{
	delete[] brand;
}
Port & Port::operator=(const Port &p)
{
	if (&p == this)
	{
		return *this;
	}
	else
	{
		delete[] brand;
		int len = strlen(p.brand) + 1;
		brand = new char[len];
		strcpy(brand, p.brand);
		strcpy(style, p.style);
		bottles = p.bottles;
		return *this;
	}
}
Port & Port::operator+=(int b)
{
	bottles += b;
	return *this;
}
Port & Port::operator-=(int b)
{
	bottles -= b;
	return *this;
}
int Port::BottleCount()const
{
	return bottles;
}
void Port::Show()const
{
	cout << brand << endl;
	cout << style << endl;
	cout << bottles << endl;
}
ostream& operator<<(ostream & os, const Port & p)
{
	os << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}


VintagePort::VintagePort()
	:Port()
{
	nickname = "none";
	year = 0;
}
VintagePort::VintagePort(const char *br, int b, const char * nn, int y)
	:Port(br, "none", b)
{
	int len = strlen(nn) + 1;
	nickname = new char[len];
	strcpy(nickname, nn);
	year = y;
}
VintagePort::VintagePort(const VintagePort &vp)
	:Port(vp)
{
	int len = strlen(vp.nickname) + 1;
	nickname = new char[len];
	strcpy(nickname, vp.nickname);
	year = vp.year;
}
VintagePort & VintagePort::operator=(const VintagePort & vp)
{
	if (&vp == this)
	{
		return *this;
	}
	else
	{
		Port::operator=(vp);
		delete[]nickname;
		int len = strlen(vp.nickname) + 1;
		nickname = new char[len];
		strcpy(nickname, vp.nickname);
		year = vp.year;
		return *this;
	}	
}
void VintagePort::Show()const
{
	Port::Show();
	cout << nickname << endl;
	cout << year << endl;
}
ostream & operator<<(ostream & os, const VintagePort & vp)
{
	os << (const Port &)vp << ", " << vp.nickname << ", " << vp.year;
	return os;
}