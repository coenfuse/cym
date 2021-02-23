// INCOMPLETE

/*
You need to create a program for Hotel reservation same like OYO,

Use cases are as follows :
1 : There can be N number of hotels in OYO
2 : there can be multiple rooms in a hotel
3 : each hotel have a name and location
4 : user can see vacant rooms for his stay
5 : user can only book a vacant property
6 : whenever booking hotel room it always gets booked from 12AM to next day 11 AM
7 : user can book hotel for multiple days as well
8 : there should be a hotel owner who can see the guest details, who have booked the room
9 : only authorised person can enter in the room(That is the person who have book the room
10: The Data structure in the above should be as such that User should be able to find nearest hotel from the Coordinates he is standing ,
Search and sorting Algo should be Optimised — <Preferable Quad Tree>

*/

#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<thread>
#include<ctime>

//Global Variables
const unsigned short MENU = 0;
const unsigned short ADMIN = 1;
const unsigned short USER = 2;
unsigned int spare_keys[10] = { 232, 563, 532, 623, 634, 342, 764, 324, 544, 999 };
bool thread_activity = true;

//Classes

class Room {
private:
	unsigned int m_key;
	int m_room_num;
	bool m_vacant;
	time_t m_booked_for;
	time_t m_booking_time;
	std::string m_booked_by;
public:

	int get_room_num() const { return m_room_num; }
	bool is_vacant() const { return m_vacant; }
	time_t booked_at() const { return m_booking_time; }
	time_t booked_for() const { return m_booked_for; }
	std::string booked_by() const { return m_booked_by; }

	int book(std::string book_by, int book_for_duration) {
		if (m_vacant) {
			m_vacant = false;
			m_booked_by = book_by;
			m_booking_time = time(NULL);
			m_booked_for = book_for_duration * 60 * 60;
			return m_key;
		}
		return -1;
	}
	bool enter(int key) {
		return m_key = key;
	}
	bool clear() {
		if (!m_vacant) {
			m_vacant = true;
			m_booked_by = "";
			m_booked_for = 0;
			return true;
		}
		return true;
	}

	Room() {
		m_key = 0;
		m_room_num = 0;
		m_vacant = true;
		m_booked_for = 0;
		m_booked_by = "";
	}
	Room(int room_num_init, unsigned int key) {
		m_key = key;
		m_room_num = room_num_init;
		m_vacant = true;
		m_booked_for = 0;
		m_booking_time = NULL;
		m_booked_by = "";
	}
	~Room(){}
};

class Hotel {
	std::string m_name;
	std::string m_location;
	unsigned int m_room_count = 0;
	std::map<int, Room> m_Rooms;
	std::vector<int> vacant_list;
	std::vector<int> occupied_list;
	

public:
	Hotel() {
		m_name = "";
		m_location = "";
		m_room_count = 0;
	}
	Hotel(std::string Name, std::string Location, unsigned int Rooms) {
		m_name = Name;
		m_location = Location;
		m_room_count = Rooms;

		for (unsigned int i = 1; i <= m_room_count; i++) { // Initializing the Rooms
			Room room(i, spare_keys[rand() % 9]);
			m_Rooms[i] = room;
		}
	}
	~Hotel() {}

	int vacant_rooms() {
		int count = 0;
		for (auto each_room : m_Rooms)
			if (each_room.second.is_vacant())
				count++;
		return count;
	}

	int occupied_rooms() {
		int count = 0;
		for (auto each_room : m_Rooms)
			if (! each_room.second.is_vacant())
				count++;
		return count;
	}

	void _guests_list() {
		for (auto each_room : m_Rooms) {
			if (!each_room.second.is_vacant())
				std::cout << "Room number: " << each_room.second.get_room_num() << " is booked by: ";
			std::cout << each_room.second.booked_by()<< std::endl;
		}
	}

	Room* get_room(int room_number) {
		Room& to_return = m_Rooms.at(room_number);
		return &to_return;
	}

	std::vector<int> get_vacant_rooms(){
		int count = 1;
		std::vector<int> local_vacant_list;
		for (auto room_itr : m_Rooms){
			if (room_itr.second.is_vacant())
				local_vacant_list.push_back(count);
		}
		return local_vacant_list;
	}

	std::vector<int> get_occupied_rooms() {
		int count = 1;
		std::vector<int> local_occupied_list;
		for (auto room_itr : m_Rooms) {
			if (!room_itr.second.is_vacant())
				local_occupied_list.push_back(count);
		}
		return local_occupied_list;
	}

	int book_room(std::string name, int room_number, int duration_hours) {
		Room newRoom = m_Rooms.at(room_number);
		int key = newRoom.book(name, duration_hours);
		if (key != -1) {
			std::cout << "Booked Room number: " << room_number << " for " << duration_hours << " days by " << name << std::endl;
			m_Rooms[room_number] = newRoom;
			occupied_list.push_back(room_number);
			return key;
		}
		else return key;
	}

