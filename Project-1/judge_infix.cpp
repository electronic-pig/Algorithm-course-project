#include "head.h"
//�ж���׺���ʽ�Ϸ���,���������ݴ�С������Ϊ��׺���ʽ�ַ���
int judge_infix(char* str) {
	int temp = 0;//�����ַ�������������ƥ��
	char allchar[] = "0123456789.+-*/()=";//���п����ַ�
	bool has_operatechar = false;//�ж��ַ������Ƿ��в�����
	int n = 1;//ѭ������
	//β�ַ���Ϊ"="ʱ�Ƿ�
	if (str[strlen(str) - 1] != '=')
		return 0;
	//β�ַ�ǰһ��ֻ�������ֻ��ߡ�)��������Ƿ�
	if (str[strlen(str) - 2] != ')' && !(str[strlen(str) - 2] >= '0' && str[strlen(str) - 2] <= '9')) {
		return 0;
	}
	//��һ���ַ�Ϊ�˳���С�����")"ʱ�Ƿ�
	if (str[0] == '/' || str[0] == '*' || str[0] == '.' || str[0] == ')')
		return 0;
	//��һ���ַ�Ϊ'('
	if (str[0] == '(') temp++;
	//�ַ����в���������ʱ�Ƿ�
	while (n < strlen(str) - 1) {
		if (str[n] == '+' || str[n] == '-' || str[n] == '*' || str[n] == '/') {
			has_operatechar = true;
			break;
		}
		n++;
	}
	if (!has_operatechar) return 0;
	//�����ַ�������Χ�ǣ�1�� n-2��
	for (int i = 1; i < strlen(str) - 1; i++) {
		//�ַ����г��ֲ�������ַ�ʱ�Ƿ�
		char* p = strchr(allchar, str[i]);
		if (p == NULL) return 0;
		//����������ʱ�Ƿ�
		if (str[i] == '+' || str[i] == '*' || str[i] == '-' || str[i] == '/')
			if (str[i + 1] == '+' || str[i + 1] == '*' || str[i + 1] == '-' || str[i + 1] == '/')
				return 0;
		//�Ⱥ���ǰ���ַǷ�
		if (str[i] == '=')
			return 0;
		//�ַ�Ϊ"("
		if (str[i] == '(') {
			//�����ַ�Ϊ�˳�ʱ�Ƿ�
			if ((str[i + 1] == '*' || str[i + 1] == '/'))
				return 0;
			//"("ǰΪ����ʱ�Ƿ�
			else if (str[i - 1] >= '0' && str[i - 1] <= '9')
				return 0;
			//�������ƥ��
			temp++;
		}
		//�ַ�Ϊ")"
		else if (str[i] == ')') {
			//")"ǰΪ������ʱ�Ƿ�
			if (str[i - 1] == '+' || str[i - 1] == '*' || str[i - 1] == '-' || str[i - 1] == '/')
				return 0;
			//")"��Ϊ����ʱ�Ƿ�
			else if (str[i + 1] >= '0' && str[i + 1] <= '9')
				return 0;
			//�������ƥ��
			temp--;
			//")"������"("ǰ��ʱ�Ƿ�
			if (temp < 0)
				return 0;
		}
		//�ַ�Ϊ"."
		if (str[i] == '.') {
			//С����ǰ��Ϊ����ʱ�Ƿ�
			if (str[i - 1] < '0' || str[i - 1] > '9') return 0;
			if (str[i + 1] < '0' || str[i + 1] > '9') return 0;
		}
		//�ַ�Ϊ"/",����0ʱ�Ƿ�(0.0,0.00,0.000��)
		if (str[i] == '/' && str[i + 1] == '0') {
			//��֤���鲻Խ��
			if (size_t(i) + 2 <= strlen(str) - 1) {
				if (str[i + 2] == '.') {
					while (size_t(i) + 2 <= strlen(str) - 1) {
						i++;
						if (str[i + 2] >= '1' && str[i + 2] <= '9') return 1;
						if (str[i + 2] != '0') return 0;
					}
				}
				else return 0;
			}
			return 0;
		}
	}
	//���Ų�ƥ��ʱ�Ƿ�
	if (temp != 0)
		return 0;
	return 1;
}