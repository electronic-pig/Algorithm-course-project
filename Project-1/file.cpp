#include "head.h"
//���ѡ����ļ�·��
char* get_file_path() {
	OPENFILENAME ofn = { 0 };
	ofn.lStructSize = sizeof(OPENFILENAME);//�ṹ���С
	ofn.hwndOwner = NULL;//ӵ���Ŵ��ھ��
	ofn.lpstrFile = strFileName;//���շ��ص��ļ�·��
	ofn.nMaxFile = sizeof(strFileName);	//����������
	ofn.lpstrInitialDir = ".\\";//��ʼĿ¼Ϊ��ĿĿ¼
	ofn.lpstrTitle = TEXT("��ѡ��һ���ļ�"); //���ڱ���
	ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY; //�ļ���Ŀ¼������ڣ�����ֻ��ѡ��
	//���ļ��Ի���
	if (GetOpenFileName(&ofn)) {
		return strFileName;
	}
	//���û��ѡ���ļ����򷵻ش�����Ϣ����
	else {
		MessageBox(NULL, TEXT("��ѡ��һ�ļ�"), NULL, MB_ICONERROR);
		return NULL;
	}
}
//���ļ����������ص�һ�е��ַ���
string read(char path[]) {
	ifstream file;
	file.open(path, ios::in);//���ļ�·�����ļ�
	string s;
	getline(file, s);//��ȡ�ļ���һ�е��ַ���
	file.close();//�ļ��ر�
	return s;
}