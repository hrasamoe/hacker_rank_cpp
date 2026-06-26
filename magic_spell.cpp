#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {
    if (Fireball* fb  = dynamic_cast<Fireball*>(spell))
        fb->revealFirepower();
    else if (Frostbite* fb  = dynamic_cast<Frostbite*>(spell))
        fb->revealFrostpower();
    else if (Thunderstorm* fb  = dynamic_cast<Thunderstorm*>(spell))
        fb->revealThunderpower();
    else if (Waterbolt* fb  = dynamic_cast<Waterbolt*>(spell))
        fb->revealWaterpower();
    else
    {
        string s1 = spell->revealScrollName();
        string s2 = SpellJournal::read();
        int n = s1.length();
        int m = s2.length();
        vector<vector <int>> matrice(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++ )
        {
            for (int j = 1; j <= m; j++)
            {
                if (s1[i - 1] == s2[j -1])
                    matrice[i][j] = 1 + matrice[i - 1][j - 1];
                else
                    matrice[i][j] = max(matrice[i][j - 1], matrice[i - 1][j]);
            }
        }
        cout << matrice[n][m] << endl;
    }
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}