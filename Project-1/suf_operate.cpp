#include "head.h"
//�ɱ��ʽ�ַ���ת��Ϊ��׺���ʽջ
void getInput() {
	int flag = 0;
	char ch = expression[0];
	int i = 0;
	while (ch != '=') {
		// ��������ַ������ֻ�С���㣬ֱ�Ӵ���
		if (ch >= '0' && ch <= '9' || ch == '.') {
			// ��ʼ�ַ�
			if (flag == 0) {
				es.stack[++es.top][++es.index] = ch;
				flag = 1;
			}
			// ǰһ������Ϊ���ֻ򸺺ţ����������
			else if (flag == 1) {
				es.stack[es.top][++es.index] = ch;
			}
			// flag == 2  // ǰһ������Ϊ����������һ����
			else {
				es.index = -1;
				es.stack[++es.top][++es.index] = ch;
				flag = 1;
			}
		}
		// ��������ַ��ǳ���'-'���������ţ�ִ����׺ת��׺�㷨
		else if (ch == '+' || ch == '*' || ch == '/' || ch == '(' || ch == ')') {
			IntoSuf(ch);
			flag = 2;
		}
		//���'-'�Ǽ��Ż��Ǹ���
		else if (ch == '-') {
			//�����-�������ڱ��ʽ��λ���Һ���������֣���ô��ʱΪ����
			if (i == 0 && expression[1] >= '0' && expression[1] <= '9') {
				es.stack[++es.top][++es.index] = ch;
				flag = 1;
			}
			//�����-�������ڱ��ʽ��λ���Һ�����������ţ���ô��ʱΪ���ţ��������ַ���������λ���0����� �� 0 - ��xxx��������ʽ
			if (i == 0 && expression[1] == '(') {
				char temp[MaxSize] = "";
				strcat_s(temp, expression);
				memset(expression, '\0', sizeof(expression));
				expression[0] = '0';
				strcat_s(expression, temp);
				i = -1;
				flag = 0;
			}
			//����� - �������������ź��棬��ô��ʱΪ���ţ��ϲ�������������ַ�����
			if (i > 0 && expression[i - 1] == '(') {
				es.index = -1;
				es.stack[++es.top][++es.index] = ch;
				flag = 1;
			}
			else if (i > 0) {
				//ִ����׺ת��׺�㷨
				IntoSuf(ch);
				flag = 2;
			}
		}
		i++;
		ch = expression[i];
	}
	// ���롮=���󣬽�������ջ�е��ַ�ȫ��ȡ����
	while (os.top >= 0) {
		es.index = -1;
		es.stack[++es.top][++es.index] = os.stack[os.top--];
	}
}
//��׺���ʽת��׺���ʽ
void IntoSuf(char ch) {
	// ���ջ��
	if (os.top == -1) {
		os.stack[++os.top] = ch;//ֱ����ջ
	}
	else
	{
		// ��������ַ�Ϊ*��/����ջ����*��/ȫ���ų��ٴ���
		if (ch == '*' || ch == '/') {
			while (os.stack[os.top] == '*' || os.stack[os.top] == '/') {
				es.index = -1;
				es.stack[++es.top][++es.index] = os.stack[os.top--];
			}
			os.stack[++os.top] = ch;
		}
		// ��������ַ�Ϊ+��-
		else if (ch == '+' || ch == '-') {
			if (os.stack[os.top] == '(')    // ջ���ǣ�����ֱ�Ӵ���
				os.stack[++os.top] = ch;
			// ջ��Ϊ��������ȡ����ջ��Ϊ����ջ�գ��ٴ���
			else {
				while (os.top >= 0 && os.stack[os.top] != '(') {
					es.index = -1;
					es.stack[++es.top][++es.index] = os.stack[os.top];//��������������ʽջ
					os.stack[os.top] = '\0';
					os.top--;//��������ջ
				}
				os.stack[++os.top] = ch;
			}
		}
		// �����ַ�Ϊ������ֱ�Ӵ���
		else if (ch == '(') {
			os.stack[++os.top] = ch;
		}
		// �����ַ�Ϊ��,��ջ�ڣ�ǰ�ַ�ȫ���ų�,��������
		else if (ch == ')') {
			while (os.stack[os.top] != '(') {
				es.index = -1;
				es.stack[++es.top][++es.index] = os.stack[os.top];//��������������ʽջ
				os.stack[os.top] = '\0';
				os.top--;//��������ջ
			}
			os.stack[os.top] = '\0';
			os.top--;//��(����ջ
		}
	}
}
//�����ɺ�׺���ʽ����Ľ��
double suf_getOutput() {
	int i;
	double Pre, Later;// PreΪǰ����LaterΪ������outΪ���ֵ
	double out = 0;//���
	char Operation;// ����
	for (i = 0; i <= es.top; i++) {
		//ջ��Ԫ�ص�һλΪ���ֻ���Ϊ���������ڶ�λԪ�ز�Ϊ��
		if (es.stack[i][0] >= '0' || es.stack[i][1] != '\0') {
			double d = atof(es.stack[i]);  // atof()���ַ�����ת��Ϊdouble����
			ns.top++;
			ns.stack[ns.top] = d;
		}
		else {
			Operation = es.stack[i][0];//������
			Later = ns.stack[ns.top--];
			Pre = ns.stack[ns.top--];
			switch (Operation) {
			case '+': out = Pre + Later; break;// ��
			case '-': out = Pre - Later; break;// ��
			case '*': out = Pre * Later; break;// ��
			case '/': out = Pre / Later; break;// ��
			}
			ns.stack[++ns.top] = out;
		}
	}
	es.clear();//������ջ���
	return out;
}