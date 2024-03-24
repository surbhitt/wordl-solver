#include <iostream>
#include <string>
using namespace std;
// go through every word in a list of ans
// solve for every word

#define WORDLEN 5

enum validity {
    NOMATCH,
    MATCH,
    MISPLACED,
};

class Wordl {
  public:
    Wordl(string ans) : answer(ans) { cout << "instantiated with" << ans << endl; };
    int solve() {
        /// stores err_code in errno
        /// return attempts to solve
        int attempt = 0;
        for (; attempt < tot_attempts; attempt++) {
            cout << "attempt" << attempt << endl;
            guesses[attempt].guess = guess();
            check(guesses[attempt].guess, answer, guesses[attempt].pat);
            int match = 0;
             
            for (auto m: guesses[attempt].pat) if (m) match++;
            if (match == 5) {
                cout << "\nDOOONEEE\n";
                return attempt;
            }
        }
        return attempt;
    }

  private:
    struct Guess {
        string guess;
        validity pat[WORDLEN];
    };

    const static int tot_attempts = 6;
    string answer;
    Guess guesses[tot_attempts];

    string guess() { return "bello"; }
    void check(string guess, string answer, validity pat[WORDLEN]) {
        cout << "checking for ans = " << answer << " g = " << guess << endl;
        pat[WORDLEN] = {NOMATCH};
        // to keep track of letters in ans that have been matched
        int f[WORDLEN] = {0};
        for (int i = 0; i < WORDLEN; i++) {
            if (guess[i] == answer[i]) {
                pat[i] = MATCH;
                f[i]++;
            }
        }
        for (int i = 0; i < WORDLEN; i++) {
            if (pat[i] == MATCH)
                continue;
            for (int j = 0; j < WORDLEN; j++) {
                if (guess[i] == answer[j] && !f[j]) {
                    pat[i] = MISPLACED;
                    f[j]++;
                }
            }
        }
    }
};

int main() {

    Wordl w("bello");
    w.solve();
    return 0;
}
