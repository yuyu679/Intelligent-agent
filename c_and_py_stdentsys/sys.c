#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Students
{
	char name[50];
	int age;
	float gpa;
};

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		printf("��������Ч������\n");
		return 1;
	}
	char* command = argv[1];

	struct Students all_student[100];
	int valid_student[100];

	int i;
	for (i = 0; i < 100; i++)
	{
		valid_student[i] = 0;
	}

	if (strcmp(command, "add") == 0)
	{
		if (argc < 6) {
			printf("�÷�����ʾ����add <���> <����> <����> <GPA>\n");
			return 1;
		}
		FILE* fp = fopen("students.txt", "a"); // ׷��д��
		if (!fp) {
			printf("�ļ���ʧ��\n");
			return 1;
		}
		int num = atoi(argv[2]);
		char* name = argv[3];
		int age = atoi(argv[4]);
		float gpa = atof(argv[5]);
		fprintf(fp, "%d %s %d %.2f\n", num, name, age, gpa); // ���浽�ļ�
		fclose(fp);
		printf("��ӳɹ�\n");
	}
	else if (strcmp(command, "delete") == 0)
	{
		if (argc < 3)
		{
			printf("�÷�����ʾ����delete <���>\n");
			return 1;
		}
		int num;
		num = atoi(argv[2]);
		valid_student[num] = 0;
		printf("ɾ���ɹ�\n");

	}
	else if (strcmp(command, "list") == 0) {
		FILE* fp = fopen("students.txt", "r");
		if (!fp) {
			printf("�ļ���ʧ��\n");
			return 1;
		}
		int num, age;
		float gpa;
		char name[50];
		while (fscanf(fp, "%d %s %d %f", &num, name, &age, &gpa) != EOF) {
			printf("ѧ����ţ�%d ������%s ���䣺%d GPA��%.2f\n", num, name, age, gpa);
		}
		fclose(fp);
	}
	else
	{
		printf("��Ч������\n");
	}
}