#include <iostream>
#include <random>
#include <ctime>
#include <Windows.h> // для Sleep()

using namespace std;


string randName() {

    string glas = "eyuioa";
    string soglas = "qwrtpsdfghjklzxcvbnm";
    string name = "";
    srand(time(0));
    for (int i = 0; i < rand() % 6 + 4; i++) {
        if (i % 2 == 0) {
            name += soglas[rand() % 20];
        }
        else {
            name += glas[rand() % 6];
        }
    }

    return name;
}



class player {
    //свойства объекта
    //private:
    //    static int x = 1;
public:
    int id;
    string name;
    int hp;
    int exp = 0;
    int lvl;

    //момент создания конкретного объекта класса(конструктор):
    player(string Name, int HP = 100){
        name = Name;
        this->id = 1; //этот объект
        lvl = 1;
        hp = HP;
    }

    void print_info() {
        cout << id << ". " << name<< " " << lvl << " " << hp << " " << exp << endl;
    }

    void lvlUp() {
        if (exp > 100 * lvl) {
            lvl++;
        }
    }


    void fight(player other) {

        srand(time(0));
        while (hp > 0 && other.hp > 0) {
            hp -= rand() % 20;
            other.hp -= rand() % 20;
            cout << name << " " << hp << endl;
            cout << other.name << " " << other.hp << endl;
            cout << "***********************************" << endl;
            Sleep(1000);
        }
        if (hp > 0) {
            exp += rand() % 10 + 5; //опыт до +14
            hp = 100 * lvl;
        }
    }

};




int main()
{

    //player pl1("Vasya"); // конструктор чтопроисхлдит в момент, когда объявляю объект класса
    /*pl1.print_info();
    player pl2("Petya");
    pl2.print_info();
    pl1.fight(pl2);
    pl1.lvlUp();
    pl2.lvlUp();
    pl1.print_info();
    pl2.print_info();*/

    player pl1("AAA");
    pl1.print_info();
    while (pl1.hp > 0) {
        player monster(randName(), rand() % 50 + 50);
        pl1.fight(monster);
        pl1.lvlUp();
        pl1.print_info();
    }

    return 0;
}
