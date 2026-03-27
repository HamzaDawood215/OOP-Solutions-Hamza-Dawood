#include <iostream>
using namespace std;

class Hero {
protected:
    string name;
    string type;
    int health;
    double power;
    int experience;

public:
    Hero(string n, string t, int h, double p, int exp) {
        name = n;
        type = t;
        health = h;
        power = p;
        experience = exp;
    }

    void show() {
        cout << "Welcome to Battle Arena\n";
        cout << "Let the battle begin\n";
    }

    virtual void attack() = 0;
    virtual void defend() = 0;

    void displaybasicinfo() {
        cout << "Hero Name: " << name << endl;
        cout << "Hero Type: " << type << endl;
        cout << "Health: " << health << endl;
        cout << "Power Level: " << power << endl;
        cout << "Experience: " << experience << endl;
    }

    virtual void displayspecial() = 0;
};

class Warrior : public Hero {
private:
    string weapon;
    int armor;
    double rage;

public:
    Warrior(string n, int h, double p, int exp,
            string w, int a, double r)
        : Hero(n, "Warrior", h, p, exp){
        	weapon = w;
        	armor = a;
        	rage = r;
		}

    void displayspecial() {
        cout << "Weapon: " << weapon << endl;
        cout << "Armor Strength: " << armor << endl;
        cout << "Rage Level: " << rage << endl;
    }

    void attack() {
        double damage = power * (1 + rage / 100);
        cout << name << " attacks with " << weapon
             << " causing damage " << damage << endl;
    }

    void defend() {
        double reduced = armor * 0.5;
        cout << name << " blocks with armor reducing damage by "
             << reduced << endl;
    }
};

class Mage : public Hero {
private:
    string spell;
    double mana;
    double multiplier;

public:
    Mage(string n, int h, double p, int exp,
         string s, double m, double mul)
        : Hero(n, "Mage", h, p, exp){
        	spell = s;
        	mana = m;
        	multiplier = mul;
        	
		}

    void displayspecial() {
        cout << "Spell: " << spell << endl;
        cout << "Mana Points: " << mana << endl;
        cout << "Multiplier: " << multiplier << endl;
    }

    void attack() {
        double damage = power * multiplier + mana * 0.3;
        cout << name << " casts " << spell
             << " causing damage " << damage << endl;
    }

    void defend() {
        double shield = mana * 0.4;
        cout << name << " uses magic shield reducing damage by "
             << shield << endl;
    }
};

class Archer : public Hero {
private:
    string bow;
    int arrows;
    double accuracy;

public:
    Archer(string n, int h, double p, int exp,
           string b, int arr, double acc)
        : Hero(n, "Archer", h, p, exp){
		
          bow = b;
          arrows = arr;
          accuracy = acc;
      }

    void displayspecial() {
        cout << "Bow Type: " << bow << endl;
        cout << "Number of Arrows: " << arrows << endl;
        cout << "Accuracy Rate: " << accuracy << endl;
    }

    void attack() {
        double damage = power * accuracy + arrows * 0.2;
        cout << name << " shoots arrows causing damage "
             << damage << endl;
    }

    void defend() {
        double dodge = accuracy * 10;
        cout << name << " dodges attack reducing damage by "
             << dodge << endl;
    }
};

int main() {
    Warrior w("Escanor", 120, 50.5, 10, "Axe", 80, 25.0);
    Mage m("Merlin", 90, 60.0, 12, "Fireball", 100, 1.5);
    Archer a("Meliodas", 100, 45.0, 8, "Crossbow", 50, 0.85);

    w.show();

    cout << "\nWarrior Info\n";
    w.displaybasicinfo();
    w.displayspecial();

    cout << "\nMage Info\n";
    m.displaybasicinfo();
    m.displayspecial();

    cout << "\nArcher Info\n";
    a.displaybasicinfo();
    a.displayspecial();

    cout << "\nBattle Simulation\n";

    w.attack();
    w.defend();

    m.attack();
    m.defend();

    a.attack();
    a.defend();

    return 0;
}