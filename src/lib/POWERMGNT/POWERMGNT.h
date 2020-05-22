#pragma once

#include "Arduino.h"
#include "../../src/targets.h"
#include "DAC.h"

#if defined(Regulatory_Domain_AU_915) || defined(Regulatory_Domain_EU_868) || defined(Regulatory_Domain_FCC_915) || defined(Regulatory_Domain_AU_433) || defined(Regulatory_Domain_EU_433)
#include "LoRaRadioLib.h"
#elif Regulatory_Domain_ISM_2400
#include "SX1280RadioLib.h"
#endif

#ifdef TARGET_R9M_TX
#define MaxPower 7
#define DefaultPowerEnum 2
#endif

#ifdef TARGET_100mW_MODULE
#define MaxPower 2
#define DefaultPowerEnum 2
#endif

#ifdef TARGET_1000mW_MODULE
#define MaxPower 4
#define DefaultPowerEnum 2
#endif

typedef enum
{
    PWR_10mW = 0,
    PWR_25mW = 1,
    PWR_50mW = 2,
    PWR_100mW = 3,
    PWR_250mW = 4,
    PWR_500mW = 5,
    PWR_1000mW = 6,
    PWR_2000mW = 7

} PowerLevels_e;

// typedef enum
// {
//     PWR_10mW = 0,
//     PWR_25mW = 1,
//     PWR_50mW = 2,

// } SX127x_PA_Boost_PowerLevels_e;

class POWERMGNT
{

private:
    static PowerLevels_e CurrentPower;

public:
    static void setPower(PowerLevels_e Power);
    static PowerLevels_e incPower();
    static PowerLevels_e decPower();
    static PowerLevels_e currPower();
    static void defaultPower();
};