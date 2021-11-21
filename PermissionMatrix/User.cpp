#include "User.h"


User::User(QString name, role_names role)
{
    set_user_name(name);
    set_user_role(role);
}

void User::set_user_name(QString name)
{
    this->user_name = name;
}

void User::set_user_role(role_names role)
{
    this->user_role = role;
}

QString User::get_user_name()
{
    return user_name;
}

role_names User::get_user_role()
{
    return user_role;
}
