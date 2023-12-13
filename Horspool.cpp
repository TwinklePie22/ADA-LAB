/*
? This program implements the Horspool's algorithm for string matching.
* It is used to find the occurrence of a pattern in a DNA sequence.
* The DNA sequence and the pattern are represented as strings of characters.
*/

#include <iostream>
#include <unordered_map>
#include <string>

std::unordered_map<char, int> preprocess_pattern(const std::string& pattern) {
    int m = pattern.length();
    std::unordered_map<char, int> bad_char_shift;

    for (int i = 0; i < m - 1; ++i) {
        bad_char_shift[pattern[i]] = m - 1 - i;
    }

    return bad_char_shift;
}

int search_pattern_dna(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();
    std::unordered_map<char, int> bad_char_shift = preprocess_pattern(pattern);
    int i = m - 1;

    while (i < n) {
        int k = 0;
        while (k < m && pattern[m - 1 - k] == text[i - k]) {
            ++k;
        }

        if (k == m) {
            return i - m + 1;  // Pattern found at position i - m + 1
        }

        // Shift based on the bad character in the text
        char bad_char = text[i];
        if (bad_char_shift.find(bad_char) != bad_char_shift.end()) {
            i += bad_char_shift[bad_char];
        } else {
            i += m;  // Shift the pattern completely to the right
        }
    }

    return -1;  // Pattern not found in the text
}

int main() {
    std::string dna_sequence = "ATCGATCGTACGATCG";
    std::string pattern_to_find = "TACG";

    int result = search_pattern_dna(dna_sequence, pattern_to_find);
    if (result != -1) {
        std::cout << "Pattern found at position " << result << std::endl;
    } else {
        std::cout << "Pattern not found in the DNA sequence" << std::endl;
    }

    return 0;
}
