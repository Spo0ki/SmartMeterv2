#include "alarm.h"
using namespace std;




void alarm(home_appliance P_property, vector <signal> waveform, vector <double> Period)
{
    vector<double> timev;
    vector<double> timei_;
    vector<double> timeF;
    vector<double> timef_;


    for (int i = 0; i < waveform.size(); i++) {

        if (waveform.at(i).voltage > P_property.getProperty().max_cap_volt)
        {
            timev.push_back(waveform.at(i).time);
        }
        if (waveform.at(i).current > P_property.getProperty().max_cap_current)
        {
            timei_.push_back(waveform.at(i).time);

        }
        if (1 / Period.at(i) > 51)
        {
            timeF.push_back(waveform.at(i).time);
           

        }

        if (1 / Period.at(i) < 51)
        {
            timef_.push_back(waveform.at(i).time);
        }



    }
   double V_time =  timev.at(timev.size() - 1)- timev.at(0);
   double I_time = timei_.at(timei_.size() - 1) - timei_.at(0);
   double F_time = timeF.at(timeF.size() - 1) - timeF.at(0);
   double ftime_under =  timef_.at(timef_.size() - 1)- timef_.at(0) ;
    if (V_time)
    {
        cout << "warning volt was too high for :" << V_time << endl; 
    }
    if (I_time)
    {
        cout << "Warning Current was too high for:" << I_time << endl; 

    }
    if (F_time)
    {
        cout << "Warning Frequency was too high for:" << F_time << endl; 
    }
    if (ftime_under)
    {
        cout << "Warning Frequency was too low for :" << ftime_under << endl; 
    }




}