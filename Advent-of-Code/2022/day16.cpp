#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 100;
const int INF = 1e9;
const int T1 = 30;
const int T2 = 26;

map<string, int> valve_to_id_map;
map<int, int> valve_to_flow_map;
map<int, vector<int>> adj_list;
map<int, map<int, int>> dp[T1+1];
vector<vector<int>> dist(N, vector<int>(N, INF));
vector<int> pos_flow_valves;

int get_max_flow(int cur_id, int state, int time_left) {
    int m = pos_flow_valves.size();
    if(state == (1 << m) - 1) {
        return 0;
    }
    if(dp[time_left][cur_id].count(state) > 0) {
        return dp[time_left][cur_id][state];
    }
    int mx = 0;
    for(int i=0;i<m;i++) {
        int next_id = pos_flow_valves[i];
        if((state & (1 << i)) == 0) {
            // if this valve is currently closed
            int time_used = dist[cur_id][next_id] + 1;
            if(time_left - time_used > 0) {
                // open this valve
                int flow = valve_to_flow_map[next_id] * (time_left - time_used);
                // take the max flow
                mx = max(mx, flow + get_max_flow(next_id, state | (1 << i), time_left - time_used));
            }
        }
    }
    dp[time_left][cur_id][state] = mx;
    return mx;
}

void part1() {
    cout << get_max_flow(valve_to_id_map["AA"], 0, T1) << endl;
}

void part2() {
    int m = pos_flow_valves.size();
    int b = (1 << m) - 1;
    int mx = 0;
    // partition each possible state into two disjoint sets, where you go to one and the elephant goes to the other
    for(int i=0;i<=b/2;i++) {
        mx = max(mx, get_max_flow(valve_to_id_map["AA"], i, T2) + get_max_flow(valve_to_id_map["AA"], b ^ i, T2)); 
    }
    cout << mx << endl;
}

int main() {
    vector<string> lines;
    string s;
    while(getline(cin, s)) {
        lines.push_back(s);
    }
    // map each valve to a numerical ID
    int id = 0;
    for(string s : lines) {
        s.erase(0, s.find(" ") + 1);
        string valve = s.substr(0, s.find(" "));
        valve_to_id_map[valve] = id++;
    }
    // represent the input as an adjacency list
    for(string s : lines) {
        s.erase(0, s.find(" ") + 1);
        string valve = s.substr(0, s.find(" "));
        int id = valve_to_id_map[valve];
        s.erase(0, s.find("=") + 1);
        int flow = stoi(s.substr(0, s.find(";")));
        valve_to_flow_map[id] = flow;
        for(int i=0;i<5;i++) {
            s.erase(0, s.find(" ") + 1);
        }
        int pos;
        string token;
        string delim = ", ";
        while((pos = s.find(delim)) != std::string::npos) {
            token = s.substr(0, pos);
            adj_list[id].push_back(valve_to_id_map[token]);
            s.erase(0, pos + delim.length());
        }
        adj_list[id].push_back(valve_to_id_map[s]);
    }
    // build distance matrix
    for(auto p : adj_list) {
        int u = p.first;
        vector<int> next = p.second;
        for(int v : next) {
            dist[u][v] = 1;
        }
    }
    // run floyd warshall to find all-pairs shortest paths
    for(int k=0;k<N;k++) {
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    // get list of valves with positive flow
    for(auto p : valve_to_flow_map) {
        int id = p.first, flow = p.second;
        if(flow > 0) {
            pos_flow_valves.push_back(id);
        }
    }
	part1();
	part2();
}
