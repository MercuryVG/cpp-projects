#ifndef FILE_H
#define FILE_H

#include <QString>
#include "roles_list.h"
#include "permissions_list.h"

class File
{
public:
    File();
    File(QString name, Permission_list permissions[]);

public:
    void update_permission_for_role(int role, int permisison);
    int get_permission_for_role(int role);
    void reset_all_permissions();
    QString get_file_name();
    void set_file_name(QString);

private:
    QString file_name;
    Permission_list permisisons[7];

};

#endif // FILE_H