	void clear_room(int room_number) {
		vacant_list.push_back(room_number);
		Room *temp = &m_Rooms.at(room_number);
		temp->clear();
	}
};

//Init Data
Hotel H1("Tara_Hotels","Janakpuri",58);
Hotel H2("Galaxy_Hotel", "Moolchand", 241);
Hotel H3("Urban_Escape", "South Extension", 120);
Hotel H4("Western_Influence_Hotel", "Preet Vihar", 782);
Hotel H5("Zelda_Hotel", "Nagloi", 35);
Hotel H6("Epsilon_Hotel", "Srinivaspuri", 40);
Hotel H7("Omega_Hotel", "Barakhamba", 64);
Hotel H8("Gamma_Hotel", "Laxmi Nagar", 15);
Hotel H9("Beta_Hotel", "Darya Ganj", 94);
Hotel H10("Phi_Hotel", "Shahdara", 100);

std::map<std::string, Hotel> OYO_DB = {
	{"Tara Hotels", H1},
	{"Galaxy Hotel", H2},
	{"Urban Escape", H3},
	{"Western Influence Hotel", H4},
	{"Zelda Hotel", H5},
	{"Epsilon Hotel", H6},
	{"Omega Hotel", H7},
	{"Gamma Hotel", H8},
	{"Beta Hotel", H9},
	{"Phi Hotel", H10},
};

void routine_check() {
	using namespace std::literals::chrono_literals;
	std::vector<int> list;
	while (thread_activity) {
		for (auto hotel : OYO_DB) {
			list = hotel.second.get_occupied_rooms();

			for (auto room : list) {
				if(difftime(hotel.second.get_room(room)->booked_for(), 
					hotel.second.get_room(room)->booked_at()) > 
					hotel.second.get_room(room)->booked_for())
				hotel.second.clear_room(room);
			}
		}
		std::this_thread::sleep_for(1s);
	}
}

// ADMIN FUNCTIONS

void get_hotel_list() {
	int i = 1;
	for (auto entity : OYO_DB) {
		std::cout << i << ". " << entity.first << std::endl;
		i++;
	}
}
void get_vacant_rooms() {
	for (auto _hotel : OYO_DB) {
		std::cout<< _hotel.first <<" : "<< _hotel.second.vacant_rooms()<<std::endl;
	}
}
void show_vacant_rooms_in(std::string m_hotel_rooms) {
	OYO_DB.at(m_hotel_rooms).vacant_rooms();
}
void get_guest_list(std::string hotel_name) {
	OYO_DB.at(hotel_name)._guests_list();
}
void add_new_hotel() {
	std::string new_hotel_name, new_hotel_location; int new_hotel_capacity;
	std::cout << "Enter name of the new hotel" << std::endl;
	std::cin>>new_hotel_name;
	std::cout << "Enter the location of your hotel" << std::endl;
	std::cin >> new_hotel_location;
	std::cout << "Enter number of rooms in your hotel" << std::endl;
	std::cin >> new_hotel_capacity;
	Hotel newHotel(new_hotel_name, new_hotel_location, new_hotel_capacity);
	OYO_DB[new_hotel_name] = newHotel;

	std::cout << "\n\nChecking the database" << std::endl;
	get_hotel_list();
}

// USER (EXCLUSIVE) FUNCTIONS

void get_nearest_hotel(std::string current_location) {
	std::cout << "This function is currently in development" << std::endl;
}
void book_room(std::string hotel_name) {
	unsigned int room_no, duration_hours; std::vector<int> temp_list; std::string user_name;
	int entry_key;

	std::cout << "Enter your name" << std::endl;
	std::cin >> user_name;

	temp_list = OYO_DB.at(hotel_name).get_vacant_rooms();
	for (auto _each_room : temp_list)
		std::cout << "Room number : " << _each_room << std::endl;
	
	std::cout << "\nOut of the vacant rooms shown above. Type in the room you want to book" << std::endl;
	std::cin >> room_no;
	std::cout << "\nAnd for how many days you want to book this room?. In hours." << std::endl;
	std::cin >> duration_hours;

	entry_key = OYO_DB.at(hotel_name).book_room(user_name, room_no, duration_hours);
	if (entry_key != -1) {
		std::cout << "You've booked a room in the hotel: " << hotel_name << ". Under name of : " << user_name << ", for the duration of : " << duration_hours << " hours."<<std::endl;
		std::cout << "Your entry key is: " << entry_key << "\n KEEP IT SAFE!" << std::endl;
	}
}
void enter_room(std::string Hotel_name, unsigned int room_number) {
	std::cout << "Type in your entry key" << std::endl;
	int key;
	std::cin >> key;
	Room* room_alias = OYO_DB.at(Hotel_name).get_room(room_number);
	std::cout << room_alias->enter(key) << std::endl;
}


