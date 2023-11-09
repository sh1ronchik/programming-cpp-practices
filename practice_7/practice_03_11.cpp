#define task_7_1

#ifdef task_7_1


#include <iostream>
#include <string>

int main() {
    std::cout << "Enter the string: ";

    std::string h;
    std::cin >> h;
    
    size_t flag = 1;
    std::string::iterator i = h.begin();
    for(std::string::reverse_iterator it = h.rbegin(); it != h.rend(); it++) {
        if ((it.base() - 1) == i) break;

        if (*it != *i) {
            flag = 0;
            break;
        }
        i++;
    }
    if (flag) {
        std::cout << "Your string is a palindrome.\n";
    }
    else {
        std::cout << "Your string is not a palindrome.\n";
    }

    std::cout << std::endl;
    return 0;
}


#endif

#ifdef task_7_2

#include <iostream>
#include <string>
#include <vector>

int main() {
    std::cout << "Enter the string: ";

    std::string h;
    getline(std::cin, h);

    std::vector<std::string> p;
    std::string tmp;
    for(std::string::iterator it = h.begin(); it != h.end(); it++) {
        if (*it == ' ') {
            if (tmp != "") {
                p.push_back(tmp);
            }
            tmp = "";
            continue;
        }

        tmp += *it;
    }
    p.push_back(tmp);

    for(std::vector<std::string>::iterator it1 = p.begin(); it1 != p.end(); it1++) {
        for(std::vector<std::string>::iterator it2 = it1 + 1; it2 != p.end(); it2++) {
            if ((*it1).size() > (*it2).size()) {
                tmp = (*it1);
                (*it1) = (*it2);
                (*it2) = tmp;
            }
        }
    }

    for(std::vector<std::string>::iterator it = p.begin(); it != p.end(); it++) {
        std::cout << *it << " ";
    }

    std::cout << std::endl;
    return 0;
}


#endif