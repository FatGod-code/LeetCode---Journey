class Solution {
public:
    string multiply(string num1, string num2)
    {
        if (num1=="0" || num2=="0") { return "0"; }

        std::string results(num1.size()+num2.size(), 0);
        for (int idx1 = num1.size()-1; idx1>=0; --idx1)
        {
            for (int idx2 = num2.size()-1; idx2>=0; --idx2)
            {
                int value1 = num1[idx1]-'0';
                int value2 = num2[idx2]-'0';
                int value3 = results[idx1+idx2+1];

                int value = value3+value1*value2;
                int residue = value%10;
                int carry = value/10;

                results[idx1+idx2+1] = residue;
                results[idx1+idx2] = results[idx1+idx2]+carry;
            }
        }

        for (auto& ele : results) { ele += '0'; }

        if (results[0]=='0') { return results.substr(1, results.size()); }
        return results;
    }
};