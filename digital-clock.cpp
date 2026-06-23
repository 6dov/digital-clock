#include <iostream>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif


// #include <thread>
// #include <chrono>
// #define NOMINMAX


using namespace std;

class Clock{
    private:

        // variables
    int sec = 0;
    int minute = 0;
    int hour = 0;
        // End variables

        vector<int> alarms;

    public:

    void setTime(){

        cout << "Hours : ";
        cin >> hour;

        cout << "Min : ";
        cin >> minute;
    }

    void addAlarm(int alarmMinute) {
        alarms.push_back(alarmMinute);
        cout << "Alarm set for minute: " << alarmMinute << "\n";
    }

    void start(){
        
        while(true){

            #ifdef _WIN32
                system("cls");
            #else
                system("clear");
            #endif

            if(sec >= 60){
                minute++;
                sec = 0;
            }

            if(minute >= 60){
                ++hour;
                minute = 0;
            }

            if(hour >= 24){
                hour = 0;
            }

            cout << hour << ":" << minute << ":" << sec << endl;

            for (int i = 0; i < alarms.size(); i++) {
                if (minute == alarms[i] && sec == 0) {
                    cout << ">>> ALARM RINGING! <<<\n";
                }
            }

            sec++;

            #ifdef _WIN32
                Sleep(1000);
            #else
                usleep(1000000);
            #endif
            
        }
    }

};

int main(){
    Clock myClock;

        myClock.addAlarm(30);
        myClock.setTime();
        myClock.start();
        // myClock.print();


    return 0;
}