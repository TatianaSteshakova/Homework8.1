#include <iostream>
#include <string>

using namespace std;

class Person {
    private:
        string name;
        int age;
        char gender;
        double weight;
    public:
        Person() {
            name = "";
            age = 0;
            gender = ' ';
            weight = 0;
        }
        Person(string n, int a, char g, double w) {
            name = n;
            age = a;
            gender = g;
            weight = w;
        }
        void setName(string n) {
            name = n;
        }
        string getName() const {
            return name;
        }
        void setAge(int a) {
            age = a;
        }
        void setWeight(double w) {
            weight = w;
        }
        int getAge() const {
            return age;
        }
        double getWeight() const {
            return weight;
        }

        char getGender() const {
            return gender;
        }
};


class Student : public Person {
    int yearOfStudy;
    public:

        Student() {
            yearOfStudy = 1;
        }

        Student(string n, int a, char g, double w, int y) : Person(n, a, g, w) {
            if(yearOfStudy >= 1)
            yearOfStudy = y;
            else
            cout << "Ошибка: значение года обучения должно быть больше 1" << endl;
            return;
        }

        void setYearOfStudy(int y) {
            if (yearOfStudy >= 1)
                yearOfStudy = y;
            else
                cout << "Ошибка: значение года обучения должно быть больше 1" << endl;
            return;
        }
        int getYearOfStudy() const {
            return yearOfStudy;
        }
};

class Teacher : public Person {
private:
    string passType;
public:

    Teacher() {
        passType = "";
    }

    Teacher(string n, int a, char g, double w, string p) : Person(n, a, g, w) {
        passType = p;
    }

    void setPassType(string p) {
        if (passType == "технический" || passType == "научный")
            passType = p;
        else
            cout << "Ошибка: преподаватель не имеет пропуска или его тип неверный. Преподаватель должен иметь пропуск." << endl;
    }
    string getPassType() const {
        return passType;
    }

    void getAccessInfo() const {
        if (passType == "технический") {
            cout << "Преподавателю доступен технический корпус университета" << endl;
            cout << "Преподавателю предоставляется скидка в столовой" << endl;
        }
        else if (passType == "научный") {
            cout << "Преподавателю доступен научный корпус университета" << endl;
            cout << "Преподавателю не предоставляется скидка в столовой" << endl;
        }
    }
};

int main()
{
    setlocale(0, "Rus");

    string n;
    char g;
    int y, w;


    cout << "Введите имя, возраст, пол и вес: " << endl;
    cin >> n >> y >> g >> w;

    Person p(n, y, g, w);

    string who;
    cout << "Кого вы хотите добавить: " << endl;
    if (who == "Студент")
    {
        int ys;
        cout << "Введите год обучения: " << endl;
        cin >> ys;

        Student s(n, y, g, w, ys);

        s.setYearOfStudy(2);

        cout << "Имя: " << s.getName() << endl;
        cout << "Возраст: " << s.getAge() << endl;
        cout << "Пол: " << s.getGender() << endl;
        cout << "Вес: " << s.getWeight() << endl;
        cout << "Год обучения: " << s.getYearOfStudy() << endl;
    }
    else if (who == "Учитель")
    {
        string passType;

        cout << "Введите тип пропуска: " << endl;
        cin >> passType;

        Teacher t(n, y, g, w, passType);
        cout << "Имя: " << t.getName() << endl;
        cout << "Возраст: " << t.getAge() << endl;
        cout << "Пол: " << t.getGender() << endl;
        cout << "Вес: " << t.getWeight() << endl;
        cout << "Тип пропуска: " << t.getPassType() << endl;
    }

    // Задание 3

    class Player {
        int id;
        string nickname;
        int coords[3];
        int hp;
        int hunger;
        int inventory[3][9]; 

        int getPlayer() {
            return id;
        }
    };

    class Item {
        int id;
        string name;
        string type;
        int maxStack; // Максимальное кол-во в одном стаке
        int parent;
    };

    class Block : Item {
        int coords[3];
        bool canDestroy;
        int takePower; // Насколько мощным должно быть взаимодействие, чтобы блок пропал и его можно было подобрать
        int destroyPower; // Насколько мощным должно быть взаимодействие, чтобы уничтожить блок без возможности подбора
    };

    class Tool : Item {
        string toolType;
        int power; // Мощность взаимодействия с блоками. Влияет на то, можно ли блок сломать данным инструментом.
    };

    class Mob {
        int id;
        string name;
        string type;
        bool peaceful; // Мирный моб (корова, курица) или нет (скелет, зомби).
        int damage; // Только для немирных мобов

        void setDamage(int i)
        {
            if (peaceful)
                cout << "Моб мирный. Установить урон невозможно." << endl;
            else
                damage = i;
        }
    };

    class Plant : Block {
        int growSpeed;
    };

}