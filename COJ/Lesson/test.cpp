#include <stdio.h>

int a, b;

int fun1(int a, int b)
{
	return b == 0 ? a : fun1(b, a % b);
}

int fun2(int a, int b)
{
	return a * b / fun1(a, b);
}

int main(int argc, char const *argv[])
{
	scanf("%d,%d", &a, &b);
	printf("���Լ����%d\n", fun1(a, b));
	printf("��С��������%d", fun2(a, b));
	return 0;
}