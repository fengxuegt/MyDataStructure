// ��׺���ʽ �� ��׺���ʽ ת���㷨
// 1�� 5 + 4              =��   5 4 +
// 2�� 1 + 2 * 3          =��   1 2 3 * +
// 3�� 8 + (3 - 1) * 5    =��   8 3 1 - 5 * +

/* �㷨��
	������׺���ʽ�����ֺͷ��ţ�
		��������֣�ֱ�����
		����Ƿ��ţ�
			�����ţ� ��ջ
			������� ��ջ�����Ž������ȼ��Ƚ�
				     ��ջ���������ȼ����ͣ����ջ�����������ȼ���ͣ�
					 ��ջ���������ȼ����ͣ���ջ�����ŵ����������֮���ٽ�ջ
			�����ţ� ��ջ�����ŵ����������ֱ��ƥ�䵽�����ţ�Ȼ�������ź�������ֱ������
	���ȫ�����
	
	
   ��׺���ʽ�ļ����㷨��
		�����������㷨����׺���ʽת��Ϊ��׺���ʽ֮�����沨���㷨���м���
	������׺���ʽ�е����ֺͷ���
		�������֣�ֱ�ӽ�ջ
		���ڷ��ţ�
			��ջ�е����Ҳ�����
			��ջ�е����������
			���ݷ��Ž�������
			��������ѹ��ջ��
	����������ջ�б���Ľ��Ϊ���ʽ�ļ�����
*/
#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<unordered_map>
using namespace std;

vector<char> mid2behind(string str) {
    unordered_map<char, int> priority_map = {
        {'+', 0},
        {'-', 0},
        {'(', -1},
        {'*', 1},
        {'/', 1}
    };
    vector<char> res;
    stack<char> stk;
    for (char ch: str) {
        if (ch >= '0' && ch <= '9') {
            res.push_back(ch);
        } else {
            if (ch == '(') {
                stk.push(ch);
            } else if (ch == ')') {
                while (stk.top() != '(') {
                    res.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();
            } else {
                if (stk.empty()) {
                    stk.push(ch);
                } else {
                    if (priority_map[ch] >= priority_map[stk.top()]) {
                        stk.push(ch);
                    } else {
                        res.push_back(stk.top());
                        stk.pop();
                        stk.push(ch);
                    }
                }
            }
        }  
    }
    while (!stk.empty()) {
        res.push_back(stk.top());
        stk.pop();
    }
    return res;
}


int calBehind(vector<char> res) {
    stack<int> stk;
    for (char ch: res) {
        if (ch >= '0' && ch <= '9') {
            stk.push(ch- '0');
        } else {
            int r = stk.top();
            stk.pop();
            int l = stk.top();
            stk.pop();
            
            switch (ch)
            {
            case '+':
                stk.push(l + r);
                break;
            case '-':
                stk.push(l - r);
                break;
            case '*':
                stk.push(l * r);
                break;
            default:
                break;
            }
        }
    }
    return stk.top();
}

int main()
{
    //string s = "1+2*3";
    //string s = "5+4";
    string s = "8+(3-1)*5";
    vector<char> res;
    res = mid2behind(s);
    for (char ch: res) {
        cout << ch << " ";
    }
    cout << " = ";
    int re = calBehind(res);
    cout << re << endl;
    getchar();
    return 0;
}




