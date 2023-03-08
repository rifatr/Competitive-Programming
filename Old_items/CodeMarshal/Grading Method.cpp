#include <bits/stdc++.h>

using namespace std;

int main()
{
    int mark, test;
    string grade;

    cin >> test;

    for(int i = 1; i <= test; i++)
    {
        cin >> mark;

        if (mark >= 90)
            grade = "A+";
        else if (mark >= 80)
            grade = "A";
        else if (mark >= 70)
            grade = "A-";
        else if (mark >= 60)
            grade = "B+";
        else if (mark >= 50)
            grade = "B-";
        else if (mark >= 40)
            grade = "C";
        else if (mark >= 35)
            grade = "D";
        else
            grade = "F";

        printf("Student %d: ", i);
        cout << grade << endl;
    }

    return 0;
}

