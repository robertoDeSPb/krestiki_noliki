#include <iostream>

char current_element(int x, int y, std::string str) {
    int i = 3*x + y;
    return str[i];
}
int count(std::string str, std::string side) {
    int kCount = 0, nCount = 0, pointCount = 0, invalidCount = 0;
    for (int x = 0; x < 9; x++) {
        if (str[x] == 'X') {
            kCount++;
        } else if (str[x] == 'O') {
            nCount++;
        } else if (str[x] == '.') {
            pointCount++;
        } else invalidCount++;
    }
    if (side == "krestiki") {
        return kCount;
    } else if (side == "noliki") {
        return nCount;
    } else if (side == "point") {
        return pointCount;
    } else if (side == "invalid") {
        return invalidCount;
    }
}

bool petya(std::string str) {
    bool krestiki = false;
    int winCount = 0;
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (x == 0 && y == 0 && current_element(x, y, str) == 'X') {
                if (current_element(x+1, y, str) == 'X' && current_element(x+2, y, str) == 'X') {
                    krestiki = true;
                    winCount++;
                } else if (current_element(x, y+1, str) == 'X' && current_element(x, y+2, str) == 'X') {
                    krestiki = true;
                    winCount++;
                } else if (current_element(x+1, y+1, str) == 'X' && current_element(x+2, y+2, str) == 'X') {
                    krestiki = true;
                    winCount++;
                }
            } else if (x == 0 && y == 1 && current_element(x, y, str) == 'X') {
                if (current_element(x+1, y, str) == 'X' && current_element(x+2, y, str) == 'X') {
                    krestiki = true;
                    winCount++;
                }
            } else if (x == 0 && y == 2 && current_element(x, y, str) == 'X') {
                if (current_element(x+1, y, str) == 'X' && current_element(x+2, y, str) == 'X') {
                    krestiki = true;
                    winCount++;
                } else if (current_element(x+1, y-1, str) == 'X' && current_element(x+2, y-2, str) == 'X') {
                    krestiki = true;
                    winCount++;
                }
            } else if (x == 1 && y == 0 && current_element(x, y, str) == 'X') {
                if (current_element(x, y+1, str) == 'X' && current_element(x, y+2, str) == 'X') {
                    krestiki = true;
                    winCount++;
                }
            } else if (x == 2 && y == 0 && current_element(x, y, str) == 'X') {
                if (current_element(x, y+1, str) == 'X' && current_element(x, y+2, str) == 'X') {
                    krestiki = true;
                    winCount++;
                }
            }
        }
    }
    if (winCount > 1) {
        krestiki = false;
    }
    return krestiki;
}

bool vanya(std::string str) {
    bool noliki = false;
    int winCount = 0;
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            if (x == 0 && y == 0 && current_element(x, y, str) == 'O') {
                if (current_element(x+1, y, str) == 'O' && current_element(x+2, y, str) == 'O') {
                    noliki = true;
                    winCount++;
                } else if (current_element(x, y+1, str) == 'O' && current_element(x, y+2, str) == 'O') {
                    noliki = true;
                    winCount++;
                } else if (current_element(x+1, y+1, str) == 'O' && current_element(x+2, y+2, str) == 'O') {
                    noliki = true;
                    winCount++;
                }
            } else if (x == 0 && y == 1 && current_element(x, y, str) == 'O') {
                if (current_element(x+1, y, str) == 'O' && current_element(x+2, y, str) == 'O') {
                    noliki = true;
                    winCount++;
                }
            } else if (x == 0 && y == 2 && current_element(x, y, str) == 'O') {
                if (current_element(x+1, y, str) == 'O' && current_element(x+2, y, str) == 'O') {
                    noliki = true;
                    winCount++;
                } else if (current_element(x+1, y-1, str) == 'O' && current_element(x+2, y-2, str) == 'O') {
                    noliki = true;
                    winCount++;
                }
            } else if (x == 1 && y == 0 && current_element(x, y, str) == 'O') {
                if (current_element(x, y+1, str) == 'O' && current_element(x, y+2, str) == 'O') {
                    noliki = true;
                    winCount++;
                }
            } else if (x == 2 && y == 0 && current_element(x, y, str) == 'O') {
                if (current_element(x, y+1, str) == 'O' && current_element(x, y+2, str) == 'O') {
                    noliki = true;
                    winCount++;
                }
            }
        }
    }
    if (winCount > 1) {
        noliki = false;
    }
    return noliki;
}

int winner (std::string str) {
    if (petya(str) == 1) {
        if (vanya(str) == 0 && count(str, "krestiki") - count(str, "noliki") == 1 &&
                count(str, "invalid") == 0) {
            return 1;
        }else return 0;
    } else if (vanya(str) == 1) {
        if (petya(str) == 0 && count(str, "krestiki") - count(str, "noliki") == 0 &&
            count(str, "invalid") == 0) {
            return 2;
        } else return 0;
    } else if (petya(str) == 0 && vanya(str) == 0) {
        if (count(str, "krestiki") + count(str, "noliki") + count(str, "point") == 9 &&
               ((count(str, "krestiki") - count(str, "noliki") == 0) ||
                (count(str, "krestiki") - count(str, "noliki") == 1))) {
            return 4;
        } else return 0;
        }
}

int main() {
    std::string str;
    int n;
    std::cout << "Input field: \n";
    std::cin >> str;

    if (winner(str) == 1) {
        std::cout << "\nPetya Won\n";
    } else if (winner(str) == 2) {
        std::cout << "\nVanya Won\n";
    } else if (winner(str) == 0) {
        std::cout << "\nIncorrect\n";
    } else if (winner(str) == 4) {
        std::cout << "\nNobody\n";
    }
}