#include "head.h"
//����ȫ�ֱ���
char strFileName[MAX_PATH] = "";	//���ڽ����ļ���
char expression[MaxSize] = "";//���ڴ����������ʽ
//����ջ����
Expression_Stack es;//���ʽջ
Operation_Stack os;//������ջ
Number_Stack ns;//����ջ
Expression_Stack es1;//���ʽջ1,������׺���ʽ��ֵ
Operation_Stack os1;//������ջ,������׺���ʽ��ֵ
Number_Stack ns1;//����ջ1��������׺���ʽ��ֵ

//main����
int main() {
	menu_init();//��ʼ������
	ExMessage msg;//��ȡ��Ϣ����
	while (true) {
		msg = getmessage(EX_MOUSE | EX_KEY);//��ȡ���ͼ�����Ϣ
		switch (msg.message) {
			case WM_LBUTTONDOWN://���������
				if (msg.x >= 250 && msg.x <= 250 + 200 && msg.y >= 250 && msg.y <= 250 + 100) {
					initgraph(400, 650);//��ʼ������
					HWND hwnd = GetHWnd();//��ȡ���ھ��������
					SetWindowText(hwnd, "������");//�޸Ĵ������ֺ���
					setbkcolor(0xFAFFF0);//���ñ�����ɫ
					cleardevice();//�ñ�����ɫˢ��
					calcul_memu();//����������
					mouse_info();//��ȡ�����Ϣ
				}
				if (msg.x >= 530 && msg.x <= 530 + 200 && msg.y >= 250 && msg.y <= 250 + 100) {
					HWND hn = GetHWnd();//��ȡ���ھ��������
					char* path = get_file_path();//����ļ�·��
					char suf[MaxSize] = "";//�����׺���ʽ�ַ���
					//����ļ�·������
					if (path) {
						strcpy_s(expression, read(path).c_str());//���ļ���һ�еı��ʽ�ַ������浽������
						//�жϱ��ʽ�Ƿ�Ϊ��
						if (strcmp(expression, "") == 0) {
							MessageBox(hn, "���ʽΪ�գ�", NULL, MB_OK | MB_ICONERROR);
							break;
						}
						//�жϱ��ʽ�Ƿ�Ƿ�
						if (judge_infix(expression) == 0) {
							MessageBox(hn, "���ʽ�Ƿ���", NULL, MB_OK | MB_ICONERROR);
						}
						else {
							MessageBox(hn, expression, "���ʽ", MB_OK | MB_ICONASTERISK);//������ʽ������
							getInput();//�����ʽ�ַ���ת��Ϊ��׺���ʽջ
							//����׺���ʽջ�����ݿ�������׺���ʽ�ַ���
							for (int i = 0; i <= es.top; i++) {
								strcat_s(suf, es.stack[i]);
								strcat_s(suf, " ");
							}
							MessageBoxA(hn, suf, "��׺���ʽ��Ϊ��׺���ʽΪ��", MB_OK | MB_ICONASTERISK);//�����׺���ʽ�ַ���������
							char out[MaxSize] = "";//�����������ַ���
							string s = to_string(suf_getOutput());//��ȡ�������ַ���
							strcpy_s(out, s.c_str());//�����ַ���
							MessageBox(hn, out, "������Ϊ", MB_OK | MB_ICONASTERISK);//�������ַ���������
							strcpy_s(expression, "");//���ʽ���
						}
					}
				}
				break;
			default:
				break;
		}
	}
	return 0;
}

