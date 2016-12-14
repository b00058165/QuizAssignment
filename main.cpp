#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string studentnumber, group;
    int choice,choice1,edit=10;
    cout << "Hello Welcome to Our Quiz!" << endl; //welcome message
    cout << "Please Enter Student number:" << endl;
    cin >> studentnumber; //read in student number
    string sn = studentnumber;
    string txt = ".txt";
    string snum = sn + txt;
    //--------------------------------------------------
    if (studentnumber == "admin")
    {
        cout << "Press 1 to view all results or 2 to edit quiz" << endl;
        cin >> choice1;
        if (choice1 == 1)
        {
            string line;
            ifstream allresults ("all_results.txt");
            if (allresults.is_open())
            {
                while (getline(allresults,line))
                {
                    cout << line << "\n"; //read in the all_results file
                }
                allresults.close(); //close file
            }
        }
        else if (choice == 2)
        {
            cout << "Enter how many questions are to be asked. (Default is 10):" << endl;
            int edit;
            cin >> edit; //Change how many questions are asked
        }
        else
        {
            cout << "Invalid" << endl;
        }
    }
    //--------------------------------------------------
    else
    {
        cout << "Press 1 to take quiz or 2 to view your previous results" << endl;
        cin >> choice;
        if (choice == 1)
        {
            string ques[15],opt[45],ans[15]; //array of strings for the questions,options and answers
            int i=0,j=0,k=0;
            ifstream quiz2 ("quiz.txt");
            if (quiz2.is_open())
            {
                while(!quiz2.eof()) //Scan in each question, option and answer
                {
                    getline(quiz2,ques[i], '\n');
                    i++;
                    getline(quiz2,opt[j], '\n');
                    j++;
                    getline(quiz2,opt[j], '\n');
                    j++;
                    getline(quiz2,opt[j], '\n');
                    j++;
                    getline(quiz2,ans[k], '\n');
                    k++;
                }
                quiz2.close(); //close question file
            }
            string answ;
            int result = 0;
            j = 0;
            for (i=0;i<edit;i++) //ask questions
            {
                cout << ques[i] << ": \n";
                cout << opt[j] << endl;
                j++;
                cout << opt[j] << endl;
                j++;
                cout << opt[j] << endl;
                j++;
                cin >> answ;
                if(answ == ans[i])
                {
                    cout << " Correct!" << endl;
                    result = result + 10; //if correct add 10%
                }
                else
                {
                    cout << "Incorrect" << endl;
                }
            }
            if(result >= 50)
            {
                cout << "Keep it up. Your result was " << result << "%" << endl;
            }
            else
            {
                cout << "Revision is needed. Your result was " << result << "%" <<  endl;
            }
            ofstream quizfile;
            quizfile.open (snum.c_str(), ios::app);
            quizfile << result << "%\n"; //save the result to personal file
            quizfile.close();
            ofstream allresults;
            allresults.open ("all_results.txt", ios::app);
            allresults << sn << " - " << result << "%\n"; //save the result to admin file
            allresults.close();
            return 0;
        }
        else if (choice == 2)
        {
            string line1;
            ifstream sn (snum.c_str());
            if (sn.is_open())
            {
                while (getline(sn,line1))
                {
                    cout << line1 << "\n"; //view preious student attempts
                }
                sn.close(); //close student file
            }
        }
        else
        {
            cout << "Invalid" << endl;
        }
    }

    return 0;
}
