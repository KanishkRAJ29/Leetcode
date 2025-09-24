class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string s = "";
        if(numerator==0) return "0";
        if(numerator<0 ^ denominator<0) s+="-";
        long long num = abs((long long)numerator);
        long long den = abs((long long)denominator);
        int g = gcd(num,den);
        num /=g , den/=g;
        long long q = num/den;
        long long r = num%den;
        s += to_string(q);
        
        if(r==0) return s;
        s+='.';
        unordered_map<long long ,int> m;
        int w = s.size();
        while(r!=0){
            if(m.find(r) != m.end()){
                s.insert(m[r],"(");
                s+=")";
                break;

            }
            m[r]=s.size();
            r =r*10;
            s+=to_string(r/den);
            r%=den;
        }
        return  s;   
    }
};