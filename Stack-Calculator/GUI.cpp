#include "head.h"
//���水ť
void button(int x, int y, int w, int h, int textSize, TCHAR* text){
	setbkmode(TRANSPARENT);//�������ֵı���͸��
	setfillcolor(0x878A80);//���ɫ
	fillroundrect(x, y, x + w, y + h, 23, 23);//����Բ�Ǿ���
	settextstyle(textSize, 0, "��Բ");//���������ʽ
	//ʹ�ı����ж���
	int tx = x + (w - textwidth(text)) / 2;
	int ty = y + (h - textheight(text)) / 2;
	settextcolor(0x363636);
	outtextxy(tx, ty, text);//����ַ���
}
//��ʼ������
void menu_init() {
	initgraph(1000, 563);//��ʼ������
	HWND hwnd = GetHWnd();//��ȡ���ھ��������
	SetWindowText(hwnd, "��ѧ���ʽ��ֵ");//�޸Ĵ������ֺ���
	/* ���ر���ͼƬ */
	IMAGE background;
	loadimage(&background, ".\\image\\background.jpg", 1000, 563);
	putimage(0, 0, &background);
	TCHAR s1[50] = "�Ӽ�������";
	TCHAR s2[50] = "���ļ�����";
	TCHAR s3[100] = "ע���Ӽ������������׺���ʽֱ����ֵ,���ļ����������׺ת��׺���ʽ��ֵ";
	//�������ı��İ�ť
	button(250, 250, 200, 100, 30, s1);
	button(530, 250, 200, 100, 30, s2);
	button(150, 0, 700, 25, 17, s3);
}
//����������
void calcul_memu() {
	setfillcolor(0xFFFFBB);
	solidrectangle(0, 100, 400, 600);
	setlinestyle(PS_ENDCAP_ROUND | PS_JOIN_ROUND, 1);
	setlinecolor(BLACK);
	line(0, 100, 400, 100);
	line(0, 200, 400, 200);
	line(0, 300, 400, 300);
	line(0, 400, 400, 400);
	line(0, 500, 400, 500);
	line(0, 599, 400, 599);
	line(100, 100, 100, 600);
	line(200, 100, 200, 600);
	line(300, 100, 300, 600);
	setbkmode(TRANSPARENT);//�������ֵı���͸��
	settextstyle(60, 35, "��Բ", 0, 0, 750, false, false, false);
	settextcolor(0x46170B);
	outtextxy(35, 120, "C");
	outtextxy(125, 120, "(");
	outtextxy(240, 120, ")");
	outtextxy(315, 120, "<-");
	outtextxy(35, 220, "7");
	outtextxy(135, 220, "8");
	outtextxy(235, 220, "9");
	outtextxy(335, 220, "+");
	outtextxy(35, 320, "4");
	outtextxy(135, 320, "5");
	outtextxy(235, 320, "6");
	outtextxy(335, 320, "-");
	outtextxy(35, 420, "1");
	outtextxy(135, 420, "2");
	outtextxy(235, 420, "3");
	outtextxy(335, 420, "*");
	outtextxy(40, 510, ".");
	outtextxy(135, 520, "0");
	outtextxy(235, 520, "=");
	outtextxy(335, 520, "/");
	setfillcolor(0xEEE58E);
	solidrectangle(0, 600, 400, 650);
	settextstyle(0, 0, "��Բ", 0, 0, 1000, false, false, false);
	outtextxy(140, 610, "����������");
}
//���������Ϣ
void mouse_info() {
	int i = 0;//�ַ��������±�
	char str[MaxSize] = "";//���ڱ�����ʽ���ַ���
	int count = 0;//ͳ���ַ���
	char out[MaxSize] = "";//�������ַ���
	char suf[MaxSize] = "";//��׺���ʽ�ַ���
	bool output = false;
	ExMessage m;
	while (true) {
		setbkmode(OPAQUE);//�ñ���ɫ�䵱������䱳��
		settextstyle(60, 20, "����", 0, 0, 0, false, false, false);
		settextcolor(0x46170B);
		m = getmessage(EX_MOUSE | EX_KEY);
		switch (m.message) {
			//����������
			case WM_LBUTTONDOWN:
				if (str[0] == '\0') {
					cleardevice();
					calcul_memu();
				}
				if (m.x > 100 && m.x < 200 && m.y > 100 && m.y < 200) {
					str[i] = '(';
					++i; count++;
				}
				if (m.x > 200 && m.x < 300 && m.y > 100 && m.y < 200) {
					str[i] = ')';
					++i; count++;
				}
				if (m.x > 300 && m.x < 400 && m.y > 200 && m.y < 300) {

					str[i] = '+';
					++i; count++;
				}
				if (m.x > 0 && m.x < 100 && m.y > 200 && m.y < 300) {

					str[i] = '7';
					++i; count++;
				}
				if (m.x > 100 && m.x < 200 && m.y > 200 && m.y < 300) {
					str[i] = '8';
					++i; count++;
				}
				if (m.x > 200 && m.x < 300 && m.y > 200 && m.y < 300) {
					str[i] = '9';
					++i; count++;
				}
				if (m.x > 300 && m.x < 400 && m.y > 300 && m.y < 400) {
					str[i] = '-';
					++i; count++;
				}
				if (m.x > 0 && m.x < 100 && m.y > 300 && m.y < 400) {
					str[i] = '4';
					++i; count++;
				}
				if (m.x > 100 && m.x < 200 && m.y > 300 && m.y < 400) {
					str[i] = '5';
					++i; count++;
				}
				if (m.x > 200 && m.x < 300 && m.y > 300 && m.y < 400) {
					str[i] = '6';
					++i; count++;
				}
				if (m.x > 300 && m.x < 400 && m.y > 400 && m.y < 500) {
					str[i] = '*';
					++i; count++;
				}
				if (m.x > 0 && m.x < 100 && m.y > 400 && m.y < 500) {
					str[i] = '1';
					++i; count++;
				}
				if (m.x > 100 && m.x < 200 && m.y > 400 && m.y < 500) {
					str[i] = '2';
					++i; count++;
				}
				if (m.x > 200 && m.x < 300 && m.y > 400 && m.y < 500) {
					str[i] = '3';
					++i; count++;
				}
				if (m.x > 300 && m.x < 400 && m.y > 500 && m.y < 600) {
					str[i] = '/';
					++i; count++;
				}
				if (m.x > 0 && m.x < 120 && m.y>500 && m.y < 600) {
					str[i] = '.';
					++i; count++;
				}
				if (m.x > 100 && m.x < 200 && m.y > 500 && m.y < 600) {
					str[i] = '0';
					++i; count++;
				}
				//��'<-'�������һ����������
				if (m.x > 300 && m.x < 400 && m.y > 100 && m.y < 200) {
					//ǰ�滹���ַ�
					if (i != 0) {
						i--;
						str[i] = '\0';
						count--;
						outtextxy(400 - count * 20 - 20, 20, " ");//��ǰһλ��ӡ���ַ����
					}
				}
				//��C����������ַ�
				if (m.x > 0 && m.x < 100 && m.y > 100 && m.y < 200) {
					i = 0;
					count = 0;
					memset(str, '\0', sizeof(str));//�ַ������
					cleardevice();
					calcul_memu();
				}
				//����=����������
				if (m.x > 200 && m.x < 300 && m.y > 500 && m.y < 600) {
					str[i] = '=';
					str[i + 1] = '\0';
					cleardevice();//�������
					calcul_memu();
					//�жϱ��ʽ�Ƿ�Ϊ��
					if (strcmp(str, "=") == 0) {
						settextstyle(60, 20, "����", 0, 0, 0, false, false, false);
						outtextxy(180, 20, "���ʽΪ�գ�");
						es.clear();//���ʽջ���
						memset(str, '\0', sizeof(str));//�ַ������
						i = 0;
						count = 0;
						output = true;
						break;
					}
					//������ʽ�Ƿ�
					if (judge_infix(str) == 0) {
						settextstyle(60, 20, "����", 0, 0, 0, false, false, false);
						outtextxy(180, 20, "���ʽ�Ƿ���");
						es.clear();//���ʽջ���
						memset(str, '\0', sizeof(str));//�ַ������
						i = 0;
						count = 0;
						output = true;
						break;
					}
					strcpy_s(expression, str);//�����ַ��������ʽ
					transfer();
					//����������ַ���
					string s = to_string(in_getOutput());
					strcpy_s(out, s.c_str());
					settextstyle(60, 20, "����", 0, 0, 0, false, false, false);
					outtextxy(400 - s.length() * 20, 20, out);
					es1.clear();//���ʽջ���
					memset(str, '\0', sizeof(str));//�ַ������
					memset(expression, '\0', sizeof(expression));//���ʽ���
					memset(out, '\0', sizeof(out));//���������
					memset(suf, '\0', sizeof(suf));//��׺���ʽ���
					i = 0;
					count = 0;
					output = true;
					break;
				}
				if (m.x > 0 && m.x < 400 && m.y > 600 && m.y < 650) {
					main();
				}
				break;
			//����������
			case WM_LBUTTONUP:
				outtextxy(400 - count * 20, 20, str);
				break;
			//���̰���
			case WM_KEYDOWN:
				if (m.vkcode == 0x30) {
					str[i] = '0';
					++i; count++;
				}
				if (m.vkcode == 0x31) {
					str[i] = '1';
					++i; count++;
				}
				if (m.vkcode == 0x32) {
					str[i] = '2';
					++i; count++;
				}
				if (m.vkcode == 0x33) {
					str[i] = '3';
					++i; count++;
				}
				if (m.vkcode == 0x34) {
					str[i] = '4';
					++i; count++;
				}
				if (m.vkcode == 0x35) {
					str[i] = '5';
					++i; count++;
				}
				if (m.vkcode == 0x36) {
					str[i] = '6';
					++i; count++;
				}
				if (m.vkcode == 0x37) {
					str[i] = '7';
					++i; count++;
				}
				if (m.vkcode == 0x38) {
					str[i] = '8';
					++i; count++;
				}
				if (m.vkcode == 0x39) {
					str[i] = '9';
					++i; count++;
				}
				//���˼�
				if (m.vkcode == VK_BACK) {
					//ǰ�滹���ַ�
					if (i != 0) {
						i--;
						str[i] = '\0';
						count--;
						outtextxy(400 - count * 20 - 20, 20, " ");//��ǰһλ��ӡ���ַ����
					}
				}
				break;
			//���̵���
			case WM_KEYUP:
				outtextxy(400 - count * 20, 20, str);
				break;
			}
	}
}