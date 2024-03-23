#include <cassert>
#include <iostream>
#include <string>
using namespace std;

#define ATTEMPTS 6

enum validity { NOMATCH, MATCH, MISPLACED };

void convert_to_validity(string vin, validity *v) {
    assert(vin.size() == 5);
    for (int i = 0; i < 5; i++) {
        switch (vin[i]) {
        case '0':
            v[i] = NOMATCH;
            break;
        case '1':
            v[i] = MATCH;
            break;
        case '2':
            v[i] = MISPLACED;
            break;
        default:
            cout << "[ERR] INVALID";
            exit(1);
        }
    }
}

class Guess {
    string guess;
    validity verdict[5];
};

class Wordl {
  public:
    Wordl(){};
    Wordl(string ans) {
        answer = ans;
        mode = 1; // Test mode
    }

    int solve() { return 0; }
    string guess() {
        // conside the history while guessing
        return "bello";
    }
    void update_history(string g, validity[5] v) {return;} 

  private:
    string answer;
    Guess guesses[ATTEMPTS];
    int at_cnt = 1;
    int mode = 0; // Interactive mode
};

void info() {
    cout << "\n----[INFO]\n";
    cout << "Enter the result of the previous guess\nin the format of a "
            "string "
            "where\n 0 = NOMATCH\n 1 = MATCH\n 2 = MISPLACED\n";
    cout << "----\n\n";
    cout << "res > ";
}

int main(int argc, char **argv) {
    if (argc < 2) {
        Wordl w;
        int attempt = 1;
        string g, vin;
        validity v[] = {NOMATCH, NOMATCH, NOMATCH, NOMATCH, NOMATCH};
        while (attempt < ATTEMPTS) {
            g = w.guess();
            cout << "guess " << attempt << " > " << g << endl;
            info();
            cin >> vin;
            convert_to_validity(vin, v);
            update_guesses(g, v);
        }
    } else {
        clog << "[INFO] Running for | " << argv[1] << " |\n";
        Wordl w(argv[1]);
        if (w.solve())
            clog << "[INFO] SUCCESS\n";
        else
            clog << "[INFO] FAIL\n";
    }

    return 0;
}
