#include "permissions.h"

Permissions::Permissions(int permission)
{
    set_permission(permission);
}

void Permissions::set_permission(int permission)
{
    this->permission = Permission_list(permission);
}
