#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <queue>
#define INF 0x3f3f3f3f

using namespace std;

struct Map {
    int V, E;
    virtual void read_input() = 0;
    virtual void process() = 0;
    virtual void output() = 0;
    virtual ~Map() {}
};

class LosSantosMap: public Map {
    // TODO: Store graphs and other variables
    int vertex;
    int edge;
    vector<list<pair<int,int>>> AdjList;
    vector<int> distance;
    vector<int> predecessor;
    vector<int> answer;
    vector<bool> visited;
public:
    void read_input() override {
        // TODO
        cin >> vertex;
        cin >> edge;
        AdjList.resize(vertex);
        for (int a=0; a<edge; a++)
        {
            int i, j, t;
            cin >> i;
            cin >> j;
            cin >> t;
            AdjList[i].push_back(make_pair(j,t));
        }
    }
    void process() override {
        // TODO
        visited.resize(vertex, false);
        distance.resize(vertex, INF);
        answer.resize(vertex, 0);

        for (int source = 0; source < vertex; source++)
        {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            for (int i=0; i<vertex; i++)
            {
                if (distance[i] != INF)
                    distance[i] = INF;
            }
            pq.push(make_pair(0, source));
            distance[source] = 0;

            while (!pq.empty())
            {
                int u = pq.top().second;
                pq.pop();

                list<pair<int, int>>::iterator i;
                for (i = AdjList[u].begin(); i!= AdjList[u].end(); ++i)
                {
                    int v = (*i).first;
                    int weight = (*i).second;
                    if (distance[v] > distance[u] + weight)
                    {
                        distance[v] = distance[u] + weight;
                        pq.push(make_pair(distance[v],v));
                    }
                }
            }
            answer[source] = distance[0];
        }


    }
    void output() override {
        // TODO
        for (int i=0; i<vertex; i++)
        {
            if (answer[i] == INF)
                cout << "INF" << endl;
            else
                cout << answer[i] << endl;
        }

    }
};

class PortalChambersMap: public Map {
    // TODO: Store graphs and other variables
    int vertex;
    int edge;
    vector<vector<int>> AdjMatrix;
    vector<vector<int>> distance;
    vector<vector<int>> predecessor;

public:
    void read_input() override {
        // TODO
        cin >> vertex;
        cin >> edge;
        AdjMatrix.resize(vertex);
        for (int z=0; z<vertex; z++)
        {
            AdjMatrix[z].resize(vertex, INF);
            /*
            for (int y=0; y<vertex; y++)
            {
                if (z==y)
                    AdjMatrix[z][y] = 0;
            }
            */
        }
        for (int a=0; a<edge; a++)
        {
            int i, j, t;
            cin >> i;
            cin >> j;
            cin >> t;
            AdjMatrix[i][j] = t;
        }

    }
    void process() override {
        // TODO
        distance.resize(vertex);
        predecessor.resize(vertex);

        for (int a=0; a<vertex; a++)
        {
            distance[a].resize(vertex, INF);
            predecessor[a].resize(vertex, -1);
            for (int b=0; b<vertex; b++)
            {
                distance[a][b] = AdjMatrix[a][b];
                if (distance[a][b]!=0 && distance[a][b]!=INF)
                {
                    predecessor[a][b] = a;
                }
            }
        }


        for (int k=0; k<vertex; k++)
        {
            for (int i=0; i<vertex; i++)
            {
                for (int j=0; j<vertex; j++)
                {
                    if (distance[i][j] > distance[i][k] + distance[k][j] && distance[i][k] != INF)
                    {
                        distance[i][j] =  distance[i][k] + distance[k][j];
                        predecessor[i][j] = predecessor[k][j];
                    }
                }
            }
        }


    }
    void output() override {
        // TODO
        for (int i=0; i<vertex; i++)
        {
            if (distance[i][i] == INF)
                cout << "INF" << endl;
            else
                cout << distance[i][i] << endl;
        }
    }
};

