#include <iostream>

std::string encode(std::string str, int shift) {
    for (int i = 0; i < str.length(); i++) {
        if (i != 0 && i % shift == 0 && str[i] != ' '){
            str[i] = str[i] + shift;
            std::cout  << str[i] << " -> " << char (str[i] + shift) << std::endl;
        }
    }

    return str;
}

std::string decode(std::string str, int shift) {
    for (int i = 0; i < str.length(); i++) {
        if (i != 0 && i % shift == 0 && str[i] != ' '){
            str[i] = str[i] - shift;
        }
    }

    return str;
}

int main() {
    std::string str = "I am a student";
    int shift = 2;
    std::cout << "Original String: " << str << std::endl;

    std::string encoded = encode(str, shift);
    std::cout << "Encoded String: " << encoded << std::endl;

    std::string decoded = decode(encoded, shift);
    std::cout << "Decoded String: " << decoded << std::endl;

    return 0;
}
