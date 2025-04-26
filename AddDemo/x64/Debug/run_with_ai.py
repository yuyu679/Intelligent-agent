import subprocess
from vivogpt import run

result = subprocess.run(
    ["AddDemo.exe"],
    capture_output=True, text=True
)

sum_result = result.stdout.strip()
print(f"[C 程序返回]: {sum_result}")
print('请输入向Ai询问的问题:', flush=True)
run()

