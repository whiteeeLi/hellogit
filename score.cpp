
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

struct students
{
public:
    string name;
    string sex;
    string score;
    double nature_score;
    bool nature_sex;
};

int main() {
    
    ifstream input("score.csv");

    students student[51];
    int counter = 1;
    char temp[5];
    getline(input, student[0].name, ',');
    getline(input, student[0].sex,',');
    getline(input, student[0].score);

    while (input)
    {
      getline(input, student[counter].name,',');
      getline(input, student[counter].sex,',');
      if(student[counter].sex == " Female")
        student[counter].nature_sex = 0;
      else
        student[counter].nature_sex = 1;
      getline(input, student[counter].score);
      strcpy(temp, student[counter].score.c_str());      
      student[counter].nature_score = std::stof(temp);
      if(counter == 32)
      break; 
      counter++;
    }

    string names;
    double scores;
    bool sexs;
    for (int m = 0; m<2 ; m++)
    {
     for(int j= 1; j <= counter; j++)
     {
      for (int i = j+1; i <= counter; i++)
       {
         if(student[j].nature_score < student[i].nature_score)
         {
          scores = student[i].nature_score;
          student[i].nature_score = student[j].nature_score;
          student[j].nature_score = scores;

          names = student[i].name;
          student[i].name = student[j].name;
          student[j].name = names;
         
          sexs = student[i].nature_sex;
          student[i].nature_sex = student[j].nature_sex;
          student[j].nature_sex = sexs; 
         }
         else if( student[j].nature_score == student[i].nature_score)
         {
           if (student[j].name > student[i].name)
            {
             scores = student[i].nature_score;
             student[i].nature_score = student[j].nature_score;
             student[j].nature_score = scores;

             names = student[i].name;
             student[i].name = student[j].name;
             student[j].name = names;

             sexs = student[i].nature_sex;
             student[i].nature_sex = student[j].nature_sex;
             student[j].nature_sex = sexs;

            }
         }          
       }
      }
     }
    
    double mscore = 0;
    double fscore = 0;
    double mcounter = 0;
    double fcounter = 0;
    
    for(int i = 1; i <= counter ; i++)
    {
     if(student[i].sex == " Female")
     { 
       fscore += student[i].nature_score;
       fcounter++;
     }
     else
     {
       mscore += student[i].nature_score;
       mcounter++;
     }
    }

    cout << "average:" << fixed << setprecision(2) << (mscore + fscore)/(mcounter + fcounter) << endl << "male average:" << fixed << mscore/mcounter << endl << "female average:" << fixed << fscore/fcounter << endl;

 
    for(int i = 1; i < counter ; i++)
    {
      cout << i << ":" << student[i].name << " " << student[i].sex << " " <<  student[i].nature_score << endl;
    }

    
    return 0;
   } 
