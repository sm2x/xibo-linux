#pragma once

#include "IFileSystemAdaptor.hpp"

class FileSystemAdaptor : public IFileSystemAdaptor
{
public:
    bool isRegularFile(const FilePath& path) const override;

};
