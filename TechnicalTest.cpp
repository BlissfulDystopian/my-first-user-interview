#include <iostream>
#include <vector>


enum Genre { 
    JAZZ, 
    BLUES, 
    ROCK, 
    GRUNGE, 
    METAL, 
    POP, 
    POPPUNK 
};

/*
    I'm gonna tell a lil messed up story

    So when i was at Technical test, 
    Mas flo nanya "Kenapa pake pointer buat vector Instrumen?"

    Me was explaining something awful krn aku gugup banget
    padahal jawabannya se simpel "Abstract class gabisa di instansiasi".

    Sorry Mas Flo, Mas Edi, Mba Maya, This was my maiden voyage doing user interview :(
*/

// Abstract
class Instrumen {
protected :    
    int _id;
    std::string _name;
public :
    Instrumen() { }

    Instrumen(int id, std::string name) : _id(id), _name(name) { }

    std::string GetName() const { return _name; }

    int GetID() const { return _id; }

    virtual void Play() = 0; // pure virtual function 
    
    virtual ~Instrumen() { }
};

class Guitar : public Instrumen {
public : 
    Guitar() : Instrumen() { }
    
    Guitar(int id) : Instrumen(id, "Guitar") { }

    void Play() override { std::cout << "Di petik!"; }

    ~Guitar() { }
};

class Drum : public Instrumen {
public : 
    Drum() : Instrumen() { }
    
    Drum(int id) : Instrumen(id, "Drum") { }

    void Play() override { std::cout << "Di pukul!"; }

    ~Drum() { }
};

class Lagu {
    int _id;
    std::string _judul; 
    std::string _deskripsi;
    char _nadaDasar;
    unsigned _tempo;
    Genre _genre;

public :
    std::vector<Instrumen*> instrumen;
    
    // mas flo bilang kalo vectornya diinisialisasi dulu
    Lagu() : _id(0), _judul("-"), _deskripsi("-"), _nadaDasar('C'), _tempo(0), _genre() { 
        instrumen.clear();
    }
    
    Lagu(int id, std::string judul, std::string deskripsi, char nadaDasar, unsigned tempo, Genre genre) :
        _id(id), _judul(judul), _deskripsi(deskripsi), _nadaDasar(nadaDasar), _tempo(tempo), _genre(genre) {
            instrumen.clear();
    }

    void PrintInstrument() const {
        std::cout << "Instrumen yang digunakan : \n";

        for(Instrumen* i : instrumen) {
            std::cout << "- "<<i->GetID() << " "<< i->GetName() << '\n';
        }
    }

    void printInfo() const { 
        std::cout << "id = " << _id << '\n';
        std::cout << "judul = " << _judul << '\n';
        std::cout << "deskripsi = " << _deskripsi << '\n';
        std::cout << "nada dasar = Do/" << _nadaDasar << '\n';
        std::cout << "tempo = " << _tempo << " BPM"<< std::endl; 
        
        // Instrumen yang digunakan
        PrintInstrument();
    }
    ~Lagu() { 
        instrumen.clear();
    }
};

int main() {
    // Instansiasi objek
    Lagu lagu1(1, "Smells Like Teen Spirit", "Energetic Music for cheering up your day", 'C', 144, GRUNGE);
    Lagu lagu2(1, "Sweet Child O' Mine", "What a lovely song", 'E', 92, ROCK);


    lagu1.instrumen.push_back(new Guitar(0));
    lagu2.instrumen.push_back(lagu1.instrumen[0]); 
    
    lagu1.instrumen.push_back(new Drum(1));
    lagu2.instrumen.push_back(lagu1.instrumen[1]);
    

    lagu1.printInfo();
    lagu2.printInfo();
    

    lagu1.instrumen[0]->Play();
    return 0;
}
