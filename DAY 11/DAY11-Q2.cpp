//990. Satisfiability of Equality Equations
class Solution
{
public:
    char findPar(unordered_map<char, char> &parent, char node)
    {
        if (node == parent[node])
            return node;
        else
            return parent[node] = findPar(parent, parent[node]);
    }
    void unionn(unordered_map<char, char> &parent, char u, char v)
    {
        u = findPar(parent, u);
        v = findPar(parent, v);
        parent[v] = u;
    }
    bool equationsPossible(vector<string> &equations)
    {
        unordered_map<char, char> parent;
        for (auto it : equations)
        {
            parent[it[0]] = it[0];
            parent[it[3]] = it[3];
        }
        for (auto it : equations)
        {
            if (it[1] == '=')
                unionn(parent, it[0], it[3]);
            else if (it[1] == '!')
            {
                if (findPar(parent, it[0]) == findPar(parent, it[3]))
                    return false;
            }
        }
        for (auto it : equations)
        {
            if (it[1] == '!')
            {
                if (findPar(parent, it[0]) == findPar(parent, it[3]))
                    return false;
            }
        }

        return true;
    }
};