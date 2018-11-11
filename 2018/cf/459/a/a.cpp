#include <iostream>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    // pref_is_good[i][j] -> balance is non negative from i to j inclusive
    vector<vector<bool>> pref_is_good(s.size(), vector<bool>(s.size(), false));

    for (int i = 0; i < s.size(); ++i) {
        int balance = 0;
        int min_balance = 0;
        for (int j = i; j < s.size(); ++j) {
            balance += s[j] == ')' ? -1 : 1;
            min_balance = min(balance, min_balance);
            if (min_balance >= 0) {
                pref_is_good[i][j] = true;
            }
        }
    }
    
    /*
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < s.size(); ++j) {
            cerr << pref_is_good[i][j];
        }
        cerr << endl;
    }
    cerr << endl;
    */
    
    vector<vector<bool>> suff_is_good(s.size(), vector<bool>(s.size(), false));
    for (int i = s.size() - 1; i >= 0; --i) {
        int balance = 0;
        int min_balance = 0;
        for (int j = i; j >= 0; --j) {
            balance += s[j] == '(' ? -1 : 1;
            min_balance = min(balance, min_balance);
            if (min_balance >= 0) {
                suff_is_good[j][i] = true;
            }
        }
    }

    /*
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < s.size(); ++j) {
            cerr << suff_is_good[i][j];
        }
        cerr << endl;
    }
    cerr << endl;
    */

    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        int n_quest = 0;
        int balance = 0;
        vector<int> quest_pos(s.size() + 1, -1);
        for (int j = i; j < s.size(); ++j) {
            if (s[j] == '(')
                ++balance;
            else if (s[j] == ')')
                --balance;
            else if (s[j] == '?') {
                ++n_quest;
                quest_pos[n_quest] = j;
                quest_pos[n_quest - 1] = j - 1;
            }

            int len = j - i + 1;
            
            /*
            cerr << i << " " << j << endl;
            cerr << "balance " << balance << endl;
            cerr << "n_quest " << n_quest << endl;
            */

            if ((len % 2 == 0) && (n_quest >= abs(balance))) {
                int n_opens = (n_quest - abs(balance)) / 2 + (balance < 0 ? abs(balance) : 0);
                bool g_pref = (n_opens == 0) || pref_is_good[i][quest_pos[n_opens]];
                bool g_suff = ((n_opens == 0) && (suff_is_good[i][j]))
                                || (quest_pos[n_opens] + 1 > j) 
                                || suff_is_good[quest_pos[n_opens] + 1][j];
                
                /*
                cerr << "n_opens " << n_opens << endl;
                cerr << "pref & suff goodness " << g_pref << " " << g_suff << endl;
                */

                ans += g_pref && g_suff;
            }
            // cerr << endl;
        }
    }

    // cerr << "ans: ";
    cout << ans << endl;
    return 0;
}
