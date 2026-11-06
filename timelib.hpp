#pragma once
#include <cstdint>
#include <chrono>
#include <thread>

#define YEAROFFSET   0b1111111111111100000000000000000000000000000000000000000000000000
#define MONTHOFFSET  0b0000000000000011110000000000000000000000000000000000000000000000
#define DAYOFFSET    0b0000000000000000001111100000000000000000000000000000000000000000
#define HOUROFFSET   0b0000000000000000000000011111000000000000000000000000000000000000
#define MINUTEOFFSET 0b0000000000000000000000000000111111000000000000000000000000000000
#define SECONDOFFSET 0b0000000000000000000000000000000000111111000000000000000000000000
#define NS100OFfSET  0b0000000000000000000000000000000000000000111111111111111111111111

#define YEARSHIFT   50
#define MONTHSHIFT  46
#define DAYSHIFT    41
#define HOURSHIFT   36
#define MINUTESHIFT 30
#define SECONDSHIFT 24
#define NS100SHIFT  0

namespace tl {
    class Time {
        std::uint64_t _time;
        public:
        Time(const std::uint64_t &time) : _time(time){}

        void setTime(const std::uint64_t &time) {
            _time = time;
        }

        std::uint64_t getTime() {
            return _time;
        }

        void setYear(const unsigned short &year) {
            _time &= ~(YEAROFFSET);
            _time = _time | ((std::uint64_t)year << YEARSHIFT);
        }

        std::uint16_t getYear() {
            return (_time & YEAROFFSET) >> YEARSHIFT;
        }

        void setMonth(const std::uint8_t &month) {
            _time &= ~(MONTHOFFSET);
            _time = _time | ((std::uint64_t)month << MONTHSHIFT);
        }

        std::uint8_t getMonth() {
            return (_time & MONTHOFFSET) >> MONTHSHIFT;
        }

        void setDay(const std::uint8_t &day) {
            _time &= ~(DAYOFFSET);
            _time = _time | ((std::uint64_t)day << DAYSHIFT);
        }

        std::uint8_t getDay() {
            return (_time & DAYOFFSET) >> DAYSHIFT;
        }

        void setHour(const std::uint8_t &hour) {
            _time &= ~(HOUROFFSET);
            _time = _time | ((std::uint64_t)hour << HOURSHIFT);
        }

        uint8_t getHour() {
            return (_time & HOUROFFSET) >> HOURSHIFT;
        }

        void setMinute(const std::uint8_t &min) {
            _time &= ~(MINUTEOFFSET);
            _time = _time | ((std::uint64_t)min << MINUTESHIFT);
        }

        std::uint8_t getMinute() {
            return (_time & MINUTEOFFSET) >> MINUTESHIFT;
        }

        void setSecond(const std::uint8_t &sec) {
            _time &= ~(SECONDOFFSET);
            _time = _time | ((std::uint64_t)sec << SECONDSHIFT);
        }

        std::uint8_t getSecond() {
            return (_time & SECONDOFFSET) >> SECONDSHIFT;
        }

        void set100ns(const std::uint32_t &ns100) {
            _time &= ~(NS100OFfSET);
            _time = _time | ((std::uint64_t)ns100);
        }

        std::uint32_t get100ns() {
            return (_time & NS100OFfSET);
        }

    };
    void sleep(int time, bool use_a_lot_of_cpu_power)
    {
        if (use_a_lot_of_cpu_power == true)
        {
        auto now = std::chrono::system_clock::now();
        auto seconds = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count();
        while( seconds + time != std::chrono::duration_cast<std::chrono::seconds>(std::chrono::system_clock::now().time_since_epoch()).count()) {}
    } else {
        std::this_thread::sleep_for(std::chrono::seconds(time));
        }
    }
}
