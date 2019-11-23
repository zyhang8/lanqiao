#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <sstream>

#define PI 3.14159265358979323
using namespace std;

// 入门练习

class CRumenPractice {
public:
    static void begin_1();

    static void begin_2();

    static void begin_3();

    static void begin_4();
};

void CRumenPractice::begin_1() {
    int a, b;
    cin >> a >> b;
    cout << a + b;
}

void CRumenPractice::begin_2() {
    long long n;
    cin >> n;
    cout << (n + 1) * n / 2;
}

void CRumenPractice::begin_3() {
    int r;
    cin >> r;
    printf("%.7lf\n", r * r * PI);
}

void CRumenPractice::begin_4() {
    int n;
    cin >> n;
    int f[n];
    f[1] = f[2] = 1;
    if (n > 2) {
        for (int i = 3; i <= n; i++) {
            f[i] = (f[i - 2] + f[i - 1]) % 10007;
        }
        cout << f[n];
    } else {
        cout << 1;
    }
}


// 基础练习

//冒泡排序
void BubbleSort(vector<int> &a) {
    int len = a.size();
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j + 1], a[j]);
            }
        }
    }
    for (int k = 0; k < a.size(); k++) {
        cout << a[k] << ' ';
    }
    cout << endl;
}

//选择排序
void SelectionSort(vector<int> &a) {
    int len = a.size();
    for (int i = 0, minIndex; i < len - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < len; j++) {
            if (a[j] < a[minIndex]) {
                swap(a[j], a[minIndex]);
            }
        }
    }
    for (int k = 0; k < a.size(); k++) {
        cout << a[k] << ' ';
    }
    cout << endl;
}

