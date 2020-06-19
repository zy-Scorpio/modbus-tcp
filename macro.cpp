#include<stdio.h>
#include<iostream>
#include<cstdlib>
#include<string>  
int main()
{
	int a, a1, b, b1, c1, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r;
n1:
	printf("//ModbusTCP Macro语法自动生成器\n//输入从站地址(局域网最后一位):");
	scanf_s("%d", &j);
	printf("//输入1生成读取语句，输入2生成写入语句，输入其他生成自定语句:");
	scanf_s("%d", &k);
	if (k == 1)
	{
		printf("//输入slave装置资料读取起始位址：");
		scanf_s("%d", &l);
		printf("//输入回传资料存放的起始R值：");
		scanf_s("%d", &m);
		printf("//输入读取的资料数量：");
		scanf_s("%d", &n);
		printf("//读取一至多笔资料：\nG10 L1900 C3 I%d A%d Q%d K%d;\n", j, l, m, n);
	}
	else if (k == 2)
	{
		printf("//输入slave装置资料写入位址：");
		scanf_s("%d", &l);
		printf("//输入写入的资料(0~65535)：");
		scanf_s("%d", &m);
		printf("//写一笔资料：\nG10 L1900 C6 I%d A%d X%d;", j, l, m);
	}
	else
	{
		printf("//输入自定义资料参考的起始R值:");
		scanf_s("%d", &a);
		a1 = a;
		printf("//输入从站接收起始位置(如果是新代控制器作为从站，对应寄存器位置*2输入）:");
		scanf_s("%d", &l);
		if (l <= 255)
			b = 0, c = l;
		else
		{
			b = l / 256;
			c = l - 256 * b;
		}
		//printf("第一个寄存器的数据地址= %d\n第一个寄存器的数据地址=%d\n", b, c);
		printf("//输入回传资料存放的起始R值：");
		scanf_s("%d", &m);
		printf("//输入写入的资料数量：");
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
		printf("//自定义Modbus封包：\n");
		printf("G10 L1000 P%d R%d;\n", a++, j);
		printf("G10 L1000 P%d R16;\n", a++);
		printf("G10 L1000 P%d R%d;\n", a++, b);
		printf("G10 L1000 P%d R%d;\n", a++, c);
		printf("G10 L1000 P%d R%d;\n", a++, b1);
		printf("G10 L1000 P%d R%d;\n", a++, c1);
		printf("G10 L1000 P%d R%d;\n", a++, 4 * n);
		do
		{
			printf("//输入第%d的数值:", p++);
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

			//printf("欲写入的数值为%d，需拆成4个资料值%d、%d、%d、%d\n", d, e, f, g, h);
			printf("G10 L1000 P%d R%d;\n", a++, e);
			printf("G10 L1000 P%d R%d;\n", a++, f);
			printf("G10 L1000 P%d R%d;\n", a++, g);
			printf("G10 L1000 P%d R%d;\n", a++, h);
		} while (a < q);
		printf("G10 L1901 P%d R%d Q%d K6;\n//打印结束", a1, 7 + 4 * n, m);
	}
	printf("\n//按Enter继续使用，或直接关闭程序");
	getchar();
	getchar();
	goto n1;
	return 0;
}