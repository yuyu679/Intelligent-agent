import subprocess

# 注意：路径中空格或中文会出问题，最好路径简单
result = subprocess.run(
    ["AddDemo.exe"],  # 如果不在同目录，写完整路径
    capture_output=True, text=True
)

sum_result = result.stdout.strip()
print(f"[C 程序返回]: {sum_result}")

# 模拟大模型输出
def fake_ai_model(text):
    return f"AI 说：{text} 是一个很不错的加法结果。"

print("[AI 模型]:", fake_ai_model(sum_result))
