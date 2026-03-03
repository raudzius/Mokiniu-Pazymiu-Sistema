#include <iostream>
using namespace std;

int main()
{
    bool programIsRunning = true;
    while (programIsRunning)
    {
        int userInput;
        string studentNames[100];
        int studentGrades[100][10];
        cout << "Pasirinkite norima veiksma, ivesdami jo numeri:" << endl;
        cout << "Pridėti mokinį - 1" << "\n";
        cout << "Perziureti mokiniu pazymius - 2" << "\n";
        cout << "Atnaujinti mokiniu pazymius - 3" << "\n";
        cout << "Pasalinti mokini is saraso - 4" << "\n";
        cout << "Iseiti - 0" << "\n";

       switch (userInput)
        {
            case 1:
               string studentName;
            cout << "Įveskite mokinio vardą" << endl;
               cin >> studentName;
               for (int i = 0; i < sizeof(studentNames); i++) {
                   if (studentNames[i].empty()) {
                       studentNames[i] = studentName;
                       break;
                   }else if (i+1==sizeof(studentNames)) {
                    cout << "Mokiniu sarasas pilnas, pries naudodami sia funkcija, pasalinkite betkuri mokini is saraso" << endl;
                   }
                   }

               }

        }
    return 0;
}
