//#include "13-1.h"
//
//#include "iostream"
//using namespace std;
//void Bravo(const Cd & disk);
//int main()
//{
//	Cd c1("Beatles", "Capitol", 14, 35.5);
//	Classic c2 = Classic("Piano Sonta in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
//	Cd *pcd = &c1;
//	cout << "Using object directly:" << endl;
//	c1.Report();
//	c2.Report();
//	cout << "Using type cd * pointer to objects:" << endl;
//	pcd->Report();
//	pcd = &c2;
//	pcd->Report();
//	cout << "Calling a function with a Cd reference argument:" << endl;
//	Bravo(c1);
//	Bravo(c2);
//	cout << "Testing assignment: ";
//	Classic copy;
//	copy = c2;
//	copy.Report();
//	return 0;
//}
//void Bravo(const Cd & disk)
//{
//	disk.Report();
//}
#include<iostream>  
#include"13.4.h"
using namespace std;

int main()
{
	Port port("mybrand", "mystyle", 100);
	cout << port << endl;
	port += 10;
	cout << port << endl;
	port -= 100;
	port.Show();
	VintagePort vin("secBrand", 100, "mynickname", 50);
	cout << vin << endl;
	vin += 30;
	vin.Show();
	return 0;
}