#include "common.h"

USESTD 

static int HourBits[5] = { 1, 2, 4, 8 };
static int MinuteBits[6] = { 1, 2, 4, 8, 16, 32 };

class Solution {
    public:
        vector<string> readBinaryWatch(int num) {
            int hours[4] = { 0, 0, 0, 0 };
            int minutes[6] = { 0, 0, 0, 0, 0, 0 };

            vector<string> times;
    
            if (num == 0)
            {
                times.push_back("0:00");
            }
            else
            {
                addMinute(times, minutes, 0, 0, num);
                addHour(times, hours, minutes, 0, 0, num);
            }
    
            return times;
        }
    
    private:
        void addHour(vector<string>& times, int hours[], int minutes[], int hour, int minute, int num) {
            if (num == 0) {
                return;
            }
    
            for (int i = 0; i < 4; i++) {
                if (hours[i] == 1) {
                    return;
                }
    
                int newHour = hour + HourBits[i];
                if (newHour > 11) {
                    return;
                }
    
                hours[i] = 1;
                addMinute(times, minutes, newHour, minute, num - 1);
                addHour(times, hours, minutes, newHour, minute, num - 1);
                hours[i] = 0;
            }
        }
    
        void addMinute(vector<string>& times, int minutes[], int hour, int minute, int num) {
            if (num == 0) {
                string time(hour < 10 ? 4 : 5, '0');
                writeTimeToString(time, hour, minute);
                times.push_back(time);
                return;
            }
    
            for (int i = 0; i < 6; i++) {
                if (minutes[i] == 1) {
                    return;
                }
    
                int newMinute = minute + MinuteBits[i];
                if (newMinute > 59) {
                    return;
                }
    
                minutes[i] = 1;
                addMinute(times, minutes, hour, newMinute, num - 1);
                minutes[i] = 0;
            }
        }
    
        void writeTimeToString(string& time, int hour, int minute) {
            int offset = 0;
            if (hour < 10) {
                time[offset++] = '0' + hour;
            }
            else {
                time[offset++] = '1';
                time[offset++] = '0' + hour % 10;
            }
    
            time[offset++] = ':';
            if (minute < 10) {
                time[offset++] = '0';
                time[offset++] = '0' + minute;
            }
            else {
                int ten = minute / 10;
                time[offset++] = '0' + ten;
                time[offset++] = '0' + (minute - ten * 10);
            }
        }
    };