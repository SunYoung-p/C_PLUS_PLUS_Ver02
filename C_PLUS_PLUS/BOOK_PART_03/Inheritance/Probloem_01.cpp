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

class HybridCar : public Car		// ���̺긮�� �ڵ���
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

class HybridWaterCar : public HybridCar // ���̺긮�� ����ī
{
private:
	int waterGauge;
public:
	HybridWaterCar(int gas, int elec, int water) : HybridCar(gas, elec), waterGauge(water)
	{ }
	void ShowCurrentGauge()
	{
		cout << "�ܿ� ���ָ� : " << GetGasGauge() << endl;
		cout << "�ܿ� ���ⷮ: " << GetElecGauge() << endl;
		cout << "�ܿ� ���ͷ�: " << waterGauge << endl;
	}

};

int No1_1021()
{
	HybridWaterCar HwCar(10, 20, 30);
	HwCar.ShowCurrentGauge();

	return 0;
}