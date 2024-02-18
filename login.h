#pragma once
#include "User.h"

class Login {
private:
	string Id, PW;
public:
	Login() :Id(""), PW("") {   }

	void setId(string id) {
		Id = id;
	}
	void setPW(string pw) {
		PW = pw;
	}

	string getId() {
		return Id;
	}
	string getPW() {
		return PW;
	}

	 int confirm_login();
};