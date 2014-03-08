/*
 * Compile Information
 * Please compile this code with GNU g++ 4.6 or later versions.
 * Compile instruction: g++ -o vigenere vigenere.cpp -std=c++11
 * Run: ./vigenere
 */

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

inline int mod(int x, int m) {
    return (x % m + m) % m;
}

string c = "ZPQHKUQHZMDXYIXBUAFDBMDXNWBTZPMIEWGWGDQWGLRJTTQPXVUCMIXAZPQCAUNTXBTTUZKRUVOTVBEXTBTXYKAJXAQVUWPAAKWLOBTPRTAUEWGGLQZPRA";
string k = "AAAA";

void decryptor(int lengthOfKey) {
    cout << k << endl;
    for (int i = 0; i < c.length(); ++i) {
        printf("%c", mod((int) c[i] - k[i % lengthOfKey], 26) + 'A');
    }
    printf("\n");
}

int main() {
    /* Step 1: Kasiski's method */
    map<string, vector<int> > dic;
    for (int i = 0; i < c.length(); ++i) {
        if (i + 3 < c.length()) {
            string s = c.substr(i, 3);
            dic[s].push_back(i);
        }
    }
    for (auto it = dic.begin(); it != dic.end(); ++it) {
        if ((*it).second.size() < 2) continue;
        cout << (*it).first << " ";
        for (int i = 0; i < (*it).second.size(); ++i) cout << (*it).second[i] << " ";
        cout << endl;
    }
    /* We get 
     * Text Block | Starting Positions | Differences
     * EWG        | 32 108             | 76
     * MDX        | 9  21              | 12
     * ZPQ        | 0  56              | 56
     * So the length of the key is gcd(76, 12, 56) = 4
     */
    int lengthOfKey = __gcd(76, __gcd(12, 56));
    printf("\nlength of key = %d\n\n", lengthOfKey);

    /* Step 2: Verify the length of the key */
    auto f = new int[lengthOfKey][26]();
    auto n = new int[lengthOfKey]();
    for (int i = 0; i < lengthOfKey; ++i) {
        for (int j = i; j < c.length(); j += lengthOfKey) {
            f[i][c[j] - 'A']++;
            n[i]++;
        }
    }
    for (int i = 0; i < 26; ++i) printf("%c ", i + 'A');
    printf("\n");
    for (int i = 0; i < lengthOfKey; ++i) {
        for (int j = 0; j < 26; ++j) printf("%d ", f[i][j]);
        printf("\n");
    }
    /*
     * Frequency table
     * A B C D E F G H I J K L M N O P Q R S T U V W X Y Z 
     * 2 1 0 0 2 0 2 0 0 0 1 1 1 1 1 0 0 2 0 2 4 1 0 3 2 4 
     * 3 4 0 1 0 0 0 0 2 0 2 1 2 0 0 3 1 0 0 2 2 2 4 0 0 1 
     * 2 1 0 2 1 1 2 0 0 0 1 0 1 1 1 1 6 1 0 3 1 0 1 2 0 1 
     * 2 1 2 1 0 0 1 2 1 2 0 1 0 0 0 3 0 1 0 4 1 1 2 4 0 0 
     */
    
    for (int i = 0; i < lengthOfKey; ++i) {
        double sum = 0.0;
        for (int j = 0; j < 26; ++j) sum += f[i][j] * (f[i][j] - 1);
        printf("%.15f\n", sum / n[i] / (n[i] - 1));
    }
    /*
     * The results are
     * 0.048275862068966
     * 0.055172413793103
     * 0.054187192118227
     * 0.049261083743842
     * Hmmm, not that bad. So let's try 4.
     */

    /* Step 3: decrypt, notice that E = 4 and T = 19 */
    /* Combine the highest characters in frequency table,
     * we have 
     * "UBQT" "UBQZ" "UWQT" "UWQZ"
     * "ZBQT" "ZBQZ" "ZWQT" "ZWQZ"
     */
    string ckey[] = {"UBQT", "UBQZ", "UWQT", "UWQZ", "ZBQT", "ZBQZ", "ZWQT", "ZWQZ"};
    for (int i = 0; i < 8; ++i) {
        for (int mask = 0; mask < (1 << lengthOfKey); ++mask) {
            for (int j = 0; j < lengthOfKey; ++j) {
                k[j] = mod(ckey[i][j] - 'A' - ((mask & (1 << j)) ? 4 : 19), 26) + 'A';
            }
            decryptor(lengthOfKey);
        }
    }
    /* Fortunately, we can find that the result is readable with key "GIMP". */
    
    /* Hmm, I think Professor Graham love the great
     * software GIMP (http://www.gimp.org/) from GNU too.
     */
    
    /*
     * So the message is:
     * the semester is almost over 
     * i hope that you have had fun learning all the number theory concepts in this course 
     * good luck with all of your finals
     */
    return 0;
}