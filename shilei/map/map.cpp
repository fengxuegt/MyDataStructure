/*
 * Created 2022-07-24 15:53:21
 * Author : fengxuegt
 * Email : fengxuegt@163.com
 */

#include<iostream>
#include<fstream>
#include<list>
#include<vector>
#include<string>
#include<queue>


using namespace std;
class Digraph {
public:
    // 从配置文件读取顶点和边的信息，生成邻接表
    void readFile(string filePath) {
        ifstream infile;
        infile.open(filePath.data());
        string line;
        vertics.emplace_back("");
        for (int i = 1; i <= 9; i++) {
            getline(infile, line);
            vertics.emplace_back(line.substr(0, line.size() - 1));
            line = "";
            getline(infile, line);
            char *vars = strtok(const_cast<char*>(line.c_str()), ",");
            while (vars != nullptr) {
                int vex = atoi(vars);
                if (vex > 0)
                    vertics[i].m_adjList.emplace_back(vex);
                vars = strtok(nullptr, ",");
            }
        }
        
        infile.close();
    }

    void show() {
        for (int i = 1 ; i < vertics.size(); i++) {
            cout << vertics[i].m_name << " : ";
            flush(cout);
            for (int v: vertics[i].m_adjList) {
                cout << v << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // 图的深度优先遍历
    void dfs() {
        vector<bool> visited(vertics.size(), false);
        dfs(1, visited);
        cout << endl;
    }

    // 图的广度优先遍历
    void bfs() {
        queue<int> q;
        vector<bool> visited(vertics.size(), false);
        q.push(1);
        visited[1] = true;
        while (!q.empty()) {
            int top = q.front();
            cout << vertics[top].m_name << " ";
            q.pop();
            for (auto i : vertics[top].m_adjList) {
                if (visited[i] != true) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;
    }


    
private:
    struct Vertic {
        Vertic(string name) : m_name(name) {

        }
        string m_name; // 定点信息（名称）
        list<int> m_adjList; // 顶点所能到达的顶点链表
    };
    vector<Vertic> vertics;

private:
    void dfs(int start, vector<bool> &visit) {
        // 该start节点已经被遍历了
        if (visit[start] == true) {
            return;
        }
        cout << vertics[start].m_name << " ";
        visit[start] = true;
        // 递归遍历下一层节点
        for (auto no : vertics[start].m_adjList) {
            dfs(no, visit);
        }
    }
};

int main()
{
    Digraph graph;
    graph.readFile("data.txt");
    graph.show();
    graph.dfs();
    graph.bfs();
    return 0;
}