//插入排序
void InsertionSort(vector<int> &a) {
    int len = a.size();
    for (int i = 0, j, temp; i < len - 1; i++) {
        j = i;
        temp = a[j + 1];
        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
    for (int k = 0; k < a.size(); k++) {
        cout << a[k] << ' ';
    }
    cout << endl;
}

//希尔排序
void ShellSort(vector<int> &a) {
    int len = a.size();
    for (int gap = len / 2; gap > 0; gap /= 2) {
        for (int i = 0; i < gap; i++) {
            for (int j = i + gap, temp, preIndex; j < len; j += gap) {
                temp = a[j];
                preIndex = j - gap;
                while (preIndex >= 0 && a[preIndex] > temp) {
                    a[preIndex + gap] = a[preIndex];
                    preIndex -= gap;
                }
                a[preIndex + gap] = temp;
            }
        }
    }
    for (int k = 0; k < a.size(); k++) {
        cout << a[k] << ' ';
    }
    cout << endl;
}

//快速排序
int partition(vector<int> &a, int left, int right) {
    int pivot = a[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (a[j] < a[right]) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[right]);
    return i + 1;
}

void QuickSort(vector<int> &a, int left, int right) {
    if (left < right) {
        int mid = partition(a, left, right);
        QuickSort(a, left, mid - 1);
        QuickSort(a, mid + 1, right);
    }
}

void QSort(vector<int> &a) {
    QuickSort(a, 0, a.size() - 1);
    for (int k = 0; k < a.size(); k++) {
        cout << a[k] << ' ';
    }
    cout << endl;
}

//归并排序
void MergeSort(vector<int> &a, vector<int> &T, int left, int right) {
    if (right - left == 1) {
        return;
    }
    int mid = (left + right) >> 1, tmid = (left + right) >> 1, tleft = left, i = left;
    MergeSort(a, T, left, mid), MergeSort(a, T, mid, right);
    while (tleft < mid || tmid < right) {
        if (tmid >= right || (tleft < mid && a[tleft] < a[tmid])) {
            T[i++] = a[tleft++];
        } else {
            T[i++] = a[tmid++];
        }
    }
    for (int i = left; i < right; i++) {
        a[i] = T[i];
    }
}

void MSort(vector<int> &a) {
    int len = a.size();
    vector<int> T(len);
    MergeSort(a, T, 0, len);
    for (int k = 0; k < a.size(); k++) {
        cout << a[k] << ' ';
    }
    cout << endl;
}

//堆排序

void AdjustHeap(vector<int> &a, int i, int len) {
    int maxIndex = i;
    if (2 * i + 1 < len && a[2 * i + 1] > a[maxIndex])
        maxIndex = 2 * i + 1;
    if (2 * i + 2 < len && a[2 * i + 2] > a[maxIndex])
        maxIndex = 2 * i + 2;
    if (maxIndex != i) {
        swap(a[maxIndex], a[i]);
        AdjustHeap(a, maxIndex, len);
    }
}

void Sort(vector<int> &a) {
    int len = a.size();
    for (int i = len / 2 - 1; i >= 0; i--) {
        AdjustHeap(a, i, len);
    }
    for (int i = len - 1; i > 0; i--) {
        swap(a[0], a[i]);
        AdjustHeap(a, 0, i);
    }
    for (int k = 0; k < a.size(); k++) {
        cout << a[k] << ' ';
    }
    cout << endl;
}

//计数排序
void CountingSort(vector<int> &a) {
    int len = a.size();
    if (len == 0) return;
    int Min = a[0], Max = a[0];
    for (int i = 1; i < len; i++) {
        Max = max(Max, a[i]);
        Min = min(Min, a[i]);
    }
    int bias = 0 - Min;
    vector<int> bucket(Max - Min + 1, 0);
    for (int i = 0; i < len; i++) {
        bucket[a[i] + bias]++;
    }
    int index = 0, i = 0;
    while (index < len) {
        if (bucket[i]) {
            a[index] = i - bias;
            bucket[i]--;
            index++;
        } else {
            i++;
        }
    }
    for (int k = 0; k < a.size(); k++) {
        cout << a[k] << ' ';
    }
    cout << endl;
}

//桶排序
void BucketSort(vector<int> &a) {
    int len = a.size();
    int bucketSize = 3;
    if (len < 2) {
        for (int k = 0; k < a.size(); k++) {
            cout << a[k] << ' ';
        }
        cout << endl;
        return;
    }
    int Max = a[0], Min = a[0];
    for (int i = 1; i < len; i++) {
        Max = max(Max, a[i]);
        Min = min(Min, a[i]);
    }
    int bucketCount = (Max - Min) / bucketSize + 1;
    vector<int> bucketArr[bucketCount];
    for (int i = 0; i < len; i++) {
        bucketArr[(a[i] - Min) / bucketCount].push_back(a[i]);
    }
    a.clear();
    for (int i = 0; i < bucketCount; i++) {
        int blen = bucketArr[i].size();
        sort(bucketArr[i].begin(), bucketArr[i].end());
        for (int j = 0; j < blen; j++) {
            a.push_back(bucketArr[i][j]);
        }
    }
    for (int k = 0; k < a.size(); k++) {
        cout << a[k] << ' ';
    }
    cout << endl;
}

//基数排序
void RadixSortSort(vector<int> &a) {
    int len = a.size();
    if (len < 2) {
        for (int k = 0; k < len; k++) {
            cout << a[k] << ' ';
        }
        cout << endl;
        return;
    }
    int Min = a[0];
    for (int i = 1; i < len; i++) {
        Min = min(Min, a[i]);
    }
    for (int i = 0; i < len; i++) {
        a[i] -= Min;
    }
    int Max = a[0];
    for (int i = 1; i < len; i++) {
        Max = max(Max, a[i]);
    }
    int maxDigit = log10(Max) + 1;
    int mod = 10, div = 1;
    vector<int> bucketList[10];
    for (int i = 0; i < maxDigit; i++, mod *= 10, div *= 10) {
        for (int j = 0; j < len; j++) {
            int num = (a[j] % mod) / div;
            bucketList[num].push_back(a[j]);
        }
        int index = 0;
        for (int j = 0; j < 10; j++) {
            int tlen = bucketList[j].size();
            for (int k = 0; k < tlen; k++) {
                a[index++] = bucketList[j][k];
            }
            bucketList[j].clear();
        }
    }
    for (int k = 0; k < a.size(); k++) {
        a[k] += Min;
        cout << a[k] << ' ';
    }
    cout << endl;
}

class CBasePractice {
public:
    static void begin_1();

    static void begin_2();

    static void begin_3();

    static void begin_4();

    static void begin_5();

    static void begin_6();

    static void begin_7();

    static void begin_8();

    static void begin_9();

    static void begin_10();

    static void begin_11();

    static void begin_12();

    static void begin_13();

    static void begin_14();

    static void begin_15();

    static void begin_16();

    static void begin_17();

    static void begin_18();

    static void begin_19();

    static void begin_20();

    static void begin_21();

    static void begin_22();

    static void begin_23();

    static void begin_24();

    static void begin_25();

    static void begin_26();

    static void begin_27();

    static void begin_28();

    static void begin_29();

    static void begin_30();
};

void CBasePractice::begin_1() {
    int n;
    cin >> n;
    if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}

void CBasePractice::begin_2() {
    for (int i = 0; i < 32; i++) {
        vector<int> p(5, 0);

        int temp = i;
        int index = 4;
        while (temp >= 1) {
            p[index--] = temp % 2;
            temp /= 2;
        }
        for (int k = 0; k < p.size(); k++) {
            cout << p[k];
        }
        cout << endl;
    }
}

void CBasePractice::begin_3() {
    int row = 0, col = 0;
    cin >> row >> col;
    for (int i = 0; i < row; i++) {
        char ch = 'A';
        char index = 'A';
        index = (char) (index + i);
        for (int k = 0; k < min(i, col); k++) {
            cout << index--;
        }
        for (int j = 0; j < col - i; j++) {
            cout << ch++;
        }
        cout << endl;
    }
}

void CBasePractice::begin_4() {
    int n = 0;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    cout << *max_element(p.begin(), p.end()) << endl << *min_element(p.begin(), p.end()) << endl
         << accumulate(p.begin(), p.end(), 0) << endl;
}

void CBasePractice::begin_5() {
    int n = 0, gpcode;
    cin >> n;
    vector<int> p(n);
    vector<int>::iterator iter;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    cin >> gpcode;
    iter = find(p.begin(), p.end(), gpcode);

    if (iter != p.end()) {
        cout << iter - p.begin() + 1 << endl;
    } else {
        cout << -1 << endl;
    }

}

void CBasePractice::begin_6() {
    int n;
    cin >> n;
    vector<vector<int> > data(n);
    data[0].push_back(1);
    for (int i = 1; i < data.size(); i++) {
        data[i].push_back(1);
        for (int j = 1; j < i; j++) {
            data[i].push_back(data[i - 1][j - 1] + data[i - 1][j]);
        }
        data[i].push_back(1);
    }
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data[i].size(); j++) {
            cout << data[i][j] << " ";
        }
        cout << '\n';
    }
}

