#include "Pilot.h"

namespace Airlane {
    string Pilot::get_info() {
        return info;
    }
    void Pilot::set_info(string info) {
        this->info = info;
    };

    string generateUUID2() {
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
    Pilot::Pilot(string info) {
        id = generateUUID2();
        this->info = info;
    };
}