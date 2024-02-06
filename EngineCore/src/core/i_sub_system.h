#pragma once

class i_sub_system
{
public:
    virtual ~i_sub_system() = default;
    virtual void init() = 0;
};
