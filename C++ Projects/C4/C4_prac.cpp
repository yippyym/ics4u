#include <iostream>
#include <vector>
#include <string>
using namespace std;

// // q5 p2
// namespace Universe
// {
//     int Galaxy = 1;
// }
// namespace Universe
// {
//     int Planet = Galaxy + 2;
// }

// // q16 p2
// void swap(float *x, float *y)
// {
//     float z = *x;
//     *x = *y;
//     *y = z;
// }

// // q17 p2
// double eval(double x)
// {
//     return x / (.5 * x);
// }
// void use(double n)
// {
//     int v = 1 / n;
//     v = eval(v);
//     cout << v;
// }

// // q21 p2
// string replicate(string s = "x", int r = 1)
// {
//     string t;
//     while (r--)
//         t += s;
//     return t;
// }

// // q22 p2
// char do1(char *x)
// {
//     return *x;
// }
// char *do2(char *y)
// {
//     return y;
// }
// char *do3(char &z)
// {
//     return &z;
// }

// // q26 p2
// float combine(float x1 = 0.0, int x2 = 1.0)
// {
//     return x2 + x1;
// }

// // q30 p2
// int op(int i, int j = 1)
// {
//     return i * j;
// }
// int op(char a, char b)
// {
//     return b - a;
// }
// int op(float x, float y)
// {
//     return x / y;
// }

int main()
{
    // // q1
    // vector<double> arr = {1e-1, 1e0, 1e1};
    // double *ptr = arr.data() + 2;
    // cout << arr[1] - *ptr;

    // // q2
    // int i = 0, k = i;
    // while (i == 0)
    // {
    //     if (k > 1)
    //         i = k;
    //     ++k;
    // }
    // cout << k;

    // // q3
    // int i = 2, j = i++, k = i++;
    // cin >> i;
    // cout << k - i << j - 1;

    // // q4
    // int k = 2 % 3 + 5 % 3;
    // cout << k;

    // // q5 p1
    // Universe::Galaxy *= 2;
    // {
    //     using namespace Universe;
    //     Planet++;
    // }
    // cout << Universe::Galaxy << Universe::Planet;

    // // q6
    // string s = "123";
    // s.append(s.substr(2)).push_back(s[s.length() - 2]);
    // cout << s;

    // // q7
    // vector<float *> ft = {new float[1], new float[1], new float[1]};
    // for (int i = 0; i < 3; i++)
    // {
    //     float *p = ft[i];
    //     *p = i;
    // }
    // cout << *ft[1];
    // for (int i = 0; i < 3; i++)
    // {
    //     delete[] ft[i];
    // }

    // // q8
    // int i = 1, k = i << 1;
    // switch (k)
    // {
    // case 1:
    //     i += 1;
    //     break;
    // case 2:
    //     i += 2;
    //     break;
    // default:
    //     i += 3;
    //     break;
    // }
    // cout << i;

    // // q9
    // vector<char> text(5);
    // char *chr1 = text.data() + 2, *chr2 = chr1 + 2;
    // cout << chr2 - text.data();

    // // q10
    // string s1 = "brick";
    // string s2 = "block";
    // string s;
    // s1.swap(s2);
    // s2.swap(s);
    // s.swap(s2);
    // cout << s1;

    // // q11
    // int a = 2, b = a >> 1;
    // int c = b >> a;
    // int d = 1 << c;
    // int e = d << d;
    // cout << e;

    // // q12
    // bool b1 = !true;
    // bool b2 = !b1 && false;
    // bool b3 = b2 || true;
    // if (b3)
    //     cout << "true";
    // else
    //     cout << "false";

    // // q15
    // short s = 1;
    // int i = 2;
    // float f = 4.;
    // cout << i / static_cast<float>(s) + i / 2 + i / f;

    // // q16 p1
    // vector<float> t = {3., 2., 1.};
    // swap(&t[0], &t[2]);
    // cout << t[1];

    // // q17 p1
    // use(1.f);

    // // q18
    // int a = 0x02, b = 001;
    // int c = a ^ b;
    // int d = c | a;
    // int e = d & 0;
    // cout << e;

    // // q19
    // int a = 2, b = a >> 1;
    // int c = a >> b;
    // int d = 1 << c;
    // int e = d >> d;
    // cout << e;

    // // q20
    // int i = 2;
    // float f = 1;
    // cout << (static_cast<float>(i) >> 1);

    // // q21 p1
    // string pattern = "a";
    // cout << replicate(pattern);

    // // q22 p1
    // char sign = '1';
    // cout << do1(do2(do3(sign)));

    // // q24
    // int i = 2;
    // string s = "2";
    // cout << s == i;

    // // q25
    // float x = 1.0 / 5.0;
    // int i = x;
    // cout << i;

    // // q26 p1
    // cout << combine() + combine(1.) + combine(2., 3.);

    // // q27
    // int i = 1, k = i & 0;
    // do
    // {
    //     k++;
    //     if (k > 1)
    //         i = k;
    // } while (i < 2);
    // cout << k;

    // // q28
    // int i, k = 1;
    // for (i = 0; i < 3; i += 2)
    //     k++;
    // cout << k;

    // // q29
    // int k = 3;
    // if (k > 0)
    // {
    //     if (k != 3)
    //         k--;
    //     if (k == 3)
    //         k++;
    // }
    // if (k < 0)
    // {
    //     k = 5;
    // }
    // cout << k;

    // // q30 p1
    // cout << op(2) << op('c', 'a') << op(4.f, 2.f);

    return 0;
}
