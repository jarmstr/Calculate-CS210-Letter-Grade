#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int NUMHOMEWORK = 7;
const int NUMPROGRAMS = 4;
const int NUMEXAM= 3;
const float MAXPROGRAMS = 400.0;
const char ASCIICONVERT = 0X0F;


int main()
{
    float finalExam, examSum = 0,programSum = 0;
    float hwSum = 0, hwDivider = 0, examDivider = 0;
    char homework[NUMHOMEWORK];
    int programs[NUMPROGRAMS];
    int exam[NUMEXAM];
    float totalGrade;

    ifstream fin;
    ofstream fout;
    fin.open("numbers.txt");

   if(!fin.is_open())
    {
       exit(EXIT_FAILURE);
    }

cout <<  "Final Exam\t" << "Three Hourly Exams\t\t\t" << "Homework" << "Programs" << endl;
    fin >> finalExam;
while(fin)
{

    for(int a = 0; a< NUMEXAM; a++)
    {
        fin >> exam[a];
        examSum += exam[a];

    }
       int tempSum = 100;
    for(int b=0; b<NUMEXAM; b++)
        {
            if(tempSum >= exam[b])
            {
            tempSum = exam[b];
            }
        }//end loop
        examSum += tempSum;


    for(int c =0;c < NUMHOMEWORK;c++)
    {
         cin >> homework[c];
         hwSum += (homework[c]-'0');
    }
        if(hwSum<NUMHOMEWORK)
        {
            hwDivider = NUMHOMEWORK-1;
           cout << hwDivider << endl;
        }
        else
        {
            hwDivider = NUMHOMEWORK;
        }
        if(300> examSum)
        {
           examDivider = NUMEXAM - 1;
        }
        else
        {
            examDivider = NUMEXAM;
        }
    for(int d=0; d < NUMPROGRAMS; d++)
        {
        fin >> programs[d];
        programSum += programs[d];
        }
     totalGrade = (finalExam*0.25)+
    (examSum/examDivider)*0.45 +(programSum/NUMPROGRAMS)*0.20+ (hwSum/hwDivider)*0.10;

    cout << finalExam << "\t" << exam[0] << "\t" << exam[1] << "\t" << exam[2] << "\t" << NUMHOMEWORK << "\t" << programs[1] << programs[2] << programs[3] << programs[4] << endl;

    fin >> finalExam;

}
    fin.close();








    return 0;
}

