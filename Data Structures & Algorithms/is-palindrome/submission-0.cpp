class Solution {
public:
    bool isPalindrome(string s) {
        char* m = new char[s.size()];
        int count = 0;
        for (auto it = (s.end() - 1); it != (s.begin() - 1); it--) {
            if ((*it >= 'a' && *it <= 'z') || *it >= '0' && *it <= '9') {
                m[count++] = (*it);
            } else if (*it >= 'A' && *it <= 'Z') {
                m[count++] = (*it - 'A' + 'a');
            }
        }
        char* k = new char[count];
        int i = 0;
        for (auto it = (s.begin()); it != (s.end()); it++) {
            if ((*it >= 'a' && *it <= 'z') || *it >= '0' && *it <= '9') {
                k[i++] = (*it);
            } else if (*it >= 'A' && *it <= 'Z') {
                k[i++] = (*it - 'A' + 'a');
            }
        }

        for (int j = 0; j < i; j++) {
            if (k[j] != m[j])
                return false;
        }
        return true;
    }
};