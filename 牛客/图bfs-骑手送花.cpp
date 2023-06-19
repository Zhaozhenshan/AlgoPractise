#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int total = 0;
    map<int, vector<pair<int, int>>> edges;
    int n;
    cin >> n;
    while (--n) {
        //默认为有向图，给有向图加边
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({ v, w });
        total += w; //记录最小生成树的总权值
    }
    int maxLength = -1, sumDistance = 0;
    queue<pair<int, int>> q;
    q.push({ 1, 0 }); //当前结点是1,到根节点的路径长度是0
    while (!q.empty()) {
        auto f = q.front();
        q.pop();
        if (edges.find(f.first) == edges.end()) {
            //f是叶子结点
            maxLength = max(maxLength, f.second);
        } else {
            //f是非叶子结点
            for (const auto& p : edges[f.first]) {
                //遍历每一个孩子,更新孩子结点到根结点的距离，入队
                q.push({ p.first, f.second + p.second });
                //f.second+p.second是根结点到该结点的距离
                sumDistance += f.second + p.second;
            }
        }
    }
    std::cout << sumDistance << " " << 2 * total - maxLength << std::endl;
}