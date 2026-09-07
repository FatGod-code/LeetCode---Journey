class UnionFind
{
public:
    UnionFind(int n) : mNumComponents(n), mParents(n)
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
            --mNumComponents;
            
            return true;
        }

        return false;
    }

    int getNumComponents() { return mNumComponents; }

private:
    std::vector<int> mParents;
    int mNumComponents{0};

    int find(int i)
    {
        if (mParents[i]==i) { return i; }

        mParents[i] = find(mParents[i]);
        return mParents[i];
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges)
    {
        UnionFind uf(n);
        for (const auto& ele :edges)
        {
            uf.unite(ele[0], ele[1]);
        }

        return uf.getNumComponents();
    }
};