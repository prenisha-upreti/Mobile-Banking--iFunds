#pragma once
#include "account.h"
class account_management :
    public account
{
protected:
    string temp_email, temp_pass, temp_email1, temp_pass1;
    int temp_mpin, temp_mpin1;
public:
    void change_email();
    void change_password();
    void change_mpin();
    int confirm_emailchange();
    int confirm_passchange();
    int confirm_pinchange();
};

