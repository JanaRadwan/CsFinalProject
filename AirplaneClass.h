#ifndef HEADER_H
#endif HEADER_H
#define HEADER_H

class Airplane {
private:
	int Tarrival;
	int Twait;

public:
	Airplane() {
		this->setTarrival(0);
		this->setTwait(0);
	}
	Airplane(int arrivalTime) {
		this->Tarrival = arrivalTime;
		this->Twait = 0;
	}

	void setTarrival(int x) { Tarrival = x; }
	void setTwait(int y) { Twait = y; }
	int getTarrival() { return Tarrival; }
	int getTwait() { return Twait; }

};

class AirportRunway {
private:
	Airplane* airplane;    
	int Tlanding;
	//bool Runwayoccupied = false;
public:
	bool Runwayoccupied = false;
	AirportRunway() {
		Tlanding = 0;
		airplane = nullptr;
	}
	void setTlanding(int z) { Tlanding = z; }
	int getTlanding() {
		return Tlanding;
	}
	
	void set_airplane(Airplane* a) {
		airplane = a;
	}
	Airplane* get_airplane() {
		return airplane;
	}
	bool isoccupied() { 
		if (Runwayoccupied == false)
			return false;
		else return true;
	}

};


