//165
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int len1 = version1.size(), len2 = version2.size();
        while (i < len1 || j < len2) {
            long revision1 = 0, revision2 = 0;
            while (i < len1 && version1[i] != '.') {
                revision1 = revision1 * 10 + (version1[i] - '0');
                i++;
            }
            while (j < len2 && version2[j] != '.') {
                revision2 = revision2 * 10 + (version2[j] - '0');
                j++;
            }
            if (revision1 < revision2) {
                return -1;
            } else if (revision1 > revision2) {
                return 1;
            }
            i++;
            j++;
        }
        return 0;
    }
};
