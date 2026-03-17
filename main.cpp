#include <iostream>
#include <iomanip>
using namespace std;

int STUDENTS_LIMIT = 100;
int GRADES_LIMIT = 10;

void printInitialServiceOptions() {
    cout << "Pasirinkite norima veiksma, ivesdami jo numeri:" << "\n";
    cout << "Pridėti mokinį ir ivesti jo pazymius - 1" << "\n";
    cout << "Perziureti visu mokiniu arba konkretaus mokinio pazymius - 2" << "\n";
    cout << "Atnaujinti mokinio pazymi - 3" << "\n";
    cout << "Pasalinti mokini is saraso - 4" << "\n";
    cout << "Iseiti - 0" << "\n";
};

string getStudentNameInput() {
    string studentName;
    cout << "Iveskite mokinio vardą" << "\n";
    cin >> studentName;
    return studentName;
}

void addStudent(string studentName, string studentNames[]) {
    int studentNameIndex;


    for (int i = 0; i < STUDENTS_LIMIT; i++) {
        if (studentNames[i].empty()) {
            studentNames[i] = studentName;
            studentNameIndex = i;
            break;
        } else if (i + 1 == STUDENTS_LIMIT && !studentNames[i].empty()) {
            cout << "Mokiniu sarasas pilnas, pries naudodami sia funkcija, pasalinkite betkuri mokini is saraso" << "\n";
        }
    }
}

int getStudentNameIndex(string studentName,string studentNames[]) {
    for (int i = 0; i < STUDENTS_LIMIT; i++) {
        if (studentName==studentNames[i]) {
            return i;
        }
        }
}

void getStudentGradeInput(int studentNameIndex, string studentName) {
    string studentGrades[];
    cout << "Iveskite" << studentName << "Pazymius" << "\n";

    for (int i = 0; i < GRADES_LIMIT; i++) {
        cout << studentGrades[studentNameIndex][i] << ": ";
        cin >> studentGrades[studentNameIndex][i];
    }
}

int main() {
    bool programIsRunning = true;
    while (programIsRunning) {
        int userInput;
        string studentNames[STUDENTS_LIMIT];
        int studentGrades[STUDENTS_LIMIT][GRADES_LIMIT];

        printInitialServiceOptions();

        switch (userInput) {
            case 1: {
                string studentName=getStudentNameInput();
                int studentNameIndex=getStudentNameIndex(studentName,studentNames);
                int studentGrades[GRADES_LIMIT]=getStudentGradeInput(studentNameIndex,studentName,s);
                addStudent();

                break;
            }
            case 2:
                cout << "Visu mokiniu pazymius - 0";
                cout << "Konkretaus mokinio pazymius - 1";
                int userInput;
                cin >> userInput;
                switch (userInput) {
                    case 1: {
                        {
                            for (int i = 0; i < STUDENTS_LIMIT; i++) {
                                cout << setw(15) << "Vardai: " << setw(15) << "Pazymiai: ";
                                for (int j = 0; j < GRADES_LIMIT; j++) {
                                    cout << studentGrades[i][j] << " ";
                                }
                            }
                        }
                    }
                        case 2: {
                        string studentNameInput;
                        printInputStudentName();
                        cin >> studentNameInput;
                        for (int i = 0; i < STUDENTS_LIMIT; i++) {
                            if (studentNames[i] == studentNameInput ) {
                                cout << setw(15) << "Vardas: " << setw(15) << "Pazymiai: ";
                                for (int j = 0; j < GRADES_LIMIT; j++) {
                                    cout << studentGrades[i][j] << " ";
                                }
                            }
                        }
                    }
                        break;
                }
                case 3: {
                    string studentNameInput;
                    printInputStudentName();
                    cin >> studentNameInput;
                    for (int i = 0; i < STUDENTS_LIMIT; i++) {
                        if (studentNames[i] == studentNameInput ) {
                            string studentName =studentNames[i];
                            cout << setw(15) << "Vardas: " << setw(15) << "Pazymiai: " << endl;
                            cout << setw(15) << studentName << setw(15);
                            for (int j = 0; j < GRADES_LIMIT; j++) {
                                cout << studentGrades[i][j] << " ";
                            }
                            cout << "\n";
                        }
                    }
                    int gradeIndexInput;
                    cout << "Iveskite eiles numeri pazymio kuri norite pakeisti:"<< "\n";
                    cin >> gradeIndexInput;
                    cout << "P";
                }
            default:
                programIsRunning = false;
                break;
        }
    }
    return 0;
}
