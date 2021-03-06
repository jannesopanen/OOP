#include <iostream>
#include <vector>



class User {

private : 
	static int user_count; // HUOM! STAATTINEN!
	std::string status;

public:
	int age{};
	std::string first_name;
	std::string last_name;

	static int get_user_count() {
		return user_count;
	}

	void print_all() {
		std::cout << "etunimi: " << this->first_name << " sukunimi: " << this->last_name << " ikä: " << this ->age << " status: " << this->status << "\n";
	}

	void set_status(std::string status) {
		if (status == "Gold" || status == "Silver" || status == "Bronse")
			this->status = status;
	}

	std::string get_status() {
		return status;
	}

	User() {
		user_count++;
	}

	User(std::string first_name, std::string last_name, int age = 1001) {
		this->first_name = first_name;
		this->last_name = last_name;
		this->age = age;
		this->status = "Bronse";
		user_count++;
	}

	~User() {		
		user_count--;
	}
};




// Lisää User-objektin vektorilistaan samoja objekteja, mikäli identtistä vastinetta ei löydy. Tämän takia &users, eli suora muistiosoite paikkaan, jossa vektori User-oliosta on luotu.
// Mikäli vastine löytyy, suoritetaan 'return i', joka keskeyttää funktion suorittamisen, sekä palauttaa paluuarvona indeksin, josta vastine löytyi.
// Jos vastinetta ei löydy, suoritetaan vector.push_back(), sekä palautetaan vektorin uusi koko. (vector.size())
int pushback_if_not_identical(std::vector<User> &users, User user) {
	for (int i = 0; i < (signed)users.size(); i++) {
		if (users[i].first_name == user.first_name && users[i].last_name == user.last_name) {
			return i;
		}
	}
	users.push_back(user);
	return users.size() - 1;
}


// STAATTISET:
int User::user_count = 0;			// User-luokassa staattiseksi määritelty user_count TÄYTYY määritellä luokan ulkopuolella myös.
// EO STAATTISET


int main() {
	
	User user, user2, user3, kakka, pillu, perse, karva, hjallis;

	std::cout << User::get_user_count() << "\n";

	return 0;
}