class Solution {
public:
    string complexNumberMultiply(string l, string m) {
        int pos = l.find('+');
        string r1 = l.substr(0,pos);
        string i1 = l.substr(pos+1);
        i1.pop_back();
        int pos1 = m.find('+');
        string r2 = m.substr(0,pos1);
        string i2 = m.substr(pos1+1);
        i2.pop_back();
        int a = stoi(r1);
        int b = stoi(i1);
        int x = stoi(r2);
        int y = stoi(i2);
        string aa = to_string(a*x-b*y);
        string bb = to_string(b*x+a*y);
        return aa+"+"+bb+"i";
    }
};
