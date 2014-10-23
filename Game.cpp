#include <string>
using namespace std;

enum Genre{
    Action,
    RolePlaying,
    Strategy,
    Sports,
    NO_GENRE
};

enum Console{
    PS3,
    PS2,
    PSX,
    PSP,
    Wonderswan,
    SwanCrystal,
    Wii,
    NGC,
    NDS,
    GBA,
    GBA_SP,
    GBM,
    iQue,
    Xbox360,
    Xbox,
    GP32,
    PanasonicQ,
    N_Gage,
    Gizmondo,
    GP2X,
    Zeebo,
    NO_CONSOLE
};
class Game{
private:
    string name;
    Genre g;
    Console c;
public:
    Game(){
        c = NO_CONSOLE;
        g = NO_GENRE;
        name = "NO_NAME";
    }

    void setName(string s);
    void setGenre(string genreString);
    float avgScore(float s1, float s2, float s3);
    void setConsole(string s);
    //enum Genre getGenre();
    /*float avgScore(float s1, float s2, float s3){
        if (g == Action)
            return (((s1/10)*0.2)+((s2/10)*0.6)+((s3/10)*0.2));
        else if (g == RolePlaying)
            return (((s1/10)*0.2)+((s2/10)*0.4)+((s3/10)*0.4));
        else if (g == Strategy)
            return (((s1/10)*0.2)+((s2/10)*0.8));
        else if (g == Sport)
            return (((s1/10)*0.5)+((s2/10)*0.5));
        else
            return 0.0;
    };
    */
};

float Game::avgScore(float s1, float s2, float s3){
    return ((s1*s2*s3)/3.0);
}

void Game::setName(string s){
    name = s;
}

void Game::setGenre(string genreString){
    if (genreString.compare("Action") == 0)
        g = Action;
    else if (genreString.compare("Strategy") == 0)
        g = Strategy;
    else if (genreString.compare("Role Playing") == 0)
        g = RolePlaying;
    else if (genreString.compare("Sports") == 0)
        g = Sports;
    else
        g = NO_GENRE;
}

void Game::setConsole(string str){
    if (str.compare("Sony PlayStation 2 (PS2)") == 0)
        c = PS2;
}
