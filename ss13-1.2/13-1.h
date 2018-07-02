#pragma once
#include "iostream"
#include "cstring"
using namespace std;


class Cd
{
private:
	char performers[50];
	char label[20];
	int selections;
	double playtime;
public:
	Cd(char *s1, char * s2, int n, double x);
	Cd(const Cd & d);
	Cd();
	virtual ~Cd();
	virtual void Report() const;
	Cd & operator= (const Cd &d);
};


class Classic : public Cd
{
private:
	char zuopin[20];
public:
	Classic();
	Classic(char *s1, char *s2,  char * s3, int n, double x);
	Classic(const Cd & cl, char s[20]);
	virtual ~Classic();
	virtual void Report() const;
	Classic & operator= (const Classic &cl);
};


Cd::Cd()
{

}
Cd::~Cd()
{

}
Cd::Cd(char *s1, char * s2, int n, double x)
{
	strcpy(performers, s1);
	strcpy(label, s2);
	selections = n;
	playtime = x;
}
Cd::Cd(const Cd & d)
{
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}
void Cd::Report()const
{
	cout << performers << endl;
	cout << label << endl;
	cout << selections << endl;
	cout << playtime << endl;
}
Cd& Cd::operator=(const Cd &d)
{
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}


Classic::Classic()
{

}
Classic::~Classic()
{

}
Classic::Classic(char *s1, char *s2, char * s3, int n, double x)
	:Cd(s1, s2, n, x)
{
	strcpy(zuopin, s3);
}
Classic::Classic(const Cd & cl, char s[20])
	: Cd(cl)
{
	strcpy(zuopin, s);
}
void Classic::Report()const
{
	Cd::Report();
	cout << zuopin << endl;
}
Classic & Classic::operator= (const Classic &cl)
{
	Cd::operator=(cl);
	strcpy(zuopin, cl.zuopin);
	return *this;
}

