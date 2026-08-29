class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        std::stack<std::string> sta;
        for (const auto& ele : tokens)
        {
            if (ele!="+" && ele!="-" && ele!="*" && ele!="/") { sta.emplace(ele); }
            else
            {
                const auto value2Str = sta.top();
                sta.pop();
                int value2 = std::stoi(value2Str);

                const auto value1Str = sta.top();
                sta.pop();
                int value1 = std::stoi(value1Str);

                if (ele=="+") { value1 += value2; }
                if (ele=="-") { value1 -= value2; }
                if (ele=="*") { value1 *= value2; }
                if (ele=="/") { value1 /= value2; }

                sta.emplace(std::to_string(value1));
            }
        }

        int results = std::stoi(sta.top());
        return results;
    }
};