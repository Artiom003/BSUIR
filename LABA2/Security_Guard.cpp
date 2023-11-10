#include "Security_Guard.h"

namespace Airlane {
    bool Security_Guard::check_passenger(Passenger* passenger) {
        srand(time(NULL));
        if (rand() % 3) {
            cout << "Passenger: " << passenger->get_info() << " with the BOMB!!!" << endl;
            return true;
        }
        else {
            cout << "Passenger: " << passenger->get_info() << " is clear" << endl;
            return false;
        }
    }

    string generateUUID1() {
        const string CHARS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
        string uuid = string(36, ' ');
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
    Security_Guard::Security_Guard(string info) {
        id = generateUUID1();
        this->info = info;
    }
    void Security_Guard::set_info(string info) {
        this->info = info;
    }
    string Security_Guard::get_info() {
        return info;
    }
    string Security_Guard::get_id() {
        return id;
    }
}