class SkyrimMap: public Map {
    // TODO: Store graphs and other variables
    int vertex;
    int edge;
    int alarm;
    vector<list<pair<int, int>>> AdjList;
    vector<int> distance;
    vector<int> predecessor;
public:
    void read_input() override {
        // TODO
        cin >> vertex;
        cin >> edge;
        AdjList.resize(vertex);
        for (int a=0; a<edge; a++)
        {
            int i, j, t;
            cin >> i;
            cin >> j;
            cin >> t;
            AdjList[i].push_back(make_pair(j,(-1)*t));
        }
    }
    void process() override {
        // TODO
        int source = 0;
        distance.resize(vertex);
        predecessor.resize(vertex);
        for (int source = 0; source < vertex; source++)
        {
            alarm = 0;
            for (int i=0; i<vertex; i++)
            {
                distance[i] = INF;
                predecessor[i] = -1;
            }
            distance[source] = 0;
            for (int i=0; i<vertex-1; i++)
            {
                for (int j=0; j<vertex; j++)
                {
                    list<pair<int, int>>::iterator itr;
                    for (itr = AdjList[j].begin(); itr!=AdjList[j].end(); itr++)
                    {
                        int v = (*itr).first;
                        int weight = (*itr).second;
                        if (distance[v] > distance[j] + weight)
                        {
                            distance[v] = distance[j] + weight;
                            predecessor[v] = j;
                        }
                    }
                }
            }

            for (int i=0; i<vertex; i++)
            {
                list<pair<int, int>>::iterator itr;
                for (itr = AdjList[i].begin(); itr!=AdjList[i].end(); itr++)
                {
                    int v = (*itr).first;
                    int weight = (*itr).second;
                    if (distance[v] > distance[i] + weight)
                    {
                        alarm = 1;
                        break;
                    }
                }
                if (alarm == 1)
                    break;
            }

            if (alarm == 1)
                break;
        }
    }
    void output() override {
        // TODO
        if (alarm == 1)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;
    }
};

class BlightTownMap: public Map {
    // TODO: Store graphs and other variables
    int vertex;
    int edge;
    int n, m;
    bool healthy;
    vector<list<pair<int, int>>> AdjList;
    vector<vector<int>> AdjMatrix;
    vector<bool> visited;
    vector<int> path;

public:
    void all_paths(int u, int dest)
    {
            visited[u] = true;
            path.push_back(u);
            if (u == dest)
            {
                vector<int>::iterator i;
                int total = 0;
                healthy = false;
                int a;


                if (path.size()>=m)
                {
                    if (path.size()>n)
                    {
                        for (int i=0; i<n; i++)
                        {
                            if (AdjMatrix[path[i]][path[i+1]] == 1)
                                total++;
                        }
                        if (total <= m)
                        {
                            for (a=0; a<path.size()-n-1; a++)
                            {
                                total = total - AdjMatrix[path[a]][path[a+1]];
                                total = total + AdjMatrix[path[a+n]][path[a+n+1]];

                                if (total <= m)
                                    continue;
                                else
                                    break;
                            }
                            if (a == path.size()-n-1)
                            {
                                healthy = true;
                            }
                        }

                    }

                    else
                    {
                        for (int i=0; i<path.size()-1; i++)
                        {
                            if (AdjMatrix[path[i]][path[i+1]] == 1)
                                total++;
                        }
                        if (total <= m)
                        {
                            healthy = true;
                        }
                    }

                }
                //print path
                /*
                for (i=path.begin(); i!=path.end(); i++)
                    cout << (*i) << " ";
                cout << endl;
                */

            }
            else
            {
                for (int i=0; i<vertex; i++)
                {
                    if (AdjMatrix[u][i] != -1)
                    {
                        if (healthy != true)
                        {
                            if (visited[i] == false)
                            all_paths(i, dest);
                        }

                    }
                }
            }
            path.pop_back();
            visited[u] = false;


    }
    void read_input() override {
        // TODO
        cin >> vertex;
        cin >> edge;
        cin >> n;
        cin >> m;
        AdjMatrix.resize(vertex);
        for (int z=0; z<vertex; z++)
        {
            AdjMatrix[z].resize(vertex, -1);
        }
        for (int a=0; a<edge; a++)
        {
            int i, j, t;
            cin >> i;
            cin >> j;
            cin >> t;
            AdjMatrix[i][j] = t;
        }
        /*
        cin >> vertex;
        cin >> edge;
        cin >> n;
        cin >> m;
        AdjList.resize(vertex);
        for (int a=0; a<edge; a++)
        {
            int i, j, t;
            cin >> i;
            cin >> j;
            cin >> t;
            AdjList[i].push_back(make_pair(j,t));
        }
        */
    }
    void process() override {
        // TODO
        visited.resize(vertex);
        for (int i=0; i<vertex; i++)
        {
            visited[i] = false;
        }
        healthy = false;
        all_paths(0, vertex-1);
    }
    void output() override {
        // TODO
        if (healthy == true)
            cout << "TRUE" << endl;
        else
            cout << "FALSE" << endl;
    }
};

int main(void)
{
    int T, map_kind;
    Map* map;
    cin >> T;
    while (T--) {
        cin >> map_kind;
        switch (map_kind) {
            case 1: map = new LosSantosMap(); break;
            case 2: map = new PortalChambersMap(); break;
            case 3: map = new SkyrimMap(); break;
            case 4: map = new BlightTownMap(); break;
            default: return 1;
        }
        map->read_input();
        map->process();
        map->output();
        delete map;
    }
    return 0;
}

