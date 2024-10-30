#include <iostream>
#include <vector>
#include <string>

void generate_binary_strings(std::vector<std::string>& otv, std::string cr, size_t l) {
    if (l == 0) {
        otv.push_back(cr);
        return;
    }
    generate_binary_strings(otv, cr + "0", l - 1);
    generate_binary_strings(otv, cr + "1", l - 1);
}

void print_binary(size_t bits_count) {
    std::vector<std::string> binary_strings;
    generate_binary_strings(binary_strings, "", bits_count);
    for (const std::string& s : binary_strings) {
        std::cout << s << std::endl;
    }
}

int main() {
    size_t bits_count;
    std::cin >> bits_count;
    print_binary(bits_count);
    return 0;
}