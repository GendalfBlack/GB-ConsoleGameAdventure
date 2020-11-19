#include <iostream>
using namespace std;

struct stats {
    int str;
    int agl;
    int intl;
    int luck;
    int chr;
    int moral;
};

struct player {
    string name;
    string pclass;
    int age;
    int hp;
    int mp;
    int lvl;
    int money;
    int exp;
    stats pstats;
};

enum combat {HIT = 1, SPELLS, IDLE, CONVINCE, RUN};

struct enemy {
    string name;
    int lvl;
    int hp;
    int mp;
    int money;
};

struct environment {
    string name;
    string discr;
    string directions[4];
    environment * locations;
    enemy* enemys;
};

void show_info(player& p);
void show_info(stats& s);
void show_info(environment& e);
void show_info(enemy& e);
void in_location(environment& e);

int main()
{
    stats s = {5, 3, 20, 14, 21, 18};
    player new_p = {"Gendalf", "Mage", 61, 1000, 500, 80, 50, 0, s};
    environment e2 = {
        "Minas Tirit. Casle",
        "Glorious castle of mans.",
        {"Kings hall", "Dungeons", "Back", "none"}
    };
    environment e3 = {
        "Minas Tirit. Market",
        "Biggest markets of humans",
        {"Blacksmith", "Food", "Tavern", "Back"}
    };
    environment e4 = {
        "Minas Tirit. Gates",
        "Entrince from white glorious stone",
        {"Out of town", "Main gates towers", "Back to town", "none"}
    };
    environment e5 = {
        "Minas Tirit. Tombs",
        "Ancient catacombs of forgotten kings.",
        {"Tunnel #1", "Tunnel #2", "Back", "none"}
    };
    environment loc[4] = { e2,e3,e4,e5 };
    environment e1 = {
        "Minas Tirit",
        "The city of Minas Tirith covered an entire hill, the Hill of Guard. This hill was a shoulder of Mindolluin, the mountain which towered behind the city and which was the easternmost peak of the White Mountains. The city was built on seven levels, culminating in the Citadel at the summit.",
        {"Castle", "Market", "Gates", "Tombs"},
        loc
    };

    in_location(e1);
}

void in_location(environment& e) {
    system("cls");
    show_info(e);
    cout << "Where to go?" << endl;
    for (int i= 0; i < 4; i++)
    {
        if (e.directions[i] != "none")
        {
            cout << i + 1 << ". " << e.directions[i] << endl;
        }
    }
    int answ;
    cin >> answ;
    in_location(e.locations[answ-1]);
}

void show_info(enemy& e) {
    cout << "You encountered " << e.name << endl;
    cout << "Lvl: " << e.lvl << endl;
    cout << endl << "HP: " << e.hp << endl << "MP:" << e.mp << endl;
}

void show_info(environment & e) {
    cout << "You are in: " << e.name << endl;
    cout << e.discr << endl;
}

void show_info(player & p) {
    cout << "Name: " << p.name << ", " << p.age << " y.o." << endl;
    cout << "Class: " << p.pclass << endl;
    cout << "Lvl: " << p.lvl << endl;
    cout << "XP: "<< p.exp << endl;
    cout << endl << "HP: " << p.hp << endl << "MP:" << p.mp << endl;
    cout << "Gold: " << p.money << endl;
}

void show_info(stats & s) {
    cout << "Strength: " << s.str << endl;
    cout << "Agility: " << s.agl << endl;
    cout << "Intelligence: " << s.intl << endl;
    cout << "Luck: " << s.luck << endl;
    cout << "Charisma: " << s.chr << endl;
    cout << "Morale: " << s.moral << endl;
}