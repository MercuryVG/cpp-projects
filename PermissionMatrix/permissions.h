#ifndef PERMISSIONS_H
#define PERMISSIONS_H
#include "permissions_list.h"

class Permissions
{
public:
    Permissions(int permission);

private:
    void set_permission(int permission);

private:
    Permission_list permission;
};

#endif // PERMISSIONS_H
