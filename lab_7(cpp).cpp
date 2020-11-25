#include <iostream>
#include <string>


using namespace std;

template<typename T>
class Time {
private:
	int  Hours;
	int  Minutes;
	int  Seconds;
	char Separator;
public:
	Time() : Hours(0), Minutes(0), Seconds(0), Separator('.') {};
	Time(int H, int M, int S, char Separator = '.') : Separator(Separator)
	{
		int temp_H;
		int temp_M;

		Seconds = S % 60;
		temp_M = M + (S - S % 60) / 60;
		Minutes = temp_M % 60;
		temp_H = H + (temp_M - temp_M % 60) / 60;
		Hours = temp_H % 24;
	}

	int GetHours()   const {
		return Hours;
	}

	int GetMinutes() const {
		return Minutes;
	}

	int GetSeconds() const {
		return Seconds;
	}

	void SetHours(int H) {
		Hours = H % 24;
	}

	void SetMinutes(int M) {
		int temp_H;
		Minutes = M % 60;
		temp_H = Hours + (M - M % 60) / 60;
		Hours = temp_H % 24;
	}

	void SetSeconds(int S) {
		int temp_H;
		int temp_M;

		Seconds = S % 60;
		temp_M = Minutes + (S - S % 60) / 60;
		Minutes = temp_M % 60;
		temp_H = Hours + (temp_M - temp_M % 60) / 60;
		Hours = temp_H % 24;
	}

	string GetTime() {
		string temp;
		string Postfix;
		if (Hours < 12) {
			Postfix = " a.m";
		}
		else
		{
			Postfix = " p.m";
		}
		temp = to_string(Hours % 12);
		temp += Separator;
		temp += to_string(Minutes % 60);
		temp += Separator;
		temp += to_string(Seconds % 60);
		temp += Postfix;
		return temp;
	}

	void operator >>(int Time) {
		Seconds = Time % 60;
		Time = (Time - Seconds) / 60;
		Minutes = Time % 60;
		Time = (Time - Minutes) / 60;
		Hours = Time % 24;
	}
	void operator+=(int Time) {
		Time += Hours * 60 * 60 + Minutes * 60 + Seconds;
		*this >> Time;

	}

};

int main()
{
	Time<int>* Start = new Time<int>();
	string temp = (*Start).GetTime();
	cout << temp << endl;

	*Start >> 216512;
	temp = (*Start).GetTime();
	cout << temp << endl;

	*Start += 5056;
	temp = (*Start).GetTime();
	cout << temp << endl;

	int x;
	cin >> x;
	return 0;
}