void CBasePractice::begin_7() {
    int max = (int) (log(1000) / log(3)) + 1;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                int num = i * 100 + j * 10 + k;
                int pnum = pow(i, 3) + pow(j, 3) + pow(k, 3);
                if (num == pnum && 100 <= num)
                    cout << num << endl;
            }
        }
    }
//    for(int i =100;i<1000;i++) {
//        int a= i%100/10;
//        int b= i%10;
//        int c= i/100;
//        if((pow(a,3)+pow(b,3)+pow(c,3))==i) {
//            cout << i << endl;
//        }
//    }
}

void CBasePractice::begin_8() {
    for (int i = 1000; i < 10000; i++) {
        int a = i % 1000 / 100;//百
        int b = i % 100 / 10;//十
        int d = i % 10;//个
        int c = i / 1000;//千
        if (a == b && c == d) {
            cout << i << endl;
        }
    }
}

void CBasePractice::begin_9() {
    int n;
    cin >> n;
    for (int i = 10000; i < 100000; i++) {
        int a = i / 10000;
        int b = i % 10000 / 1000;
        int c = i % 1000 / 100;
        int d = i % 100 / 10;
        int e = i % 10;
        if (a == e && b == d && (a + b + c + d + e == n)) {
            cout << i << endl;
        }
    }
    for (int i = 100000; i < 1000000; i++) {
        int a = i / 100000;
        int b = i % 100000 / 10000;
        int c = i % 10000 / 1000;
        int d = i % 1000 / 100;
        int e = i % 100 / 10;
        int f = i % 10;
        if (a == f && b == e && c == d && (a + b + c + d + e + f == n)) {
            cout << i << endl;
        }
    }
}

