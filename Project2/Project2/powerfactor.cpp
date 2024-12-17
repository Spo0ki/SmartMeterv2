
#pragma once
#include "powerfactor.h"
#include <cmath>
#include <vector>

double powerfactor(std::vector<signal>& waveform1)
{
    double vrms = 0.0;
    double irms = 0.0;
    double tsample = waveform1.at(1).time - waveform1.at(0).time;
    double powerfactor;

    for (int i = 0; i < waveform1.size(); i++)
    {
        vrms += pow(waveform1.at(i).voltage, 2)/tsample;
        irms += pow(waveform1.at(i).current, 2)/tsample;
    }
    vrms = sqrt(vrms);
    irms = sqrt(irms);
    double SumPower = 0;
    int size = waveform1.size();
    for (int i = 0; i < size; i++)
    {
        SumPower += waveform1.at(i).current * waveform1.at(i).voltage;
    }

    powerfactor =  (vrms * irms)/SumPower;
    return powerfactor;
}
