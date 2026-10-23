// Средний уровень
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Athlete {
private:
    string name;
    string sport;
    double record;

    static int count;

public:
    Athlete(string n, string s, double r) : name(n), sport(s), record(r) {
        count++;
        cout << "Создан спортсмен: " << name << endl;
    }

    ~Athlete() {
        count--;
        cout << "Удалён спортсмен: " << name << endl;
    }

    void print() const {
        cout << "Имя: " << name
             << ", вид спорта: " << sport
             << ", рекорд: " << record << endl;
    }

    static int getCount() {
        return count;
    }
};

int Athlete::count = 0;

class Roster {
private:
    string name;
    vector<Athlete*> athletes;

public:
    Roster(string n) : name(n) {
        cout << "Создан список: " << name << endl;
    }

    ~Roster() {
        cout << "Удалён список: " << name << endl;
    }

    void addAthlete(Athlete* athlete) {
        athletes.push_back(athlete);
    }

    void print() const {
        cout << "Список спортсменов " << name << ":" << endl;

        for (const auto& athlete : athletes) {
            athlete->print();
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    Athlete a1("one", "Бег", 10.5);
    Athlete a2("two", "Плавание", 52.3);

    cout << "\nКоличество спортсменов: "
         << Athlete::getCount() << endl;

    {
        Roster roster("Russia");
        roster.addAthlete(&a1);
        roster.addAthlete(&a2);

        roster.print();
    }

    cout << "\nСписок уничтожен, но спортсмены существуют:" << endl;

    a1.print();
    a2.print();

    cout << "Количество спортсменов: "
         << Athlete::getCount() << endl;

    return 0;
}
