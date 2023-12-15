/* �����ṩ�Ľӿ� */
#include<easyx.h>/* ͼ�ο�ͷ�ļ� */
#include<iostream>
#include<string>
#include<fstream>
#define MaxSize 100
using namespace std;
//����ȫ�ֱ���
extern char strFileName[MAX_PATH];
extern char expression[MaxSize];
//���ʽջ
class Expression_Stack {
public:
	int top;//ջ���±�
	int index;//�����±�
	char stack[MaxSize][MaxSize];//���ڴ洢���ʽ�Ķ�ά����
	//���췽��
	Expression_Stack() {
		top = -1;
		index = -1;
		for (int i = 0; i < MaxSize; i++) {
			for (int j = 0; j < MaxSize; j++) {
				stack[i][j] = '\0';
			}
		}
	}
	//ջ���
	void clear() {
		top = -1;
		index = -1;
		for (int i = 0; i < MaxSize; i++) {
			for (int j = 0; j < MaxSize; j++) {
				stack[i][j] = '\0';
			}
		}
	}
};
//�����ջ
class Operation_Stack {
public:
	int top;//ջ���±�
	char stack[MaxSize];//���ڴ洢��������һά����
	//���췽��
	Operation_Stack() {
		top = -1;
		for (int i = 0; i < MaxSize; i++) {
			stack[i] = '\0';
		}
	}
};
//����ջ
class Number_Stack {
public:
	int top;//ջ���±�
	double stack[MaxSize];//���ڴ洢���ݵ�һά����
	//���췽��
	Number_Stack() {
		top = -1;
		for (int i = 0; i < MaxSize; i++) {
			stack[i] = 0.0;
		}
	}
};
//ջ������
extern Expression_Stack es;//���ʽջ,���ں�׺���ʽ��ֵ
extern Operation_Stack os;//������ջ,���ں�׺���ʽ��ֵ
extern Number_Stack ns;//����ջ,���ں�׺���ʽ��ֵ
extern Expression_Stack es1;//���ʽջ1,������׺���ʽ��ֵ
extern Operation_Stack os1;//������ջ1,������׺���ʽ��ֵ
extern Number_Stack ns1;//����ջ1��������׺���ʽ��ֵ
//main.cpp
int main();
//GUI.cpp
void button(int x, int y, int w, int h, int textSize, TCHAR* text);
void menu_init();
void calcul_memu();
void mouse_info();
//file.cpp
char* get_file_path();
string read(char path[]);
//judge_infix.cpp
int judge_infix(char* str);
//suf_oparate.cpp
void getInput();
void IntoSuf(char ch);
double suf_getOutput();
//in_oparate.cpp
void transfer();
double in_getOutput();
double Cal(char a, double b, double c);