// UTILITY FUNCTIONS

void graphics(int option) {
	switch (option){
	case MENU:{
		std::cout<<"\t\t\t\t\tWelcome to OYO"<<std::endl;
		std::cout << "\t\t\t      Please select the option to proceed";
		std::cout << "\n\t\t\t    =======================================\n" << std::endl;
		std::cout << "\t\t\t\t  Press 1 to proceed as Admin\n" << std::endl;
		std::cout << "\t\t\t\t  Press 2 to proceed as User\n" << std::endl;
		std::cout << "\t\t\t    =======================================\n" << std::endl;
	}
			 break;
	case ADMIN:{
		system("cls");
		std::cout << "\t\t\t\t\tADMIN DASHBOARD" << std::endl;
		std::cout << "\t\t\t      Please select the option to proceed" << std::endl;
		std::cout << "\n\t\t\t    =======================================\n" << std::endl;
		std::cout << "\t\t\t\t  Press 1 to Get List of Hotels\n" << std::endl;
		std::cout << "\t\t\t\t  Press 2 to Get vacant rooms in each hotel\n" << std::endl;
		std::cout << "\t\t\t\t  Press 3 to Get guest list in each hotel\n" << std::endl;
		std::cout << "\t\t\t\t  Press 4 to add new hotel to the OYO database.\n" << std::endl;
		std::cout << "\t\t\t\t  Press 5 to exit" << std::endl;
		std::cout << "\n\t\t\t    =======================================\n" << std::endl;
	}
			  break;
	case USER:{
		system("cls");
		std::cout << "\t\t\t\t\tUSER DASHBOARD" << std::endl;
		std::cout << "\t\t\t      Please select the option to proceed" << std::endl;
		std::cout << "\n\t\t\t    =======================================\n" << std::endl;
		std::cout << "\t\t\t\t  Press 1 to Get List of Hotels\n" << std::endl;
		std::cout << "\t\t\t\t  Press 2 to Get vacant rooms in each hotel\n" << std::endl;
		std::cout << "\t\t\t\t  Press 3 to Find closest Hotel\n" << std::endl;
		std::cout << "\t\t\t\t  Press 4 to Book a Room\n" << std::endl;
		std::cout << "\t\t\t\t  Press 5 to Enter a Room\n" << std::endl;
		std::cout << "\t\t\t\t  Press 6 to exit" << std::endl;
		std::cout << "\n\t\t\t    =======================================\n" << std::endl;
	}
			 break;
	default:
		break;
	}
	//body
}
void dashboard(int type) {
	if (type == ADMIN) {
		int option = 0;
		std::cin >> option;
		switch (option)
		{
		case 1: {
			get_hotel_list();
		}
			  break;
		case 2: {
			get_vacant_rooms();
		}
			  break;
		case 3: {
			std::string hotel_name = "";
			std::cout << "Enter Hotel Name" << std::endl;
			std::cin >> hotel_name;
			get_guest_list(hotel_name);
		}
			  break;
		case 4: {
			add_new_hotel();
		}
			  break;
		default:
			break;
		}
	}
	else {
		int option = 0;
		std::cin >> option;
		switch (option)
		{
		case 1: {
			get_hotel_list();
		}
			  break;
		case 2: {
			get_vacant_rooms();
		}
			  break;
		case 3: { 
			std::string current_loc = "";
			std::cout << "Enter your current location" << std::endl;
			std::cin >> current_loc;
			get_nearest_hotel(current_loc);
		}
			  break;
		case 4: {
			std::string hotel_name;
			std::cout << "Enter which hotel you want your room to get booked?" << std::endl;
			std::cin >> hotel_name;
			book_room(hotel_name);
		}
		case 5: {
			std::string hotel_name; unsigned int room_number;
			std::cout << "Enter your hotel name?" << std::endl;
			std::cin >> hotel_name;
			std::cout << "Enter your room number" << std::endl;
			std::cin >> room_number;
			enter_room(hotel_name, room_number);
		}
			  break;
		default:
			break;
		}
	}
}

// DRIVER CODE

int main() {

	std::thread routine(routine_check);

	char run = 'y';
	while (run == 'Y' || run == 'y') {

		system("cls");
		graphics(MENU);
		int choice = 0;
		std::cin >> choice;
		if (choice == 1) {
			graphics(ADMIN);
			dashboard(ADMIN);
		}
		else if(choice == 2) {
			graphics(USER);
			dashboard(USER);
		}
		else {
			std::cout << "\t\t\t\t\tIncorrect input!" << std::endl;
		}
		std::cout << "\t\t\t      Want to run the program again? [Y/N]" << std::endl;
		std::cin >> run;
	}
	thread_activity = false;
	routine.join();
	exit(0);
}