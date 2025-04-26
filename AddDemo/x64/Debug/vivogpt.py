import uuid
import time
import requests
from auth_util import gen_sign_headers

APP_ID = '2025240367'
APP_KEY = 'hDLpvsdnTAweBggf'
URI = '/vivogpt/completions'
DOMAIN = 'api-ai.vivo.com.cn'
METHOD = 'POST'

def sync_vivogpt(prompt):
    params = {
        'requestId': str(uuid.uuid4())
    }
    print('requestId:', params['requestId'])

    data = {
        'prompt': prompt,
        'model': 'vivo-BlueLM-TB-Pro',
        'sessionId': str(uuid.uuid4()),
        'extra': {
            'temperature': 0.9
        }
    }
    headers = gen_sign_headers(APP_ID, APP_KEY, METHOD, URI, params)
    headers['Content-Type'] = 'application/json'

    start_time = time.time()
    url = f'https://{DOMAIN}{URI}'
    response = requests.post(url, json=data, headers=headers, params=params)

    if response.status_code == 200:
        res_obj = response.json()
        print(f'response:{res_obj}')
        if res_obj['code'] == 0 and res_obj.get('data'):
            content = res_obj['data']['content']
            print(f'final content:\n{content}')
    else:
        print(response.status_code, response.text)
    end_time = time.time()
    print('请求耗时: %.2f秒' % (end_time - start_time))

# 加上 run() 函数！！
def run():
    prompt = input()
    sync_vivogpt(prompt)

if __name__ == '__main__':
    run()