void CBasePractice::begin_10() {
    int num;
    cin >> num;
    if (num == 0) {
        cout << num << endl;
        return;
    }
    vector<int> data;
    while (num != 0) {
        data.push_back(num % 16);
        num /= 16;
    }
    vector<int>::size_type st = data.size();
    vector<string> vect;
    int temp;
    string m, n;
    stringstream sstream;
    for (vector<int>::size_type index = 0; index < st; index++) {
        if (data[st - 1 - index] > 9) {
            temp = data[st - 1 - index] + 55;
            m = char(temp);
            vect.push_back(m);
        } else {
            sstream << data[st - 1 - index];
            sstream >> n;
            sstream.clear();
            vect.push_back(n);
        }
    }
    for (vector<int>::size_type i = 0; i < st; i++) {
        cout << vect[i];
    }
    cout << endl;
}

void CBasePractice::begin_11() {
    char num;
    string data;
    cin >> data;
    vector<int>::size_type len = data.size();
    int temp, temp1;
    size_t sum = 0, times;
    for (vector<int>::size_type index = 0; index < len; index++) {
        data[index] = tolower(data[index]);
        temp = 0;
        if ('a' <= data[index] && data[index] <= 'z') {
            temp = (int) data[index] - 97 + 10;
        } else {
            temp = (int) data[index] - 48;
        }
        times = pow(16, len - 1 - index);
        sum += temp * times;
    }
    cout << sum << endl;
}

void CBasePractice::begin_12() {
    string s1, s2;
    int n;
    int i, j, k;
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> s1;
        s2 = "";
        for (j = 0; j < s1.length(); j++) {
            switch (s1[j]) {
                case '0':
                    s2 += "0000";
                    break;
                case '1':
                    s2 += "0001";
                    break;
                case '2':
                    s2 += "0010";
                    break;
                case '3':
                    s2 += "0011";
                    break;
                case '4':
                    s2 += "0100";
                    break;
                case '5':
                    s2 += "0101";
                    break;
                case '6':
                    s2 += "0110";
                    break;
                case '7':
                    s2 += "0111";
                    break;
                case '8':
                    s2 += "1000";
                    break;
                case '9':
                    s2 += "1001";
                    break;
                case 'A':
                    s2 += "1010";
                    break;
                case 'B':
                    s2 += "1011";
                    break;
                case 'C':
                    s2 += "1100";
                    break;
                case 'D':
                    s2 += "1101";
                    break;
                case 'E':
                    s2 += "1110";
                    break;
                case 'F':
                    s2 += "1111";
                    break;
                default:
                    break;
            }
        }
        if (s2.length() % 3 == 1)
            s2 = "00" + s2;
        if (s2.length() % 3 == 2)
            s2 = "0" + s2;
        int flag = 0;
        for (k = 0; k < s2.length() - 2; k += 3) {
            int p = 4 * (s2[k] - '0') + 2 * (s2[k + 1] - '0') + s2[k + 2] - '0';
            if (p)
                flag = 1;
            if (flag)
                cout << p;
        }
        cout << endl;
    }

}

void CBasePractice::begin_13() {
    int n = 0;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    BubbleSort(p);
//    SelectionSort(p);
//    InsertionSort(p);
//    ShellSort(p);
//    QSort(p);
//    MSort(p);
//    Sort(p);
//    CountingSort(p);
//    BucketSort(p);
    RadixSortSort(p);
}

void CBasePractice::begin_14() {
    int n = 0;
    cin >> n;
    int a = n / 3600;
    int b = n % 3600 / 60;
    int c = n % 60;
    cout << a << ":" << b << ":" << c << endl;
}

void CBasePractice::begin_15() {
    string a, b;
    cin >> a;
    cin >> b;
    string c = a, d = b;
    for (int i = 0; i < c.size(); i++) {
        c[i] = tolower(c[i]);
    }
    for (int i = 0; i < d.size(); i++) {
        d[i] = tolower(d[i]);
    }
    if (a.size() != b.size()) {
        cout << 1 << endl;
    } else if (a.size() == b.size() && a == b) {
        cout << 2 << endl;
    } else if (a.size() == b.size() && a != b && c == d) {
        cout << 3 << endl;
    } else {
        cout << 4 << endl;
    }
}

