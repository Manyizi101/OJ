#include <stdio.h>

int a, b;

int fun1(int a, int b)
{
}

int fun2(int a, int b)
{
	return a * b / fun1(a, b);
}

int main(int argc, char const *argv[])
{
	return 0;
}