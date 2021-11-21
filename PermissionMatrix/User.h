#ifndef USER_H
#define USER_H

#include <QString>
#include <QList>
#include "roles_list.h"

class User
{
public:
    User(QString name, role_names role);

public:
    void set_user_name(QString name);
    void set_user_role(role_names role);
    QString get_user_name();
    role_names get_user_role();

private:
    QString user_name;
    role_names user_role;
};

#endif // USER_H
