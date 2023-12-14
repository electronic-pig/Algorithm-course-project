#include "head.h"
//���㺯����aΪ�����,b��c�ֱ�Ϊ����
double Cal(char a, double b, double c) {
	switch (a) {
	case '+':
		return (b + c);
		break;
	case '-':
		return (b - c);
		break;
	case '*':
		return (b * c);
		break;
	case '/':
		return (1.0 * b / c);
		break;
	default:
		return 0;
	}
}
//���ַ����ַ�ת��Ϊ��׺���ʽ,�洢����׺���ʽջ��
void transfer() {
	int flag = 0;
	char ch = expression[0];
	int i = 0;
	while (ch != '=') {
		// ��������ַ������ֻ�С���㣬ֱ�Ӵ���
		if (ch >= '0' && ch <= '9' || ch == '.') {
			// ��ʼ�ַ�
			if (flag == 0) {
				es1.stack[++es1.top][++es1.index] = ch;
				flag = 1;
			}
			// ǰһ������Ϊ���ֻ򸺺ţ����������
			else if (flag == 1) {
				es1.stack[es1.top][++es1.index] = ch;
				flag = 1;
			}
			// flag == 2  // ǰһ������Ϊ����������һ����
			else {
				es1.index = -1;
				es1.stack[++es1.top][++es1.index] = ch;
				flag = 1;
			}
		}
		// ��������ַ��ǳ���'-'���������ţ���һ����
		else if (ch == '+' || ch == '*' || ch == '/' || ch == '(' || ch == ')') {
			es1.index = -1;
			es1.stack[++es1.top][++es1.index] = ch;
			flag = 2;
		}
		//���'-'�Ǽ��Ż��Ǹ���
		else if (ch == '-') {
			//�����-�������ڱ��ʽ��λ���Һ���������֣���ô��ʱΪ����
			if (i == 0 && expression[1] >= '0' && expression[1] <= '9') {
				es1.stack[++es1.top][++es1.index] = ch;
				flag = 1;
			}
			//�����-�������ڱ��ʽ��λ���Һ�����������ţ���ô��ʱΪ���ţ��������ַ���������λ���0����� �� 0 - ��xxx��������ʽ
			if (i == 0 && expression[1] == '(') {
				es1.stack[++es1.top][++es1.index] = '0';
				es1.index = -1;
				es1.stack[++es1.top][++es1.index] = ch;
				flag = 2;
			}
			//����� - �������������ź��棬��ô��ʱΪ���ţ��ϲ�������������ַ�����
			if (i > 0 && expression[i - 1] == '(') {
				es1.index = -1;
				es1.stack[++es1.top][++es1.index] = ch;
				flag = 1;
			}
			else if (i > 0) {
				//��һ����
				es1.index = -1;
				es1.stack[++es1.top][++es1.index] = ch;
				flag = 2;
			}
		}
		i++;
		ch = expression[i];
	}
}
//��׺���ʽ��ֵ
double in_getOutput() {
	char a;
	double b;
	double c;
	int temp = 0;//��������ƥ��
	//������׺���ʽ��ά����
	for (int i = 0; i <= es1.top; i++) {
		//����ǼӺŻ���ţ���ôջ������������ó���������
		if ((es1.stack[i][0] == '+' || es1.stack[i][0] == '-') && es1.stack[i][1] == '\0') {
			//��������ջΪ�գ�����������������ջ
			if (os1.top == -1) {
				os1.stack[++os1.top] = es1.stack[i][0];
			}
			else {
				while (os1.stack[os1.top] == '+' || os1.stack[os1.top] == '-' || os1.stack[os1.top] == '*' || os1.stack[os1.top] == '/') {
					b = ns1.stack[ns1.top--];//ȡ��һ������
					c = ns1.stack[ns1.top--];//��ȡ��һ������
					a = os1.stack[os1.top--];//������ջ��Ԫ���ó�
					ns1.stack[++ns1.top] = Cal(a, b, c);//������Ҫ������ջ
				}
				os1.stack[++os1.top] = es1.stack[i][0];//��������֮��������Ҫ��ջ
			}
		}
		//����ǳ˺Ż���ţ���ֻ��ջ��Ҳ�ǳ˳���ʱ����Ҫ����
		else if (es1.stack[i][0] == '*' || es1.stack[i][0] == '/') {
			//ͬ��
			if (os1.top == -1) {
				os1.top++;
				os1.stack[os1.top] = es1.stack[i][0];
			}
			else {
				while (os1.stack[os1.top] == '*' || os1.stack[os1.top] == '/') {
					a = os1.stack[os1.top--];//ͬ��
					c = ns1.stack[ns1.top--];//ͬ��
					b = ns1.stack[ns1.top--];//ͬ��
					ns1.stack[++ns1.top] = Cal(a, b, c);//ͬ��
					ns1.stack[ns1.top + 1] = 0;//ջ����һ��Ԫ�����
					os1.stack[os1.top + 1] = '\0';//ջ����һ��Ԫ�����
				}
				os1.stack[++os1.top] = es1.stack[i][0];//ͬ��
			}
		}
		//�������������ֱ��ѹ��ջ2
		else if (es1.stack[i][0] == '(') {
			os1.top++;
			os1.stack[os1.top] = es1.stack[i][0];
			temp++;
		}
		//����������ţ�������һ��������ǰ�����в���������󽫴�������ֱ�ӵ���
		else if (es1.stack[i][0] == ')') {
			if (temp > 0) {
				while (os1.stack[os1.top] != '(') {
					a = os1.stack[os1.top--];
					c = ns1.stack[ns1.top--];
					b = ns1.stack[ns1.top--];
					ns1.stack[++ns1.top] = Cal(a, b, c);
					ns1.stack[ns1.top + 1] = 0;//ջ����һ��Ԫ�����
					os1.stack[os1.top + 1] = '\0';//ջ����һ��Ԫ�����
				}
				os1.top--;//��������ֱ�ӵ���
				os1.stack[os1.top + 1] = '\0';//ջ����һ��Ԫ�����
				temp--;
			}
		}
		//������ǲ�������ֱ�ӽ�ȥ
		else {
			ns1.stack[++ns1.top] = atof(es1.stack[i]);//���֣�תΪ����
		}
	}
	//���������ջ��Ϊ�գ�����ʣ�²�����
	while (os1.top != -1) {
		a = os1.stack[os1.top--];
		c = ns1.stack[ns1.top--];
		b = ns1.stack[ns1.top--];
		ns1.stack[++ns1.top] = Cal(a, b, c);
		ns1.stack[ns1.top + 1] = 0;//ջ����һ��Ԫ�����
	}
	return ns1.stack[ns1.top];
}