// Daily 15.2.2025
// 2698. Find the Punishment Number of an Integer
// https://leetcode.com/problems/find-the-punishment-number-of-an-integer/submissions/1544402294

struct CompileTimeCalc {
    static consteval bool part(int x, int goal) {
        constexpr int m[] = {10, 100, 1000};
        if(goal < 0 || x < goal) return false;
        if(x == goal) return true;

        return part(x / m[0], goal - x % m[0]) ||
            part(x / m[1], goal - x % m[1]) ||
            part(x / m[2], goal - x % m[2]);
    }
    static consteval std::array<int, 1001> getArr()
    {
        std::array<int, 1001> a;
        a[0] = 0;
        for (auto i = 1; i < 1001; i++)
        {
            a[i] = a[i-1];
            if(part(i*i, i))
                a[i] += i*i;
        }
        return a;
    }
};


class Solution {
public:
    int punishmentNumber(int n) {
        return ar[n];
    }
private:
    static const constexpr auto ar = CompileTimeCalc::getArr();
};
