#pragma once

class i_opengl_resource
{
public:
    virtual ~i_opengl_resource() = default;
    virtual void release_opengl_resources() = 0;
};
