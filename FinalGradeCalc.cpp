   Oct. 2, 2011
   Calculates your final grade for the class */
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int NUMHOMEWORK = 7;
const int NUMPROGRAMS = 4;
const float MAXPROGRAMS = 400.0;
const char ASCIICONVERT =0X0F;





int main()

{
    ifstream fin;
    ofstream fout;
    float proSum=0, numHW=0;
    float finPoints,exPoints,proPoints,finalGrade,hwDiv;
    int proGrade,finalExam,homePoints;
    int exam1,exam2,exam3;
    int examSub, examSum;
    char letterGrade;
    fin.open("gradelist.txt");
    fout.open("reportc.txt");
 
 
 
 
 fin >> finalExam;
 
 
     while(fin) //  Begining of end-of-file loop
 {
     
     float numHW=0, proSum = 0;
            
                            
     fin >> exam1 >> exam2 >> exam3;   // Input 3 hourly exam grades 
           
      if(exam1 > exam2) // Test the exam grades to find the lowest
      examSub = exam2;
      else 
      examSub = exam1; 
      if(exam3 > examSub)
      examSub = examSub; 
      else
      examSub = exam3;


 examSum = (exam1+exam2+exam3)- examSub; // sum all exam grades + subtract one


 for(int r = 1; r <=NUMHOMEWORK; r++)
{
         char a,c;
         int b =0;
         fin >> a;
         b = int(a - '0');
         numHW = numHW + b;

}


     if( numHW < NUMHOMEWORK)
          hwDiv = 6;
          else
          hwDiv = 7;



for( int i = 1; i <= NUMPROGRAMS; i++) // Program grade read in loop
{
     
     
     fin >> proGrade;
     proSum = proGrade + proSum;

}
 


      finPoints=(finalExam/100.0)*25; // Calcuate points
      exPoints = (examSum/200.0)*45; 
      proPoints = (proSum/400.0)*20;
      homePoints =(numHW/hwDiv)*10;
   
      finalGrade = finPoints + exPoints + proPoints + homePoints; // adds points 

           
     if (finalGrade >= 90) // Finds letter grade
     letterGrade = 'A';
     else if (finalGrade >= 80)
     letterGrade = 'B';
     else if (finalGrade >= 70)
     letterGrade = 'C';
     else if (finalGrade >= 60)
     letterGrade = 'D';
     else if (finalGrade <= 50)
     letterGrade = 'F';

   fout <<  "Number"<< " " << "Letter"<< endl 
          <<  "-----" << "  " << "-----" << endl
          <<    "  "<< setprecision(2) << finalGrade 
          <<   "   "<< letterGrade  << endl;
     fin >> finalExam;   
}

  
     system("pause");
     return 0;  
}
