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
		printf("请输入有效的命令\n");
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
			printf("用法错误！示例：add <编号> <姓名> <年龄> <GPA>\n");
			return 1;
		}
		FILE* fp = fopen("students.txt", "a"); // 追加写入
		if (!fp) {
			printf("文件打开失败\n");
			return 1;
		}
		int num = atoi(argv[2]);
		char* name = argv[3];
		int age = atoi(argv[4]);
		float gpa = atof(argv[5]);
		fprintf(fp, "%d %s %d %.2f\n", num, name, age, gpa); // 保存到文件
		fclose(fp);
		printf("添加成功\n");
	}
	else if (strcmp(command, "delete") == 0)
	{
		if (argc < 3)
		{
			printf("用法错误！示例：delete <编号>\n");
			return 1;
		}
		int num;
		num = atoi(argv[2]);
		valid_student[num] = 0;
		printf("删除成功\n");

	}
	else if (strcmp(command, "list") == 0) {
		FILE* fp = fopen("students.txt", "r");
		if (!fp) {
			printf("文件打开失败\n");
			return 1;
		}
		int num, age;
		float gpa;
		char name[50];
		while (fscanf(fp, "%d %s %d %f", &num, name, &age, &gpa) != EOF) {
			printf("学生编号：%d 姓名：%s 年龄：%d GPA：%.2f\n", num, name, age, gpa);
		}
		fclose(fp);
	}
	else
	{
		printf("无效的命令\n");
	}
}