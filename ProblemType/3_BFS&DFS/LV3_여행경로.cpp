#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>


using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;


    sort(tickets.begin(), tickets.end(), greater<vector<string>>());

    // a[�����] = *vector ���·� map ����
    // �������� ���ĵ�, ������ vector�� �� ������ ū ���Ĺ��� �����
    unordered_map<string, vector<string>> routes;
    // Ticket�� ���� ����
    for (int i = 0; i < tickets.size(); i++) {
        routes[tickets[i][0]].push_back(tickets[i][1]);
    }

    // ����� ����
    vector<string> tempStack = { "ICN" };
    while (!tempStack.empty()) {
        string airport = tempStack.back();

        if (routes.find(airport) == routes.end() || routes[airport].size() == 0) {
            answer.push_back(airport);
            tempStack.pop_back();
        }
        else {
            tempStack.push_back(routes[airport].back());
            routes[airport].pop_back();
        }
    }

    reverse(answer.begin(), answer.end());

    return answer;
}

int main() {

    vector<vector<string>> t = { {"ICN", "JFK"} ,{"HND", "IAD"},{"JFK", "HND"} };
    vector<string> result = solution(t);

    for (auto it : result) {
        printf("%s\n", it.c_str());
    }

    return 0;
}