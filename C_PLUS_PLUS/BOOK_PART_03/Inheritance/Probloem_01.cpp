#include <iostream>

using namespace std;

class Car
{
private:
	int gasolineGauge;
public:
	Car(int gas) : gasolineGauge(gas)
	{ }
	int GetGasGauge()
	{
		return gasolineGauge;
	}
};

class HybridCar : public Car		// 하이브리드 자동차
{
private:
	int electricGauge;
public:
	HybridCar(int gas, int elec) : Car(gas), electricGauge(elec)
	{ }
	int GetElecGauge()
	{
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar // 하이브리드 워터카
{
private:
	int waterGauge;
public:
	HybridWaterCar(int gas, int elec, int water) : HybridCar(gas, elec), waterGauge(water)
	{ }
	void ShowCurrentGauge()
	{
		cout << "잔여 가솔린 : " << GetGasGauge() << endl;
		cout << "잔여 전기량: " << GetElecGauge() << endl;
		cout << "잔여 워터량: " << waterGauge << endl;
	}

};

int No1_1021()
{
	HybridWaterCar HwCar(10, 20, 30);
	HwCar.ShowCurrentGauge();

	return 0;
}