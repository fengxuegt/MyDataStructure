// 中缀表达式 和 后缀表达式 转换算法
// 1、 5 + 4              =》   5 4 +
// 2、 1 + 2 * 3          =》   1 2 3 * +
// 3、 8 + (3 - 1) * 5    =》   8 3 1 - 5 * +

/* 算法：
	遍历中缀表达式的数字和符号：
		如果是数字：直接输出
		如果是符号：
			左括号： 进栈
			运算符： 与栈顶符号进行优先级比较
				     若栈顶符号优先级更低，则进栈（左括号优先级最低）
					 若栈顶符号优先级不低，将栈顶符号弹出并输出，之后再进栈
			右括号： 将栈顶符号弹出并输出，直到匹配到左括号，然后左括号和右括号直接舍弃
	最后全部输出
	
	
   后缀表达式的计算算法：
		根据上述的算法由中缀表达式转换为后缀表达式之后，用逆波兰算法进行计算
	遍历后缀表达式中的数字和符号
		对于数字：直接进栈
		对于符号：
			从栈中弹出右操作数
			从栈中弹出左操作数
			根据符号进行运算
			将运算结果压入栈中
	遍历结束后，栈中保存的结果为表达式的计算结果
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




