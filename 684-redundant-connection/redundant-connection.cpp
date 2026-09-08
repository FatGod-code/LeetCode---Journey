class UnionFind
{
public:
    UnionFind(int n) : mParents(n), mNumComponenets(n)
    {
        std::iota(mParents.begin(), mParents.end(), 0);
    }

    bool unite(int i, int j)
    {
        auto rooti = find(i);
        auto rootj = find(j);
        if (rooti!=rootj)
        {
            mParents[rootj] = rooti;
            --mNumComponenets;
            return true;
        }

        return false;
    }

private:
    std::vector<int> mParents;
    int mNumComponenets{0};

    int find(int i)
    {
        if (mParents[i]==i) { return i; }

        mParents[i] = find(mParents[i]);
        return mParents[i];
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        UnionFind uf(edges.size());
        for (const auto& ele : edges)
        {
            if (!uf.unite(ele[0]-1, ele[1]-1)) { return ele; }
        }

        return {};
    }
};