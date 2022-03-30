// Parking Lot
//
// entrance gate count - N
// exit gate count - M
// Parking Lots - 1000 
// 250 for 2 wheelers - 50 Rs/hr
// 250 for 4 wheelers cars small - 100 Rs/hr
// 250 for 4 wheelers cars large - 150 Rs/hr
// 250 for XXL vehicles - 200 Rs/hr
// Rs to be paid on exit

class Slot{
	private:
		int id;
		int cost;
		bool occupied;
	public:
		GetSlotDetails(int id){}
};

class ParkingLot{
	private:
		list<Slot> slots;
		unordered_map<int, Slot> slotStatus;
		unordered_map<VehicleId, Slot> pmap;
		unordered_map<VehicleId, Vehicle*> vmap;
		DB* instance;
	public:
		virtual parkVehicle(Vehicle* v) = 0;
		virtual UnparkVehicle(Vehicle* v) = 0;
		virtual IsSlotAvailable() = 0;
		virtual UpdateDB();
};

class FreeParkingLot: public ParkingLot{
	parkVehicle(Vehicle* v);
	UnparkVehicle(Vehicle* v);
	IsSlotAvailable();
};

class SEZParkingLot: public ParkingLot{
	private:
		int parkingCharge;
		long long TotalRevenue;
		SEZParkingLot()=0;
		static SEZParkingLot* instance;
	public:
		static SEZParkingLot* GetInstance();
		parkVehicle(Vehicle* v);
		UnparkVehicle(Vehicle* v);
		GetFee(Vehicle* v);
		IsSlotAvailable();
};

class Vehicle{
	private:
		string vehicleNo;
		TimeStamp entry_time;
		TimeStamp exit_time;
		VehicleType v;
};

class 2Wheeler: public Vehicle{
	private:
		int feeprhr;
};

class 4WheelerSmall: public Vehicle{
	private:
		int feeprhr;
};

class 4Wheeler: public Vehicle{
	private:
		int feeprhr;
};

class NWheeler: public Vehicle{
	private:
		int feeprhr;
};

enum VehicleType {2Wheeler, 4WheelerSmall, 4Wheeler, NWheeler}



// If asked to create the DB Schema to persist the DataInformation
class DB{
	private:
		static DB* instance;
		DB();
	public:
		static DB* GetDBInstance(){}
}

class MySQLDB: pubic DB{
	
}


// If Rest Endpoints are required for the same problem
//
- UpdateSlot(SlotID, Slot) - /UpdateSlot   //?SlotID=123&Slot=nceni
- GetSlot(SlotID) - /GetSlot?SlotID=123
- Updatefees - /Updatefees // SlotID, VehicleId, fees
