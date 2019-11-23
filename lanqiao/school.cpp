//
// Created by zyh on 2019/11/5.
//

#include <iostream>

using namespace std;

class CSchoolContend {
public:
    static void begin_1();
};

void CSchoolContend::begin_1() {
    int n;
    cin >> n;
    char star[2] = "*";
    char space[2] = " ";
    for (int i =0;i<n;i++) {
        for (int j=n-2;j>=i;j--) {
            printf("%s",space);
        }
        for (int k=0;k<2*(i+1)-1;k++) {
            printf("%s",star);
        }
        printf("\n");
    }
}

int main() {
    CSchoolContend r;
    r.begin_1();
    return 0;
}
