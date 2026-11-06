#include <iostream>
#include "timelib.hpp"

int main() {
    tl::Time t(0);
    t.setYear(2026);
    t.setMonth(11);
    t.setDay(6);
    t.setHour(17);
    t.setMinute(48);
    t.setSecond(43);
    t.set100ns(9999999);
    std::printf("Year: %d\nMonth: %d\nDay: %d\nHour: %d\nMinute: %d\nSecond: %d\n100ns: %d\n",
        t.getYear(), t.getMonth(), t.getDay(), t.getHour(), t.getMinute(), t.getSecond(), t.get100ns());
    return 0;
}