void CBasePractice::begin_16() {
    vector<int> a(2, 0);//初始化数组
    for (int i = 0; i < a.size(); i++)//输入
    {
        cin >> a[i];
    }
    for (int i = a[0]; i <= a[1]; i++) {
        cout << i << "=";
        int temp = i;
        for (int j = 2; j <= temp; j++) {
            while (temp % j == 0 && temp != j) {
                temp /= j;
                cout << j << "*";
            }

            if (temp == j) {
                cout << j << endl;
                break;
            }
        }
    }
}

void CBasePractice::begin_17() {
    int n, m;
    cin >> n;
    cin >> m;
    vector<vector<int> > rect(n, vector<int>(n, 0));//初始化数组
    vector<vector<int> > mul(n, vector<int>(n, 0));
    vector<vector<int> > result(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> rect[i][j];
            mul[i][j] = rect[i][j];
        }
    }

    if (m == 0) {
        for (int i = 0; i < rect.size(); i++) {
            for (int j = 0; j < rect[i].size(); j++) {
                if (i == j) {
                    cout << 1 << ' ';
                } else {
                    cout << 0 << ' ';
                }
            }
            cout << endl;
        }
        return;
    }

    if (m == 1) {
        for (int i = 0; i < rect.size(); i++) {
            for (int j = 0; j < rect[i].size(); j++) {
                cout << rect[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }

    while (m > 1) {
        for (int i = 0; i < rect.size(); i++) {
            for (int j = 0; j < rect[i].size(); j++) {
                for (int k = 0; k < n; k++) {
                    result[i][j] += rect[i][k] * mul[k][j];
                }
            }
        }
        for (int i = 0; i < rect.size(); i++) {
            for (int j = 0; j < rect[i].size(); j++) {
                rect[i][j] = result[i][j];
                result[i][j] = 0;
            }
        }
        m--;
    }

    for (int i = 0; i < rect.size(); i++) {
        for (int j = 0; j < rect[i].size(); j++) {
            cout << rect[i][j] << " ";
        }
        cout << endl;
    }
}

void CBasePractice::begin_18() {
    double x1, y1, x2, y2;
    double x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;
    double m1, m2, m3, m4;
    m1 = max(min(x1, x2), min(x3, x4));
    m2 = max(min(y1, y2), min(y3, y4));
    m3 = min(max(x1, x2), max(x3, x4));
    m4 = min(max(y1, y2), max(y3, y4));
    if (m1 <= m3 && m2 <= m4) {
        double area = (m1 - m3) * (m2 - m4);
        printf("%.2f", area);
    } else {
        double area = 0;
        printf("%.2f", area);
    }
}

void CBasePractice::begin_19() {
    int n;
    cin >> n;
    string a;
    cin >> a;
    int j = n - 1;
    int ctn = 0;
    int flag = 0;
    for (int i = 0; i < j; i++) {
        for (int k = j; k >= i; k--) {
            if (k == i) {
                if (n%2==0||flag==1) {
                    cout << "Impossible";
                }
                flag = 1;
                ctn += n/2-i;
                cout<<ctn<<endl;
            } else if (a[k] == a[i]) {
                cout<<"i"<<i<<endl;
                cout<<"j"<<j<<endl;
                for (int l = k; l < j; l++) {
                    swap(a[k], a[k + 1]);
                    ctn++;
                    cout<<ctn<<endl;
                }
                j--;
                break;
            }
            cout<<a<<endl;
        }
    }
    cout<<ctn;
}

int main() {
    CRumenPractice r;
//    r.begin_1();
//    r.begin_2();
//    r.begin_3();
//    r.begin_4();

    CBasePractice b;
//    b.begin_1();
//    b.begin_2();
//    b.begin_3();
//    b.begin_4();
//    b.begin_5();
//    b.begin_6();
//    b.begin_7();
//    b.begin_8();
//    b.begin_9();
//    b.begin_10();
//    b.begin_11();
//    b.begin_12();
//    b.begin_13();
//    b.begin_14();
//    b.begin_15();
//    b.begin_16();
//    b.begin_17();
//    b.begin_18();
    b.begin_19();
//    b.begin_20();
//    b.begin_21();
//    b.begin_22();
//    b.begin_23();
//    b.begin_24();
//    b.begin_25();
//    b.begin_26();
//    b.begin_27();
//    b.begin_28();
//    b.begin_29();
//    b.begin_30();

    return 0;
}

