import subprocess
from vivogpt import run

def add_student(num, name, age, gpa):
    result = subprocess.run(
        ['c_and_py_stdentsys.exe', 'add', str(num), name, str(age), str(gpa)],
        capture_output=True,
        text=True,
        encoding='gbk'
    )
    print(result.stdout)

def delete_student(num):
    result = subprocess.run(
        ['c_and_py_stdentsys.exe', 'delete', str(num)],
        capture_output=True,
        text=True,
        encoding='gbk'
    )
    print(result.stdout)

def list_students():
    result = subprocess.run(
        ['c_and_py_stdentsys.exe', 'list'],
        capture_output=True,
        text=True,
        encoding='gbk'
    )
    print(result.stdout)

print('{:-^20}'.format('学生信息管理系统'))
print(' '*8+'1:添加学生')
print(' '*8+'2:删除学生')
print(' '*8+'3:打印学生')
print(' '*8+'4:使用蓝星大模型')
print(' '*8+'5:退出应用')

while True:
    c = input(' ' * 8 + '在此输入选择:')
    if c == '1':
        print('输入学号,姓名,年龄,gpa')
        num, name, age, gpa = input().split()
        add_student(num, name, age, gpa)
    elif c == '2':
        print('输入删除学生的学号:')
        delete_student(input())
    elif c == '3':
        list_students()
    elif c == '5':
        print("感谢使用")
        exit()
    elif c == '4':
        run()
    else:
        print("无效选择，请重新输入")
