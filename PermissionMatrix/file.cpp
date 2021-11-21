#include "file.h"

File::File()
{
    //setting all fields of permissions array in file with none
    for(auto &i : permisisons)
    {
        i = none;
    }
}

int File::get_permission_for_role(int role)
{
    return permisisons[role];
}

void File::update_permission_for_role(int role, int permisison)
{
    permisisons[role] = Permission_list(permisison);
}

void File::reset_all_permissions()
{
    //clearing all fields of permissions array in file with none
    for(auto &i : permisisons)
    {
        i = none;
    }
}

QString File::get_file_name()
{
    return file_name;
}

void File::set_file_name(QString name)
{
    file_name = name;
}
