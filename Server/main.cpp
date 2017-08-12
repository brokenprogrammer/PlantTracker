#include <iostream>
#include <Python.h>
#include "WebsiteAuto.h"

int main()
{
	std::cout << "Hello, World!" << std::endl;

	wchar_t* title = L"Hello";

	Py_SetProgramName(title);
	Py_Initialize();
	PyRun_SimpleString("print ('Hello World.')");
	Py_Finalize();

	WebsiteAuto web;
	web.open("test");

	int temp = 0;
	std::cin >> temp;
	return 0;
}