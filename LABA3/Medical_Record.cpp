#include "Medical_Record.h"
namespace Hospital_Management_System {
    std::string generateUUID2() {
        const std::string CHARS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        std::string uuid = std::string(36, ' ');
        int rnd = 0;
        int r = 0;
        uuid[8] = '-';
        uuid[13] = '-';
        uuid[18] = '-';
        uuid[23] = '-';
        uuid[14] = '4';
        for (int i = 0; i < 36; i++) {
            if (i != 8 && i != 13 && i != 18 && i != 14 && i != 23) {
                if (rnd <= 0x02) {
                    rnd = 0x2000000 + (std::rand() * 0x1000000) | 0;
                }
                rnd >>= 4;
                uuid[i] = CHARS[(i == 19) ? ((rnd & 0xf) & 0x3) | 0x8 : rnd & 0xf];
            }
        }
        return uuid;
    }

    Medical_Record::Medical_Record() {
        id = generateUUID2();
    }
    void Medical_Record::add_treatment(string treatment) {
        this->treatment = treatment;
        list_of_treatments.push_back(treatment);
    }
    void Medical_Record::display_info() {
        for (int i = 0; i < list_of_treatments.size(); i++) {
            cout << i + 1 << "." << list_of_treatments[i] << endl;
        }
    }
}