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

int getStudentGradeCount()
{
    int gradeCount;
    cout << "\nKiek pazymiu norite ivesti?: ";
    cin >> gradeCount;
    cout << "\n";
    return gradeCount;
}

int addStudent(const string studentName, string (&studentNames)[STUDENTS_LIMIT])
{
    for (int i = 0; i < STUDENTS_LIMIT; i++)
    {
        if (studentName == studentNames[i])
        {
            cout << "\nMokinys su siuo vardu jau egzistuoja\n";
            return 0;
        }

        if (studentNames[i].empty())
        {
            studentNames[i] = studentName;
            break;
        }

        if (i + 1 == STUDENTS_LIMIT && !studentNames[i].empty())
        {
            cout << "\nMokiniu sarasas pilnas, pries naudodami sia funkcija, pasalinkite betkuri mokini is saraso\n";
            return 0;
        }
    }
    return 1;
}

void addStudentGrades(string studentName, string (&studentNames)[STUDENTS_LIMIT], int (&studentGrades)[STUDENTS_LIMIT][GRADES_LIMIT], array<int, GRADES_LIMIT> &studentGradeInputs, int studentGradeCount)
{
    int studentNameIndex = getStudentNameIndexUsingStudentName(studentName, studentNames);

    cout << "\n"
         << studentName << " pazymiai: \n";
    for (int i = 0; i < studentGradeCount; i++)
    {
        studentGrades[studentNameIndex][i] = studentGradeInputs[i];
        cout << i + 1 << ". " << studentGradeInputs[i] << "\n";
    }

    cout << "----------------\n";
}

array<int, GRADES_LIMIT> getStudentGradeInput(string studentName, int studentGradeCount)
{
    array<int, GRADES_LIMIT> studentGrades;
    cout << "\nIveskite " << studentName << " pazymius\n";

    for (int i = 0; i < studentGradeCount; i++)
    {
        int studentGrade;

        cout << "\nPazymys " << (i + 1) << ": ";
        cin >> studentGrade;
        while (studentGrade < 1 || studentGrade > 10)
        {
            cout << "\nNeteisinga ivestis leistinu pazymiu rezis 1-10\n";
            cout << "\nPazymys " << (i + 1) << ": ";
            cin >> studentGrade;
        }

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
        if (studentGrades[i] < 1 || studentGrades[i] > 10)
            break;

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

void changeStudentGrade(string studentName, string (&studentNames)[STUDENTS_LIMIT], int (&studentGrades)[STUDENTS_LIMIT][GRADES_LIMIT])
{
    int studentIndex = getStudentNameIndexUsingStudentName(studentName, studentNames);
    int gradeIndexInput;
    int newGradeInput;

    displayGrades(studentName, studentGrades[studentIndex]);

    cout << "\nIrasykite indeksa pazymio kuri norite pakeisti: ";
    cin >> gradeIndexInput;
    int oldGrade = studentGrades[studentIndex][gradeIndexInput - 1];
    cout << "\n\n";

    cout << "Irasykite nauja pazymi: ";
    cin >> newGradeInput;
    while (newGradeInput < 1 || newGradeInput > 10)
    {
        cout << "\nNeteisinga ivestis leistinu pazymiu rezis 1-10\n";
        cout << "\nIrasykite nauja pazymi: ";
        cin >> newGradeInput;
    }

    studentGrades[studentIndex][gradeIndexInput - 1] = newGradeInput;
    cout << "\n\n";

    cout << "Pazymys " << oldGrade << " pakeistas i " << newGradeInput << "\n";
}

void deleteStudent(string studentName, string (&studentNames)[STUDENTS_LIMIT], int (&studentGrades)[STUDENTS_LIMIT][GRADES_LIMIT], int studentCount)
{
    int studentIndex = getStudentNameIndexUsingStudentName(studentName, studentNames);

    if (studentIndex == -1)
    {
        cout << "\nStudentas nerastas";
        return;
    }

    for (int i = studentIndex; i < studentCount - 1; i++)
    {
        studentNames[i] = studentNames[i + 1];

        for (int j = 0; j < GRADES_LIMIT; j++)
        {
            studentGrades[i][j] = studentGrades[i + 1][j];
        }
    }

    studentNames[studentCount - 1] = "";
    for (int i = 0; i < GRADES_LIMIT; i++)
    {
        studentGrades[studentCount - 1][i] = -1;
    }

    cout << "\nStudentas " << studentName << " istrintas\n";
}

int main()
{
    string studentNames[STUDENTS_LIMIT];
    int studentGrades[STUDENTS_LIMIT][GRADES_LIMIT];
    int studentCount = 0;

    bool programIsRunning = true;
    while (programIsRunning)
    {
        int serviceIndexInput = getInitialServiceOptionInput();
        switch (serviceIndexInput)
        {
        case 1:
        {
            string studentName = getStudentNameInput();
            int isAddingSuccesful = addStudent(studentName, studentNames);
            if (isAddingSuccesful == 0)
                break;
            int studentGradeCount = getStudentGradeCount();
            array<int, GRADES_LIMIT> studentGradeInputs = getStudentGradeInput(studentName, studentGradeCount);
            addStudentGrades(studentName, studentNames, studentGrades, studentGradeInputs, studentGradeCount);
            studentCount++;
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
        case 3:
        {
            string studentName = getStudentNameInput();
            changeStudentGrade(studentName, studentNames, studentGrades);
            break;
        }
        case 4:
        {
            string studentName = getStudentNameInput();
            deleteStudent(studentName, studentNames, studentGrades, studentCount);
            studentCount--;
            break;
        }
        default:
            programIsRunning = false;
            break;
        }
    }
    return 0;
}
