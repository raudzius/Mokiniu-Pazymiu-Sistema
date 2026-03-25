#include <array>
#include <iostream>
#include <iomanip>
using namespace std;

const int STUDENTS_LIMIT = 100;
const int GRADES_LIMIT = 10;

int getStudentNameIndexUsingStudentName(const string studentName, string (&studentNames)[STUDENTS_LIMIT])
{
    for (int i = 0; i < STUDENTS_LIMIT; i++)
    {
        if (studentName == studentNames[i])
        {
            return i;
        }
    }
    return -1;
}

int getInitialServiceOptionInput()
{
    int userInput;

    cout << "\nPasirinkite norima paslauga, ivesdami numeri:\n";
    cout << "Prideti mokini ir mokinio pazymius - 1\n";
    cout << "Perziureti visu mokiniu arba konkretaus mokinio pazymius - 2\n";
    cout << "Atnaujinti mokinio pazymi - 3\n";
    cout << "Pasalinti mokini is saraso - 4\n";
    cout << "Iseiti - 0\n\n";

    cin >> userInput;

    return userInput;
};

int getDisplayStudentGradesServiceInput()
{
    int userInput;

    cout << "\nPasirinkite norima paslauga, ivesdami numeri:\n";
    cout << "Perziureti visu mokiniu pazymius - 1\n";
    cout << "Perziureti konkretaus mokinio pazymius - 2\n";
    cout << "Grizti - 0\n\n";
    cin >> userInput;

    return userInput;
}

string getStudentNameInput()
{
    string studentName;
    cout << "\nIveskite mokinio vardą: ";
    cin >> studentName;
    cout << "\n";
    return studentName;
}

void addStudent(const string studentName, string (&studentNames)[STUDENTS_LIMIT])
{
    for (int i = 0; i < STUDENTS_LIMIT; i++)
    {
        if (studentName == studentNames[i])
        {
            cout << "\nMokinys su siuo vardu jau egzistuoja\n";
            break;
        }

        if (studentNames[i].empty())
        {
            studentNames[i] = studentName;
            break;
        }

        if (i + 1 == STUDENTS_LIMIT && !studentNames[i].empty())
        {
            cout << "\nMokiniu sarasas pilnas, pries naudodami sia funkcija, pasalinkite betkuri mokini is saraso\n";
            break;
        }
    }
}

void addStudentGrades(string studentName, string (&studentNames)[STUDENTS_LIMIT], int (&studentGrades)[STUDENTS_LIMIT][GRADES_LIMIT], array<int, GRADES_LIMIT> &studentGradeInputs)
{
    int studentNameIndex = getStudentNameIndexUsingStudentName(studentName, studentNames);

    for (int i = 0; i < GRADES_LIMIT; i++)
    {
        studentGrades[studentNameIndex][i] = studentGradeInputs[i];
        cout << studentGradeInputs[i];
    }

    cout << "\n";
}

array<int, GRADES_LIMIT> getStudentGradeInput(string studentName)
{
    array<int, GRADES_LIMIT> studentGrades;
    cout << "\nIveskite " << studentName << " Pazymius\n";

    for (int i = 0; i < GRADES_LIMIT; i++)
    {
        int studentGrade;

        cout << "\nPazymys " << (i + 1) << ": ";
        cin >> studentGrade;
        studentGrades[i] = studentGrade;
    }

    return studentGrades;
}

void displayGrades(string studentName, int studentGrades[])
{
    cout << "\n"
         << studentName << " Pazymiai: ";

    for (int i = 0; i < GRADES_LIMIT; i++)
    {
        cout << "\n"
             << i + 1 << ". " << studentGrades[i];
    }

    cout << "\n";
    cout << "----------------\n";
}

void showGradesOfAllStudents(string (&studentNames)[STUDENTS_LIMIT], int (&studentGrades)[STUDENTS_LIMIT][GRADES_LIMIT])
{
    for (int i = 0; i < STUDENTS_LIMIT; i++)
    {
        if (studentNames[i].empty())
            break;

        displayGrades(studentNames[i], studentGrades[i]);
    }
}

void showGradesOfIndividualStudent(string studentName, string (&studentNames)[STUDENTS_LIMIT], int studentGrades[STUDENTS_LIMIT][GRADES_LIMIT])
{

    int studentNameIndex = getStudentNameIndexUsingStudentName(studentName, studentNames);

    displayGrades(studentName, studentGrades[studentNameIndex]);
}

int main()
{
    string studentNames[STUDENTS_LIMIT];
    int studentGrades[STUDENTS_LIMIT][GRADES_LIMIT];

    bool programIsRunning = true;
    while (programIsRunning)
    {
        int serviceIndexInput = getInitialServiceOptionInput();
        switch (serviceIndexInput)
        {
        case 1:
        {
            string studentName = getStudentNameInput();
            addStudent(studentName, studentNames);
            array<int, GRADES_LIMIT> studentGradeInputs = getStudentGradeInput(studentName);
            addStudentGrades(studentName, studentNames, studentGrades, studentGradeInputs);
            break;
        }
        case 2:
        {
            int serviceChoiceInput = getDisplayStudentGradesServiceInput();
            switch (serviceChoiceInput)
            {
            case 1:
            {
                showGradesOfAllStudents(studentNames, studentGrades);
                break;
            }
            case 2:
            {
                string studentName = getStudentNameInput();
                showGradesOfIndividualStudent(studentName, studentNames, studentGrades);
            }
            default:
                break;
            }

            break;
        }
            // case 3:
            // {
            //     string studentNameInput;
            //     printInputStudentName();
            //     cin >> studentNameInput;
            //     for (int i = 0; i < STUDENTS_LIMIT; i++)
            //     {
            //         if (studentNames[i] == studentNameInput)
            //         {
            //             cout << setw(15) << "Vardas: " << setw(15) << "Pazymiai: ";
            //             for (int j = 0; j < GRADES_LIMIT; j++)
            //             {
            //                 cout << studentGrades[i][j] << " ";
            //             }
            //         }
            //     }
            // }
            // break;
            // }
            // case 4:
            // {
            //     {
            //         string studentNameInput;
            //         printInputStudentName();
            //         cin >> studentNameInput;
            //         for (int i = 0; i < STUDENTS_LIMIT; i++)
            //         {
            //             if (studentNames[i] == studentNameInput)
            //             {
            //                 string studentName = studentNames[i];
            //                 cout << setw(15) << "Vardas: " << setw(15) << "Pazymiai: " << endl;
            //                 cout << setw(15) << studentName << setw(15);
            //                 for (int j = 0; j < GRADES_LIMIT; j++)
            //                 {
            //                     cout << studentGrades[i][j] << " ";
            //                 }
            //                 cout << "\n";
            //             }
            //         }
            //         int gradeIndexInput;
            //         cout << "Iveskite eiles numeri pazymio kuri norite pakeisti:" << "\n";
            //         cin >> gradeIndexInput;
            //         cout << "P";
            //     }
            //     break;
        default:
            programIsRunning = false;
            break;
        }
    }
    return 0;
}
