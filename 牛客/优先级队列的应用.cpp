#include <iostream>
#include <queue>
//https://www.nowcoder.com/exam/test/28665343/summary 美团2021校招笔试通用第10场
using namespace std;

int main()
{
    int group;
    cin >> group;
    while (group--) {
        int table_num, person_num;
        string table_person, person_queue;
        cin >> table_num >> table_person
            >> person_num >> person_queue;

        priority_queue<int, vector<int>, greater<int>> mp0, mp1;
        for (int i = 0; i < table_num; i++) {
            if (table_person[i] == '0') {
                mp0.push(i + 1);
            }
            if (table_person[i] == '1') {
                mp1.push(i + 1);
            }
        }

        for (const auto& c : person_queue) {
            if (c == 'M') {
                if (!mp1.empty()) {
                    printf("%d\n", mp1.top());
                    mp1.pop();
                } else {
                    auto t = mp0.top();
                    printf("%d\n", t);
                    mp0.pop();
                    mp1.push(t);
                }
            } else {
                if (!mp0.empty()) {
                    auto t = mp0.top();
                    printf("%d\n", t);
                    mp0.pop();
                    mp1.push(t);
                } else {
                    auto t = mp1.top();
                    printf("%d\n", t);
                    mp1.pop();
                }
            }
        }
    }
}