#ifndef EXPORTER_H
#define EXPORTER_H
#include <iostream>
#include <fstream>
#include "Database/lib/communitydata.h"


class Exporter{
private:
    friend class Controller;

    std::ofstream exportFile;

    static Exporter* instance;
    CommunityData* data;

protected:
    Exporter(CommunityData* data);


public:
    void exportShopinglist();
    void exportCleaningplan(int week);

    static Exporter* getInstance(CommunityData* data);

    ~Exporter();
};

#endif // EXPORTER_H
