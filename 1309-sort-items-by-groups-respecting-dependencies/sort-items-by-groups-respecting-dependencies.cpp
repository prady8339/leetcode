class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int groupId = m;
        for (int i = 0; i < n; ++i) {
            if (group[i] == -1) {
                group[i] = groupId;
                groupId++;
            }
        }

        unordered_map<int, vector<int>> itemGraph;
        vector<int> itemIndegree(n, 0);
        for (int i = 0; i < n; ++i) {
            itemGraph[i] = vector<int>();
        }

        unordered_map<int, vector<int>> groupGraph;
        vector<int> groupIndegree(groupId, 0);
        for (int i = 0; i < groupId; ++i) {
            groupGraph[i] = vector<int>();
        }

        for (int curr = 0; curr < n; ++curr) {
            for (int prev : beforeItems[curr]) {
                itemGraph[prev].push_back(curr);
                itemIndegree[curr]++;

                if (group[curr] != group[prev]) {
                    groupGraph[group[prev]].push_back(group[curr]);
                    groupIndegree[group[curr]]++;
                }
            }
        }

        vector<int> itemOrder = topologicalSort(itemGraph, itemIndegree);
        vector<int> groupOrder = topologicalSort(groupGraph, groupIndegree);

        if (itemOrder.empty() || groupOrder.empty()) {
            return vector<int>();
        }

        unordered_map<int, vector<int>> orderedGroups;
        for (int item : itemOrder) {
            orderedGroups[group[item]].push_back(item);
        }

        vector<int> answerList;
        for (int groupIndex : groupOrder) {
            answerList.insert(answerList.end(), orderedGroups[groupIndex].begin(), orderedGroups[groupIndex].end());
        }

        return answerList;
    }

private:
    vector<int> topologicalSort(unordered_map<int, vector<int>>& graph, vector<int>& indegree) {
        vector<int> visited;
        stack<int> st;
        for (const auto& entry : graph) {
            int key = entry.first;
            if (indegree[key] == 0) {
                st.push(key);
            }
        }

        while (!st.empty()) {
            int curr = st.top();
            st.pop();
            visited.push_back(curr);

            for (int prev : graph[curr]) {
                indegree[prev]--;
                if (indegree[prev] == 0) {
                    st.push(prev);
                }
            }
        }

        return visited.size() == graph.size() ? visited : vector<int>();
    }
};
