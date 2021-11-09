#include<iostream>
#include"MyStack.h"
#include"Person.h"
using namespace std;
static bool guess(string s) {
    MyStack<char> my_stack(100);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                my_stack.push(s[i]);
            } else if (s[i] == ')') {
                if (my_stack.isEmpty())
                    return false;
                char tmp;
                my_stack.pop(tmp);
                if (tmp != '(')
                    return false;
            }
        }
        if (!my_stack.isEmpty()) {
            return false;
        }
        return true;
}

int main()
{
    string s = "())";
    cout << ((guess(s)== true) ? "true":"false") << endl;
    
    system("pause");
    return 0;
}





// int main_8()
// {

//     int num;
//     cout << "please input your number: " << endl;
//     cin >> num;
//     MyStack<int> my_8(10);
//     while (num > 0) {
//         my_8.push(num % 8);
//         num = num / 8;
//     }
//     cout << "----------------------" << endl;
//     my_8.traverse();
//     getchar();
//     system("pause");
//     return 0;
// }



// int main_Person()
// {
//     MyStack<Person> my_stack(4);
//     my_stack.push(Person(string("liwang"), 18));
//     my_stack.push(Person(string("jiyingxin"), 17));
//     my_stack.push(Person(string("dema"), 22));
//     my_stack.push(Person(string("huangzi"), 44));

//     my_stack.traverse();
//     getchar();
//     return 0;
// }

// int main01()
// {
//     MyStack<int> my_stack(4);

//     cout << my_stack.isEmpty() << endl;
//     my_stack.push(1);
//     my_stack.push(2);
    
//     cout << my_stack.size() << endl;
//     my_stack.push(3);
//     my_stack.push(4);
//     cout << my_stack.isFull() << endl;


//     my_stack.traverse();
//     getchar();
//     return 0;
// }