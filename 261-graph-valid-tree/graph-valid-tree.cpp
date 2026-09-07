class UnionFind
{
public:
    UnionFind(int n) : mNumComponents(n), mNodes(n)
    {
        std::iota(mNodes.begin(), mNodes.end(), 0);
    }

    bool Unite(int i, int j)
    {
        auto rooti = find(i);
        auto rootj = find(j);
        if (rooti!=rootj)
        {
            mNodes[rootj] = rooti;
            --mNumComponents;
            return true;
        }

        return false;
    }

    int GetNumComponents() { return mNumComponents; }

private:
    std::vector<int> mNodes;
    int mNumComponents{0};

    int find(int i)
    {
        if (mNodes[i]==i) { return i; }
        mNodes[i] = find(mNodes[i]);

        return mNodes[i];
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges)
    {
        UnionFind unionFind(n);
        for (const auto& ele : edges)
        {
            if (!unionFind.Unite(ele[0], ele[1])) { return false; }
        }

        return unionFind.GetNumComponents()==1;
    }
};