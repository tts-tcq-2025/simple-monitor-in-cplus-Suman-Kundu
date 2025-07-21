#include <assert.h>
#include <iostream>
using namespace std;

bool TemperatureIsOk(float temperature) {
  if(temperature < 0 || temperature > 45) {
     cout << "Temperature out of range!\n";
     return false;
  }
  return true;
}

bool SocIsOk(float soc) {
  if(soc < 20 || soc > 80) {
     cout << "State of Charge out of range!\n";
     return false;
  }
  return true;
}

bool ChargeRateIsOk(float chargeRate) {
   if(chargeRate < 0.0f || chargeRate > 0.8f) {
       cout << "Charge Rate out of range!\n";
       return false;
   }
   return true;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
  bool temperature_status = TemperatureIsOk(temperature);
  bool soc_status = SocIsOk(soc);
  bool chargeRate_status = ChargeRateIsOk(chargeRate);

  return temperature_status && soc_status && chargeRate_status;
}

int main() {
    // Good case
    assert(batteryIsOk(25, 70, 0.7) == true);

    Failed cases
    assert(batteryIsOk(-1, 50, 0.7) == false);  // Temp low
    assert(batteryIsOk(48, 70, 0.6) == false);  // Temp high
    assert(batteryIsOk(32, 18, 0.5) == false);  // SOC low
    assert(batteryIsOk(33, 81, 0.4) == false);  // SOC high
    assert(batteryIsOk(40, 65, 0.9) == false);  // Charge rate high
    assert(batteryIsOk(-3, 15, 1.0) == false);  // All parameters out of range

    // Boundary check
    assert(batteryIsOk(0, 20, 0.0) == true);
    assert(batteryIsOk(45, 80, 0.8) == true);

    // Edge + one parameter fail scenario
    assert(batteryIsOk(46, 80, 0.8) == false);   // Temp high
    assert(batteryIsOk(0, 80, 0.9) == false);    // Charge rate high
    assert(batteryIsOk(45, 19, 0.8) == false);   // Soc high
}
