#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<string>  
int main()
{
	int a, a1, b, b1, c1, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r;
n1:
	printf("//ModbusTCP Macro�﷨�Զ�������\n//�����վ��ַ(���������һλ):");
	scanf_s("%d", &j);
	printf("//����1���ɶ�ȡ��䣬����2����д����䣬�������������Զ����:");
	scanf_s("%d", &k);
	if (k == 1)
	{
		printf("//����slaveװ�����϶�ȡ��ʼλַ��");
		scanf_s("%d", &l);
		printf("//����ش����ϴ�ŵ���ʼRֵ��");
		scanf_s("%d", &m);
		printf("//�����ȡ������������");
		scanf_s("%d", &n);
		printf("//��ȡһ��������ϣ�\nG10 L1900 C3 I%d A%d Q%d K%d;\n", j, l, m, n);
	}
	else if (k == 2)
	{
		printf("//����slaveװ������д��λַ��");
		scanf_s("%d", &l);
		printf("//����д�������(0~65535)��");
		scanf_s("%d", &m);
		printf("//дһ�����ϣ�\nG10 L1900 C6 I%d A%d X%d;", j, l, m);
	}
	else
	{
		printf("//�����Զ������ϲο�����ʼRֵ:");
		scanf_s("%d", &a);
		a1 = a;
		printf("//�����վ������ʼλ��(������´���������Ϊ��վ����Ӧ�Ĵ���λ��*2���룩:");
		scanf_s("%d", &l);
		if (l <= 255)
			b = 0, c = l;
		else
		{
			b = l / 256;
			c = l - 256 * b;
		}
		//printf("��һ���Ĵ��������ݵ�ַ= %d\n��һ���Ĵ��������ݵ�ַ=%d\n", b, c);
		printf("//����ش����ϴ�ŵ���ʼRֵ��");
		scanf_s("%d", &m);
		printf("//����д�������������");
		scanf_s("%d", &n);
		o = n;
		p = 1;
		q = a + 7 + 4 * n;
		i = 2 * n;
		if (n <= 255)
			b1 = 0, c1 = i;
		else
		{
			b1 = i / 256;
			c1 = i - 256 * b1;
		}
		printf("//�Զ���Modbus�����\n");
		printf("G10 L1000 P%d R%d;\n", a++, j);
		printf("G10 L1000 P%d R16;\n", a++);
		printf("G10 L1000 P%d R%d;\n", a++, b);
		printf("G10 L1000 P%d R%d;\n", a++, c);
		printf("G10 L1000 P%d R%d;\n", a++, b1);
		printf("G10 L1000 P%d R%d;\n", a++, c1);
		printf("G10 L1000 P%d R%d;\n", a++, 4 * n);
		do
		{
			printf("//�����%d����ֵ:", p++);
			scanf_s("%d", &d);
			if (d >= 0)
			{
				e = d / 16777216;
				f = (d % 16777216) / 65536;
				g = (d % 16777216) % 65536 / 256;
				h = (d % 16777216) % 65536 % 256;
				//0~2147483647
			}
			else
			{
				r = 2147483648 + d;
				e = r / 16777216 + 128;
				f = (r % 16777216) / 65536;
				g = (r % 16777216) % 65536 / 256;
				h = (r % 16777216) % 65536 % 256;
				//-1~-2147483648
			}

			//printf("��д�����ֵΪ%d������4������ֵ%d��%d��%d��%d\n", d, e, f, g, h);
			printf("G10 L1000 P%d R%d;\n", a++, e);
			printf("G10 L1000 P%d R%d;\n", a++, f);
			printf("G10 L1000 P%d R%d;\n", a++, g);
			printf("G10 L1000 P%d R%d;\n", a++, h);
		} while (a < q);
		printf("G10 L1901 P%d R%d Q%d K6;\n//��ӡ����", a1, 7 + 4 * n, m);
	}
	printf("\n//��Enter����ʹ�ã���ֱ�ӹرճ���");
	getchar();
	getchar();
	goto n1;
	return 0;
}